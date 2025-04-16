#pragma once

#include "Utilities/StrUtils.h"

#include "Combobox.h"

class BrandComboBox: public weight::ComboBox
{
public:
    BrandComboBox(const std::vector<std::string>& availableTexts, bool aIsForFiltering,
                  const std::string& anInitialBrand = _T(""));

    void AddLines() override;

private:
    bool mIsForFiltering;
};
