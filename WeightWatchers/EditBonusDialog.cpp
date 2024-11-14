// EditBonusDialog.cpp : implementation file
//

#include "stdafx.h"
#include "WeightWatchers.h"
#include "EditBonusDialog.h"
#include ".\editbonusdialog.h"


// EditBonusDialog dialog

IMPLEMENT_DYNAMIC(EditBonusDialog, CDialog)
EditBonusDialog::EditBonusDialog(const WW::BonusPointsMap & aMap, double aWeight, CWnd* pParent /*=NULL*/)
: CDialog(EditBonusDialog::IDD, pParent),
  mBonus    (WW::Bonus::INTENSITY::Low, static_cast<int>(aWeight), 0, aMap),
  mBonusMap (aMap),
  mWeight   (aWeight)
{
}


EditBonusDialog::EditBonusDialog(const WW::BonusPointsMap & aMap, double aWeight, const WW::Bonus & aBonus, CWnd* pParent)
: CDialog(EditBonusDialog::IDD, pParent),
  mBonus    (aBonus),
  mBonusMap (aMap),
  mWeight   (aWeight)
{
}

EditBonusDialog::~EditBonusDialog()
{
}

void EditBonusDialog::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  DDX_Control(pDX, IDC_GEWICHT, mWeightEdit);
  DDX_Control(pDX, IDC_DUUR, mDurationEdit);
  DDX_Control(pDX, IDC_PUNTEN, mPointsEdit);
}


BEGIN_MESSAGE_MAP(EditBonusDialog, CDialog)
  ON_BN_CLICKED(IDC_RADIO_LOW, OnBnClickedRadioLow)
  ON_BN_CLICKED(IDC_RADIO_MEDIUM, OnBnClickedRadioMedium)
  ON_BN_CLICKED(IDC_RADIO_HIGH, OnBnClickedRadioHigh)
  ON_EN_CHANGE(IDC_GEWICHT, OnEnChangeGewicht)
  ON_EN_CHANGE(IDC_DUUR, OnEnChangeDuur)
END_MESSAGE_MAP()


BOOL EditBonusDialog::OnInitDialog()
{
  if (CDialog::OnInitDialog() == FALSE)
    return FALSE;

  mWeightEdit.SetValue(mWeight);
  mDurationEdit.SetValue(mBonus.GetDuration());
  switch (mBonus.GetIntensity())
  {
  case WW::Bonus::INTENSITY::Low:
    CheckDlgButton(IDC_RADIO_LOW, 1);
    break;
  case WW::Bonus::INTENSITY::Medium:
    CheckDlgButton(IDC_RADIO_MEDIUM, 1);
    break;
  case WW::Bonus::INTENSITY::High:
    CheckDlgButton(IDC_RADIO_HIGH, 1);
    break;
  }

  return TRUE;
}



// EditBonusDialog message handlers

void EditBonusDialog::OnBnClickedRadioLow()
{
  mBonus.Set(WW::Bonus::INTENSITY::Low, static_cast<int>(mWeight), mBonus.GetDuration(), mBonusMap);
  mPointsEdit.SetValue(mBonus.GetPoints());
  mPointsEdit.UpdateWindow();
}

void EditBonusDialog::OnBnClickedRadioMedium()
{
  mBonus.Set(WW::Bonus::INTENSITY::Medium, static_cast<int>(mWeight), mBonus.GetDuration(), mBonusMap);
  mPointsEdit.SetValue(mBonus.GetPoints());
  mPointsEdit.UpdateWindow();
}

void EditBonusDialog::OnBnClickedRadioHigh()
{
  mBonus.Set(WW::Bonus::INTENSITY::High, static_cast<int>(mWeight), mBonus.GetDuration(), mBonusMap);
  mPointsEdit.SetValue(mBonus.GetPoints());
  mPointsEdit.UpdateWindow();
}

void EditBonusDialog::OnEnChangeGewicht()
{
  mWeight = mWeightEdit.GetValue();
  mBonus.Set(mBonus.GetIntensity(), static_cast<int>(mWeight), mBonus.GetDuration(), mBonusMap);
  mPointsEdit.SetValue(mBonus.GetPoints());
  mPointsEdit.UpdateWindow();
}

void EditBonusDialog::OnEnChangeDuur()
{
  mBonus.Set(mBonus.GetIntensity(), static_cast<int>(mWeight), mDurationEdit.GetValue(), mBonusMap);
  mPointsEdit.SetValue(mBonus.GetPoints());
  mPointsEdit.UpdateWindow();
}
