// BewegingDialog.cpp : implementation file
//

#include "stdafx.h"
#include "BewegingDialog.h"


// BewegingDialog dialog

IMPLEMENT_DYNAMIC(BewegingDialog, CDialogEx)

BewegingDialog::BewegingDialog(double initialCalories, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADD_BEWEGING, pParent)
	, m_calories(initialCalories)
{

}

BewegingDialog::~BewegingDialog()
{
}

BOOL BewegingDialog::OnInitDialog()
{
	if (CDialog::OnInitDialog() == FALSE)
		return FALSE;

	m_caloriesEdit.SetValue(m_calories);
	return TRUE;
}

void BewegingDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_CALORIES, m_caloriesEdit);
}

double BewegingDialog::GetBewegingsPunten() const
{
	return m_calories;
}


BEGIN_MESSAGE_MAP(BewegingDialog, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_CALORIES, &BewegingDialog::OnEnChangeEditCalories)
END_MESSAGE_MAP()


// BewegingDialog message handlers


void BewegingDialog::OnEnChangeEditCalories()
{
	m_calories = m_caloriesEdit.GetValue();
}
