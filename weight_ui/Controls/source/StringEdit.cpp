#include "stdafx.h"

#include "StringEdit.h"

#include <assert.h>

std::string CStringEdit::GetValue() const
{
  assert(m_hWnd != NULL);
  CString text;
  GetWindowText(text);
  return (const char*)text;
}


void CStringEdit::SetValue(const std::string & aValue)
{
  assert(m_hWnd != NULL);
  SetWindowText(aValue.c_str());
}

