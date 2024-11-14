// ItemsPage.cpp : implementation file
//

#include "stdafx.h"
#include "afxmsg_.h"
#include "WeightWatchers.h"
#include "ItemsPage.h"

#include "EditFoodDefDialog.h"

#include "WW/WWModel/Unit.h"
#include "WW/WWModel/VoedingsmiddelDefinitie.h"
#include ".\itemspage.h"

// CItemsPage dialog

IMPLEMENT_DYNAMIC(CItemsPage, CDialog)
CItemsPage::CItemsPage(WW::Model & aModel, CWnd* pParent /*=NULL*/)
: CDialog         (CItemsPage::IDD, pParent),
  mModel          (aModel),
  mCategory       (aModel),
  mMerk           (aModel, true),
  mItemsList      (aModel),
  mUpdatingFilter (false)
{
}

CItemsPage::~CItemsPage()
{
}

void CItemsPage::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  DDX_Control(pDX, IDC_ITEMLIST, mItemsList);
  DDX_Control(pDX, IDC_NAAM, mNaam);
  DDX_Control(pDX, IDC_COMBO1, mCategory);
  DDX_Control(pDX, IDC_BRAND, mMerk);
}


BEGIN_MESSAGE_MAP(CItemsPage, CDialog)
  ON_BN_CLICKED(IDC_ADD, OnBnClickedAdd)
  ON_BN_CLICKED(IDC_EDIT, OnBnClickedEdit)
  ON_BN_CLICKED(IDC_DELETE, OnBnClickedDelete)
  ON_NOTIFY(NM_DBLCLK, IDC_ITEMLIST, OnNMDblclkItemlist)
  ON_EN_CHANGE(IDC_NAAM, OnEnChangeNaam)
  ON_CBN_SELCHANGE(IDC_COMBO1, OnCbnSelchangeCombo1)
  ON_CBN_SELCHANGE(IDC_BRAND, OnCbnSelchangeBrand)
  ON_CBN_EDITCHANGE(IDC_COMBO1, OnCbnEditchangeCombo1)
  ON_BN_CLICKED(IDC_CHECK_FAVOURITES, OnBnClickedCheckFavourites)
END_MESSAGE_MAP()


// CItemsPage message handlers


BOOL CItemsPage::OnInitDialog()
{
  if (CDialog::OnInitDialog() == FALSE)
    return FALSE;

  mItemsList.Initialize();
  mItemsList.Fill();

  mCategory.Initialize();
  mCategory.Fill();

  mMerk.Initialize();
  mMerk.Fill();

  return TRUE;
}

void CItemsPage::OnBnClickedAdd()
{
  CEditFoodDefDialog dialog(mModel, NULL, this);
  INT_PTR nResponse = dialog.DoModal();
	if (nResponse == IDOK)
	{
    mItemsList.Fill();
	}
}

void CItemsPage::OnBnClickedEdit()
{
  EditItem();
}

void CItemsPage::OnCancel()
{
}

void CItemsPage::OnBnClickedDelete()
{
  VMDefinitiesListItem * item = mItemsList.GetSelectedItem();
  if (item == NULL)
    return;

  if (mModel.Remove(item->GetItem()))
    mItemsList.Fill();
}


void CItemsPage::EditItem()
{
  VMDefinitiesListItem * item = mItemsList.GetSelectedItem();
  if (item != NULL) {
    CEditFoodDefDialog dlg(mModel, item->GetItem(), this);
    INT_PTR nResponse = dlg.DoModal();
    if (nResponse == IDOK)
    {
	    // TODO: Place code here to handle when the dialog is
	    //  dismissed with OK
    }
  }
}


void CItemsPage::UpdateItemFilter()
{
  mItemsList.SetFilter(VMDefinitiesFilter(mNaam.GetValue(),
                                          mCategory.GetString(),
                                          mMerk.GetString()));
  mItemsList.Fill();
}


void CItemsPage::OnNMDblclkItemlist(NMHDR *pNMHDR, LRESULT *pResult)
{
  (void)pNMHDR;
  EditItem();
  *pResult = 0;
}

void CItemsPage::OnEnChangeNaam()
{
  if (!mUpdatingFilter)
    UpdateItemFilter();
}

void CItemsPage::OnCbnSelchangeCombo1()
{
  if (!mUpdatingFilter)
    UpdateItemFilter();
}

void CItemsPage::OnCbnSelchangeBrand()
{
  if (!mUpdatingFilter)
    UpdateItemFilter();
}

void CItemsPage::OnCbnEditchangeCombo1()
{
  if (mCategory.GetEditString().empty())
    mCategory.SetCurSel(-1);

  if (!mUpdatingFilter)
    UpdateItemFilter();
}

void CItemsPage::OnBnClickedCheckFavourites()
{
  mItemsList.SetFavouritesOnly(IsDlgButtonChecked(IDC_CHECK_FAVOURITES) != FALSE);
  mItemsList.Fill();
}
