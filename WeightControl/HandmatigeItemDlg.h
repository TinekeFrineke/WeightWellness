#pragma once
#include "stringedit.h"
#include "doubleedit.h"


// HandmatigeItemDlg dialog

namespace WW { class ManualItem; }

class HandmatigeItemDlg: public CDialog
{
    DECLARE_DYNAMIC(HandmatigeItemDlg)

public:
    HandmatigeItemDlg(WW::ManualItem* anItem = nullptr, CWnd* pParent = nullptr);   // standard constructor
    virtual ~HandmatigeItemDlg();

    // Dialog Data
    enum { IDD = IDD_HANDMATIG_ITEM };

    std::unique_ptr<WW::ManualItem>  GetItem() { return std::move(mItem); }

protected:
    virtual void      DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    BOOL              OnInitDialog();

    DECLARE_MESSAGE_MAP()

    afx_msg void      OnBnClickedOk();

private:
    CStringEdit       mName;
    CDoubleEdit       mAmount;
    CDoubleEdit       mPoints;

    std::unique_ptr<WW::ManualItem>  mItem;
};
