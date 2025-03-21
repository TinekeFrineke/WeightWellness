#pragma once

#include <list>
#include <vector>
#include "Entity.h"
#include "Utilities/Date.h"

#include "IDay.h"


namespace weight
{

class Bonus;
class BonusPointsMap;
class Item;
class IModel;
class PointsCalculator;


class Day
    : public Entity<Day>
    , public IDay
{
public:
    explicit Day(const Utils::Date& aDate);
    ~Day() override;

    void                      Add(std::unique_ptr<Item> anItem);
    void                      Remove(Item* anItem);

    void                      SetWeight(double aWeight) noexcept override { mWeight = aWeight; }
    void                      Add(const Bonus& aBonus);
    void                      SetFreeBonusPoints(double aPoints) noexcept override { mBonusPoints = aPoints; }

    double                    GetPoints() const override;

    bool                      IsEmpty() const override;

    const std::vector<std::unique_ptr<Item>>& GetItems() const noexcept override { return mItems; }

    Utils::Date               GetDate() const noexcept override { return mDate; }
    double                    GetWeight() const noexcept override { return mWeight; }
    const std::list<Bonus>& GetBonuses() const noexcept override { return mBonuses; }
    void                      SetBonuses(const std::list<Bonus>& aBonuses) override;

    double                    GetCalculatedBonusPoints() const override;
    double                    GetFreeBonusPoints() const noexcept override { return mBonusPoints; }
    double                    GetTotalBonusPoints() const override { return GetCalculatedBonusPoints() + GetFreeBonusPoints(); }

    // Entity overrides
    std::wstring      GetInstanceName() const override { return Utils::ToString(mDate); }
    static std::tstring       GetClassName() { return _T("Dag"); }

private:
    Day& operator=(const Day&) = delete;
    Day(const Day&) = delete;

    Utils::Date               mDate;
    // 0 == no weight
    double                    mWeight;
    double                    mBonusPoints;
    std::vector<std::unique_ptr<Item>>   mItems;
    std::list<Bonus>      mBonuses;
};


} // namespace weight
