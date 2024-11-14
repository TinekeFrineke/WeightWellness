// FindVoedingsmiddel.cpp : implementation file
//

#include "stdafx.h"
#include ".\findvoedingsmiddel.h"

#include <assert.h>
#include "WeightWatchers.h"
#include "WW/WWModel/Day.h"
#include "WW/WWModel/Portie.h"
#include "WW/WWModel/Voedingsmiddel.h"
#include "WW/WWModel/VoedingsmiddelDefinitie.h"
#include "WW/WWModel/XmlVMCreateVisitor.h"

// CFindVoedingsmiddel dialog

IMPLEMENT_DYNAMIC(CFindVoedingsmiddel, CDialog)
CFindVoedingsmiddel::CFindVoedingsmiddel(WW::Model &                    aModel,
                                         WW::VMDefinitie *  aDefinitie,
                                         CWnd *                         pParent /*=NULL*/)
: CDialog         (CFindVoedingsmiddel::IDD, pParent),
  mItemList       (aModel),
  mCategorieBox   (aModel),
  mMerkBox        (aModel, true),
  mModel          (aModel),
  mFood           (NULL),
  mState          (NULL),
  mDefinitie      (aDefinitie),
  mPortieNaam     (mModel, _T("")),
  mUpdating       (false),
  mUpdatingFilter (false)
{
}

CFindVoedingsmiddel::~CFindVoedingsmiddel()
{
  delete mState;
}

void CFindVoedingsmiddel::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  DDX_Control(pDX, IDC_COMBO1, mCategorieBox);
  DDX_Control(pDX, IDC_NAAM, mNaam);
  DDX_Control(pDX, IDC_ITEMLIST, mItemList);
  DDX_Control(pDX, IDC_PORTIES, mPorties);
  DDX_Control(pDX, IDC_UNITS, mUnits);
  DDX_Control(pDX, IDC_PORTIENAAM, mPortieNaam);
  DDX_Control(pDX, IDC_UNIT, mUnitNaam);
  DDX_Control(pDX, IDC_POINTS, mPoints);
  DDX_Control(pDX, IDC_VRIJEPORTIE_CHECK, mVrijePortieCheck);
  DDX_Control(pDX, IDC_BRAND, mMerkBox);
}


BEGIN_MESSAGE_MAP(CFindVoedingsmiddel, CDialog)
  ON_BN_CLICKED(IDOK, OnBnClickedOk)
  ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
  ON_EN_CHANGE(IDC_NAAM, OnEnChangeNaam)
  ON_CBN_SELCHANGE(IDC_COMBO1, OnCbnSelchangeCombo1)
  ON_NOTIFY(LVN_ITEMCHANGED, IDC_ITEMLIST, OnLvnItemchangedItemlist)
  ON_CBN_SELCHANGE(IDC_PORTIENAAM, OnCbnSelchangePortienaam)
  ON_EN_CHANGE(IDC_PORTIES, OnEnChangePorties)
  ON_EN_CHANGE(IDC_UNITS, OnEnChangeUnits)
  ON_NOTIFY(NM_DBLCLK, IDC_ITEMLIST, OnNMDblclkItemlist)
  ON_BN_CLICKED(IDC_VRIJEPORTIE_CHECK, OnBnClickedVrijeportieCheck)
  ON_CBN_SELCHANGE(IDC_BRAND, OnCbnSelchangeBrand)
  ON_BN_CLICKED(IDC_CHECK_FAVOURITES, OnBnClickedCheckFavourites)
END_MESSAGE_MAP()


void CFindVoedingsmiddel::UpdateItemFilter()
{
  mItemList.SetFilter(VMDefinitiesFilter(mNaam.GetValue(),
                                         mCategorieBox.GetString(),
                                         mMerkBox.GetString()));
  mItemList.Fill();
}


// CFindVoedingsmiddel message handlers

BOOL CFindVoedingsmiddel::OnInitDialog()
{
  if (CDialog::OnInitDialog() == FALSE)
    return FALSE;

  mVrijePortieCheck.EnableWindow(false);

  mItemList.Initialize();
  mItemList.Fill();

  mPortieNaam.Initialize();

  mCategorieBox.Initialize();
  mCategorieBox.Fill();
  mCategorieBox.SetString(_T(""));

  mMerkBox.Initialize();
  mMerkBox.Fill();
  mMerkBox.SetString(_T(""));

  return TRUE;
}


void CFindVoedingsmiddel::OnBnClickedOk()
{
  if (mVrijePortieCheck.GetCheck())
  {
    mFood = new WW::Voedingsmiddel(new WW::FreeLot(mModel.GetStrategy(), mDefinitie->GetFreePortionPoints(mModel.GetStrategy())), *mDefinitie);
  }
  else
  {
    WW::Portie * portie = mPortieNaam.GetSelectedPortie();
    if (portie == NULL)
    {
      ::MessageBox(m_hWnd, _T("Pick a valid portion"), _T("ERROR"), MB_OK);
      return;
    }

    WW_NAMESPACE::CreateLotFromVMDef creator(mModel.GetCalculator());
    WW::PortionedLot * lot = creator.Create(*mDefinitie, *portie);
    assert(lot != NULL);
    lot->SetNumberOfPortions(mPorties.GetValue());
    mFood = new WW::Voedingsmiddel(lot, *mDefinitie);
  }

  OnOK();
}

void CFindVoedingsmiddel::OnBnClickedCancel()
{
  OnCancel();
}

void CFindVoedingsmiddel::OnEnChangeNaam()
{
  if (!mUpdatingFilter)
    UpdateItemFilter();
}

void CFindVoedingsmiddel::OnCbnSelchangeCombo1()
{
  if (!mUpdatingFilter)
    UpdateItemFilter();
}

void CFindVoedingsmiddel::OnLvnItemchangedItemlist(NMHDR *pNMHDR, LRESULT *pResult)
{
  (void)pNMHDR;
  *pResult = 0;

  VMDefinitiesListItem * lvitem = mItemList.GetSelectedItem();
  if (lvitem == NULL)
    return;

  mUpdatingFilter = true;

  mDefinitie = lvitem->GetItem();
  assert(mDefinitie != NULL);
  mUnitNaam.SetValue(mDefinitie->GetUnit().GetName());

  SetState(CreateState(*mDefinitie));

  mUpdatingFilter = false;
}

void CFindVoedingsmiddel::OnCbnSelchangePortienaam()
{
  WW::Portie * portie = mPortieNaam.GetSelectedPortie();
  if (portie != NULL)
  {
    mUnits.SetValue(portie->GetUnits());
    mPorties.SetValue(1);

      if (mDefinitie != NULL)
      {
        if (mDefinitie->IsSterrePortion(portie))
          mPoints.SetValue(0);
        else
          mPoints.SetValue((mUnits.GetValue() * mDefinitie->GetPointsPer100Units()) / 100);
      }
  }
}

void CFindVoedingsmiddel::OnEnChangePorties()
{
  if (!mUpdating)
  {
    mUpdating = true;

    WW::Portie * portie = mPortieNaam.GetSelectedPortie();
    if (portie != NULL)
    {
      mUnits.SetValue(mPorties.GetValue() * portie->GetUnits());

      if (mDefinitie != NULL)
      {
        if (mDefinitie->IsSterrePortion(portie))
          mPoints.SetValue(0);
        else
          mPoints.SetValue((mUnits.GetValue() * mDefinitie->GetPointsPer100Units()) / 100);
      }
    }

    mUpdating = false;
  }
}

void CFindVoedingsmiddel::OnEnChangeUnits()
{
  if (!mUpdating)
  {
    mUpdating = true;
    WW::Portie * portie = mPortieNaam.GetSelectedPortie();
    if (portie != NULL)
    {
      mPorties.SetValue(mUnits.GetValue() / portie->GetUnits());

      if (mDefinitie != NULL)
      {
        if (mDefinitie->IsSterrePortion(portie))
          mPoints.SetValue(0);
        else
          mPoints.SetValue((mUnits.GetValue() * mDefinitie->GetPointsPer100Units()) / 100);
      }
    }

    mUpdating = false;
  }
}


void CFindVoedingsmiddel::OnNMDblclkItemlist(NMHDR *pNMHDR, LRESULT *pResult)
{
  (void)pNMHDR;

  if (mVrijePortieCheck.GetCheck())
  {
    mFood = new WW::Voedingsmiddel(new WW::FreeLot(mModel.GetStrategy(), mDefinitie->GetFreePortionPoints(mModel.GetStrategy())), *mDefinitie);
  }
  else
  {
    WW::Portie * portie = mPortieNaam.GetSelectedPortie();
    if (portie == NULL)
    {
      ::MessageBox(m_hWnd, _T("Pick a valid portion"), _T("ERROR"), MB_OK);
      return;
    }

    WW_NAMESPACE::CreateLotFromVMDef creator(mModel.GetCalculator());
    WW::PortionedLot * lot = creator.Create(*mDefinitie, *portie);
    lot->SetNumberOfPortions(mPorties.GetValue());
    mFood = new WW::Voedingsmiddel(lot, *mDefinitie);
  }

  OnOK();

  *pResult = 0;
}


void CFindVoedingsmiddel::OnBnClickedVrijeportieCheck()
{
  if (mState)
    mState->OnCheckFreePortion();
}


VMState * CFindVoedingsmiddel::CreateState(WW::VMDefinitie & aDefinitie)
{
  if (aDefinitie.HasFreePortion(mModel.GetStrategy()))
  {
    if (aDefinitie.GetPortieList().empty())
      return new VMFreePortionState(*this, aDefinitie, mModel);
    else
      return new VMBothState(*this, aDefinitie, mModel);
  }
  else // No free portion
  {
    if (aDefinitie.GetPortieList().empty())
      return new VMNoPortionsState(*this, aDefinitie, mModel);
    else
      return new VMStandardPortionsState(*this, aDefinitie, mModel);
  }
}


void CFindVoedingsmiddel::SetState(VMState * aState)
{
  if (mState != NULL)
    delete mState;

  mState = aState;
  if (mState != NULL)
    mState->Initialize();
}


void VMState::UpdateFreeStateValues()
{
  GetPoints().SetValue(mDefinitie.GetFreePortionPoints(mModel.GetStrategy()));
}


void VMState::UpdatePortionValues(const WW::Portie & aPortie)
{
  GetUnits().SetValue(aPortie.GetUnits());
  GetPorties().SetValue(1);
  GetPortieBox().SetString(aPortie.GetName().Get());
}


void VMNoPortionsState::Initialize()
{
  GetUnits().SetReadOnly(true);
  GetPorties().SetReadOnly(true);
  GetPortieBox().EnableWindow(false);

  GetVrijePortieCheck().EnableWindow(false);
  GetVrijePortieCheck().SetCheck(false);
}


void VMNoPortionsState::OnCheckFreePortion()
{
  assert(false);
}


void VMFreePortionState::Initialize()
{
  GetUnits().SetReadOnly(true);
  GetPorties().SetReadOnly(true);
  GetPortieBox().EnableWindow(false);

  GetVrijePortieCheck().EnableWindow(true);
  GetVrijePortieCheck().SetCheck(true);

  UpdateFreeStateValues();
}


void VMFreePortionState::OnCheckFreePortion()
{
  GetVrijePortieCheck().SetCheck(true);
}


void VMStandardPortionsState::Initialize()
{
  GetUnits().SetReadOnly(false);
  GetPorties().SetReadOnly(false);
  GetPortieBox().EnableWindow(true);
  GetPortieBox().Fill(GetDefinitie().GetPortieList());

  GetVrijePortieCheck().EnableWindow(false);
  GetVrijePortieCheck().SetCheck(false);

  UpdatePortionValues(*GetPortieBox().GetSelectedPortie());
}


void VMStandardPortionsState::OnCheckFreePortion()
{
  assert(false);
}


void VMBothState::Initialize()
{
  GetUnits().SetReadOnly(true);
  GetPorties().SetReadOnly(true);
  GetPortieBox().EnableWindow(false);
  GetPortieBox().Fill(GetDefinitie().GetPortieList());

  GetVrijePortieCheck().EnableWindow(true);
  GetVrijePortieCheck().SetCheck(true);

  UpdateFreeStateValues();
}


void VMBothState::OnCheckFreePortion()
{
  if (GetVrijePortieCheck().GetCheck())
  {
    GetUnits().SetReadOnly(true);
    GetPorties().SetReadOnly(true);
    GetPortieBox().EnableWindow(false);

    UpdateFreeStateValues();
  }
  else
  {
    GetUnits().SetReadOnly(false);
    GetPorties().SetReadOnly(false);
    GetPortieBox().EnableWindow(true);

    assert(GetPortieBox().GetSelectedPortie() != NULL);
    UpdatePortionValues(*GetPortieBox().GetSelectedPortie());
  }
}

void CFindVoedingsmiddel::OnCbnSelchangeBrand()
{
  if (!mUpdatingFilter)
    UpdateItemFilter();
}

void CFindVoedingsmiddel::OnBnClickedCheckFavourites()
{
  mItemList.SetFavouritesOnly(IsDlgButtonChecked(IDC_CHECK_FAVOURITES) != FALSE);
  mItemList.Fill();
}
