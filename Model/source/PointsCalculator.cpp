
#include "pointscalculator.h"

namespace weight
{


static int PointsCalculatorInstances = 0;


PointsCalculator::PointsCalculator()
    : mImplementation(std::make_unique<KCalCalculator>())
    , mStrategy(STRATEGY_TYPE::KCal)
{
}


PointsCalculator::~PointsCalculator() = default;


double PointsCalculator::GetPointsPer100Units(const FoodParameters& aParameters) const
{
    return mImplementation->GetPointsPer100Units(aParameters);
}


void PointsCalculator::SetStrategy(STRATEGY_TYPE eStrategy)
{
    switch (eStrategy) {
        case STRATEGY_TYPE::KCal:
            mImplementation = std::make_unique<KCalCalculator>();
            break;
        case STRATEGY_TYPE::CarboHydrates:
            mImplementation = std::make_unique<CarboHydratesCalculator>();
            break;
        default:
            throw 0;
    }

    mStrategy = eStrategy;
}


double KCalCalculator::GetPointsPer100Units(const FoodParameters& aParameters) const
{
    return aParameters.GetKCalPer100Units();
}


double CarboHydratesCalculator::GetPointsPer100Units(const FoodParameters& aParameters) const
{
    return aParameters.GetKoolhydratenPer100Units();
}

} // namespace weight
