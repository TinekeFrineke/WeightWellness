#pragma once

#include "IViewModelWeek.h"

namespace weight {
class Model;
}


namespace viewmodel {

class Week
    : public IViewModelWeek
{
public:
    Week(std::shared_ptr<weight::Model> model, QObject* parent = nullptr);

private:
    std::shared_ptr<weight::Model> m_model;

    // Inherited via IViewModelWeek
    void setWeek(weight::Week* week) override;

private:
    weight::Week* m_week{};
};


}