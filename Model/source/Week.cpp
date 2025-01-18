
#include "Week.h"

#include <assert.h>

#include "Day.h"
#include "Model.h"
#include "Personalia.h"

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


Day* Week::GetDay(const Utils::Date& aDay)
{
    auto day = std::find_if(mDays.begin(), mDays.end(), [aDay] (const std::unique_ptr<Day>& day) noexcept {
        return day->GetDate() == aDay;
    });
    if (day != mDays.end())
        return day->get();

    return nullptr;
}


Day* Week::AddDay(const Model& model, const Utils::Date& date)
{
    if (date < mStartDate || date > mEndDate)
        return nullptr;

    auto dayIter = std::find_if(mDays.begin(), mDays.end(), [date] (const std::unique_ptr<Day>& day) noexcept {
        return day->GetDate() == date;
    });
    if (dayIter != mDays.end())
        return dayIter->get();

    auto newDay = std::make_unique<Day>(date);
    newDay->SetWeight(model.GetActivePersonalia()->GetHuidigGewicht());

    auto dayPtr = newDay.get();
    if (Add(std::move(newDay)))
        return dayPtr;

    return nullptr;
}

bool Week::Add(std::unique_ptr<Day> aDay)
{
    if (aDay->GetDate() < mStartDate || aDay->GetDate() > mEndDate)
        return false;

    auto dayIter = std::find_if(mDays.begin(), mDays.end(), [&aDay] (const std::unique_ptr<Day>& day) noexcept {
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
                    const auto points(GetPoints());
                    const auto dayPoints(mDays[i]->GetPoints());
                    if (points < dayPoints)
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


void Week::SetStrategy(STRATEGY_TYPE eType, Model& aModel)
{
    if (mStrategy == eType)
        return;

    mStrategy = eType;
    mPoints = aModel.GetPuntenTotaal(mStrategy);
    mSaveablePoints = aModel.GetWeekPuntenTotaal();
    Recalculate(aModel);
}


// Recalculates the points for the days in the week
void Week::Recalculate(Model& aModel)
{
    PointsCalculator calculator;
    calculator.SetStrategy(mStrategy);

    for (size_t i = 0; i < mDays.size(); ++i)
        mDays[i]->Recalculate(aModel, calculator);
}


bool Week::SetEndDate(const Utils::Date& aDate)
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


} // namespace weight
