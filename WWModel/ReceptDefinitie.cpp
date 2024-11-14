#include "stdafx.h"

#include "ReceptDefinitie.h"


namespace WW
{


ReceptDefinitie::~ReceptDefinitie()
{
  for (size_t i = 0; i < mItems.size(); ++i)
    delete mItems[i];
}


double ReceptDefinitie::GetPointsPerPortion() const
{
  if (mPorties == 0)
    return 0;

  double points = 0;
  double fixedpoints = 0;
  for (size_t i = 0; i < mItems.size(); ++i)
  {
    if (mItems[i]->IsFreePortion())
      fixedpoints += mItems[i]->GetPoints();
    else
      points += mItems[i]->GetPoints();
  }

  return (points / (double)mPorties) + fixedpoints;
}


void ReceptDefinitie::Add(Item * anItem)
{
  mItems.push_back(anItem);
}


void ReceptDefinitie::Remove(Item * anItem)
{
  for (std::vector<Item *>::iterator i = mItems.begin(); i != mItems.end(); ++i)
  {
    if (*i == anItem)
    {
      delete *i;
      mItems.erase(i);
      return;
    }
  }
}


} // namespace WW
