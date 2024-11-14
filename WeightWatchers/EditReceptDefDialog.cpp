// EditReceptDefDialog.cpp : implementation file
//

#include "stdafx.h"
#include "WeightWatchers.h"
#include ".\editreceptdefdialog.h"

#include "FindVoedingsmiddel.h"
#include "ItemEditVisitor.h"

#include "WW/WWModel/ReceptDefinitie.h"

// EditReceptDefDialog dialog

IMPLEMENT_DYNAMIC(EditReceptDefDialog, CDialog)
EditReceptDefDialog::EditReceptDefDialog(WW::Model & aModel, WW::ReceptDefinitie * aRecept, CWnd* pParent /*=NULL*/)
: CDialog(EditReceptDefDialog::IDD, pParent),
  mModel            (aModel),
  mItemList         (aModel),
  mRecept           (aRecept)
{
}

EditReceptDefDialog::~EditReceptDefDialog()
{
}

void EditReceptDefDialog::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  DDX_Control(pDX, IDC_ITEMS_LIST, mItemList);
  DDX_Control(pDX, IDC_EDIT1, mName);
  DDX_Control(pDX, IDC_PUNTEN, mPointsPerPortion);
  DDX_Control(pDX, IDC_PORTIES, mPorties);
}


BEGIN_MESSAGE_MAP(EditReceptDefDialog, CDialog)
  ON_BN_CLICKED(IDC_ADD, OnBnClickedAdd)
  ON_BN_CLICKED(IDOK, OnBnClickedOk)
  ON_BN_CLICKED(IDC_EDIT, OnBnClickedEdit)
  ON_NOTIFY(LVN_ITEMCHANGED, IDC_ITEMS_LIST, OnLvnItemchangedItemsList)
  ON_NOTIFY(NM_DBLCLK, IDC_ITEMS_LIST, OnNMDblclkItemsList)
  ON_EN_CHANGE(IDC_PORTIES, OnEnChangePorties)
  ON_BN_CLICKED(IDC_DELETE, OnBnClickedDelete)
END_MESSAGE_MAP()


BOOL EditReceptDefDialog::OnInitDialog()
{
  if (CDialog::OnInitDialog() == FALSE)
    return FALSE;

  mItemList.Initialize();
  if (mRecept == 0)
  {
    mPointsPerPortion.SetValue(0);
    mPorties.SetValue(4);
  }
  else
  {
    mName.SetValue(mRecept->GetName());
    mItemList.View(mRecept->GetItems());
    mPointsPerPortion.SetValue(mRecept->GetPointsPerPortion());
    mPorties.SetValue(mRecept->GetPortions());
  }

  return TRUE;

}


void EditReceptDefDialog::EditSelectedItem()
{
  ItemListItem * item = mItemList.GetSelectedItem();
  if (item == NULL || mRecept == NULL)
    return;

  ItemEditVisitor visitor(mModel, this);
  item->GetItem()->Accept(visitor);

  mItemList.View(mRecept->GetItems());
  mPointsPerPortion.SetValue(mRecept->GetPointsPerPortion());
  mPorties.SetValue(mRecept->GetPortions());
}


// EditReceptDefDialog message handlers

void EditReceptDefDialog::OnBnClickedAdd()
{
  if (mRecept == NULL) {
    if (mName.GetValue().empty()) {
      ::MessageBox(0, _T("Type name"), _T("ERROR"), MB_OK);
      return;
    }

    if (mModel.FindReceptDefinitie(mName.GetValue()) != NULL)
    {
      ::MessageBox(0, _T("Duplicate recept name"), _T("ERROR"), MB_OK);
      return;
    }

    mRecept = new WW::ReceptDefinitie(mName.GetValue());
  }

  CFindVoedingsmiddel dialog(mModel, NULL, this);
  INT_PTR nResponse = dialog.DoModal();
	if (nResponse == IDOK)
	{
    if (dialog.GetVoedingsMiddel() != NULL) {
      mRecept->Add(dialog.GetVoedingsMiddel());
    }
	}
  else
  {
    if (dialog.GetVoedingsMiddel() != NULL)
      delete dialog.GetVoedingsMiddel();
  }

  mPointsPerPortion.SetValue(mRecept->GetPointsPerPortion());
  mItemList.View(mRecept->GetItems());
}

void EditReceptDefDialog::OnBnClickedOk()
{
  if (mRecept == NULL)
    return;

  mRecept->SetPortions(mPorties.GetValue());

  OnOK();
}


void EditReceptDefDialog::OnBnClickedEdit()
{
  EditSelectedItem();
}


void EditReceptDefDialog::OnLvnItemchangedItemsList(NMHDR *pNMHDR, LRESULT *pResult)
{
  LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
  (void)pNMLV;
  // TODO: Add your control notification handler code here
  *pResult = 0;
}

void EditReceptDefDialog::OnNMDblclkItemsList(NMHDR *pNMHDR, LRESULT *pResult)
{
  (void)pNMHDR;

  EditSelectedItem();

  *pResult = 0;
}

void EditReceptDefDialog::OnEnChangePorties()
{
  if (mRecept == NULL)
    return;
 
  mRecept->SetPortions(mPorties.GetValue());
  mPointsPerPortion.SetValue(mRecept->GetPointsPerPortion());
}

void EditReceptDefDialog::OnBnClickedDelete()
{
  ItemListItem * item = mItemList.GetSelectedItem();
  if (item == NULL || mRecept == NULL)
    return;

  mRecept->Remove(item->GetItem());

  mItemList.View(mRecept->GetItems());
  mPointsPerPortion.SetValue(mRecept->GetPointsPerPortion());
  mPorties.SetValue(mRecept->GetPortions());
}
