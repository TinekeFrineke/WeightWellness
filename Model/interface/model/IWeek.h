#pragma once

#include <memory>
//#include <vector>
//#include "Utilities/Date.h"
//
//#include "PointsCalculator.h"
#include "WWDefinitions.h"


namespace Utils {
class Date;
}

namespace weight
{


class IDay;
class IModel;

class IWeek
{
public:
    virtual ~IWeek() = default;

    virtual bool Add(std::unique_ptr<IDay> day) = 0;

    virtual const std::vector<std::unique_ptr<IDay>>& GetDays() const = 0;

    virtual IDay* GetDay(const Utils::Date& aDay) = 0;

    virtual bool Includes(const Utils::Date& aDay) const = 0;

    virtual Utils::Date GetStartDate() const = 0;
    virtual Utils::Date GetEndDate() const = 0;
    virtual double GetStartWeight() const = 0;
    virtual double GetPoints() const = 0;
    virtual double GetSaveablePoints() const = 0;
    virtual STRATEGY_TYPE GetStrategy() const = 0;

    virtual bool SetEndDate(const Utils::Date& aDate) = 0;
    virtual void SetPoints(double aPoints) = 0;
    virtual void SetSaveablePoints(double aPoints) = 0;
    virtual void SetStartWeight(double aWeight) = 0;
    virtual void SetStrategy(STRATEGY_TYPE eType, IModel& aModel) = 0;

    virtual double GetPointsLeft(const Utils::Date& aDate) = 0;
    virtual double GetWeekPointsLeft(const Utils::Date& aDate) = 0;
};


} // namespace weight
