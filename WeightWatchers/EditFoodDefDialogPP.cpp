// EditFoodDefDialogPP.cpp : implementation file
//

#include "stdafx.h"
#include "WeightWatchers.h"
#include "EditFoodDefDialogPP.h"
#include ".\editfooddefdialogpp.h"
#include "WW/WWModel/VoedingsmiddelDefinitie.h"


// CEditFoodDefDialogPP dialog

IMPLEMENT_DYNAMIC(CEditFoodDefDialogPP, CDialog)
CEditFoodDefDialogPP::CEditFoodDefDialogPP(WW::Model & aModel,
                                           WW::VoedingsmiddelDefinitie * aDefinitie,
                                           CWnd* pParent/* = NULL*/)
: CDialog         (CEditFoodDefDialogPP::IDD, pParent),
  mDefinitie      (aDefinitie),
  mModel          (aModel),
  mPortieListView (aModel, aDefinitie),
  mSterrePortieBox(aModel, _T("")),
  mUnitBox        (aModel, (aDefinitie ? aDefinitie->GetUnit().GetName() : _T(""))),
  mCategorie      (aModel, (aDefinitie ? aDefinitie->GetCategory().Get() : _T("")))
{
}

CEditFoodDefDialogPP::~CEditFoodDefDialogPP()
{
}

void CEditFoodDefDialogPP::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  DDX_Control(pDX, IDC_NAAM, mName);
  DDX_Control(pDX, IDC_CATEGORIE, mCategorie);
  DDX_Control(pDX, IDC_UNIT, mUnitBox);
  DDX_Control(pDX, IDC_EIWITTEN_PER_100, mEiwitPer100Edit);
  DDX_Control(pDX, IDC_KOOLHYDRATEN_PER_100, mKoolhydratenPer100);
  DDX_Control(pDX, IDC_VETPER100, mVetPer100);
  DDX_Control(pDX, IDC_VEZELS_PER_100, mVezelsPer100);
  DDX_Control(pDX, IDC_PORTIE, mPortieListView);
  DDX_Control(pDX, IDC_VRIJEPORTIECHECK, mVrijePortieCheck);
  DDX_Control(pDX, IDC_PUNTEN_STATIC, mVrijePuntenStatic);
  DDX_Control(pDX, IDC_PUNTEN, mVrijePunten);
  DDX_Control(pDX, IDC_STERREPORTIE, mSterrePortieBox);
}


BEGIN_MESSAGE_MAP(CEditFoodDefDialogPP, CDialog)
  ON_BN_CLICKED(IDC_ADD, OnBnClickedAdd)
  ON_BN_CLICKED(IDC_EDIT, OnBnClickedEdit)
  ON_BN_CLICKED(IDC_DELETE, OnBnClickedDelete)
  ON_BN_CLICKED(IDOK, OnBnClickedOk)
  ON_BN_CLICKED(IDC_VRIJEPORTIECHECK, OnBnClickedVrijeportiecheck)
  ON_EN_CHANGE(IDC_EIWITTEN_PER_100, OnEnChangeEiwittenPer100)
  ON_EN_CHANGE(IDC_KOOLHYDRATEN_PER_100, OnEnChangeKoolhydratenPer100)
  ON_EN_CHANGE(IDC_VETPER100, OnEnChangeVetper100)
  ON_EN_CHANGE(IDC_VEZELS_PER_100, OnEnChangeVezelsPer100)
END_MESSAGE_MAP()


BOOL CEditFoodDefDialogPP::OnInitDialog()
{
  if (CDialog::OnInitDialog() == FALSE)
    return FALSE;

  mName.SetReadOnly(mDefinitie != NULL);

  if (mDefinitie == NULL)
  {
    mEiwitPer100Edit.SetValue(0);
    mKoolhydratenPer100.SetValue(0);
    mVetPer100.SetValue(0);
    mVezelsPer100.SetValue(0);
    mVrijePortieCheck.SetCheck(FALSE);
    mVrijePunten.SetValue(0);
  }
  else
  {
    mName.SetValue(mDefinitie->GetName());
    mEiwitPer100Edit.SetValue(mDefinitie->GetEiwitPer100Units());
    mKoolhydratenPer100.SetValue(mDefinitie->GetKoolhydratenPer100Units());
    mVetPer100.SetValue(mDefinitie->GetVetPer100Units());
    mVezelsPer100.SetValue(mDefinitie->GetVezelsPer100Units());
    mVrijePortieCheck.SetCheck(mDefinitie->HasFreePortion());
    if (mDefinitie->HasFreePortion())
    {
      mVrijePuntenStatic.EnableWindow(TRUE);
      mVrijePunten.SetReadOnly(FALSE);
      mVrijePunten.SetValue(mDefinitie->GetFreePortionPoints());
    }
    else
    {
      mVrijePuntenStatic.EnableWindow(FALSE);
      mVrijePunten.SetReadOnly(TRUE);
      mVrijePunten.SetValue(0);
    }
  }

  mPortieListView.Initialize();
  mSterrePortieBox.Initialize();
  mUnitBox.Initialize();
  mCategorie.Initialize();

  mPortieListView.Fill();
  if (mDefinitie != NULL)
  {
    if (mDefinitie->HasSterrePortion())
    {
      mSterrePortieBox.Fill(mDefinitie->GetPortieList(), mDefinitie->GetSterrePortion()->GetName().Get());
    }
    else
    {
      mSterrePortieBox.Fill(mDefinitie->GetPortieList(), _T(""));
      mSterrePortieBox.SetString(_T(""));
    }
  }

  mUnitBox.Fill();
  mCategorie.Fill();

  return TRUE;
}

// CEditFoodDefDialogPP message handlers

void CEditFoodDefDialogPP::OnBnClickedAdd()
{
  if (mDefinitie == NULL && !CreateFood())
    return;

  std::tstring portie = mSterrePortieBox.GetString();

  CEditPortieDialog dialog(mModel, *mDefinitie, NULL, this);
  INT_PTR nResponse = dialog.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
    if (dialog.GetPortie() != NULL) {
      mDefinitie->AddPortie(dialog.GetPortie());
      mPortieListView.Fill();
    }
	}
  else
  {
    WW::Portie * portie = dialog.GetPortie();
    if (portie != NULL)
      delete portie;
  }

  UpdateSterrePortieBox();
}

void CEditFoodDefDialogPP::OnBnClickedEdit()
{
  // TODO: Add your control notification handler code here
  PortieListItem * item = mPortieListView.GetSelectedItem();
  if (item != NULL &&  mDefinitie != NULL)
  {
    CEditPortieDialog dialog(mModel, *mDefinitie, item->GetPortie(), this);
    INT_PTR nResponse = dialog.DoModal();
	  if (nResponse == IDOK)
	  {
      mPortieListView.Update(item);
	  }
  }
}

void CEditFoodDefDialogPP::UpdateSterrePortieBox()
{
  std::tstring name = mSterrePortieBox.GetString();
  mSterrePortieBox.Fill(mDefinitie->GetPortieList(), name);
  mSterrePortieBox.SetString(name);
}


bool CEditFoodDefDialogPP::CreateFood()
{
  if (mDefinitie != NULL)
    return false;

  std::tstring name = mName.GetValue();
  if (name.empty())
    return false;

  for (size_t i = 0; i < mModel.GetVoedingsmiddelDefinities().size(); ++i)
    if (mModel.GetVoedingsmiddelDefinities()[i]->GetName() == name)
      return false;

  if (mUnitBox.GetString().empty())
    return false;

  mDefinitie = new WW::VoedingsmiddelDefinitie(name, WW::Unit(mModel, mUnitBox.GetString()));
  mModel.Add(mDefinitie);

  //mDefinitie->SetKCalPer100Units(mKCalPer100.GetValue());
  mDefinitie->SetVetPer100Units (mVetPer100.GetValue());
  mDefinitie->SetKoolhydratenPer100Units(Str::ToDouble(vmlist[i]->Getkoolhydratenper100().c_str()));
  mDefinitie->SetEiwitPer100Units(Str::ToDouble(vmlist[i]->Geteiwitper100().c_str()));
  mDefinitie->SetVezelsPer100Units(Str::ToDouble(vmlist[i]->Getvezelsper100().c_str()));

  if (mSterrePortieBox.GetSelectedPortie() != NULL)
    mDefinitie->SetSterrePortie(mSterrePortieBox.GetSelectedPortie()->GetName());

  mPortieListView.SetDefinition(mDefinitie);

  return true;
}


void CEditFoodDefDialogPP::OnBnClickedDelete()
{
  // TODO: Add your control notification handler code here
  PortieListItem * item = mPortieListView.GetSelectedItem();
  if (item != NULL &&  mDefinitie != NULL)
  {
    if (mDefinitie->RemovePortie(item->GetPortie()))
    {
      mPortieListView.Fill();
      UpdateSterrePortieBox();
    }
  }
}

void CEditFoodDefDialogPP::OnBnClickedOk()
{
  std::tstring name = mName.GetValue();

  if (mDefinitie == NULL)
  {
    if (!CreateFood())
      return;
  }

  mDefinitie->SetUnit(WW::Unit(mModel, mUnitBox.GetString()));
  mDefinitie->SetCategory(WW::CategorieNaam(mModel, mCategorie.GetString()));
  mDefinitie->SetKCalPer100Units(mKCalPer100.GetValue());
  mDefinitie->SetVetPer100Units(mVetPer100.GetValue());
  mDefinitie->SetHasFreePortion(mVrijePortieCheck.GetCheck() == BST_CHECKED);
  if (mDefinitie->HasFreePortion())
    mDefinitie->SetFreePortionPoints(mVrijePunten.GetValue());

  if (mSterrePortieBox.GetString().empty())
  {
    if (mDefinitie->HasSterrePortion())
      mDefinitie->RemoveAsSterrePortie(mDefinitie->GetSterrePortion()->GetName());
  }
  else
  {
    mDefinitie->SetSterrePortie(WW::PortieNaam(mModel, mSterrePortieBox.GetString()));
  }

  OnOK();
}

void CEditFoodDefDialogPP::OnBnClickedVrijeportiecheck()
{
  switch (mVrijePortieCheck.GetCheck())
  {
    case BST_CHECKED:
      mVrijePuntenStatic.EnableWindow(TRUE);
      mVrijePunten.SetReadOnly(FALSE);
      break;

    case BST_UNCHECKED:
    case BST_INDETERMINATE:
    default:
      mVrijePuntenStatic.EnableWindow(FALSE);
      mVrijePunten.SetReadOnly(TRUE);
      break;
  }
}

void CEditFoodDefDialogPP::OnEnChangeEiwittenPer100()
{
  if (mDefinitie)
    mDefinitie->SetEiwit100Units(mEiwitPer100Edit.GetValue());
}

void CEditFoodDefDialogPP::OnEnChangeKoolhydratenPer100()
{
  if (mDefinitie)
    mDefinitie->SetKoolhydratenPer100Units(mKoolhydratenPer100.GetValue());
}

void CEditFoodDefDialogPP::OnEnChangeVetper100()
{
  if (mDefinitie)
    mDefinitie->SetVetPer100Units(mVetPer100.GetValue());
}

void CEditFoodDefDialogPP::OnEnChangeVezelsPer100()
{
  if (mDefinitie)
    mDefinitie->SetVezelsPer100Units(mVezelsPer100.GetValue());
}
