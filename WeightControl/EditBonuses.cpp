// EditBonuses.cpp : implementation file
//

#include "stdafx.h"
#include "WeightControl.h"
#include "EditBonuses.h"

#include "EditBonusDialog.h"
#include ".\editbonuses.h"


// CEditBonuses dialog

IMPLEMENT_DYNAMIC(CEditBonuses, CDialog)
CEditBonuses::CEditBonuses(WW::Model & aModel, const std::list<WW::Bonus> & aBonuses, double aWeight, CWnd* pParent /*=NULL*/)
: CDialog(CEditBonuses::IDD, pParent),
  mBonuses  (aBonuses),
  mModel    (aModel),
  mWeight   (aWeight),
  mBonusList(aModel)
{
}


CEditBonuses::~CEditBonuses()
{
}

void CEditBonuses::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  DDX_Control(pDX, IDC_BONUSLISTJBJ, mBonusList);
}


BEGIN_MESSAGE_MAP(CEditBonuses, CDialog)
  ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
  ON_BN_CLICKED(IDC_ADD, OnBnClickedAdd)
  ON_BN_CLICKED(IDC_EDIT, OnBnClickedEdit)
  ON_BN_CLICKED(IDC_DELETE, OnBnClickedDelete)
  ON_NOTIFY(NM_DBLCLK, IDC_BONUSLISTJBJ, OnNMDblclkBonuslistjbj)
END_MESSAGE_MAP()


// CEditBonuses message handlers

void CEditBonuses::OnBnClickedCancel()
{
  OnCancel();
}

void CEditBonuses::OnBnClickedAdd()
{
  EditBonusDialog dialog(mModel.GetBonusPointsMap(), mWeight, this);
  INT_PTR nResponse = dialog.DoModal();
	if (nResponse == IDOK)
    mBonuses.push_back(dialog.GetBonus());

  mBonusList.View(mBonuses);
}


BOOL CEditBonuses::OnInitDialog()
{
  if (CDialog::OnInitDialog() == FALSE)
    return FALSE;

  mBonusList.Initialize();
  mBonusList.SetSelectionMark(0);
  mBonusList.ShowWindow(SW_SHOW);
  mBonusList.View(mBonuses);

  return TRUE;
}

void CEditBonuses::OnBnClickedEdit()
{
  EditBonus();
}

void CEditBonuses::OnBnClickedDelete()
{
}


void CEditBonuses::EditBonus()
{
  BonusListItem * item = mBonusList.GetSelectedItem();
  if (item != NULL) {
    EditBonusDialog dlg(mModel.GetBonusPointsMap(), mWeight, item->GetBonus(), this);
    INT_PTR nResponse = dlg.DoModal();
    if (nResponse == IDOK)
      item->GetBonus() = dlg.GetBonus();
  }
}

void CEditBonuses::OnNMDblclkBonuslistjbj(NMHDR *pNMHDR, LRESULT *pResult)
{
  (void)pNMHDR;
  EditBonus();
  *pResult = 0;
}
