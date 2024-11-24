// ReceptenPage.cpp : implementation file
//

#include "stdafx.h"
#include "WeightWatchers.h"
#include "ReceptenPage.h"
#include ".\receptenpage.h"

#include "EditReceptDefDialog.h"
#include "model/ReceptDefinitie.h"


// ReceptenPage dialog

// TODO ww2019: Now the page directly removes recepies from the model. 
// It would be better if this happens only when the user presses "OK".

IMPLEMENT_DYNAMIC(ReceptenPage, CDialog)
ReceptenPage::ReceptenPage(WW::Model& aModel, CWnd* pParent)
    : CDialog(ReceptenPage::IDD, pParent),
    mReceptenList(aModel),
    mModel(aModel)
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
    EditReceptDefDialog dialog(mModel, NULL, this);
    INT_PTR nResponse = dialog.DoModal();
    if (nResponse == IDOK)
    {
        if (dialog.ExtractRecept() != NULL)
            mModel.Add(dialog.ExtractRecept());
    }

    mReceptenList.View(mModel.GetReceptDefs());
}


void ReceptenPage::View(const std::vector<std::unique_ptr<WW::ReceptDefinitie>>& aRecepten)
{
    mReceptenList.View(aRecepten);
}

void ReceptenPage::OnBnClickedEdit()
{
    ReceptDefinitiesListItem* item = mReceptenList.GetSelectedItem();
    if (item == NULL || item->GetItem() == NULL)
        return;

    EditReceptDefDialog dialog(mModel, item->GetItem(), this);
    /*INT_PTR nResponse = */dialog.DoModal();

    mReceptenList.View(mModel.GetReceptDefs());
}

void ReceptenPage::OnNMDblclkList1(NMHDR* pNMHDR, LRESULT* pResult)
{
    (void)pNMHDR;

    ReceptDefinitiesListItem* item = mReceptenList.GetSelectedItem();
    if (item == NULL || item->GetItem() == NULL)
        return;

    EditReceptDefDialog dialog(mModel, item->GetItem(), this);
    /*INT_PTR nResponse = */dialog.DoModal();


    mReceptenList.View(mModel.GetReceptDefs());

    *pResult = 0;
}


void ReceptenPage::OnBnClickedDelete()
{
    ReceptDefinitiesListItem* item = mReceptenList.GetSelectedItem();
    if (item == NULL)
        return;

    if (::MessageBox(m_hWnd, _T("Zeker weten?"), _T("Waarschuwing"), MB_ICONQUESTION | MB_YESNO) == IDYES) {
        mModel.Remove(item->GetItem());
    }

    View(mModel.GetReceptDefs());
}
