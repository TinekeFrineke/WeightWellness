#pragma once

#include "afxcmn.h"

#include <memory>
#include <vector>


class TabPage;

/////////////////////////////////////////////////////////////////////////////
// CMyTabControl window

class CMyTabControl: public CTabCtrl
{
    // Construction
public:
    CMyTabControl();
    virtual ~CMyTabControl();

    void AddPage(std::unique_ptr<TabPage> aPage, UINT aResourceID, TCHAR* aName);

    void Initialize();
    void SelectPage(int iPage);

    // Overrides
        // ClassWizard generated virtual function overrides
        //{{AFX_VIRTUAL(CMyTabControl)
        //}}AFX_VIRTUAL

    // Implementation
        // Generated message map functions

protected:
    //{{AFX_MSG(CMyTabControl)
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    //}}AFX_MSG

    DECLARE_MESSAGE_MAP()

private:
    struct DialogData
    {
        DialogData(std::unique_ptr<TabPage> aDialog, UINT anID, TCHAR* aName);
        ~DialogData();
        std::unique_ptr<TabPage> mDialog;
        UINT                  mResourceID;
        TCHAR* mName;
    };

    void                    SetRectangle();
    void                    UpdateSelection();

    std::vector<std::unique_ptr<DialogData>> m_tabPages;
    int                     m_tabCurrent;
    int                     m_nNumberOfPages;

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
