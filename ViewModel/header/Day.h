
#pragma once

#include "model/Day.h"

#include "IDay.h"

namespace weight {
class Model;
}


namespace viewmodel
{

class Day
    : public IDay
{
    Q_OBJECT
public:
    Day(std::shared_ptr < weight::Model> model, QObject* parent = nullptr);

private:
    std::shared_ptr<weight::Model> m_model;
};

} // namespace viewmodel
