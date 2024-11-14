#include "stdafx.h"

#include "BrandComboBox.h"

#include <assert.h>

#include "WW/WWmodel/Unit.h"
#include "WW/WWmodel/WWModel.h"


BrandComboBox::BrandComboBox(const WW::Model &    aModel,
                             bool                 aIsForFiltering,
                             const std::tstring & anInitialBrand)
: WW::ComboBox    (aModel, anInitialBrand),
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
