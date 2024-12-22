// WWDialog.h : header file
//

#pragma once
#include "afxcmn.h"

//#include "MyTabControl.h"
#include "model/Model.h"

#include "IWWDialog.h"


class CMyTabControl;

// CWWDialog dialog
class CWWDialog
	: public CDialog
	, public weightview::IWWDialog
{
// Construction
public:
	CWWDialog(weight::Model & aModel, CWnd* pParent = NULL);	// standard constructor
	~CWWDialog();

// Dialog Data
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


  // Inherited via IWWDialog
	virtual CDialog* GetWindow() override;
	virtual INT_PTR DoModal() override;

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
  std::unique_ptr<CMyTabControl> mTabControl;

  weight::Model &     mModel;
};
