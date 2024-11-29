#include "stdafx.h"

#include "BrandComboBox.h"

#include <assert.h>

#include "model/Unit.h"
#include "model/Model.h"


BrandComboBox::BrandComboBox(const weight::Model &    aModel,
                             bool                 aIsForFiltering,
                             const std::tstring & anInitialBrand)
: weight::ComboBox    (aModel, anInitialBrand),
  mIsForFiltering (aIsForFiltering)
{
}


void BrandComboBox::AddLines()
{
  if (mIsForFiltering) {
    AddString(_T("<alles>"));
    AddString(_T("<merkloos>"));
  }

  for (size_t i = 0; i < GetModel().GetMerkNamen().size(); ++i)
    AddString(GetModel().GetMerkNamen()[i].Get().c_str());
}
