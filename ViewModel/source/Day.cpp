
#include "Day.h"

namespace viewmodel {


Day::Day(std::shared_ptr<weight::Model> model, QObject* parent)
    : IDay(parent)
    , m_model(std::move(model))
{
}


} // namespace viewmodel