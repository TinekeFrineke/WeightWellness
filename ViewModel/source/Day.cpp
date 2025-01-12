
#include "Day.h"

namespace viewmodel {


Day::Day(std::shared_ptr<weight::Model> model, QObject* parent)
    : IViewModelDay(parent)
    , m_model(std::move(model))
{
}

void Day::setDay(weight::Day* day)
{
    m_day = day;
}

void Day::itemChanged()
{
}

void Day::weightChanged(double newWeight)
{
    m_day->SetWeight(newWeight);
}

void Day::freeBonusChanged(double newValue)
{
    m_day->SetFreeBonusPoints(newValue);
}


} // namespace viewmodel