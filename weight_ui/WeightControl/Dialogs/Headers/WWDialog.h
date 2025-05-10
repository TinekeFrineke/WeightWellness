// WWDialog.h : header file
//

#pragma once
#include "afxcmn.h"

#include "MyTabControl.h"
#include "model/IModel.h"

class IPageFactory;


// CWWDialog dialog
class CWWDialog: public CDialog
{
    // Construction
public:
    CWWDialog(weight::IModel& aModel, std::unique_ptr<IPageFactory> pageFactory, CWnd* pParent = nullptr);	// standard constructor
    ~CWWDialog() override;

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
    afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
    DECLARE_MESSAGE_MAP()

private:
    CMyTabControl mTabControl;

    std::unique_ptr<IPageFactory> m_factory;
    weight::IModel& mModel;
};
