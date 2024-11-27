#include "stdafx.h"

#include "UnitComboBox.h"

#include <assert.h>

#include "model/Unit.h"
#include "model/WWModel.h"

BEGIN_MESSAGE_MAP(UnitComboBox, CComboBox)
	//{{AFX_MSG_MAP(UnitComboBox)
  //ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


UnitComboBox::UnitComboBox(const WW::Model & aModel, const std::tstring & aUnitName)
: WW::ComboBox    (aModel, aUnitName)
{
}


//void UnitComboBox::Initialize()
//{
//  RECT rect;
//  GetWindowRect(&rect);
//  SetWindowPos(NULL, 0, 0, rect.right - rect.left, (rect.bottom - rect.top) * 5/*min(5, size)*/, SWP_NOMOVE | SWP_NOZORDER);
//}


void UnitComboBox::AddLines()
{
  for (size_t i = 0; i < GetModel().GetUnits().size(); ++i)
    AddString(GetModel().GetUnits()[i].GetName().c_str());
}


//std::tstring UnitComboBox::GetString() const
//{
//  assert(m_hWnd != NULL);
//  CString text;
//  GetWindowText(text);
//  return (const TCHAR *)text;
//}
