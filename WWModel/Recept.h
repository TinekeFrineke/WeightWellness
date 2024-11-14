#pragma once

#include "Item.h"
#include "Portie.h"
#include "Voedingsmiddel.h"

namespace WW
{


class Recept : public Item
{
public:
                                Recept(const std::tstring & aName) : mName(aName) {}
  virtual                       ~Recept();

  virtual std::tstring          GetName() const                         { return mName; }
  virtual double                GetPoints() const;

  double                        GetNumberOfPortions() const             { return mNumberOfPortions; }
  double                        GetPointsPerPortion() const             { return mPointsPerPortion; }

  void                          SetNumberOfPortions(double aNumber)     { mNumberOfPortions = aNumber; }
  void                          SetPointsPerPortion(double aPunten)     { mPointsPerPortion = aPunten; }

  virtual void                  Accept(ItemVisitor & aVisitor);

private:
  std::tstring                  mName;
  double                        mNumberOfPortions;
  double                        mPointsPerPortion;
};


} // namespace WW
