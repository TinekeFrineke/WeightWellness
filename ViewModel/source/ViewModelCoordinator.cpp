
#include "ViewModelCoordinator.h"

#include <Utilities/date.h>

#include "model/Model.h"

#include "factories/IViewModelFactory.h"

#include "ViewModelDay.h"
#include "ViewModelWeek.h"

namespace viewmodel {




Coordinator::Coordinator(weight::Model& model, std::unique_ptr<factory::IViewModelFactory> factory)
    : m_model(model)
    , m_factory(std::move(factory))
{
    m_date = Utils::Date::Today();
    auto week = m_model.FindWeek(m_date);
}

Coordinator::~Coordinator() = default;

void Coordinator::NextDay()
{
    Utils::Date date(m_date);
    date.AddDays(1);
    SetDate(date);
}

void Coordinator::PreviousDay()
{
    Utils::Date date(m_date);
    date.SubtractDays(1);
    SetDate(date);
}

void Coordinator::SetEndOfWeek(const Utils::Date& date)
{
}

void Coordinator::SetDate(const Utils::Date& date)
{
    //if (m_week == nullptr)
    //    m_week = m_model.CreateWeek(m_date);

    //if (m_week == nullptr)
    //    throw std::runtime_error("viewmodel::Week::SetDate: Unable to create week");

    //auto currentDay = m_week->GetDay(m_date);
    //if (currentDay == nullptr)
    //    currentDay = m_week->AddDay(m_date);
    //if (currentDay == nullptr)
    //    throw std::runtime_error("viewmodel::Week::SetDate: Unable to create day");

    //m_day->SetDay(m_date, currentDay);
    //m_date = date;
}

} // namespace viewmodel