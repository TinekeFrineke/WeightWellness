#pragma once

#include <vector>

#include "Utilities/Date.h"

#include "IWeek.h"
#include "PointsCalculator.h"
#include "WWDefinitions.h"


namespace weight
{


class IDay;
class IModel;

class Week
    : public IWeek
{
public:
    Week(const Utils::Date& aStartDate,
         const Utils::Date& aEndDate) noexcept;

    ~Week();

    IDay* AddDay(const Utils::Date& date);
    bool Add(std::unique_ptr<IDay> day);

    const std::vector<std::unique_ptr<IDay>>& GetDays() const { return mDays; }

    IDay* GetDay(const Utils::Date& aDay);

    bool Includes(const Utils::Date& aDay) const;

    Utils::Date GetStartDate() const { return mStartDate; }
    Utils::Date GetEndDate() const { return mEndDate; }
    double GetStartWeight() const { return mStartWeight; }
    double GetPoints() const { return mPoints; }
    double GetSaveablePoints() const { return mSaveablePoints; }
    STRATEGY_TYPE GetStrategy() const { return mStrategy; }

    bool SetEndDate(const Utils::Date& aDate);
    void SetPoints(double aPoints) { mPoints = aPoints; }
    void SetSaveablePoints(double aPoints) { mSaveablePoints = aPoints; }
    void SetStartWeight(double aWeight) { mStartWeight = aWeight; }
    void SetStrategy(STRATEGY_TYPE eType, IModel& aModel);

    double GetPointsLeft(const Utils::Date& aDate);
    double GetWeekPointsLeft(const Utils::Date& aDate);

private:
    std::vector<std::unique_ptr<IDay>> mDays;
    Utils::Date mStartDate;
    Utils::Date mEndDate;
    double mStartWeight;
    double mPoints;
    double mSaveablePoints;
    STRATEGY_TYPE mStrategy;
};


} // namespace weight
