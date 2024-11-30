#include "stdafx.h"

#include "ComboBox.h"

#include <assert.h>

#include "model/Unit.h"
#include "model/Model.h"

BEGIN_MESSAGE_MAP(weight::ComboBox, CComboBox)
    //{{AFX_MSG_MAP(VMDefinitiesList)
  //ON_WM_CREATE()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()


namespace weight
{

ComboBox::ComboBox(const std::vector<std::wstring>& availableTexts, const std::tstring& anInitialText)
    : m_availableTexts(availableTexts)
    , mInitialText(anInitialText)
{
}


void ComboBox::Initialize()
{
    RECT rect;
    GetWindowRect(&rect);
    CComboBox::SetWindowPos(NULL, 0, 0, rect.right - rect.left, (rect.bottom - rect.top) * 5, SWP_NOMOVE | SWP_NOZORDER);
}


void ComboBox::Fill()
{
    ResetContent();

    AddLines();

    if (mInitialText.empty())
        SetCurSel(-1);
    else
        SetCurSel(FindStringExact(0, mInitialText.c_str()));
}

void ComboBox::AddLines()
{
    for (size_t i = 0; i < m_availableTexts.size(); ++i)
        AddString(m_availableTexts[i].c_str());
}


std::wstring ComboBox::GetEditString() const
{
    CString text;
    GetWindowText(text);
    return static_cast<const TCHAR*>(text);
}


std::wstring ComboBox::GetString() const
{
    int nIndex = GetCurSel();

    if (nIndex < 0 || nIndex >= GetCount())
        // Maybe a new string was added:
        return GetEditString();

    CString text;
    GetLBText(nIndex, text);

    return static_cast<const TCHAR*>(text);
}


void ComboBox::SetText(const std::wstring& aString)
{
    SetWindowText(aString.c_str());
}

}