#include "stdafx.h"

#include "MyTabControl.h"

/////////////////////////////////////////////////////
// This class is provided as is and Ben Hill takes no
// responsibility for any loss of any kind in connection
// to this code.
/////////////////////////////////////////////////////
// Is is meant purely as a educational tool and may
// contain bugs.
/////////////////////////////////////////////////////
// ben@shido.fsnet.co.uk
// http://www.shido.fsnet.co.uk
/////////////////////////////////////////////////////
// Thanks to a mystery poster in the C++ forum on 
// www.codeguru.com I can't find your name to say thanks
// for your Control drawing code. If you are that person 
// thank you very much. I have been able to use some of 
// you ideas to produce this sample application.
/////////////////////////////////////////////////////

#include <assert.h>
#include "controls/TabPage.h"

/////////////////////////////////////////////////////////////////////////////
// CMyTabControl

CMyTabControl::CMyTabControl()
    : m_nNumberOfPages(0)
{
}

CMyTabControl::~CMyTabControl() = default;


void CMyTabControl::AddPage(std::unique_ptr<TabPage> aPage, UINT aResourceID, TCHAR* aName)
{
    assert(aPage->GetDialog() != NULL);
    m_tabPages.push_back(std::make_unique<DialogData>(std::move(aPage), aResourceID, aName));
}


void CMyTabControl::Initialize()
{
    m_tabCurrent = 0;

    for (size_t i = 0; i < m_tabPages.size(); ++i) {
        m_tabPages[i]->mDialog->GetDialog()->Create(m_tabPages[i]->mResourceID, this);
        InsertItem(static_cast<int>(i), m_tabPages[i]->mName);
        m_nNumberOfPages++;
    }

    if (!m_tabPages.empty())
    {
        m_tabPages[0]->mDialog->GetDialog()->ShowWindow(SW_SHOW);
        for (int i = 1; i < m_nNumberOfPages; ++i)
            m_tabPages[i]->mDialog->GetDialog()->ShowWindow(SW_HIDE);
    }

    SetRectangle();
}

void CMyTabControl::SetRectangle()
{
    CRect tabRect, itemRect, windowrect;

    GetClientRect(&tabRect);
    GetItemRect(0, &itemRect);
    GetWindowRect(&windowrect);

    int nX = itemRect.left;
    int nY = itemRect.bottom + 1;
    int nXc = tabRect.right - itemRect.left - 2;
    int nYc = tabRect.bottom - nY - 2;

    if (!m_tabPages.empty())
    {
        m_tabPages[0]->mDialog->GetDialog()->SetWindowPos(&wndTop, nX, nY, nXc, nYc, SWP_SHOWWINDOW);
        for (int nCount = 1; nCount < m_nNumberOfPages; nCount++) {
            m_tabPages[nCount]->mDialog->GetDialog()->SetWindowPos(&wndTop, nX, nY, nXc, nYc, SWP_HIDEWINDOW);
        }
    }
}

BEGIN_MESSAGE_MAP(CMyTabControl, CTabCtrl)
    //{{AFX_MSG_MAP(CMyTabControl)
    ON_WM_LBUTTONDOWN()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyTabControl message handlers

void CMyTabControl::OnLButtonDown(UINT nFlags, CPoint point)
{
    CTabCtrl::OnLButtonDown(nFlags, point);
    UpdateSelection();
}


void CMyTabControl::SelectPage(int iPage)
{
    SetCurSel(iPage);
    UpdateSelection();
}


void CMyTabControl::UpdateSelection()
{
    if (m_tabCurrent != GetCurFocus()) {
        if (m_tabPages[m_tabCurrent]->mDialog->CanExit(false))
        {
            m_tabPages[m_tabCurrent]->mDialog->GetDialog()->ShowWindow(SW_HIDE);
            m_tabCurrent = GetCurFocus();
            m_tabPages[m_tabCurrent]->mDialog->GetDialog()->ShowWindow(SW_SHOW);
            m_tabPages[m_tabCurrent]->mDialog->GetDialog()->SetFocus();
        }
        else
        {
            SetCurFocus(m_tabCurrent);
        }
    }
}

CMyTabControl::DialogData::DialogData(std::unique_ptr<TabPage> aDialog, UINT anID, TCHAR* aName)
    : mDialog(std::move(aDialog))
    , mResourceID(anID)
    , mName(aName)
{
}

CMyTabControl::DialogData::~DialogData() = default;
