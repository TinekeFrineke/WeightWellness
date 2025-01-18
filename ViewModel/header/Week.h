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
    // Inherited via IViewModelWeek
    void setWeek(weight::Week* week) override;
    weight::Week* getWeek() const override;

    // Inherited via IViewModelWeek
    QString strategy() const override;
    double points() const override;

    // m_model will disappear, just temporary
    std::shared_ptr<weight::Model> m_model;
    weight::Week* m_week{};
};


}