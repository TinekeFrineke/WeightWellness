// NewNameDialog.cpp : implementation file
//

#include "stdafx.h"

#include "NewNameDialog.h"

#include "afxdialogex.h"


// NewNameDialog dialog

IMPLEMENT_DYNAMIC(NewNameDialog, CDialogEx)

NewNameDialog::NewNameDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NEWNAME, pParent)
{

}

NewNameDialog::~NewNameDialog()
{
}

std::tstring NewNameDialog::GetName() const
{
  return m_Name;
}

void NewNameDialog::DoDataExchange(CDataExchange* pDX)
{
  CDialogEx::DoDataExchange(pDX);
  DDX_Control(pDX, IDC_NAME, mName);
}


BEGIN_MESSAGE_MAP(NewNameDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &NewNameDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// NewNameDialog message handlers


void NewNameDialog::OnBnClickedOk()
{
	m_Name = mName.GetValue();
	CDialogEx::OnOK();
}
