#pragma once

#include "afxdialogex.h"
#include "afxwin.h"
#include "afxcmn.h"
#include "afxdtctl.h"
#include "resource.h"

#include "StringEdit.h"


// NewNameDialog dialog

class NewNameDialog : public CDialogEx
{
	DECLARE_DYNAMIC(NewNameDialog)

public:
	NewNameDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~NewNameDialog();

  std::tstring GetName() const;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NEWNAME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
  CStringEdit mName;
  std::tstring m_Name;
  afx_msg void OnBnClickedOk();
};
