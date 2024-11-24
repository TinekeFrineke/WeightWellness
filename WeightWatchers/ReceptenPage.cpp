// ReceptenPage.cpp : implementation file
//

#include "stdafx.h"
#include "WeightWatchers.h"
#include "ReceptenPage.h"
#include ".\receptenpage.h"

#include "EditReceptDefDialog.h"
#include "model/ReceptDefinitie.h"


// ReceptenPage dialog

IMPLEMENT_DYNAMIC(ReceptenPage, CDialog)
ReceptenPage::ReceptenPage(WW::Model & aModel, CWnd* pParent)
: CDialog       (ReceptenPage::IDD, pParent),
  mReceptenList (aModel),
  mModel        (aModel)
{
}

ReceptenPage::~ReceptenPage()
{
}

void ReceptenPage::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  DDX_Control(pDX, IDC_LIST1, mReceptenList);
}


BEGIN_MESSAGE_MAP(ReceptenPage, CDialog)
  ON_BN_CLICKED(IDC_ADD, OnBnClickedAdd)
  ON_BN_CLICKED(IDC_EDIT, OnBnClickedEdit)
  ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnNMDblclkList1)
  ON_BN_CLICKED(IDC_DELETE, &ReceptenPage::OnBnClickedDelete)
END_MESSAGE_MAP()


BOOL ReceptenPage::OnInitDialog()
{
  if (CDialog::OnInitDialog() == FALSE)
    return FALSE;

  mReceptenList.Initialize();
  View(mModel.GetReceptDefs());
  return TRUE;
}


// ReceptenPage message handlers

void ReceptenPage::OnBnClickedAdd()
{
  // TODO: Add your control notification handler code here
  EditReceptDefDialog dialog(mModel, NULL, this);
  INT_PTR nResponse = dialog.DoModal();
	if (nResponse == IDOK)
	{
    if (dialog.GetRecept() != NULL)
      mModel.Add(dialog.GetRecept());

    mReceptenList.View(mModel.GetReceptDefs());
	}
  else
  {
    if (dialog.GetRecept() != NULL)
      delete(dialog.GetRecept());
  }

  mReceptenList.View(mRecepten);
}


void ReceptenPage::View(const std::vector<std::unique_ptr<WW::ReceptDefinitie>> & aRecepten)
{
  mRecepten.clear();
  for (size_t i = 0; i < aRecepten.size(); ++i)
    mRecepten.push_back(aRecepten[i]);

  mReceptenList.View(mRecepten);
}

void ReceptenPage::OnBnClickedEdit()
{
  // TODO: Add your control notification handler code here
  ReceptDefinitiesListItem * item = mReceptenList.GetSelectedItem();
  if (item == NULL || item->GetItem() == NULL)
    return;

  // TODO: Add your control notification handler code here
  EditReceptDefDialog dialog(mModel, item->GetItem(), this);
  /*INT_PTR nResponse = */dialog.DoModal();

  mReceptenList.View(mRecepten);
}

void ReceptenPage::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
  (void)pNMHDR;

  // TODO: Add your control notification handler code here
  ReceptDefinitiesListItem * item = mReceptenList.GetSelectedItem();
  if (item == NULL || item->GetItem() == NULL)
    return;

  // TODO: Add your control notification handler code here
  EditReceptDefDialog dialog(mModel, item->GetItem(), this);
  /*INT_PTR nResponse = */dialog.DoModal();


  mReceptenList.View(mRecepten);

  *pResult = 0;
}


void ReceptenPage::OnBnClickedDelete()
{
  ReceptDefinitiesListItem * item = mReceptenList.GetSelectedItem();
  if (item == NULL)
    return;
  
  if (::MessageBox(m_hWnd, _T("Zeker weten?"), _T("Waarschuwing"), MB_ICONQUESTION | MB_YESNO) == IDYES) {
    for (std::vector<WW::ReceptDefinitie *>::iterator iter = mRecepten.begin(); iter != mRecepten.end(); ++iter) {
      if (*iter == item->GetItem()) {
        mReceptenList.DeleteItem(item);
        mRecepten.erase(iter);
        mReceptenList.View(mRecepten);
        delete item;
        return;
      }
    }
  }
}
