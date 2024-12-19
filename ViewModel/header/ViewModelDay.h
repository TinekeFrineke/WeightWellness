#pragma once


#include "IDayInterface.h"
#include "IViewModelDay.h"

#include "Utilities/date.h"

#include "Value.h"

namespace weight {
class Day;
class Model;
class Week;
}

namespace viewmodel {


class Day
    : public Private::IDayInterface
{
public:
    Day(weight::Model& model);

    // Inherited via IDay
    virtual void SetBonuspunten(double points) override;
    virtual void SetWeight(double weight) override;
    //virtual void AddFood() override;
    //virtual void AddManually() override;
    //virtual void AddRecipe() override;
    //virtual void Edit(const std::wstring& name) override;
    //virtual void Delete() override;

    // Inherited via IDayInterface
    virtual Utils::Date GetDate() const override;
    virtual double GetWeight() const override;
    virtual double GetPointsSpent() const override;
    virtual double GetBonusPoints() const override;


    int SubscribeDateChanged(const std::function<void(const Utils::Date&)>& callback) override;
    int SubscribeWeightChanged(const std::function<void(const double&)>& callback) override;
    int SubscribeBonusPointsChanged(const std::function<void(const double&)> callback) override;
    int SubscribePointsSpentChanged(const std::function<void(const double&)>& callback) override;
    void UnsubscribeDateChanged(int handle) override;
    void UnsubscribeWeightChanged(int handle) override;
    void UnsubscribePointsSpentChanged(int handle) override;
    void UnsubscribeBonusPointsChanged(int handle) override;

    // Inherited via Private::IDay
    void SetDay(const Utils::Date& date, weight::Day* day) override;

private:

    void GetAll();

    weight::Model& m_model;
    Utils::Date m_currentDate;
    weight::Day* m_day;

    Value<Utils::Date> m_date;
    Value<double> m_weight;
    Value<double> m_bonusPoints;
    Value<double> m_pointsSpent;
};


} // namespace viewmodel