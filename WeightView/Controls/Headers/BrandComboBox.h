#pragma once

#include "Utilities/StrUtils.h"

#include "Combobox.h"

namespace weight
{
class Model;
}

class BrandComboBox: public weight::ComboBox
{
public:
    BrandComboBox(const std::vector<std::tstring>& availableTexts, bool aIsForFiltering,
                  const std::tstring& anInitialBrand = _T(""));

    void AddLines() override;

private:
    bool mIsForFiltering;
};
