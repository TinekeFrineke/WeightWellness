
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


} // namespace viewmodel