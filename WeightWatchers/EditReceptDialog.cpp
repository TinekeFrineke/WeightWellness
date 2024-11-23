// EditReceptDialog.cpp : implementation file
//

#include "stdafx.h"
#include "WeightWatchers.h"
#include ".\editreceptdialog.h"

#include "model/Recept.h"

// EditReceptDialog dialog

IMPLEMENT_DYNAMIC(EditReceptDialog, CDialog)
EditReceptDialog::EditReceptDialog(WW::Model & aModel, WW::Recept & aRecept, CWnd* pParent /*=NULL*/)
: CDialog (EditReceptDialog::IDD, pParent),
  mModel  (aModel),
  mRecept (aRecept)
{
}

EditReceptDialog::~EditReceptDialog()
{
}

void EditReceptDialog::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  DDX_Control(pDX, IDC_NAAM, mName);
  DDX_Control(pDX, IDC_PORTIES, mPorties);
  DDX_Control(pDX, IDC_POINTS, mPunten);
}


BEGIN_MESSAGE_MAP(EditReceptDialog, CDialog)
  ON_EN_CHANGE(IDC_PORTIES, OnEnChangePorties)
  ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


BOOL EditReceptDialog::OnInitDialog()
{
  if (CDialog::OnInitDialog() == FALSE)
    return FALSE;

  mName.SetValue(mRecept.GetName());
  mPorties.SetValue(mRecept.GetNumberOfPortions());
  mPunten.SetValue(mRecept.GetPointsPerPortion() * mRecept.GetNumberOfPortions());

  return TRUE;
}


// EditReceptDialog message handlers

void EditReceptDialog::OnEnChangePorties()
{
  mPunten.SetValue(mRecept.GetPointsPerPortion() * mPorties.GetValue());
}

void EditReceptDialog::OnBnClickedOk()
{
  mRecept.SetNumberOfPortions(mPorties.GetValue());
  OnOK();
}
