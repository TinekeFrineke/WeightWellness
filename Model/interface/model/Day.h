#pragma once

#include <list>
#include <memory>
#include <vector>
#include "Entity.h"


namespace Utils {
class Date;
}

namespace weight
{

class BonusPointsMap;
class Item;
class Model;
class PointsCalculator;


class Bonus
{
public:
    enum class INTENSITY { High, Medium, Low };

    Bonus(INTENSITY anIntensity, int aDuration, int aPoints)
        : mIntensity(anIntensity), mDuration(aDuration), mPoints(aPoints) {}
    Bonus(INTENSITY anIntensity, int aWeight, int aDuration, const BonusPointsMap& aMap)
        : mIntensity(anIntensity), mDuration(aDuration), mPoints(0) {
        Set(anIntensity, aWeight, aDuration, aMap);
    }

    void Set(INTENSITY anIntensity, int aDuration, int aPoints);
    void Set(INTENSITY anIntensity, int aWeight, int aDuration, const BonusPointsMap& aMap);

    INTENSITY GetIntensity() const noexcept { return mIntensity; }
    int GetDuration() const noexcept { return mDuration; }
    int GetPoints() const noexcept { return mPoints; }

private:
    INTENSITY mIntensity;
    int mDuration;
    int mPoints;
};


class Day: public Entity<Day>
{
public:
    Day(const Utils::Date& aDate);
    ~Day();

    void                      Add(std::unique_ptr<Item> anItem);
    void                      Remove(Item* anItem);

    void                      SetWeight(double aWeight) noexcept { mWeight = aWeight; }
    void                      Add(const Bonus& aBonus) { mBonuses.push_back(aBonus); }
    void                      SetFreeBonusPoints(double aPoints) noexcept  { mBonusPoints = aPoints; }

    double                    GetPoints() const;

    bool                      IsEmpty() const;

    const std::vector<std::unique_ptr<Item>>& GetItems() const noexcept  { return mItems; }

    Utils::Date               GetDate() const noexcept;
    double                    GetWeight() const noexcept { return mWeight; }
    const std::list<Bonus>& GetBonuses() const noexcept { return mBonuses; }
    void                      SetBonuses(const std::list<Bonus>& aBonuses);

    double                    GetCalculatedBonusPoints() const;
    double                    GetFreeBonusPoints() const noexcept { return mBonusPoints; }
    double                    GetTotalBonusPoints() const { return GetCalculatedBonusPoints() + GetFreeBonusPoints(); }

    // Recalculates the points for the items in the day
    void                      Recalculate(Model& aModel, const PointsCalculator& aCalculator);

    // Entity overrides
    virtual std::wstring      GetInstanceName() const noexcept override;
    static std::wstring       GetClassName() { return L"Dag"; }

private:
    Day& operator=(const Day&) = delete;
    Day(const Day&) = delete;

    std::unique_ptr<Utils::Date> mDate;
    // 0 == no weight
    double                    mWeight;
    double                    mBonusPoints;
    std::vector<std::unique_ptr<Item>>   mItems;
    std::list<Bonus>        mBonuses;
};


} // namespace weight
