#pragma once

#include "Utilities/StrUtils.h"

namespace WW
{

  
class GerechtDefinitie
{
public:
                        GerechtDefinitie(const std::tstring & aName, double aPoints) : mName(aName), mPoints(aPoints) {}
  virtual               ~GerechtDefinitie() {}

  virtual std::tstring  GetName() const { return mName; }
  virtual double        GetPoints() const { return mPoints; }

private:
  std::tstring          mName;
  double                mPoints;
};


}
