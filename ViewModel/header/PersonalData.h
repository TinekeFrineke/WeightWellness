
#pragma once

#include "IPersonalData.h"

namespace weight {
class Model;
}


namespace viewmodel {


class PersonalData
    : public IPersonalData
{
public:
    PersonalData(std::shared_ptr<weight::Model> model, QObject* parent = nullptr);

private:
    std::shared_ptr<weight::Model> m_model;
};

} // namespace viewmodel
