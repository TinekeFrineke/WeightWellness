#pragma once

#include <list>
#include <map>


namespace WW
{
class PointsPerDuration
{
public:
  // Calculates by adding values if necessary
  int                         operator[](int aDuration) const;
  // Adds element if necessary
  int &                       operator[](int aDuration);

  //void                        Debug()const;

private:
  struct BonusDuration
  {
                              BonusDuration(int aDuration, int aPoints)
                                : mDuration(aDuration),
                                  mPoints(aPoints) {}

    int                       mDuration;
    int                       mPoints;
  };

  typedef std::list<BonusDuration> BonusDurationList;

  BonusDurationList   mBonusDurations;
};


class PointsPerDurationAndWeight
{
public:
  bool                        IsEmpty() const;

  PointsPerDuration &         operator[](int aWeight);
  const PointsPerDuration &   operator[](int aWeight) const;

private:
  struct BonusDurationWeight
  {
                              BonusDurationWeight(int aWeight) : mWeight(aWeight) {}

    PointsPerDuration         mPointsPerDuration;
    int                       mWeight;
  };

  typedef std::list<BonusDurationWeight> BonusDurationWeightList;

  BonusDurationWeightList     mBonusDurationWeights;
};

class BonusPointsMap
{
public:
  enum MOVEMENT_INTENSITY { MI_Low, MI_Medium, MI_High };

  bool                        Has(MOVEMENT_INTENSITY anIntensity) const;
  bool                        IsEmpty(MOVEMENT_INTENSITY anIntensity) const;

  PointsPerDurationAndWeight &operator[](MOVEMENT_INTENSITY anIntensity);
  const PointsPerDurationAndWeight &
                              operator[](MOVEMENT_INTENSITY anIntensity) const;

  //void                        Debug() const;

private:
  typedef std::map<MOVEMENT_INTENSITY, PointsPerDurationAndWeight> IntensityPointsMap;

  IntensityPointsMap          mPointsMap;
};

} // namespace WW
