
#pragma once

#include <list>
#include <memory>
#include <vector>

namespace Utils {
class Date;
}

namespace weight {

class Bonus;
class Item;

class IDay
{
public:
    virtual ~IDay() = default;

    virtual void Add(std::unique_ptr<Item> anItem) = 0;
    virtual void Remove(Item* anItem) = 0;

    virtual void SetWeight(double aWeight) noexcept = 0;
    //void                      Add(const Bonus& aBonus) { mBonuses.push_back(aBonus); }
    virtual void SetFreeBonusPoints(double aPoints) noexcept = 0;

    virtual double GetPoints() const = 0;

    //bool                      IsEmpty() const;

    virtual const std::vector<std::unique_ptr<Item>>& GetItems() const noexcept = 0;

    virtual Utils::Date GetDate() const noexcept = 0;
    virtual double GetWeight() const noexcept = 0;
    //const std::list<Bonus>& GetBonuses() const noexcept { return mBonuses; }
    virtual void SetBonuses(const std::list<Bonus>& aBonuses) = 0;

    virtual double GetCalculatedBonusPoints() const = 0;
    virtual double GetFreeBonusPoints() const noexcept = 0;
    //double                    GetTotalBonusPoints() const { return GetCalculatedBonusPoints() + GetFreeBonusPoints(); }

    //// Recalculates the points for the items in the day
    //void                      Recalculate(Model& aModel, const PointsCalculator& aCalculator);
};

} // namespace weight