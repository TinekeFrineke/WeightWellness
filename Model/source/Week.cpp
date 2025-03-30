
#include "Week.h"

#include <assert.h>

#include "Day.h"
#include "Model.h"
#include "ModelFactory.h"

#ifdef min
# undef min
#endif

#ifdef max
# undef max
#endif

namespace weight
{


Week::Week(const Utils::Date& aStartDate,
           const Utils::Date& aEndDate) noexcept
    : mStartDate(aStartDate)
    , mEndDate(aEndDate)
    , mStrategy(STRATEGY_TYPE::KCal)
{
}


Week::~Week() = default;


IDay* Week::GetDay(const Utils::Date& aDay)
{
    auto x = std::find_if(mDays.begin(), mDays.end(), [aDay] (const std::unique_ptr<IDay>& day) noexcept {
        return day->GetDate() == aDay;
    });
    if (x != mDays.end())
        return x->get();

    return nullptr;
}


bool Week::Add(std::unique_ptr<IDay> aDay)
{
    if (aDay->GetDate() < mStartDate || aDay->GetDate() > mEndDate)
        return false;

    auto dayIter = std::find_if(mDays.begin(), mDays.end(), [&aDay] (const std::unique_ptr<IDay>& day) noexcept {
        return day->GetDate() == aDay->GetDate();
    });
    if (dayIter != mDays.end())
        return false;

    mDays.push_back(std::move(aDay));
    return true;
}


bool Week::Includes(const Utils::Date& aDate) const
{
    return aDate >= mStartDate && aDate <= mEndDate;
}


double Week::GetPointsLeft(const Utils::Date& aDate)
{
    switch (mStrategy)
    {
        case STRATEGY_TYPE::KCal:
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


double Week::GetWeekPointsLeft(const Utils::Date& aDate)
{
    switch (mStrategy)
    {
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


void Week::SetStrategy(STRATEGY_TYPE eType, IModel& aModel)
{
    if (mStrategy == eType)
        return;

    mStrategy = eType;
    mPoints = aModel.GetPuntenTotaal(mStrategy);
    mSaveablePoints = aModel.GetWeekPuntenTotaal();
}


bool Week::SetEndDate(const Utils::Date& aDate)
{
    if (aDate < mStartDate)
        return false;

    int daysdifference;
    if (!mStartDate.DaysDifference(aDate, daysdifference))
        return false;

    if (daysdifference > 13)
        return false;

    mEndDate = aDate;
    return true;
}


} // namespace weight
