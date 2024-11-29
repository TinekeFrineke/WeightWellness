#include "stdafx.h"

#include "CategoryComboBox.h"

#include <assert.h>

#include "model/Unit.h"
#include "model/Model.h"


CategoryComboBox::CategoryComboBox(const weight::Model & aModel, const std::tstring & anInitialCategory)
: weight::ComboBox(aModel, anInitialCategory)
{
}


void CategoryComboBox::AddLines()
{
  for (size_t i = 0; i < GetModel().GetCategorieNamen().size(); ++i)
    AddString(GetModel().GetCategorieNamen()[i].Get().c_str());
}
