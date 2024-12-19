#pragma once

#include "IWeekInterface.h"

#include "Utilities/date.h"

#include "Value.h"

namespace weight {
class Day;
class Model;
class Week;
}


namespace Private {
class IDayInterface;
}

namespace viewmodel {


class IDay;

class Week :
    public Private::IWeekInterface
{
public:
    Week(weight::Model& model,
         const Utils::Date& date,
         weight::Week* week,
         std::shared_ptr<Private::IDayInterface> day);

    // Inherited via IWeek
    void NextDay() override;
    void PreviousDay() override;
    void SetEndOfWeek(const Utils::Date& date) override;

    Strategy GetStrategy() const override;
    Utils::Date GetStartDate() const override;
    Utils::Date GetEndDate() const override;
    double GetPoints() const override;
    double GetPointsLeft() const override;
    double GetWeekPointsLeft() const override;

    int SubscribeStrategyChanged(const std::function<void(Strategy)>& callback) override;
    int SubscribeStartOfWeekChanged(const std::function<void(const Utils::Date& date)>& callback) override;
    int SubscribeEndOfWeekChanged(const std::function<void(const Utils::Date& date)>& callback) override;
    int SubscribePointsChanged(const std::function<void(double)>& callback) override;
    int SubscribeWeekPointsChanged(const std::function<void(double)>& callback) override;

    void UnsubscribeStartOfWeekChanged(int handle) override;
    void UnsubscribeEndOfWeekChanged(int handle) override;
    void UnsubscribePointsChanged(int handle) override;
    void UnsubscribeWeekPointsChanged(int handle) override;
    void UnsubscribeStrategyChanged(int handle) override;

private:
    void SetDate(const Utils::Date& date);

    weight::Model& m_model;
    Utils::Date m_date;
    weight::Week* m_week{};

    Value<Strategy> m_strategy;
    Value<Utils::Date> m_startOfWeek;
    Value<Utils::Date> m_endOfWeek;
    Value<double> m_points;
    Value<double> m_weekPoints;

    std::shared_ptr<Private::IDayInterface> m_day;

    // Inherited via IWeekInterface
};


} // namespace viewmodel