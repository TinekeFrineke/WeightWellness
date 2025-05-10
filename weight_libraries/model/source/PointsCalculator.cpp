
#include "pointscalculator.h"

namespace weight
{

namespace {

int PointsCalculatorInstances = 0;

class KCalCalculator: public PointsCalculatorBase
{
public:
    double GetPointsPer100Units(const FoodParameters& aParameters) const override;
};


class CarboHydratesCalculator: public PointsCalculatorBase
{
public:
    double GetPointsPer100Units(const FoodParameters& aParameters) const override;

private:
};



}

PointsCalculator::PointsCalculator()
    : mImplementation(std::make_unique<KCalCalculator>())
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
