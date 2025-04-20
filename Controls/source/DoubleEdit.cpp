#include "stdafx.h"

#include "DoubleEdit.h"

#include "Utilities/StrUtils.h"

#include <assert.h>

BEGIN_MESSAGE_MAP(CDoubleEdit, CEdit)
    //{{AFX_MSG_MAP(CDoubleEdit)
    ON_WM_CHAR()
    ON_WM_KILLFOCUS()
    //  ON_MESSAGE(WM_PASTE, OnPaste)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()


bool CDoubleEdit::CheckContents()
{
    assert(m_hWnd != NULL);
    char text[1024];
    GetWindowText(text, 1023);

    return Str::IsDouble(text);
}


double CDoubleEdit::GetValue() const
{
    assert(m_hWnd != NULL);
    char text[1024];
    GetWindowText(text, 1023);

    if (Str::IsDouble(text))
        return Str::ToDouble(text);
    else
        return 0;
}


void CDoubleEdit::SetValue(double aValue)
{
    assert(m_hWnd != NULL);
    char format[10];
    sprintf_s(format, "%c.%df", '%', mDecimals);
    char buffer[1024];
    sprintf_s(buffer, format, aValue);
    SetWindowText(buffer);
}


void CDoubleEdit::OnChar(UINT nChar, UINT nRepCount, UINT nFlags)
{
    if (!isdigit(nChar) && (nChar != '.' && nChar != ',' && nChar != '\b' && nChar != 0x16))
        return;

    CEdit::OnChar(nChar, nRepCount, nFlags);
}


void CDoubleEdit::OnKillFocus(CWnd* aWnd)
{
    if (!CheckContents())
        ::MessageBox(0, "Enter a double", "Error", MB_OK);

    CEdit::OnKillFocus(aWnd);
}
