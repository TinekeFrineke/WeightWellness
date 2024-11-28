#pragma once

#include "Utilities/StrUtils.h"


namespace weight
{

class Model;

class Unit
{
public:
                        Unit(Model & aModel, const std::tstring & aName);

  std::tstring          GetName() const { return mName; }

private:
  std::tstring          mName;
};


} // namespace weight


inline bool operator==(const weight::Unit & aUnit1, const weight::Unit & aUnit2)
{
  return aUnit1.GetName() == aUnit2.GetName();
}
