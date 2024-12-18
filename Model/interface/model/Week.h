#pragma once

#include <vector>
#include "Utilities/Date.h"

#include "PointsCalculator.h"
#include "WWDefinitions.h"


namespace weight
{


class Day;
class Model;

class Week
{
public:
    Week(const Utils::Date& aStartDate,
         const Utils::Date& aEndDate) noexcept;

    ~Week();

    Day* AddDay(const Utils::Date& date);
    bool Add(std::unique_ptr<Day> day);

    const std::vector<std::unique_ptr<Day>>& GetDays() const { return mDays; }

    Day* GetDay(const Utils::Date& aDay);

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
    void SetStrategy(STRATEGY_TYPE eType, Model& aModel);

    double GetPointsLeft(const Utils::Date& aDate);
    double GetWeekPointsLeft(const Utils::Date& aDate);

    // Recalculates the points for the days in the week
    void Recalculate(Model& aModel);

private:
    friend class Model;

    std::vector<std::unique_ptr<Day>> mDays;
    Utils::Date mStartDate;
    Utils::Date mEndDate;
    double mStartWeight;
    double mPoints;
    double mSaveablePoints;
    STRATEGY_TYPE mStrategy;
};


} // namespace weight
