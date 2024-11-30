#include "stdafx.h"

#include "BrandComboBox.h"

#include <assert.h>

#include "model/Unit.h"
#include "model/Model.h"


BrandComboBox::BrandComboBox(const std::vector<std::wstring>& availableTexts, bool aIsForFiltering,
                             const std::tstring& anInitialBrand)
    : weight::ComboBox(availableTexts, anInitialBrand)
    , mIsForFiltering(aIsForFiltering)
{
}


void BrandComboBox::AddLines()
{
    if (mIsForFiltering) {
        AddString(_T("<alles>"));
        AddString(_T("<merkloos>"));
    }

    weight::ComboBox::AddLines();
}
