
#pragma once

#include "model/Day.h"

#include "IViewModelDay.h"

namespace weight {
class Model;
}


namespace viewmodel
{


class FoodListModel;

class Day
    : public IViewModelDay
{
    Q_OBJECT
public:
    Day(std::shared_ptr < weight::Model> model, QObject* parent = nullptr);

    IFoodListModel* getFoodListModel() { return m_foodListmodel.get(); }

private:
    // Inherited via IViewModelDay
    void setDay(weight::Day* day) override;
    const weight::Day* getDay() const override;

    // m_model will disappear, just temporary
    std::shared_ptr<weight::Model> m_model;
    weight::Day* m_day{};

    // Inherited via IViewModelDay
    double weight() const override;
    void setWeight(double weight) override;

    double freeBonus() const override;
    void setFreeBonus(double bonus) override;

    double totalPointsSpent() const override;

    std::unique_ptr<IFoodListModel> m_foodListmodel;
};

} // namespace viewmodel
