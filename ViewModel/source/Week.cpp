
#include "Week.h"


namespace viewmodel {



Week::Week(std::shared_ptr<weight::Model> model, QObject* parent)
    : IWeek(parent)
    , m_model(std::move(model))
{
}

} // namespace viewmodel