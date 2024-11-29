#pragma once

#include "controls/stringedit.h"
#include "controls/doubleedit.h"


// HandmatigeItemDlg dialog

namespace weight { class ManualItem; }

class HandmatigeItemDlg: public CDialog
{
    DECLARE_DYNAMIC(HandmatigeItemDlg)

public:
    HandmatigeItemDlg(weight::ManualItem* anItem = nullptr, CWnd* pParent = nullptr);   // standard constructor
    virtual ~HandmatigeItemDlg();

    // Dialog Data
    enum { IDD = IDD_HANDMATIG_ITEM };

    std::unique_ptr<weight::ManualItem>  GetItem() { return std::move(mItem); }

protected:
    virtual void      DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    BOOL              OnInitDialog();

    DECLARE_MESSAGE_MAP()

    afx_msg void      OnBnClickedOk();

private:
    CStringEdit       mName;
    CDoubleEdit       mAmount;
    CDoubleEdit       mPoints;

    std::unique_ptr<weight::ManualItem>  mItem;
};
