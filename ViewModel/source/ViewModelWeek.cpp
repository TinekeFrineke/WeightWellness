
#include "ViewModelWeek.h"

#include "model/Day.h"
#include "model/Model.h"
#include "model/Personalia.h"
#include "model/Week.h"

#include "IDayInterface.h"

namespace viewmodel {



Week::Week(weight::Model& model, const Utils::Date& date, weight::Week* week,
           std::shared_ptr<Private::IDayInterface> day)
    : m_model(model)
    , m_date(date)
    , m_week(week)
    , m_day(std::move(day))
{
}

void Week::NextDay()
{
    auto newDate = m_date;
    newDate.AddDays(1);

    SetDate(newDate);
}

void Week::PreviousDay()
{
    auto newDate = m_date;
    newDate.SubtractDays(1);

    SetDate(newDate);
}

void Week::SetEndOfWeek(const Utils::Date& date)
{
    m_week->SetEndDate(date);
    auto oldDate(m_week->GetEndDate());
    if (m_date > date)
        SetDate(m_date);
}

int Week::SubscribeStrategyChanged(const std::function<void(Strategy)>& callback)
{
    return m_strategy.SubscribeCallback(callback);
}

int Week::SubscribeStartOfWeekChanged(const std::function<void(const Utils::Date& date)>& callback)
{
    return m_startOfWeek.SubscribeCallback(callback);
}

int Week::SubscribeEndOfWeekChanged(const std::function<void(const Utils::Date& date)>& callback)
{
    return m_endOfWeek.SubscribeCallback(callback);
}

int Week::SubscribePointsChanged(const std::function<void(double)>& callback)
{
    return m_points.SubscribeCallback(callback);
}

int Week::SubscribeWeekPointsChanged(const std::function<void(double)>& callback)
{
    return m_weekPoints.SubscribeCallback(callback);
}

void Week::SetDate(const Utils::Date& date)
{
    m_date = date;
    if (m_week == nullptr)
        m_week = m_model.CreateWeek(m_date);

    if (m_week == nullptr)
        throw std::runtime_error("viewmodel::Week::SetDate: Unable to create week");

    auto currentDay = m_week->GetDay(m_date);
    if (currentDay == nullptr)
        currentDay = m_week->AddDay(m_date);
    if (currentDay == nullptr)
        throw std::runtime_error("viewmodel::Week::SetDate: Unable to create day");

    m_day->SetDay(m_date, currentDay);
}

IWeek::Strategy Week::GetStrategy() const
{
    switch (m_model.GetStrategy()) {
        case weight::STRATEGY_TYPE::CarboHydrates:
            return Strategy::Carbs;
        case weight::STRATEGY_TYPE::KCal:
        default:
            return Strategy::KCal;
    }
}

Utils::Date Week::GetStartDate() const
{
    return m_week->GetStartDate();
}

Utils::Date Week::GetEndDate() const
{
    return m_week->GetEndDate();
}

double Week::GetPoints() const
{
    return m_week->GetPoints();
}

double Week::GetPointsLeft() const
{
    return m_week->GetPointsLeft(m_date);
}

double Week::GetWeekPointsLeft() const
{
    return m_week->GetWeekPointsLeft(m_date);
}

void Week::UnsubscribeStartOfWeekChanged(int handle)
{
    m_startOfWeek.UnsubscribeCallback(handle);
}

void Week::UnsubscribeEndOfWeekChanged(int handle)
{
    m_endOfWeek.UnsubscribeCallback(handle);
}

void Week::UnsubscribePointsChanged(int handle)
{
    m_points.UnsubscribeCallback(handle);
}

void Week::UnsubscribeWeekPointsChanged(int handle)
{
    m_weekPoints.UnsubscribeCallback(handle);
}

void Week::UnsubscribeStrategyChanged(int handle)
{
    m_strategy.UnsubscribeCallback(handle);
}


} // namespace viewmodel
