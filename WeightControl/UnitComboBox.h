#pragma once

#include "afxcmn.h"
#include "Utilities/StrUtils.h"
#include "wwcombobox.h"

namespace WW
{
  class Model;
}

class UnitComboBox : public WW::ComboBox
{
public:
                              UnitComboBox(const WW::Model & aModel,
                                           const std::tstring & aUnitName);
  void                        AddLines();

	DECLARE_MESSAGE_MAP()
};
