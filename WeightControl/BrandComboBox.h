#pragma once

#include "WWCombobox.h"
#include "Utilities/StrUtils.h"

namespace WW
{
  class Model;
}

class BrandComboBox : public WW::ComboBox
{
public:
                              BrandComboBox(const WW::Model &     aModel,
                                            bool                  aIsForFiltering,
                                            const std::tstring &  anInitialBrand = _T(""));

  void                        AddLines();

private:
  bool                        mIsForFiltering;
};
