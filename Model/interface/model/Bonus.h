#pragma once

#include <list>
#include <vector>
#include "Entity.h"
#include "Utilities/Date.h"

namespace weight
{

class BonusPointsMap;
//class Item;
//class Model;
//class PointsCalculator;
//
//
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

} // namespace weight
