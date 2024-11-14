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


/*
class IntensityPoints
{
public:
  enum MOVEMENT_INTENSITY { MI_Low, MI_Medium, MI_High };
  // Calculates by adding values if necessary
  int                 operator[](MOVEMENT_INTENSITY anIntensity) const;
  // Adds element if necessary
  int &               operator[](MOVEMENT_INTENSITY anIntensity);

private:
  typedef std::map<MOVEMENT_INTENSITY, int> IntensityPointsMap;

  IntensityPointsMap  mPointsMap;
};


class PointsPerDuration
{
public:

private:
  struct DurationIntensityPoints
  {
    int               mDuration;
    IntensityPoints   mIntensityPoints;
  };
};
*/

class PointsPerDurationAndWeight
{
public:
  bool                        IsEmpty() const;

  PointsPerDuration &         operator[](int aWeight);
  const PointsPerDuration &   operator[](int aWeight) const;

  //void                        Debug() const;

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
