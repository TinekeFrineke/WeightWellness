// EditVoedingsmiddelDialog.cpp : implementation file
//

#include "stdafx.h"
#include "WeightWatchers.h"
#include ".\editvoedingsmiddeldialog.h"

#include <assert.h>

#include "model/Voedingsmiddel.h"
#include "model/VoedingsmiddelDefinitie.h"
#include "model/WWModel.h"
#include "model/LotFactory.h"

// EditVoedingsmiddelDialog dialog

IMPLEMENT_DYNAMIC(EditVoedingsmiddelDialog, CDialog)
EditVoedingsmiddelDialog::EditVoedingsmiddelDialog(WW::Model& aModel,
                                                   WW::Voedingsmiddel& aVoedingsmiddel,
                                                   WW::VMDefinitie& aDefinitie,
                                                   CWnd* aParent)
    : CDialog(EditVoedingsmiddelDialog::IDD, aParent),
    mModel(aModel),
    mVoedingsmiddel(aVoedingsmiddel),
    mVoedingsmiddelDef(aDefinitie),
    mPortie(aModel, _T("")),
    mState(nullptr),
    mUpdating(false)
{
}

EditVoedingsmiddelDialog::~EditVoedingsmiddelDialog() = default;

void EditVoedingsmiddelDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_AANTAL_PORTIES, mAantalPorties);
    DDX_Control(pDX, IDC_AANTAL_UNITS, mAantalEenheden);
    DDX_Control(pDX, IDC_PORTIENAAM, mPortie);
    DDX_Control(pDX, IDC_PUNTEN, mPunten);
    DDX_Control(pDX, IDC_VOEDINGSMIDDELNAAM, mNaam);
}


BEGIN_MESSAGE_MAP(EditVoedingsmiddelDialog, CDialog)
    ON_EN_CHANGE(IDC_AANTAL_PORTIES, OnEnChangeAantalPorties)
    ON_EN_CHANGE(IDC_AANTAL_UNITS, OnEnChangeAantalUnits)
    ON_CBN_SELCHANGE(IDC_PORTIENAAM, OnCbnSelchangePortienaam)
    ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()

BOOL EditVoedingsmiddelDialog::OnInitDialog()
{
    if (CDialog::OnInitDialog() == FALSE)
        return FALSE;

    // Allow for editing of the lot
    SetState(std::move(CreateState()));

    mNaam.SetValue(mVoedingsmiddel.GetName());
    mPortie.Initialize();
    WW::PortionedLot* dlot = mVoedingsmiddel.GetLot().GetPortionedLot();
    if (dlot != nullptr)
        mPortie.Fill(mVoedingsmiddelDef.GetPortieList(), dlot->GetPortie().GetName().Get());
    else
        mPortie.Fill(mVoedingsmiddelDef.GetPortieList());

    WW::Portie* portie = mPortie.GetSelectedPortie();
    (void)portie;

    return TRUE;
}


void EditVoedingsmiddelDialog::SetState(std::unique_ptr<EditState> aState)
{
    mUpdating = true;

    mState = std::move(aState);
    if (mState)
        mState->Initialize();

    mUpdating = false;
}


std::unique_ptr<EditVoedingsmiddelDialog::EditState> EditVoedingsmiddelDialog::CreateState()
{
    if (mVoedingsmiddelDef.GetPortieList().empty())
        return std::make_unique<EditNoPortionsState>(*this, mVoedingsmiddelDef, mVoedingsmiddel, mModel);
    else
        return std::make_unique<EditStandardPortionsState>(*this, mVoedingsmiddelDef, mVoedingsmiddel, mModel);
}

// EditVoedingsmiddelDialog message handlers

void EditVoedingsmiddelDialog::OnEnChangeAantalPorties()
{
    if (!mUpdating)
    {
        mUpdating = true;
        if (mPortie.GetSelectedPortie() != nullptr)
        {
            WW::Portie* portie = mPortie.GetSelectedPortie();
            mAantalEenheden.SetValue(mAantalPorties.GetValue() * portie->GetUnits());

            mPunten.SetValue((mAantalEenheden.GetValue()
                              * mVoedingsmiddelDef.GetPointsPer100Units()) / 100);
        }

        mUpdating = false;
    }
}

void EditVoedingsmiddelDialog::OnEnChangeAantalUnits()
{
    if (!mUpdating)
    {
        mUpdating = true;
        if (mPortie.GetSelectedPortie() != nullptr)
        {
            mAantalPorties.SetValue(mAantalEenheden.GetValue() / mPortie.GetSelectedPortie()->GetUnits());
            mPunten.SetValue((mAantalPorties.GetValue()
                                * mPortie.GetSelectedPortie()->GetUnits()
                                * mVoedingsmiddelDef.GetPointsPer100Units()) / 100);
        }

        mUpdating = false;
    }
}

void EditVoedingsmiddelDialog::OnCbnSelchangePortienaam()
{
    if (!mUpdating)
    {
        mUpdating = true;
        WW::Portie* portie = mPortie.GetSelectedPortie();
        if (portie != nullptr)
        {
            mAantalEenheden.SetValue(portie->GetUnits() * mAantalPorties.GetValue());
            mPunten.SetValue((mAantalEenheden.GetValue()
                                * mVoedingsmiddelDef.GetPointsPer100Units()) / 100);
        }
        mUpdating = false;
    }
}


void EditVoedingsmiddelDialog::OnBnClickedOk()
{
    if (mPortie.GetSelectedPortie() == nullptr)
    {
        MessageBox(_T("Select a valid portion"), _T("Error"), MB_OK);
        return;
    }

    if (mVoedingsmiddel.GetLot().GetPortionedLot() != nullptr &&
        mVoedingsmiddel.GetLot().GetPortionedLot()->GetPortie().GetName() == mPortie.GetSelectedPortie()->GetName())
    {
        mVoedingsmiddel.GetLot().GetPortionedLot()->SetNumberOfPortions(mAantalPorties.GetValue());
    }
    else
    {
        WW::LotFactory lotFactory(mModel.GetCalculator());
        auto lot = lotFactory.Create(mVoedingsmiddelDef, *mPortie.GetSelectedPortie());
        if (lot != nullptr)
        {
            lot->SetNumberOfPortions(mAantalPorties.GetValue());
            mVoedingsmiddel.SetLot(std::move(lot));
        }
    }

    OnOK();
}


void EditVoedingsmiddelDialog::EditState::UpdatePortionValues(const WW::PortionedLot& aLot)
{
    GetAantalEenheden().SetValue(aLot.GetPortie().GetUnits() * aLot.GetNumberOfPortions());
    GetAantalPorties().SetValue(aLot.GetNumberOfPortions());
    std::tstring name(aLot.GetPortie().GetName().Get());
    int index = GetPortieBox().FindStringExact(0, name.c_str());
    GetPortieBox().SetCurSel(index);
    GetPunten().SetValue(aLot.GetPoints());
}


void EditNoPortionsState::Initialize()
{
    GetAantalEenheden().SetReadOnly(true);
    GetAantalPorties().SetReadOnly(true);
    GetPortieBox().EnableWindow(false);
}


void EditStandardPortionsState::Initialize()
{
    GetAantalEenheden().SetReadOnly(false);
    GetAantalPorties().SetReadOnly(false);
    GetPortieBox().EnableWindow(true);
    GetPortieBox().Fill(GetDefinitie().GetPortieList());

    if (GetVoedingsMiddel().GetLot().GetPortionedLot() != nullptr)
        UpdatePortionValues(*GetVoedingsMiddel().GetLot().GetPortionedLot());
}
