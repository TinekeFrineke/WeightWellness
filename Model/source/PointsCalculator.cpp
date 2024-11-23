
#include "pointscalculator.h"

namespace WW
{


static int PointsCalculatorInstances = 0;


PointsCalculator::PointsCalculator()
    : mImplementation(new FlexiPointsCalculator),
    mStrategy(STRATEGY_TYPE::KCal)
{
}


PointsCalculator::~PointsCalculator()
{
    delete mImplementation;
}


double PointsCalculator::GetPointsPer100Units(const FoodParameters& aParameters) const
{
    return mImplementation->GetPointsPer100Units(aParameters);
}


void PointsCalculator::SetStrategy(STRATEGY_TYPE eStrategy)
{
    delete mImplementation;

    switch (eStrategy) {
    case STRATEGY_TYPE::KCal:
        mImplementation = new KCalCalculator;
        break;
    case STRATEGY_TYPE::CarboHydrates:
        mImplementation = new CarboHydratesCalculator;
        break;
    default:
        throw 0;
    }

    mStrategy = eStrategy;
}


double FlexiPointsCalculator::GetPointsPer100Units(const FoodParameters& aParameters) const
{
    //algorithm points calculator:
    //points = calories / 60 * vet / 9.
    return (aParameters.GetKCalPer100Units() / 60.0) + (aParameters.GetVetPer100Units() / 9.0);
}


double KCalCalculator::GetPointsPer100Units(const FoodParameters& aParameters) const
{
    return aParameters.GetKCalPer100Units();
}


const double ProPointsCalculator::mEiwittenFactor = 0.09143;
const double ProPointsCalculator::mKoolhydratenFactor = 0.10857;
const double ProPointsCalculator::mVettenFactor = 0.25714;
const double ProPointsCalculator::mVezelFactor = 0.02857;


double ProPointsCalculator::GetPointsPer100Units(const FoodParameters& aParameters) const
{
    //algorithm points calculator:
    return mEiwittenFactor * aParameters.GetEiwitPer100Units() +
        mKoolhydratenFactor * aParameters.GetKoolhydratenPer100Units() +
        mVettenFactor * aParameters.GetVetPer100Units() +
        mVezelFactor * aParameters.GetVezelsPer100Units();
}


double CarboHydratesCalculator::GetPointsPer100Units(const FoodParameters& aParameters) const
{
    return aParameters.GetKoolhydratenPer100Units();
}

} // namespace WW
