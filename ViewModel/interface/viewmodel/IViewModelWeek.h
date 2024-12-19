#pragma once

#include <functional>

namespace Utils
{
class Date;
}

namespace viewmodel {

class IWeek
{
public:
    enum class Strategy { KCal, Carbs };

    virtual ~IWeek() = default;

    virtual void NextDay() = 0;
    virtual void PreviousDay() = 0;
    virtual void SetEndOfWeek(const Utils::Date& date) = 0;

    virtual Strategy GetStrategy() const = 0;
    virtual Utils::Date GetStartDate() const = 0;
    virtual Utils::Date GetEndDate() const = 0;
    // These are the reserved points as present in the profile page, stored for the week
    virtual double GetPoints() const = 0; // Per day
    // These are the points left from these
    virtual double GetPointsLeft() const = 0;
    virtual double GetWeekPointsLeft() const = 0;

    virtual int SubscribeStartOfWeekChanged(const std::function<void(const Utils::Date& date)>& callback) = 0;
    virtual int SubscribeEndOfWeekChanged(const std::function<void(const Utils::Date& date)>& callback) = 0;
    virtual int SubscribePointsChanged(const std::function<void(double)>& callback) = 0;
    virtual int SubscribeWeekPointsChanged(const std::function<void(double)>& callback) = 0;
    virtual int SubscribeStrategyChanged(const std::function<void(Strategy)>& callback) = 0;

    virtual void UnsubscribeStartOfWeekChanged(int handle) = 0;
    virtual void UnsubscribeEndOfWeekChanged(int handle) = 0;
    virtual void UnsubscribePointsChanged(int handle) = 0;
    virtual void UnsubscribeWeekPointsChanged(int handle) = 0;
    virtual void UnsubscribeStrategyChanged(int handle) = 0;
};

} // namespace viewmodel