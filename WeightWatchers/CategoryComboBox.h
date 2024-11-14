#pragma once

#include "WWCombobox.h"
#include "Utilities/StrUtils.h"

namespace WW
{
  class Model;
}

class CategoryComboBox : public WW::ComboBox
{
public:
                              CategoryComboBox(const WW::Model &    aModel,
                                               const std::tstring & anInitialCategory = _T(""));

  virtual void                AddLines();

	////{{AFX_MSG(CategoryComboBox)
 // //afx_msg int                 OnCreate(LPCREATESTRUCT lpCreateStruxct);
	////}}AFX_MSG

	//DECLARE_MESSAGE_MAP()

private:
};
