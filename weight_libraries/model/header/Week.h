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

    ~Week() override;

    bool Add(std::unique_ptr<IDay> day) override;

    const std::vector<std::unique_ptr<IDay>>& GetDays() const override { return mDays; }

    IDay* GetDay(const Utils::Date& aDay) override;

    bool Includes(const Utils::Date& aDay) const override;

    Utils::Date GetStartDate() const override { return mStartDate; }
    Utils::Date GetEndDate() const override { return mEndDate; }
    double GetStartWeight() const override { return mStartWeight; }
    double GetPoints() const override { return mPoints; }
    double GetSaveablePoints() const override { return mSaveablePoints; }
    STRATEGY_TYPE GetStrategy() const override { return mStrategy; }

    bool SetEndDate(const Utils::Date& aDate) override;
    void SetPoints(double aPoints) override { mPoints = aPoints; }
    void SetSaveablePoints(double aPoints) override { mSaveablePoints = aPoints; }
    void SetStartWeight(double aWeight) override { mStartWeight = aWeight; }
    void SetStrategy(STRATEGY_TYPE eType, IModel& aModel) override;

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
