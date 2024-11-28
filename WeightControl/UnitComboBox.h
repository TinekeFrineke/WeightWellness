#pragma once

#include "afxcmn.h"
#include "Utilities/StrUtils.h"
#include "wwcombobox.h"

namespace weight
{
  class Model;
}

class UnitComboBox : public weight::ComboBox
{
public:
                              UnitComboBox(const weight::Model & aModel,
                                           const std::tstring & aUnitName);
  void                        AddLines();

	DECLARE_MESSAGE_MAP()
};
