#include "stdafx.h"

#include "PortieComboBox.h"

#include <assert.h>

#include "model/Portie.h"
#include "model/PortieNaam.h"
#include "model/Model.h"

BEGIN_MESSAGE_MAP(PortieComboBox, CComboBox)
    //{{AFX_MSG_MAP(PortieComboBox)
  //ON_WM_CREATE()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()


PortieComboBox::PortieComboBox(const std::wstring& aPortie)
    : mInitialPortie(aPortie)
{
}


void PortieComboBox::Initialize()
{
    RECT rect;
    GetWindowRect(&rect);
    SetWindowPos(NULL, 0, 0, rect.right - rect.left, (rect.bottom - rect.top) * 5, SWP_NOMOVE | SWP_NOZORDER);
}


void PortieComboBox::Fill(const std::vector<std::wstring>& aNames, const std::tstring& aPortie)
{
    ResetContent();

    for (size_t i = 0; i < aNames.size(); ++i)
    {
        int index = AddString(aNames[i].c_str());
        SetItemDataPtr(index, NULL);
    }

    if (!aPortie.empty())
        SetCurSel(FindStringExact(0, aPortie.c_str()));
    else if (!mInitialPortie.empty())
        SetCurSel(FindStringExact(0, mInitialPortie.c_str()));
    else
        SetCurSel(0);
}


void PortieComboBox::Fill(const std::vector<std::unique_ptr<weight::Portie>>& aList, const std::tstring& aPortie)
{
    ResetContent();

    for (size_t i = 0; i < aList.size(); ++i)
    {
        int index = AddString(aList[i]->GetName().c_str());
        SetItemDataPtr(index, aList[i].get());
    }

    if (!aPortie.empty())
        SetCurSel(FindStringExact(0, aPortie.c_str()));
    else if (!mInitialPortie.empty())
        SetCurSel(FindStringExact(0, mInitialPortie.c_str()));
    else
        SetCurSel(0);
}


weight::Portie* PortieComboBox::GetSelectedPortie()
{
    int index = GetCurSel();
    if (index == CB_ERR)
        return NULL;

    return static_cast<weight::Portie*>(GetItemDataPtr(index));
}


void PortieComboBox::SetString(const std::wstring& aString)
{
    SetWindowText(aString.c_str());
}


std::wstring PortieComboBox::GetString() const
{
    assert(m_hWnd != NULL);
    CString text;
    GetWindowText(text);
    return (const TCHAR*)text;
}
