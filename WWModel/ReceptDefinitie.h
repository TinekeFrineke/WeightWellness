#pragma once

#include "Portie.h"
#include "Voedingsmiddel.h"

namespace WW
{


class ReceptDefinitie
{
public:
                                ReceptDefinitie(const std::tstring & aName) : mName(aName) {}
  virtual                       ~ReceptDefinitie();

  virtual std::tstring          GetName() const { return mName; }
  virtual double                GetPointsPerPortion() const;
  int                           GetPortions() const { return mPorties; }

  void                          SetPortions(int aPorties) { mPorties = aPorties; }
  void                          Add(Item * anItem);
  void                          Remove(Item * anItem);

  std::vector<Item *> &         GetItems()       { return mItems; }
  const std::vector<Item *> &   GetItems() const { return mItems; }


private:
  std::tstring                  mName;
  std::vector<Item *>           mItems;
  int                           mPorties;
};


} // namespace WW
