#include "stdafx.h"

#include <assert.h>
#include <tchar.h>
#include <windows.h>

#include "BonusPointsMap.h"

namespace WW
{


int PointsPerDuration::operator[](int aDuration) const
{
  int points = 0;
  for (BonusDurationList::const_iterator citer = mBonusDurations.begin();
    citer != mBonusDurations.end();
    ++citer)
  {
    while (aDuration >= citer->mDuration)
    {
      points    += citer->mPoints;
      aDuration -= citer->mDuration;
    }
  }

  return points;
}


int & PointsPerDuration::operator[](int aDuration)
{
  // Add points in reverse order of duration
  for (BonusDurationList::iterator iter = mBonusDurations.begin();
       iter != mBonusDurations.end();
       ++iter)
  {
    if (iter->mDuration > aDuration)
      continue;
    else if (iter->mDuration == aDuration)
      return iter->mPoints;
    else
      return mBonusDurations.insert(iter, BonusDuration(aDuration, 0))->mPoints;
  }

  return mBonusDurations.insert(mBonusDurations.end(), BonusDuration(aDuration, 0))->mPoints;
}


//void PointsPerDuration::Debug() const
//{
//  TCHAR smsg[1024];
//
//  // Add points in reverse order of duration
//  for (BonusDurationList::const_iterator iter = mBonusDurations.begin();
//       iter != mBonusDurations.end();
//       ++iter)
//  {
//    _stprintf(smsg, _T("      mDuration == %d mPoints == %d\n"), iter->mDuration, iter->mPoints);
//    OutputDebugString(smsg);
//  }
//}


bool PointsPerDurationAndWeight::IsEmpty() const
{
  return mBonusDurationWeights.empty();
}


const PointsPerDuration & PointsPerDurationAndWeight::operator[](int aWeight) const
{
  assert(!mBonusDurationWeights.empty());

  for (BonusDurationWeightList::const_iterator iter = mBonusDurationWeights.begin();
       iter != mBonusDurationWeights.end();
       ++iter)
  {
    if (iter->mWeight > aWeight)
      continue;
    else
      return iter->mPointsPerDuration;
  }

  return mBonusDurationWeights.begin()->mPointsPerDuration;
}


/*
// Calculates by adding values if necessary
int IntensityPoints::operator[](MOVEMENT_INTENSITY anIntensity) const
{
  IntensityPointsMap::const_iterator citer = mPointsMap.find(anIntensity);
  if (citer == mPointsMap.end())
    return 0;

  return citer->second;
}


// Adds element if necessary
int & IntensityPoints::operator[](MOVEMENT_INTENSITY anIntensity)
{
  return mPointsMap[anIntensity];
}
*/


PointsPerDuration & PointsPerDurationAndWeight::operator[](int aWeight)
{
  for (BonusDurationWeightList::iterator iter = mBonusDurationWeights.begin();
       iter != mBonusDurationWeights.end();
       ++iter)
  {
    // Maps are stored from large to small weight
    if (iter->mWeight > aWeight)
      continue;
    else if (iter->mWeight == aWeight)
      return iter->mPointsPerDuration;

    return mBonusDurationWeights.insert(iter, BonusDurationWeight(aWeight))->mPointsPerDuration;
  }

  return mBonusDurationWeights.insert(mBonusDurationWeights.end(), BonusDurationWeight(aWeight))->mPointsPerDuration;
}


//void PointsPerDurationAndWeight::Debug() const
//{
//  TCHAR smsg[1024];
//
//  for (BonusDurationWeightList::const_iterator iter = mBonusDurationWeights.begin();
//       iter != mBonusDurationWeights.end();
//       ++iter)
//    
//  {
//    _stprintf(smsg, _T("    mWeight == %d\n"), iter->mWeight);
//    OutputDebugString(smsg);
//    iter->mPointsPerDuration.Debug();
//  }
//}


bool BonusPointsMap::Has(MOVEMENT_INTENSITY anIntensity) const
{
  return mPointsMap.find(anIntensity) != mPointsMap.end();
}


bool BonusPointsMap::IsEmpty(MOVEMENT_INTENSITY anIntensity) const
{

  IntensityPointsMap::const_iterator citer = mPointsMap.find(anIntensity);
  if (citer == mPointsMap.end())
    return false;

  return citer->second.IsEmpty();
}


PointsPerDurationAndWeight & BonusPointsMap::operator[](MOVEMENT_INTENSITY anIntensity)
{
  return mPointsMap[anIntensity];
}


const PointsPerDurationAndWeight & BonusPointsMap::operator[](MOVEMENT_INTENSITY anIntensity) const
{
  IntensityPointsMap::const_iterator iter(mPointsMap.find(anIntensity));
  assert(mPointsMap.find(anIntensity) != mPointsMap.end());
  return iter->second;
}


//void BonusPointsMap::Debug() const
//{
//  TCHAR smsg[1024];
//
//  for (IntensityPointsMap::const_iterator iter = mPointsMap.begin();
//       iter != mPointsMap.end();
//       ++iter)
//  {
//    _stprintf(smsg, _T("  mIntensity == %s\n"), iter->first == MI_Low     ? _T("MI_Low")
//                                              : iter->first == MI_Medium  ? _T("MI_Medium")
//                                              :                             _T("MI_High"));
//    OutputDebugString(smsg);
//    iter->second.Debug();
//  }
//}


} // namespace WW
