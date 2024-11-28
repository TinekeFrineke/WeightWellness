
#include "Day.h"

#include <assert.h>

#include "Utilities/MathUtils.h"

#include "BonusPointsMap.h"
#include "Item.h"


namespace weight
{


void Bonus::Set(INTENSITY anIntensity, int aDuration, int aPoints)
{
    mIntensity = anIntensity;
    mDuration = aDuration;
    mPoints = aPoints;
}


void Bonus::Set(INTENSITY anIntensity, int aWeight, int aDuration, const BonusPointsMap& aMap)
{
    mIntensity = anIntensity;
    mDuration = aDuration;

    const BonusPointsMap::MOVEMENT_INTENSITY intensity = mIntensity == INTENSITY::High ? BonusPointsMap::MI_High :
        mIntensity == INTENSITY::Medium ? BonusPointsMap::MI_Medium :
        BonusPointsMap::MI_Low;
    mPoints = aMap[intensity][aWeight][mDuration];
}


Day::Day(const Utils::Date& aDate)
    : mDate(aDate),
    mWeight(0),
    mBonusPoints(0)
{
}


Day::~Day() = default;


bool Day::IsEmpty() const
{
    if (!mItems.empty())
        return false;

    return Math::Equals(GetTotalBonusPoints(), 0) && Math::Equals(mWeight, 0);
}


double Day::GetPoints() const
{
    double points = 0;
    for (auto& item : mItems)
        points += item->GetPoints();

    return points;
}


double Day::GetCalculatedBonusPoints() const
{
    double bp = 0;
    for (const auto& bonus : mBonuses)
        bp += bonus.GetPoints();

    return bp;
}


void Day::Add(std::unique_ptr<Item> anItem)
{
    assert(anItem != NULL);
    mItems.push_back(std::move(anItem));
}


void Day::Remove(Item* anItem)
{
    for (std::vector<std::unique_ptr<Item>>::iterator i = mItems.begin(); i != mItems.end(); ++i)
    {
        if (i->get() == anItem)
        {
            mItems.erase(i);
            return;
        }
    }
}


void Day::Recalculate(Model& aModel, const PointsCalculator& aCalculator)
{
    for (auto& item : mItems)
        item->Recalculate(aModel, aCalculator);
}


void Day::SetBonuses(const std::list<Bonus>& aBonuses)
{
    mBonuses = aBonuses;
}


} // namespace weight
