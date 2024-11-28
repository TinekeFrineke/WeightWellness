#pragma once

#include "WWDefinitions.h"


namespace weight
{

struct FoodParameters
{
public:
    FoodParameters(double aKCalPer100Units,
                   double anEiwitPer100Units,
                   double aVetPer100Units,
                   double aVezelsPer100Units,
                   double aKoolhydratenPer100Units)
        : mKCalPer100Units(aKCalPer100Units),
        mEiwitPer100Units(anEiwitPer100Units),
        mVetPer100Units(aVetPer100Units),
        mVezelsPer100Units(aVezelsPer100Units),
        mKoolhydratenPer100Units(aKoolhydratenPer100Units)
    {
    }


    FoodParameters()
        : mKCalPer100Units(0),
        mEiwitPer100Units(0),
        mVetPer100Units(0),
        mVezelsPer100Units(0),
        mKoolhydratenPer100Units(0)
    {
    }

    double                GetKCalPer100Units() const { return mKCalPer100Units; }
    double                GetEiwitPer100Units() const { return mEiwitPer100Units; }
    double                GetVetPer100Units() const { return mVetPer100Units; }
    double                GetVezelsPer100Units() const { return mVezelsPer100Units; }
    double                GetKoolhydratenPer100Units() const { return mKoolhydratenPer100Units; }

    void                  SetKCalPer100Units(double aKCal) { mKCalPer100Units = aKCal; }
    void                  SetEiwitPer100Units(double anEiwit) { mEiwitPer100Units = anEiwit; }
    void                  SetVetPer100Units(double aVet) { mVetPer100Units = aVet; }
    void                  SetVezelsPer100Units(double aVezels) { mVezelsPer100Units = aVezels; }
    void                  SetKoolhydratenPer100Units(double aKoolhydraten) { mKoolhydratenPer100Units = aKoolhydraten; }

private:
    double                mKCalPer100Units;
    double                mEiwitPer100Units;
    double                mVetPer100Units;
    double                mVezelsPer100Units;
    double                mKoolhydratenPer100Units;
};



class PointsCalculatorBase
{
public:
    PointsCalculatorBase() {}
    virtual               ~PointsCalculatorBase() = default;

    virtual double        GetPointsPer100Units(const FoodParameters& aParameters) const = 0;
};


class ProPointsCalculator: public PointsCalculatorBase
{
public:
    double                GetPointsPer100Units(const FoodParameters& aParameters) const;

private:
    static const double   mEiwittenFactor;
    static const double   mKoolhydratenFactor;
    static const double   mVettenFactor;
    static const double   mVezelFactor;
};


class FlexiPointsCalculator: public PointsCalculatorBase
{
public:
    double                GetPointsPer100Units(const FoodParameters& aParameters) const;
};


class KCalCalculator: public PointsCalculatorBase
{
public:
    double                GetPointsPer100Units(const FoodParameters& aParameters) const;

private:
};


class CarboHydratesCalculator: public PointsCalculatorBase
{
public:
    double                GetPointsPer100Units(const FoodParameters& aParameters) const;

private:
};


class PointsCalculator: public PointsCalculatorBase
{
public:
    PointsCalculator();
    virtual               ~PointsCalculator();

    virtual void          SetStrategy(STRATEGY_TYPE eStrategy);
    STRATEGY_TYPE         GetStrategy() const { return mStrategy; }

    virtual double        GetPointsPer100Units(const FoodParameters& aParameters) const;

private:
    PointsCalculator& operator=(const PointsCalculator& aCalculator);
    PointsCalculator(const PointsCalculator& aCalculator);

    PointsCalculatorBase* mImplementation;
    STRATEGY_TYPE         mStrategy;
};

} // namespace weight
