
#include "Bonus.h"

//#include <assert.h>
//
//#include "Utilities/MathUtils.h"
//
#include "BonusPointsMap.h"
//#include "Item.h"


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

    const BonusPointsMap::MOVEMENT_INTENSITY intensity = mIntensity == INTENSITY::High ? BonusPointsMap::MOVEMENT_INTENSITY::MI_High :
        mIntensity == INTENSITY::Medium ? BonusPointsMap::MOVEMENT_INTENSITY::MI_Medium :
        BonusPointsMap::MOVEMENT_INTENSITY::MI_Low;
    mPoints = aMap[intensity][aWeight][mDuration];
}
} // namespace weight
