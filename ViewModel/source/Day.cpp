
#include "Day.h"

namespace viewmodel {


Day::Day(std::shared_ptr<weight::Model> model, QObject* parent)
    : IViewModelDay(parent)
    , m_model(std::move(model))
{
}

void Day::setDay(weight::Day* day)
{
    if (day == m_day)
        return;

    m_day = day;
    emit weightChanged(m_day->GetWeight());
}

const weight::Day* Day::getDay() const
{
    return m_day;
}

double Day::weight() const
{
    return m_day->GetWeight();
}

void Day::setWeight(double weight)
{
    m_day->SetWeight(weight);
}

double Day::freeBonus() const
{
    return m_day->GetFreeBonusPoints();
}

void Day::setFreeBonus(double bonus)
{
    m_day->SetFreeBonusPoints(bonus);
}

double Day::totalPointsSpent() const
{
    return m_day->GetPoints();
}


} // namespace viewmodel