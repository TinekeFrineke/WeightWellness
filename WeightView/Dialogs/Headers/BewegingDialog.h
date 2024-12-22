#pragma once

#include "afxdialogex.h"
#include "controls/doubleedit.h"
#include "resource.h"

// BewegingDialog dialog

class BewegingDialog : public CDialogEx
{
	DECLARE_DYNAMIC(BewegingDialog)

public:
	BewegingDialog(double initialCalories, CWnd* pParent = nullptr);   // standard constructor
	virtual ~BewegingDialog();

	BOOL OnInitDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_BEWEGING };
#endif

	double GetBewegingsPunten() const;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
public:
	CDoubleEdit m_caloriesEdit;
	double m_calories;
	afx_msg void OnEnChangeEditCalories();
};
