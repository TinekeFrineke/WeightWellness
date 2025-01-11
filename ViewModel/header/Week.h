#pragma once

#include "IWeek.h"

namespace weight {
class Model;
}


namespace viewmodel {

class Week
    : public IWeek
{
public:
    Week(std::shared_ptr<weight::Model> model, QObject* parent = nullptr);

private:
    std::shared_ptr<weight::Model> m_model;
};


}