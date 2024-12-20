// EditFoodDefDialog.cpp : implementation file
//

#include "stdafx.h"
#include ".\EditFoodDialog.h"

#include <assert.h>

#include "model/LotFactory.h"
#include "model/NutritionalValue.h"
#include "model/PointsCalculator.h"
#include "model/Voedingsmiddel.h"

// EditFoodDialog dialog

IMPLEMENT_DYNAMIC(EditFoodDialog, CDialog)
EditFoodDialog::EditFoodDialog(weight::Voedingsmiddel& aVoedingsmiddel,
                               const weight::FoodParameters& parameters,
                               std::shared_ptr<weight::PointsCalculator> calculator,
                               double pointsPerUnit,
                               const std::vector<std::unique_ptr<weight::Portie>>& porties,
                               CWnd* aParent)
    : CDialog(EditFoodDialog::IDD, aParent)
    , mVoedingsmiddel(aVoedingsmiddel)
    , m_parameters(parameters)
    , m_calculator(calculator)
    , m_pointsPer100Units(pointsPerUnit)
    , m_porties(porties)
    , mPortie(aVoedingsmiddel.GetLot().GetPortie().GetName())
    , mUpdating(false)
{
}

EditFoodDialog::~EditFoodDialog() = default;

void EditFoodDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_AANTAL_PORTIES, mAantalPorties);
    DDX_Control(pDX, IDC_AANTAL_UNITS, mAantalEenheden);
    DDX_Control(pDX, IDC_PORTIENAAM, mPortie);
    DDX_Control(pDX, IDC_PUNTEN, mPunten);
    DDX_Control(pDX, IDC_VOEDINGSMIDDELNAAM, mNaam);
}


BEGIN_MESSAGE_MAP(EditFoodDialog, CDialog)
    ON_EN_CHANGE(IDC_AANTAL_PORTIES, OnEnChangeAantalPorties)
    ON_EN_CHANGE(IDC_AANTAL_UNITS, OnEnChangeAantalUnits)
    ON_CBN_SELCHANGE(IDC_PORTIENAAM, OnCbnSelchangePortienaam)
    ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()

BOOL EditFoodDialog::OnInitDialog()
{
    if (CDialog::OnInitDialog() == FALSE)
        return FALSE;

    mAantalEenheden.SetReadOnly(false);
    mAantalPorties.SetReadOnly(false);
    mPortie.EnableWindow(m_porties.size() > 1);
    mPortie.Fill(m_porties);

    const auto& lot = mVoedingsmiddel.GetConstLot();
    mAantalEenheden.SetValue(lot.GetPortie().GetUnits() * lot.GetNumberOfPortions());
    mAantalPorties.SetValue(lot.GetNumberOfPortions());
    std::tstring name(lot.GetPortie().GetName());
    int index = mPortie.FindStringExact(0, name.c_str());
    mPortie.SetCurSel(index);
    mPunten.SetValue(lot.GetPoints());

    mNaam.SetValue(mVoedingsmiddel.GetName());
    mPortie.Initialize();
    mPortie.Fill(m_porties, lot.GetPortie().GetName());

    return TRUE;
}


// EditFoodDialog message handlers

void EditFoodDialog::OnEnChangeAantalPorties()
{
    if (!mUpdating)
    {
        mUpdating = true;
        if (mPortie.GetSelectedPortie() != nullptr)
        {
            weight::Portie* portie = mPortie.GetSelectedPortie();
            mAantalEenheden.SetValue(mAantalPorties.GetValue() * portie->GetUnits());

            mPunten.SetValue((mAantalEenheden.GetValue() * m_pointsPer100Units) / 100);
        }

        mUpdating = false;
    }
}

void EditFoodDialog::OnEnChangeAantalUnits()
{
    if (!mUpdating)
    {
        mUpdating = true;
        if (mPortie.GetSelectedPortie() != nullptr)
        {
            mAantalPorties.SetValue(mAantalEenheden.GetValue() / mPortie.GetSelectedPortie()->GetUnits());
            mPunten.SetValue((mAantalPorties.GetValue()
                                * mPortie.GetSelectedPortie()->GetUnits()
                                * m_pointsPer100Units) / 100);
        }

        mUpdating = false;
    }
}

void EditFoodDialog::OnCbnSelchangePortienaam()
{
    if (!mUpdating)
    {
        mUpdating = true;
        weight::Portie* portie = mPortie.GetSelectedPortie();
        if (portie != nullptr)
        {
            mAantalEenheden.SetValue(portie->GetUnits() * mAantalPorties.GetValue());
            mPunten.SetValue((mAantalEenheden.GetValue() * m_pointsPer100Units) / 100);
        }
        mUpdating = false;
    }
}


void EditFoodDialog::OnBnClickedOk()
{
    if (mPortie.GetSelectedPortie() == nullptr)
    {
        MessageBox(_T("Select a valid portion"), _T("Error"), MB_OK);
        return;
    }

    if (mVoedingsmiddel.GetLot().GetPortie().GetName() == mPortie.GetSelectedPortie()->GetName())
    {
        mVoedingsmiddel.GetLot().SetNumberOfPortions(mAantalPorties.GetValue());
    }
    else
    {
        weight::LotFactory lotFactory(m_calculator);
        auto lot = lotFactory.Create(m_parameters, *mPortie.GetSelectedPortie());
        if (lot != nullptr)
        {
            lot->SetNumberOfPortions(mAantalPorties.GetValue());
            mVoedingsmiddel.SetLot(std::move(lot));
        }
    }

    OnOK();
}


//void EditFoodDialog::EditState::UpdatePortionValues(const weight::Lot& aLot)
//{
//    GetAantalEenheden().SetValue(aLot.GetPortie().GetUnits() * aLot.GetNumberOfPortions());
//    GetAantalPorties().SetValue(aLot.GetNumberOfPortions());
//    std::tstring name(aLot.GetPortie().GetName());
//    int index = GetPortieBox().FindStringExact(0, name.c_str());
//    GetPortieBox().SetCurSel(index);
//    GetPunten().SetValue(aLot.GetPoints());
//}
//
//
//void EditNoPortionsState::Initialize()
//{
//    GetAantalEenheden().SetReadOnly(true);
//    GetAantalPorties().SetReadOnly(true);
//    GetPortieBox().EnableWindow(false);
//}
//
//
//void EditStandardPortionsState::Initialize()
//{
//    GetAantalEenheden().SetReadOnly(false);
//    GetAantalPorties().SetReadOnly(false);
//    GetPortieBox().EnableWindow(true);
//    GetPortieBox().Fill(GetDefinitie().GetPortieList());
//
//    UpdatePortionValues(GetVoedingsMiddel().GetLot());
//}
