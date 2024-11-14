#pragma once

#include "Utilities/StrUtils.h"


namespace WW
{

class Model;

class Unit
{
public:
                        Unit(WW::Model & aModel, const std::tstring & aName);

  std::tstring          GetName() const { return mName; }

private:
  std::tstring          mName;
};


} // namespace WW


inline bool operator==(const WW::Unit & aUnit1, const WW::Unit & aUnit2)
{
  return aUnit1.GetName() == aUnit2.GetName();
}
