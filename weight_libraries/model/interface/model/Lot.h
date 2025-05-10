#pragma once

#include "PointsCalculator.h"
#include "Portie.h"
#include "WWDefinitions.h"


namespace weight
{


class Lot
{
public:
    virtual ~Lot() = 0 {}

    virtual Portie GetPortie() const = 0;
    virtual double GetNumberOfPortions() const = 0;
    virtual FoodParameters GetParameters() const = 0;
    virtual double GetPointsPer100Units() const = 0;

    virtual void SetNumberOfPortions(double aNumber) = 0;

    virtual double GetPoints() const = 0;
};


class PortionedLot: public Lot
{
public:
    PortionedLot(std::shared_ptr<PointsCalculator> calculator, const Portie& aPortie)
        : mPortie(aPortie)
        , m_calculator(std::move(calculator))
    {}

    Portie GetPortie() const override { return mPortie; }
    double GetNumberOfPortions() const noexcept override { return mNumberOfPortions; }
    FoodParameters GetParameters() const noexcept override { return mParameters; }
    double GetPointsPer100Units() const override { return m_calculator->GetPointsPer100Units(mParameters); }
    double GetPoints() const override;

    void   SetNumberOfPortions(double aNumber) noexcept { mNumberOfPortions = aNumber; }

    double GetKCalPer100Units() const { return mParameters.GetKCalPer100Units(); }
    double GetVetPer100Units() const { return mParameters.GetVetPer100Units(); }
    double GetEiwitPer100Units() const { return mParameters.GetEiwitPer100Units(); }
    double GetKoolhydratenPer100Units() const { return mParameters.GetKoolhydratenPer100Units(); }
    double GetVezelsPer100Units() const { return mParameters.GetVezelsPer100Units(); }

    void SetParameters(const FoodParameters& aParameters) { mParameters = aParameters; }
    void SetKCalPer100Units(double aKCalPer100) { mParameters.SetKCalPer100Units(aKCalPer100); }
    void SetVetPer100Units(double aVetPer100) { mParameters.SetVetPer100Units(aVetPer100); }
    void SetEiwitPer100Units(double anEiwit) { mParameters.SetEiwitPer100Units(anEiwit); }
    void SetKoolhydratenPer100Units(double akh) { mParameters.SetKoolhydratenPer100Units(akh); }
    void SetVezelsPer100Units(double aVezels) { mParameters.SetVezelsPer100Units(aVezels); }

private:
    PortionedLot(const PortionedLot&);
    PortionedLot& operator=(const PortionedLot&);

    Portie mPortie;
    double mNumberOfPortions{ 1 };
    FoodParameters mParameters;
    std::shared_ptr<PointsCalculator> m_calculator;
};

} // namespace weight
