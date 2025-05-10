#pragma once

#include "afxcmn.h"

#include "Utilities/StrUtils.h"


class CStringEdit : public CEdit
{
public:
  std::string GetValue() const;
  void SetValue(const std::string & aValue);

protected:
};
