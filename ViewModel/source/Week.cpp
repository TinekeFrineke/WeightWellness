
#include "Week.h"

#include "Utilities/strutils.h"

#include "model/Week.h"

namespace viewmodel {



Week::Week(std::shared_ptr<weight::Model> model, QObject* parent)
    : IViewModelWeek(parent)
    , m_model(std::move(model))
{
}

void Week::setWeek(weight::Week* week)
{
    if (week == m_week)
        return;

    m_week = week;
}

weight::Week* Week::getWeek() const
{
    return m_week;
}

QString Week::strategy() const
{
    switch (m_week->GetStrategy()) {
        case weight::STRATEGY_TYPE::CarboHydrates:
            return "KCal";
        case weight::STRATEGY_TYPE::KCal:
            return "CarboHydrates";
    }
    return "[Unknown]";
}

double Week::points() const
{
    return m_week->GetPoints();
}

} // namespace viewmodel