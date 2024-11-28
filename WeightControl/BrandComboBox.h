#pragma once

#include "WWCombobox.h"
#include "Utilities/StrUtils.h"

namespace weight
{
  class Model;
}

class BrandComboBox : public weight::ComboBox
{
public:
                              BrandComboBox(const weight::Model &     aModel,
                                            bool                  aIsForFiltering,
                                            const std::tstring &  anInitialBrand = _T(""));

  void                        AddLines();

private:
  bool                        mIsForFiltering;
};
