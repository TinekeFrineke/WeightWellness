#pragma once


#include "IDayViewModel.h"

#include "Utilities/date.h"

#include "Value.h"

namespace weight {
class Day;
class Model;
class Week;
}

namespace viewmodel {


class Day :
    public IDay
{
public:
    Day(weight::Model& model);

    // Inherited via IDiaryPage
    virtual void SetDate(const Utils::Date& date) override;
    virtual void SetBonuspunten(double points) override;
    virtual void SetWeight(double weight) override;
    virtual void SetEndOfWeek(const Utils::Date& date) = 0;
    virtual void AddFood() override;
    virtual void AddManually() override;
    virtual void AddRecipe() override;
    virtual void Edit(const std::wstring& name) override;
    virtual void Delete() override;

    virtual void SubscribeDateChanged(const std::function<void(const Utils::Date&)>& callback) override;
    virtual void SubscribePointsChanged(const std::function<void(double&)>& callback) override;
    virtual void SubscribeStartOfWeekChanged(const std::function<void(const std::wstring&)>& callback) override;
    virtual void SubscribeEndOfWeekChanged(const std::function<void(const std::wstring&)>& callback) override;
    virtual void SubscribeBonusPointsChanged(const std::function<void(double)> callback) override;
    virtual void SubscribeCalculatedBonusPointsChanged(const std::function<void(double)>& callback) override;
    virtual void SubscribePointsLeftChanged(const std::function<void(double)>& callback) override;
    virtual void SubscribeWeightChanged(const std::function<void(double)>& callback) override;
    virtual void SubscribeTotalChanged(const std::function<void(double)>& callback) override;
    virtual void SubscribeStragegyChanged(const std::function<void(const std::wstring&)>& callback) override;
    virtual void SubscribeWeekPointsChanged(const std::function<void(double)>& callback) override;


private:
    weight::Model& m_model;
    Utils::Date m_currentDate;
    weight::Week* m_currentWeek;
    weight::Day* m_currentDay;

    //Value<Utils::Date> m_date;
    //Value<Utils::Date> m_startOfWeek;
    //Value<Utils::Date> m_endOfWeek;
    //Value<double> m_points;
};


} // namespace viewmodel