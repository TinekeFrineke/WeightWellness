#pragma once

#include <list>
#include <vector>
#include "Entity.h"
#include "Utilities/Date.h"


namespace WW
{

class BonusPointsMap;
class Item;
class Model;
class PointsCalculator;


class Bonus
{
public:
  enum class INTENSITY { High, Medium, Low };

  Bonus(INTENSITY anIntensity, int aDuration, int aPoints)
    : mIntensity(anIntensity), mDuration(aDuration), mPoints(aPoints) {}
  Bonus(INTENSITY anIntensity, int aWeight, int aDuration, const BonusPointsMap & aMap)
    : mIntensity(anIntensity), mDuration(aDuration), mPoints(0) { Set(anIntensity, aWeight, aDuration, aMap); }

  void                      Set(INTENSITY anIntensity, int aDuration, int aPoints);
  void                      Set(INTENSITY anIntensity, int aWeight, int aDuration, const BonusPointsMap & aMap);

  INTENSITY                 GetIntensity() const  { return mIntensity; }
  int                       GetDuration() const   { return mDuration; }
  int                       GetPoints() const     { return mPoints; }

private:
  INTENSITY                 mIntensity;
  int                       mDuration;
  int                       mPoints;
};


class Day : public Entity<Day>
{
public:
                            Day(const Utils::Date & aDate);
                            ~Day();

  void                      Add(Item * anItem);
  void                      Remove(Item * anItem);

  void                      SetWeight(double aWeight)           { mWeight = aWeight; }
  void                      Add(const Bonus & aBonus)           { mBonuses.push_back(aBonus); }
  void                      SetFreeBonusPoints(double aPoints)  { mBonusPoints = aPoints; }

  double                    GetPoints() const;

  bool                      IsEmpty() const;

  const std::vector<WW::Item *> &
                            GetItems() const { return mItems; }
  std::vector<WW::Item *> & GetItems() { return mItems; }

  Utils::Date               GetDate() const         { return mDate; }
  double                    GetWeight() const       { return mWeight; }
  const std::list<WW::Bonus> &
                            GetBonuses() const { return mBonuses; }
  void                      SetBonuses(const std::list<WW::Bonus> & aBonuses);

  double                    GetCalculatedBonusPoints() const;
  double                    GetFreeBonusPoints() const  { return mBonusPoints; }
  double                    GetTotalBonusPoints() const  { return GetCalculatedBonusPoints() + GetFreeBonusPoints(); }

  // Recalculates the points for the items in the day
  void                      Recalculate(Model & aModel, const PointsCalculator & aCalculator);

  // Entity overrides
  virtual std::tstring      GetInstanceName() const           { return Utils::ToString(mDate); }
  static std::tstring       GetClassName()                    { return _T("Dag"); }

private:
  Day &                     operator=(const Day &);
                            Day(const Day &);

  Utils::Date               mDate;
  // 0 == no weight
  double                    mWeight;
  double                    mBonusPoints;
  std::vector<WW::Item *>   mItems;
  std::list<WW::Bonus>      mBonuses;
};


} // namespace WW
