#include "stdafx.h"

#include "WWComboBox.h"

#include <assert.h>

#include "model/Unit.h"
#include "model/WWModel.h"

BEGIN_MESSAGE_MAP(WW::ComboBox, CComboBox)
	//{{AFX_MSG_MAP(VMDefinitiesList)
  //ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


namespace WW
{

ComboBox::ComboBox(const WW::Model & aModel, const std::tstring & anInitialText)
: mModel      (aModel),
  mInitialText(anInitialText)
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


std::tstring ComboBox::GetEditString() const
{
  CString text;
  GetWindowText(text);
  return static_cast<const TCHAR *>(text);
}


std::tstring ComboBox::GetString() const
{
  int nIndex = GetCurSel();

  if (nIndex < 0 || nIndex >= GetCount())
    // Maybe a new string was added:
    return GetEditString();

  CString text;
  GetLBText(nIndex, text);

  return static_cast<const TCHAR *>(text);
}


void ComboBox::SetString(const std::tstring & aString)
{
  SetWindowText(aString.c_str());
}

}