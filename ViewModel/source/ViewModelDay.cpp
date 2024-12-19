
#include "ViewModelDay.h"

#include "model/Day.h"
#include "model/Model.h"
#include "model/Personalia.h"
#include "model/Week.h"

namespace viewmodel {



Day::Day(weight::Model& model)
    : m_model(model)
    , m_currentDate(Utils::Date::Today())
{
}

void Day::SetBonuspunten(double points)
{
    m_day->SetFreeBonusPoints(points);
}

//void Day::AddFood()
//{
//}
//
//void Day::AddManually()
//{
//}
//
//void Day::AddRecipe()
//{
//}
//
//void Day::Edit(const std::wstring& name)
//{
//}
//
//void Day::Delete()
//{
//}

int Day::SubscribeDateChanged(const std::function<void(const Utils::Date&)>& callback)
{
    return m_date.SubscribeCallback(callback);
}

int Day::SubscribeBonusPointsChanged(const std::function<void(const double&)> callback)
{
    return m_bonusPoints.SubscribeCallback(callback);
}

int Day::SubscribePointsSpentChanged(const std::function<void(const double&)>& callback)
{
    return m_pointsSpent.SubscribeCallback(callback);
}

int Day::SubscribeWeightChanged(const std::function<void(const double&)>& callback)
{
    return m_weight.SubscribeCallback(callback);
}

void Day::SetDay(const Utils::Date& date, weight::Day* day)
{
    m_currentDate = date;
    m_day = day;
}

void Day::GetAll()
{
    if (m_day == nullptr)
        throw std::runtime_error("Day not set!");

    m_bonusPoints.SetValue(m_day->GetFreeBonusPoints());
    m_date.SetValue(m_currentDate);
    m_pointsSpent.SetValue(m_day->GetPoints());
    m_weight.SetValue(m_day->GetWeight());
}

} // namespace viewmodel
