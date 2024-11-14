#include "stdafx.h"

#include "IntEdit.h"

#include "Utilities/StrUtils.h"

#include <assert.h>

BEGIN_MESSAGE_MAP(CIntEdit, CEdit)
	//{{AFX_MSG_MAP(CIntEdit)
  ON_WM_KILLFOCUS( )
  ON_WM_CHAR( )
//}}AFX_MSG_MAP
END_MESSAGE_MAP()


bool CIntEdit::CheckContents()
{
  assert(m_hWnd != NULL);
  TCHAR text[1024];
  GetWindowText(text, 1023);

  return Str::IsInt(text);
}


int CIntEdit::GetValue() const
{
  assert(m_hWnd != NULL);
  CString text;
  GetWindowText(text);
  return _ttoi(text);
}


void CIntEdit::SetValue(int aValue)
{
  assert(m_hWnd != NULL);
  TCHAR buffer[10];
  _stprintf_s(buffer, _T("%d"), aValue);
  SetWindowText(buffer);
}


void CIntEdit::OnChar(UINT nChar, UINT nRepCount, UINT nFlags)
{
  if (!isdigit(nChar) && nChar != _T('\b') && nChar != 0x16)
    return;

  CEdit::OnChar(nChar, nRepCount, nFlags);
}


void CIntEdit::OnKillFocus(CWnd * aWnd)
{
  if (!CheckContents())
    ::MessageBox(0, _T("Enter an integer"), _T("Error"), MB_OK);

  CEdit::OnKillFocus(aWnd);
}
