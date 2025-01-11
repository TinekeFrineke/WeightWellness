
#pragma once

#include "model/Day.h"

#include "IViewModelDay.h"

namespace weight {
class Model;
}


namespace viewmodel
{

class Day
    : public IViewModelDay
{
    Q_OBJECT
public:
    Day(std::shared_ptr < weight::Model> model, QObject* parent = nullptr);

    // IViewModelDay
    void setDay(weight::Day* day) override;

private:
    std::shared_ptr<weight::Model> m_model;
    weight::Day* m_day{};
};

} // namespace viewmodel
