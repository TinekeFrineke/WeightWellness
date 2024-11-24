#include "stdafx.h"

#include "CategoryComboBox.h"

#include <assert.h>

#include "model/Unit.h"
#include "model/WWModel.h"


CategoryComboBox::CategoryComboBox(const WW::Model & aModel, const std::tstring & anInitialCategory)
: WW::ComboBox(aModel, anInitialCategory)
{
}


void CategoryComboBox::AddLines()
{
  for (size_t i = 0; i < GetModel().GetCategorieNamen().size(); ++i)
    AddString(GetModel().GetCategorieNamen()[i].Get().c_str());
}
