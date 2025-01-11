
#include "PersonalData.h"


namespace viewmodel {



PersonalData::PersonalData(std::shared_ptr<weight::Model> model, QObject* parent)
    : IPersonalData(parent)
    , m_model(model)
{
}

} // namespace viewmodel