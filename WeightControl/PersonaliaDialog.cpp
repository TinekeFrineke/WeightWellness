// PersonaliaDialog.cpp : implementation file
//

#include "stdafx.h"
#include "WeightControl.h"

#include "model/Personalia.h"
#include "model/Model.h"

#include ".\personaliadialog.h"


// CPersonaliaDialog dialog

IMPLEMENT_DYNAMIC(CPersonaliaDialog, CDialog)
CPersonaliaDialog::CPersonaliaDialog(weight::Model& aModel, CWnd* pParent /*=nullptr*/)
    : CDialog(CPersonaliaDialog::IDD, pParent),
    mModel(aModel),
    mGeslacht(GS_Mannelijk),
    mPersonalia(nullptr)
{
    mPersonalia = mModel.GetActivePersonalia();
}

CPersonaliaDialog::~CPersonaliaDialog()
{
}

void CPersonaliaDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_EDIT1, mNaam);
    DDX_Control(pDX, IDC_EDIT2, mUsername);
    DDX_Control(pDX, IDC_MANNELIJK, mButtonMannelijk);
    DDX_Control(pDX, IDC_VROUWELIJK, mButtonVrouwelijk);
    DDX_Control(pDX, IDC_PUNTENTOTAAL, mPuntenTotaal);
    DDX_Control(pDX, IDC_EDIT4, mStreefGewicht);
    DDX_Control(pDX, IDC_LENGTE, mLengte);
    DDX_Control(pDX, IDC_STARTGEWICHT, mStartWeight);
    DDX_Control(pDX, IDC_HUIDIGGEWICHT, mCurrentWeight);
    DDX_Control(pDX, IDC_WEEKPUNTENSTATIC, mWeekPuntenStatic);
    DDX_Control(pDX, IDC_WEEKPUNTEN, mWeekPunten);
}


BEGIN_MESSAGE_MAP(CPersonaliaDialog, CDialog)
    ON_BN_CLICKED(IDC_MANNELIJK, OnBnClickedMannelijk)
    ON_BN_CLICKED(IDC_VROUWELIJK, OnBnClickedVrouwelijk)
    ON_EN_KILLFOCUS(IDC_EDIT1, OnEnKillfocusNaam)
    ON_EN_KILLFOCUS(IDC_EDIT2, OnEnKillfocusUserNaam)
    ON_EN_KILLFOCUS(IDC_EDIT4, OnEnKillfocusEdit4)
    ON_EN_KILLFOCUS(IDC_LENGTE, OnEnKillfocusLengte)
    ON_EN_KILLFOCUS(IDC_PUNTENTOTAAL, OnEnKillfocusPuntentotaal)
    ON_EN_CHANGE(IDC_STARTGEWICHT, OnEnChangeStartgewicht)
    ON_EN_KILLFOCUS(IDC_STARTGEWICHT, OnEnKillfocusStartgewicht)
    ON_EN_KILLFOCUS(IDC_WEEKPUNTEN, OnEnKillfocusWeekpunten)
    ON_BN_CLICKED(IDC_RADIO_KCAL, OnBnClickedRadioKcal)
    ON_BN_CLICKED(IDC_RADIO_CARBOHYDRATES, OnBnClickedCarbohydrates)
END_MESSAGE_MAP()


BOOL CPersonaliaDialog::OnInitDialog()
{
    if (CDialog::OnInitDialog() == FALSE)
        return FALSE;

    mStreefGewicht.SetDecimals(1);

    if (mPersonalia == nullptr)
    {
        mButtonMannelijk.SetCheck(TRUE);
        mButtonMannelijk.SetCheck(FALSE);
        mPuntenTotaal.SetValue(0);
        mWeekPunten.SetValue(0);
        mStreefGewicht.SetValue(0);
        mStartWeight.SetValue(0);
        mCurrentWeight.SetValue(0);
        mLengte.SetValue(0);
    }
    else
    {
        mNaam.SetValue(mPersonalia->GetName());
        mUsername.SetValue(mPersonalia->GetUserName());
        mButtonMannelijk.SetCheck(mPersonalia->GetGeslacht() == weight::Personalia::GESLACHT::Mannelijk);
        mButtonVrouwelijk.SetCheck(mPersonalia->GetGeslacht() == weight::Personalia::GESLACHT::Vrouwelijk);

        switch (mModel.GetStrategy())
        {
            case weight::STRATEGY_TYPE::KCal:
                mWeekPunten.SetValue(mPersonalia->GetKCWeekPuntenTotaal());
                break;
            case weight::STRATEGY_TYPE::CarboHydrates:
                mWeekPunten.SetValue(mPersonalia->GetCHWeekPuntenTotaal());
                break;
        }

        mPuntenTotaal.SetValue(mPersonalia->GetPuntenTotaal(mModel.GetStrategy()));
        mStreefGewicht.SetValue(mPersonalia->GetStreefGewicht());
        mStartWeight.SetValue(mPersonalia->GetStartGewicht());
        mCurrentWeight.SetValue(mPersonalia->GetHuidigGewicht());
        mLengte.SetValue(mPersonalia->GetLengte());
    }

    switch (mModel.GetStrategy())
    {
        case weight::STRATEGY_TYPE::KCal:
            CheckDlgButton(IDC_RADIO_KCAL, 1);
            break;
        case weight::STRATEGY_TYPE::CarboHydrates:
            CheckDlgButton(IDC_RADIO_CARBOHYDRATES, 1);
            break;
    }

    mStreefGewicht.SetReadOnly(mStreefGewicht.GetValue() > 1);
    mStartWeight.SetReadOnly(mStartWeight.GetValue() > 1);
    return TRUE;
}


// CPersonaliaDialog message handlers

void CPersonaliaDialog::OnCancel()
{
}

void CPersonaliaDialog::OnBnClickedMannelijk()
{
    mGeslacht = GS_Mannelijk;
    mButtonVrouwelijk.SetCheck(BST_UNCHECKED);
}

void CPersonaliaDialog::OnBnClickedVrouwelijk()
{
    mGeslacht = GS_Vrouwelijk;
    mButtonMannelijk.SetCheck(BST_UNCHECKED);
}

void CPersonaliaDialog::OnEnKillfocusNaam()
{
    if (mPersonalia != nullptr)
        mPersonalia->SetName(mNaam.GetValue());
}

void CPersonaliaDialog::OnEnKillfocusUserNaam()
{
    if (!mUsername.GetValue().empty())
        mUsername.SetReadOnly(TRUE);

    if (mPersonalia == nullptr)
    {
        if (mUsername.GetValue().empty())
            return;

        auto personalia = std::make_unique< weight::Personalia>(mUsername.GetValue());
        mPersonalia = personalia.get();
        mPersonalia->SetName(mNaam.GetValue());

        mModel.Add(std::move(personalia));
    }

}

void CPersonaliaDialog::OnEnKillfocusEdit4()
{
    if (mPersonalia != nullptr)
        mPersonalia->SetStreefGewicht(mStreefGewicht.GetValue());
}

void CPersonaliaDialog::OnEnKillfocusLengte()
{
    if (mPersonalia != nullptr)
        mPersonalia->SetLengte(mLengte.GetValue());
}

void CPersonaliaDialog::OnEnKillfocusPuntentotaal()
{
    if (mPersonalia != nullptr)
        mPersonalia->SetPuntenTotaal(mModel.GetStrategy(), mPuntenTotaal.GetValue());
}



bool CPersonaliaDialog::CanExit(bool bLeaveApplication)
{
    return bLeaveApplication || (mPersonalia != nullptr);
}

void CPersonaliaDialog::OnEnChangeStartgewicht()
{
}

void CPersonaliaDialog::OnEnKillfocusStartgewicht()
{
    if (mStartWeight.GetValue() > 1)
    {
        mStartWeight.SetReadOnly(TRUE);
        mCurrentWeight.SetValue(mStartWeight.GetValue());

        mPersonalia->SetStartGewicht(mStartWeight.GetValue());
        mPersonalia->SetHuidigGewicht(mStartWeight.GetValue());
    }
}


void CPersonaliaDialog::OnEnKillfocusWeekpunten()
{
    if (mPersonalia != nullptr) {
        switch (mModel.GetStrategy()) {
            case weight::STRATEGY_TYPE::KCal:
                mPersonalia->SetKCWeekPuntenTotaal(static_cast<int>(mWeekPunten.GetValue()));
                break;
            case weight::STRATEGY_TYPE::CarboHydrates:
                mPersonalia->SetCHWeekPuntenTotaal(mWeekPunten.GetValue());
                break;
        }
    }
}


void CPersonaliaDialog::OnBnClickedRadioKcal()
{
    mModel.SetStrategy(weight::STRATEGY_TYPE::KCal);
    mPuntenTotaal.SetValue(mPersonalia->GetKCPuntenTotaal());
    mWeekPunten.SetReadOnly(FALSE);
    mWeekPunten.SetValue(mPersonalia->GetKCWeekPuntenTotaal());
    UpdateWindow();
}


void CPersonaliaDialog::OnBnClickedCarbohydrates()
{
    mModel.SetStrategy(weight::STRATEGY_TYPE::CarboHydrates);
    mPuntenTotaal.SetValue(mPersonalia->GetCHPuntenTotaal());
    mWeekPunten.SetReadOnly(FALSE);
    mWeekPunten.SetValue(mPersonalia->GetCHWeekPuntenTotaal());
    UpdateWindow();
}
