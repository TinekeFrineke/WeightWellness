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

    virtual void SetWeight(double weight) = 0;
    virtual void SetBonuspunten(double points) = 0;

    virtual Utils::Date GetDate() const = 0;
    virtual double GetWeight() const = 0;
    virtual double GetPointsSpent() const = 0;
    virtual double GetBonusPoints() const = 0;

    //virtual void AddFood() = 0;
    //virtual void AddManually() = 0;
    //virtual void AddRecipe() = 0;
    //virtual void Edit(const std::wstring& name) = 0;
    //virtual void Delete() = 0;

    virtual int SubscribeDateChanged(const std::function<void(const Utils::Date&)>& callback) = 0;
    virtual int SubscribeWeightChanged(const std::function<void(const double&)>& callback) = 0;
    virtual int SubscribePointsSpentChanged(const std::function<void(const double&)>& callback) = 0;
    virtual int SubscribeBonusPointsChanged(const std::function<void(const double&)> callback) = 0;

    virtual void UnsubscribeDateChanged(int handle) = 0;
    virtual void UnsubscribeWeightChanged(int handle) = 0;
    virtual void UnsubscribePointsSpentChanged(int handle) = 0;
    virtual void UnsubscribeBonusPointsChanged(int handle) = 0;
};

} // namespace viewmodel