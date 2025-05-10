#include "stdafx.h"

#include "BrandComboBox.h"

#include <assert.h>


BrandComboBox::BrandComboBox(const std::vector<std::string>& availableTexts, bool aIsForFiltering,
                             const std::string& anInitialBrand)
    : weight::ComboBox(availableTexts, anInitialBrand)
    , mIsForFiltering(aIsForFiltering)
{
}


void BrandComboBox::AddLines()
{
    if (mIsForFiltering) {
        AddString("<alles>");
        AddString("<merkloos>");
    }

    weight::ComboBox::AddLines();
}
