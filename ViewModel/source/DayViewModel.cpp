
#include "DayViewModel.h"

#include "model/Day.h"
#include "model/Model.h"
#include "model/Personalia.h"
#include "model/Week.h"

namespace viewmodel {



Day::Day(weight::Model& model)
    : m_model(model)
    , m_currentDate(Utils::Date::Today())
    , m_currentWeek(model.FindWeek(m_currentDate))
{
    if (m_currentWeek == nullptr)
        m_currentWeek = model.CreateWeek(m_currentDate);

    if (m_currentWeek == nullptr)
        throw std::runtime_error("viewmodel::Day::Day: Unable to create week");

    m_currentDay = m_currentWeek->GetDay(m_currentDate);
    if (m_currentDay == nullptr)
        m_currentDay = m_currentWeek->AddDay(m_currentDate);
    if (m_currentDay == nullptr)
        throw std::runtime_error("viewmodel::Day::Day: Unable to create day");
}

void Day::SetDate(const Utils::Date& date)
{
    auto newWeek = m_model.FindWeek(date);
    if (newWeek == nullptr)
        newWeek = m_model.CreateWeek(date);

    auto notifyWeek = newWeek != m_currentWeek;
    m_currentWeek = newWeek;

    auto day = m_currentWeek->GetDay(date);
    if (day == nullptr)
        day = m_currentWeek->AddDay(date);

    auto notifyDay = day != m_currentDay;
}

void Day::SetBonuspunten(double points)
{
    m_currentDay->SetFreeBonusPoints(points);
}

void Day::AddFood()
{
}

void Day::AddManually()
{
}

void Day::AddRecipe()
{
}

void Day::Edit(const std::wstring& name)
{
}

void Day::Delete()
{
}

void Day::SubscribeDateChanged(const std::function<void(const Utils::Date&)>& callback)
{
}

void Day::SubscribePointsChanged(const std::function<void(double&)>& callback)
{
}

void Day::SubscribeStartOfWeekChanged(const std::function<void(const std::wstring&)>& callback)
{
}

void Day::SubscribeEndOfWeekChanged(const std::function<void(const std::wstring&)>& callback)
{
}

void Day::SubscribeBonusPointsChanged(const std::function<void(double)> callback)
{
}

void Day::SubscribeCalculatedBonusPointsChanged(const std::function<void(double)>& callback)
{
}

void Day::SubscribePointsLeftChanged(const std::function<void(double)>& callback)
{
}

void Day::SubscribeWeightChanged(const std::function<void(double)>& callback)
{
}

void Day::SubscribeTotalChanged(const std::function<void(double)>& callback)
{
}

void Day::SubscribeStragegyChanged(const std::function<void(const std::wstring&)>& callback)
{
}

void Day::SubscribeWeekPointsChanged(const std::function<void(double)>& callback)
{
}

} // namespace viewmodel
