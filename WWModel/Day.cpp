#include "stdafx.h"

#include <assert.h>

#include "BonusPointsMap.h"
#include "Day.h"

#include "Utilities/MathUtils.h"

#include "Item.h"


namespace WW
{


void Bonus::Set(INTENSITY anIntensity, int aDuration, int aPoints)
{
  mIntensity = anIntensity;
  mDuration  = aDuration;
  mPoints    = aPoints;
}


void Bonus::Set(INTENSITY anIntensity, int aWeight, int aDuration, const BonusPointsMap & aMap)
{
  mIntensity  = anIntensity;
  mDuration   = aDuration;

  const BonusPointsMap::MOVEMENT_INTENSITY intensity = mIntensity == INTENSITY::High ?    BonusPointsMap::MI_High :
                                                       mIntensity == INTENSITY::Medium ?  BonusPointsMap::MI_Medium :
                                                                                          BonusPointsMap::MI_Low;
  mPoints = aMap[intensity][aWeight][mDuration];
}


Day::Day(const Utils::Date & aDate)
: mDate       (aDate),
  mWeight     (0),
  mBonusPoints(0)
{
}


Day::~Day()
{
  for (size_t i = 0; i < mItems.size(); ++i)
    delete mItems[i];
}


bool Day::IsEmpty() const
{
  if (!mItems.empty())
    return false;

  return Math::Equals(GetTotalBonusPoints(), 0) && Math::Equals(mWeight, 0);
}


double Day::GetPoints() const
{
  double points = 0;
  for (std::vector<Item *>::const_iterator i = mItems.begin(); i != mItems.end(); ++i)
    points += (*i)->GetPoints();

  return points;
}


double Day::GetCalculatedBonusPoints() const
{
  double bp = 0;
  for (std::list<WW::Bonus>::const_iterator citer = mBonuses.begin();
       citer != mBonuses.end();
       ++citer)
    bp += citer->GetPoints();

  return bp;
}


void Day::Add(Item * anItem)
{
  assert(anItem != NULL);
  mItems.push_back(anItem);
}


void Day::Remove(Item * anItem)
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


void Day::Recalculate(Model & aModel, const PointsCalculator & aCalculator)
{
  for (std::vector<Item *>::iterator iter = mItems.begin(); iter != mItems.end(); ++iter)
    (*iter)->Recalculate(aModel, aCalculator);
}


void Day::SetBonuses(const std::list<WW::Bonus> & aBonuses)
{
  mBonuses = aBonuses;
}


} // namespace WW
