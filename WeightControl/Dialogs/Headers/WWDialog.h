// WWDialog.h : header file
//

#pragma once
#include "afxcmn.h"

#include "MyTabControl.h"
#include "model/Model.h"


// CWWDialog dialog
class CWWDialog : public CDialog
{
// Construction
public:
	CWWDialog(weight::Model & aModel, CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_WEIGHTWATCHERS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);

private:
  CMyTabControl mTabControl;

  weight::Model &     mModel;
};
