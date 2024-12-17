#pragma once
#include <functional>

namespace Utils
{
class Date;
}

namespace viewmodel {

class IDay
{
public:
    virtual ~IDay() = default;

    virtual void SetDate(const Utils::Date& date) = 0;
    virtual void SetBonuspunten(double points) = 0;
    virtual void SetWeight(double weight) = 0;
    virtual void SetEndOfWeek(const Utils::Date& date) = 0;

    virtual void AddFood() = 0;
    virtual void AddManually() = 0;
    virtual void AddRecipe() = 0;
    virtual void Edit(const std::wstring& name) = 0;
    virtual void Delete() = 0;

    virtual void SubscribeDateChanged(const std::function<void(const Utils::Date&)>& callback) = 0;
    virtual void SubscribePointsChanged(const std::function<void(double&)>& callback) = 0;
    virtual void SubscribeStartOfWeekChanged(const std::function<void(const std::wstring&)>& callback) = 0;
    virtual void SubscribeEndOfWeekChanged(const std::function<void(const std::wstring&)>& callback) = 0;
    virtual void SubscribeBonusPointsChanged(const std::function<void(double)> callback) = 0;
    virtual void SubscribeCalculatedBonusPointsChanged(const std::function<void(double)>& callback) = 0;
    virtual void SubscribePointsLeftChanged(const std::function<void(double)>& callback) = 0;
    virtual void SubscribeWeightChanged(const std::function<void(double)>& callback) = 0;
    virtual void SubscribeTotalChanged(const std::function<void(double)>& callback) = 0;
    virtual void SubscribeStragegyChanged(const std::function<void(const std::wstring&)>& callback) = 0;
    virtual void SubscribeWeekPointsChanged(const std::function<void(double)>& callback) = 0;

};

} // namespace viewmodel