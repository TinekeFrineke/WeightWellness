#pragma once

#include "Item.h"

namespace WW
{

  
class Gerecht : public Item
{
public:
                                Gerecht(const std::tstring & aName, double aPoints)
                                  : mName             (aName),
                                    mPointsPerPortion (aPoints)
                                {}
  virtual                       ~Gerecht() {}

  virtual std::tstring          GetName() const { return mName; }
  virtual double                GetPoints() const;

  virtual void                  Accept(ItemVisitor & aVisitor);

  double                        GetNumberOfPortions() const { return mNumberOfPortions; }
  double                        GetPointsPerPortion() const { return mPointsPerPortion; }

  void                          SetNumberOfPortions(double aNumber)  { mNumberOfPortions = aNumber; }
  void                          SetPointsPerPortie(double aPunten)   { mPointsPerPortion = aPunten; }

private:
  std::tstring                  mName;
  double                        mNumberOfPortions{ 1 };
  double                        mPointsPerPortion;
};


}
