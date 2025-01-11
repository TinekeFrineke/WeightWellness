
#include "Week.h"


namespace viewmodel {



Week::Week(std::shared_ptr<weight::Model> model, QObject* parent)
    : IViewModelWeek(parent)
    , m_model(std::move(model))
{
}

void Week::setWeek(weight::Week* week)
{
    m_week = week;
}

} // namespace viewmodel