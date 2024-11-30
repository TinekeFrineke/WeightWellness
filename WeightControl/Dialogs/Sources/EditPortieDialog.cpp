// EditPortieDalog.cpp : implementation file
//

#include "stdafx.h"
#include "WeightControl.h"
#include "EditPortieDialog.h"

#include "model/Unit.h"
#include "model/VoedingsmiddelDefinitie.h"
#include ".\editportiedialog.h"


// CEditPortieDialog dialog

IMPLEMENT_DYNAMIC(CEditPortieDialog, CDialog)
CEditPortieDialog::CEditPortieDialog(weight::VMDefinitie& aDefinitie,
                                     weight::Portie& aPortie,
                                     const std::vector<std::unique_ptr<weight::Portie>>& aPorties,
                                     CWnd* pParent)
    : CDialog(CEditPortieDialog::IDD, pParent)
    , mDefinitie(aDefinitie)
    , mPortie(&aPortie)
    , mNaam(aPortie.GetName())
{
    for (size_t i = 0; i < aPorties.size(); ++i)
        mPortienames.push_back(aPorties[i]->GetName());
}

CEditPortieDialog::~CEditPortieDialog() = default;


void CEditPortieDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //DDX_Control(pDX, IDC_AMOUNT,        mAmount);
    DDX_Control(pDX, IDC_POINTS, mPoints);
    DDX_Control(pDX, IDC_VMNAAM, mVoedingsMiddel);
    DDX_Control(pDX, IDC_UNITAMOUNT, mUnitAmount);
    DDX_Control(pDX, IDC_UNIT, mUnitStatic);
    DDX_Control(pDX, IDC_OMSCHRIJVING, mNaam);
}


BEGIN_MESSAGE_MAP(CEditPortieDialog, CDialog)
    //  ON_WM_CREATE()
    ON_BN_CLICKED(IDOK, OnBnClickedOk)
    ON_EN_CHANGE(IDC_AMOUNT, OnEnChangeAmount)
    ON_EN_CHANGE(IDC_UNITAMOUNT, OnEnChangeUnitamount)
    ON_CBN_SELCHANGE(IDC_OMSCHRIJVING, OnCbnSelchangeOmschrijving)
END_MESSAGE_MAP()


void CEditPortieDialog::UpdatePoints()
{
    mPoints.SetValue((mDefinitie.GetPointsPer100Units() * mUnitAmount.GetValue()) / 100);
}


// CEditPortieDialog message handlers

BOOL CEditPortieDialog::OnInitDialog()
{
    if (CDialog::OnInitDialog() == FALSE)
        return FALSE;

    mNaam.Initialize();
    mNaam.Fill(mPortienames, mPortie->GetName());

    mUnitStatic.SetWindowText(mDefinitie.GetUnit().GetName().c_str());
    mVoedingsMiddel.SetValue(mDefinitie.GetName());

    mUnitAmount.SetValue(mPortie->GetUnits());

    UpdatePoints();
    return TRUE;
}

void CEditPortieDialog::OnBnClickedOk()
{
    TCHAR text[1024];
    mNaam.GetWindowText(text, 1024);

    mPortie->SetName(text);
    mPortie->SetUnits(mUnitAmount.GetValue());

    OnOK();
}

void CEditPortieDialog::OnEnChangeAmount()
{
    UpdatePoints();
}


void CEditPortieDialog::OnEnChangeUnitamount()
{
    UpdatePoints();
}

void CEditPortieDialog::OnCbnSelchangeOmschrijving()
{
    mPortie = mNaam.GetSelectedPortie();
    mUnitAmount.SetValue(mPortie->GetUnits());
}
