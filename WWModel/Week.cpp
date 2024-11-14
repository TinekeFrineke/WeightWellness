#include "stdafx.h"

#include "Week.h"

#include <assert.h>

#include "Day.h"
#include "WWModel.h"


namespace WW
{


Week::Week(const Utils::Date & aStartDate,
           const Utils::Date & aEndDate)
: mStartDate  (aStartDate),
  mEndDate    (aEndDate),
  mStrategy   (STRATEGY_TYPE::KCal)
{
}


Week::~Week()
{
  for (size_t i = 0; i < mDays.size(); ++i)
    delete mDays[i];
}


Day * Week::GetDay(const Utils::Date & aDay)
{
  for (size_t i = 0; i < mDays.size(); ++i)
    if (mDays[i]->GetDate() == aDay)
      return mDays[i];

  return NULL;
}


bool Week::Add(Day * aDay)
{
  if (aDay->GetDate() < mStartDate || aDay->GetDate() > mEndDate)
    return false;

  for (size_t i = 0; i < mDays.size(); ++i)
    if (mDays[i]->GetDate() == aDay->GetDate())
      return false;

  mDays.push_back(aDay);
  return true;
}


bool Week::Includes(const Utils::Date & aDate) const
{
  return aDate >= mStartDate && aDate <= mEndDate;
}


double Week::GetPointsLeft(const Utils::Date & aDate)
{
  switch (mStrategy)
  {
  case STRATEGY_TYPE::FlexiPoints:
    {
      double points = 0;

      for (size_t i = 0; i < mDays.size(); ++i)
      {
        if (mDays[i]->GetDate() == aDate)
        {
          points += GetPoints() - mDays[i]->GetPoints();
        }
        else if (!mDays[i]->GetItems().empty())
        {
          if (mDays[i]->GetDate() < aDate)
            points += std::min(GetPoints() - mDays[i]->GetPoints(), 4.0);
        }
      }

      return points;
    }
  case STRATEGY_TYPE::ProPoints:
    {
      for (size_t i = 0; i < mDays.size(); ++i)
      {
        if (mDays[i]->GetDate() == aDate)
            return GetPoints();
        return std::max(GetPoints() - mDays[i]->GetPoints(), 0.0);
      }

      return GetPoints();
    }
  case STRATEGY_TYPE::KCal:
    {
      for (size_t i = 0; i < mDays.size(); ++i)
      {
        if (mDays[i]->GetDate() == aDate)
          return std::max(GetPoints() - mDays[i]->GetPoints(), 0.0);
      }

      return GetPoints();
    }
  case STRATEGY_TYPE::CarboHydrates:
    {
      for (size_t i = 0; i < mDays.size(); ++i)
      {
        if (mDays[i]->GetDate() == aDate)
          return std::max(GetPoints() - mDays[i]->GetPoints(), 0.0);
      }

      return GetPoints();
    }
  default:
    assert(false);
    return 0;
  }
}


double Week::GetWeekPointsLeft(const Utils::Date & aDate)
{
  switch (mStrategy)
  {
    case STRATEGY_TYPE::ProPoints:
    {
      double weekpoints = 0;

      for (size_t i = 0; i < mDays.size(); ++i)
      {
        if (mDays[i]->GetDate() <= aDate)
        {
          weekpoints += GetSaveablePoints();
          weekpoints += mDays[i]->GetTotalBonusPoints();
          if (GetPoints() < mDays[i]->GetPoints())
            weekpoints -= mDays[i]->GetPoints() - GetPoints();
        }
      }

      int daysleft;
      mEndDate.DaysDifference(aDate, daysleft);
      weekpoints += daysleft * GetSaveablePoints();

      return weekpoints;
    }
    case STRATEGY_TYPE::KCal:
    case STRATEGY_TYPE::CarboHydrates:
    {
      double weekpoints = 0;

      for (size_t i = 0; i < mDays.size(); ++i)
      {
        if (mDays[i]->GetDate() <= aDate)
        {
          weekpoints += GetSaveablePoints();
          // This is sort of a hack: for bonus points, no implementation is available
          // except for the manual entry of points. These are added as is.
          weekpoints += mDays[i]->GetTotalBonusPoints();
          if (GetPoints() < mDays[i]->GetPoints())
            weekpoints -= mDays[i]->GetPoints() - GetPoints();
        }
      }

      int daysleft;
      mEndDate.DaysDifference(aDate, daysleft);
      weekpoints += daysleft * GetSaveablePoints();

      return weekpoints;
    }
    default:
    {
      return 0;
    }
  }
}


void Week::SetStrategy(STRATEGY_TYPE eType, Model & aModel)
{
  if (mStrategy == eType)
    return;

  mStrategy = eType;
  mPoints = aModel.GetPuntenTotaal(mStrategy);
  mSaveablePoints = aModel.GetWeekPuntenTotaal();
  Recalculate(aModel);
}


// Recalculates the points for the days in the week
void Week::Recalculate(Model & aModel)
{
  PointsCalculator calculator;
  calculator.SetStrategy(mStrategy);

  for (size_t i = 0; i < mDays.size(); ++i)
    mDays[i]->Recalculate(aModel, calculator);
}


bool Week::SetEndDate(const Utils::Date & aDate)
{
  if (aDate < mStartDate)
    return false;

  int daysdifference;
  if (!mStartDate.DaysDifference(aDate, daysdifference))
    return false;

  if (daysdifference < 1 || daysdifference > 13)
    return false;

  mEndDate = aDate;
  return true;
}


} // namespace WW
