// EditVoedingsmiddelDialog.cpp : implementation file
//

#include "stdafx.h"
#include "WeightWatchers.h"
#include ".\editvoedingsmiddeldialog.h"

#include <assert.h>

#include "WW/WWmodel/Voedingsmiddel.h"
#include "WW/WWmodel/VoedingsmiddelDefinitie.h"
#include "WW/WWmodel/WWModel.h"
#include "WW/WWmodel/XmlVMCreateVisitor.h"

// EditVoedingsmiddelDialog dialog

IMPLEMENT_DYNAMIC(EditVoedingsmiddelDialog, CDialog)
EditVoedingsmiddelDialog::EditVoedingsmiddelDialog(WW::Model &          aModel,
                                                   WW::Voedingsmiddel & aVoedingsmiddel,
                                                   WW::VMDefinitie &    aDefinitie,
                                                   CWnd *               aParent)
: CDialog           (EditVoedingsmiddelDialog::IDD, aParent),
  mModel            (aModel),
  mVoedingsmiddel   (aVoedingsmiddel),
  mVoedingsmiddelDef(aDefinitie),
  mPortie           (aModel, _T("")),
  mState            (NULL),
  mUpdating         (false)
{
}

EditVoedingsmiddelDialog::~EditVoedingsmiddelDialog()
{
  if (mState != NULL)
    delete mState;
}

void EditVoedingsmiddelDialog::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  DDX_Control(pDX, IDC_AANTAL_PORTIES, mAantalPorties);
  DDX_Control(pDX, IDC_AANTAL_UNITS, mAantalEenheden);
  DDX_Control(pDX, IDC_PORTIENAAM, mPortie);
  DDX_Control(pDX, IDC_PUNTEN, mPunten);
  DDX_Control(pDX, IDC_VOEDINGSMIDDELNAAM, mNaam);
  DDX_Control(pDX, IDC_VRIJEPORTIE_CHECK, mVrijePortieCheck);
  DDX_Control(pDX, IDC_STERREPORTIECHECK, mSterreportieCheck);
}


BEGIN_MESSAGE_MAP(EditVoedingsmiddelDialog, CDialog)
  ON_EN_CHANGE(IDC_AANTAL_PORTIES, OnEnChangeAantalPorties)
  ON_EN_CHANGE(IDC_AANTAL_UNITS, OnEnChangeAantalUnits)
  ON_CBN_SELCHANGE(IDC_PORTIENAAM, OnCbnSelchangePortienaam)
  ON_BN_CLICKED(IDC_VRIJEPORTIE_CHECK, OnBnClickedVrijeportieCheck)
  ON_BN_CLICKED(IDOK, OnBnClickedOk)
//  ON_BN_CLICKED(IDC_STERREPORTIECHECK, OnBnClickedSterreportiecheck)
END_MESSAGE_MAP()

BOOL EditVoedingsmiddelDialog::OnInitDialog()
{
  if (CDialog::OnInitDialog() == FALSE)
    return FALSE;

  // Allow for editing of the lot
  SetState(CreateState());

  mNaam.SetValue(mVoedingsmiddel.GetName());
  mPortie.Initialize();
  WW::PortionedLot * dlot = mVoedingsmiddel.GetLot().GetPortionedLot();
  if (dlot != NULL)
    mPortie.Fill(mVoedingsmiddelDef.GetPortieList(), dlot->GetPortie().GetName().Get());
  else
    mPortie.Fill(mVoedingsmiddelDef.GetPortieList());

  mSterreportieCheck.ShowWindow(mVoedingsmiddelDef.HasSterrePortion() ? SW_SHOW : SW_HIDE);
  mSterreportieCheck.EnableWindow(false);
  WW::Portie * portie = mPortie.GetSelectedPortie();
  (void)portie;
  mSterreportieCheck.SetCheck(mVoedingsmiddelDef.HasSterrePortion() &&
                              mPortie.GetSelectedPortie() == mVoedingsmiddelDef.GetSterrePortion());

  return TRUE;
}


void EditVoedingsmiddelDialog::SetState(EditState * aState)
{
  mUpdating = true;

  if (mState == NULL)
    delete mState;

  mState = aState;
  if (mState)
    mState->Initialize();

  mUpdating = false;
}


EditVoedingsmiddelDialog::EditState * EditVoedingsmiddelDialog::CreateState()
{
  if (mVoedingsmiddelDef.HasFreePortion(mModel.GetStrategy()))
  {
    if (mVoedingsmiddelDef.GetPortieList().empty())
      return new EditFreePortionState(*this, mVoedingsmiddelDef, mVoedingsmiddel, mModel);
    else
      return new EditBothState(*this, mVoedingsmiddelDef, mVoedingsmiddel, mModel);
  }
  else // No free portion
  {
    if (mVoedingsmiddelDef.GetPortieList().empty())
      return new EditNoPortionsState(*this, mVoedingsmiddelDef, mVoedingsmiddel, mModel);
    else
      return new EditStandardPortionsState(*this, mVoedingsmiddelDef, mVoedingsmiddel, mModel);
  }
}

// EditVoedingsmiddelDialog message handlers

void EditVoedingsmiddelDialog::OnEnChangeAantalPorties()
{
  if (!mUpdating)
  {
    mUpdating = true;
    if (mPortie.GetSelectedPortie() != NULL)
    {
      WW::Portie * portie = mPortie.GetSelectedPortie();
      mAantalEenheden.SetValue(mAantalPorties.GetValue() * portie->GetUnits());

      if (mVoedingsmiddelDef.IsSterrePortion(portie))
        mPunten.SetValue(0);
      else
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
    if (mPortie.GetSelectedPortie() != NULL)
    {
      mAantalPorties.SetValue(mAantalEenheden.GetValue() / mPortie.GetSelectedPortie()->GetUnits());
      if (mVoedingsmiddelDef.IsSterrePortion(mPortie.GetSelectedPortie()))
        mPunten.SetValue(0);
      else
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
    WW::Portie * portie = mPortie.GetSelectedPortie();
    if (portie != NULL)
    {
      mAantalEenheden.SetValue(portie->GetUnits() * mAantalPorties.GetValue());
      if (mVoedingsmiddelDef.IsSterrePortion(mPortie.GetSelectedPortie()))
        mPunten.SetValue(0);
      else
        mPunten.SetValue((mAantalEenheden.GetValue()
                        * mVoedingsmiddelDef.GetPointsPer100Units()) / 100);
    }
    mUpdating = false;
  }
}


void EditVoedingsmiddelDialog::OnBnClickedVrijeportieCheck()
{
  if (mState)
    mState->OnCheckFreePortion();
}


void EditVoedingsmiddelDialog::OnBnClickedOk()
{
  if (mVrijePortieCheck.GetCheck())
  {
    if (mVoedingsmiddel.GetLot().GetFreeLot() == NULL)
      mVoedingsmiddel.SetLot(new WW::FreeLot(mModel.GetStrategy(),
                                             mVoedingsmiddelDef.GetFreePortionPoints(mModel.GetStrategy())));
  }
  else
  {
    if (mPortie.GetSelectedPortie() == NULL)
    {
      MessageBox(_T("Select a valid portion"), _T("Error"), MB_OK);
      return;
    }

    if (mVoedingsmiddel.GetLot().GetPortionedLot() != NULL &&
        mVoedingsmiddel.GetLot().GetPortionedLot()->GetPortie().GetName() == mPortie.GetSelectedPortie()->GetName())
    {
      mVoedingsmiddel.GetLot().GetPortionedLot()->SetNumberOfPortions(mAantalPorties.GetValue());
    }
    else
    {
      WW_NAMESPACE::CreateLotFromVMDef creator(mModel.GetCalculator());
      WW::PortionedLot * lot = creator.Create(mVoedingsmiddelDef, *mPortie.GetSelectedPortie());
      if (lot != NULL)
      {
        lot->SetNumberOfPortions(mAantalPorties.GetValue());
        mVoedingsmiddel.SetLot(lot);
      }
    }
  }

  OnOK();
}


void EditVoedingsmiddelDialog::EditState::UpdateFreeStateValues()
{
  GetPunten().SetValue(mDefinitie.GetFreePortionPoints(mModel.GetStrategy()));
}


void EditVoedingsmiddelDialog::EditState::UpdatePortionValues(const WW::PortionedLot & aLot)
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

  GetVrijePortieCheck().EnableWindow(false);
  GetVrijePortieCheck().SetCheck(false);
}


void EditNoPortionsState::OnCheckFreePortion()
{
  assert(false);
}


void EditFreePortionState::Initialize()
{
  GetAantalEenheden().SetReadOnly(true);
  GetAantalPorties().SetReadOnly(true);
  GetPortieBox().EnableWindow(false);

  GetVrijePortieCheck().EnableWindow(true);
  GetVrijePortieCheck().SetCheck(true);

  UpdateFreeStateValues();
}


void EditFreePortionState::OnCheckFreePortion()
{
  GetVrijePortieCheck().SetCheck(true);
}


void EditStandardPortionsState::Initialize()
{
  GetAantalEenheden().SetReadOnly(false);
  GetAantalPorties().SetReadOnly(false);
  GetPortieBox().EnableWindow(true);
  GetPortieBox().Fill(GetDefinitie().GetPortieList());

  if (GetVoedingsMiddel().GetLot().GetPortionedLot() != NULL)
    UpdatePortionValues(*GetVoedingsMiddel().GetLot().GetPortionedLot());

  GetVrijePortieCheck().EnableWindow(false);
  GetVrijePortieCheck().SetCheck(false);
}


void EditStandardPortionsState::OnCheckFreePortion()
{
  assert(false);
}


void EditBothState::Initialize()
{
  GetVrijePortieCheck().EnableWindow(true);

  if (GetVoedingsMiddel().GetLot().GetPortionedLot() == NULL)
  {
    GetAantalEenheden().SetReadOnly(true);
    GetAantalPorties().SetReadOnly(true);
    GetPortieBox().EnableWindow(true);
    GetVrijePortieCheck().SetCheck(true);
    UpdateFreeStateValues();
  }
  else
  {
    GetAantalEenheden().SetReadOnly(false);
    GetAantalPorties().SetReadOnly(false);
    GetPortieBox().EnableWindow(false);
    UpdatePortionValues(*GetVoedingsMiddel().GetLot().GetPortionedLot());
  }
}


void EditBothState::OnCheckFreePortion()
{
  if (GetVrijePortieCheck().GetCheck())
  {
    GetAantalEenheden().SetReadOnly(true);
    GetAantalPorties().SetReadOnly(true);
    GetPortieBox().EnableWindow(false);

    UpdateFreeStateValues();
  }
  else
  {
    GetAantalEenheden().SetReadOnly(false);
    GetAantalPorties().SetReadOnly(false);
    GetPortieBox().EnableWindow(true);

    assert(GetPortieBox().GetSelectedPortie() != NULL);
//    UpdatePortionValues(*GetPortieBox().GetSelectedPortie());
  }
}
