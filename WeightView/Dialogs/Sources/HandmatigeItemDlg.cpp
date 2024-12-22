// HandmatigeItemDlg.cpp : implementation file
//

#include "stdafx.h"
#include ".\handmatigeitemdlg.h"

#include "model/ManualItem.h"


// HandmatigeItemDlg dialog

IMPLEMENT_DYNAMIC(HandmatigeItemDlg, CDialog)
HandmatigeItemDlg::HandmatigeItemDlg(weight::ManualItem* anItem, CWnd* pParent /*=NULL*/)
    : CDialog(HandmatigeItemDlg::IDD, pParent),
    mItem(anItem)
{
}

HandmatigeItemDlg::~HandmatigeItemDlg()
{
}

void HandmatigeItemDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_EDIT1, mName);
    DDX_Control(pDX, IDC_EDIT3, mPoints);
}


BEGIN_MESSAGE_MAP(HandmatigeItemDlg, CDialog)
    ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


BOOL HandmatigeItemDlg::OnInitDialog()
{
    if (CDialog::OnInitDialog() == FALSE)
        return FALSE;

    if (mItem == NULL)
    {
        mPoints.SetValue(0);
    }
    else
    {
        mName.SetValue(mItem->GetName());
        mPoints.SetValue(mItem->GetPoints());
    }

    return TRUE;
}


// HandmatigeItemDlg message handlers

void HandmatigeItemDlg::OnBnClickedOk()
{
    if (mItem == NULL)
        mItem = std::make_unique<weight::ManualItem>(mName.GetValue(), mPoints.GetValue());

    mItem->Set(mPoints.GetValue());
    OnOK();
}
