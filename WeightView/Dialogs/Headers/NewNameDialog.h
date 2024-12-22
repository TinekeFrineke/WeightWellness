#pragma once

#include "INewNameDialog.h"

#include "afxdialogex.h"
#include "afxwin.h"
#include "afxcmn.h"
#include "afxdtctl.h"
#include "resource.h"

#include "controls/StringEdit.h"


// NewNameDialog dialog

namespace weightview
{

class NewNameDialog
	: public CDialogEx
	, public weightview::INewNameDialog
{
	DECLARE_DYNAMIC(NewNameDialog)

public:
	NewNameDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~NewNameDialog();

	// Inherited via INewNameDialog
	virtual INT_PTR DoModal() override;
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

} // namespace weightview
