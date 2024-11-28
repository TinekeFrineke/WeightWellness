#pragma once

#include "PointsCalculator.h"
#include "Portie.h"
#include "WWDefinitions.h"


namespace weight
{


class LotVisitor;

class PortionedLot;
class CalculatedLot;
class FixedLot;

class Lot
{
public:
    virtual                 ~Lot() = 0 {}

    virtual double          GetPoints() const = 0;
    virtual void            Accept(LotVisitor& aVisitor) = 0;

    virtual CalculatedLot* GetCalculatedLot() { return nullptr; }
    virtual PortionedLot* GetPortionedLot() { return nullptr; }
    virtual FixedLot* GetFixedLot() { return nullptr; }
};


class PortionedLot: public Lot
{
public:
    PortionedLot(const Portie& aPortie)
        : mPortie(aPortie) {}

    virtual PortionedLot* GetPortionedLot() override { return this; }

    virtual double          GetPointsPer100Units() const = 0;
    double                  GetNumberOfPortions() const { return mNumberOfPortions; }

    void                    SetNumberOfPortions(double aNumber) { mNumberOfPortions = aNumber; }

    const Portie& GetPortie() const { return mPortie; }

private:
    PortionedLot(const PortionedLot&);
    PortionedLot& operator=(const PortionedLot&);

    Portie                  mPortie;
    double                  mNumberOfPortions{ 1 };
};


class CalculatedLot: public PortionedLot
{
public:
    CalculatedLot(const PointsCalculator& aCalculator, const Portie& aPortie)
        : PortionedLot(aPortie),
        mCalculator(aCalculator) {}

    const FoodParameters& GetParameters() const { return mParameters; }
    double                  GetPointsPer100Units() const { return mCalculator.GetPointsPer100Units(mParameters); }
    double                  GetKCalPer100Units() const { return mParameters.GetKCalPer100Units(); }
    double                  GetVetPer100Units() const { return mParameters.GetVetPer100Units(); }
    double                  GetEiwitPer100Units() const { return mParameters.GetEiwitPer100Units(); }
    double                  GetKoolhydratenPer100Units() const { return mParameters.GetKoolhydratenPer100Units(); }
    double                  GetVezelsPer100Units() const { return mParameters.GetVezelsPer100Units(); }

    void                    SetParameters(const FoodParameters& aParameters)
    {
        mParameters = aParameters;
    }
    void                    SetKCalPer100Units(double aKCalPer100) { mParameters.SetKCalPer100Units(aKCalPer100); }
    void                    SetVetPer100Units(double aVetPer100) { mParameters.SetVetPer100Units(aVetPer100); }
    void                    SetEiwitPer100Units(double anEiwit) { mParameters.SetEiwitPer100Units(anEiwit); }
    void                    SetKoolhydratenPer100Units(double akh) { mParameters.SetKoolhydratenPer100Units(akh); }
    void                    SetVezelsPer100Units(double aVezels) { mParameters.SetVezelsPer100Units(aVezels); }

    virtual double          GetPoints() const;
    virtual void            Accept(LotVisitor& aVisitor);
    virtual CalculatedLot* GetCalculatedLot() { return this; }

protected:
    const PointsCalculator& GetCalculator() const { return mCalculator; }
    FoodParameters& GetFoodParameters() { return mParameters; }
    const FoodParameters& GetFoodParameters() const { return mParameters; }

private:
    CalculatedLot(const CalculatedLot&);
    CalculatedLot& operator=(const CalculatedLot&);

    FoodParameters          mParameters;
    const PointsCalculator& mCalculator;
};


class FixedLot: public PortionedLot
{
public:
    FixedLot(const Portie& aPortie)
        : PortionedLot(aPortie) {}

    virtual void          Accept(LotVisitor& aVisitor);

    virtual FixedLot* GetFixedLot() { return this; }

    virtual double        GetPointsPer100Units() const { return mPointsPer100Units; }
    void                  SetPointsPer100Units(double aPoints) { mPointsPer100Units = aPoints; }
    virtual double        GetPoints() const;

private:
    double                mPointsPer100Units;
};


class LotVisitor
{
public:
    virtual void          Visit(CalculatedLot& aLot) = 0;
    virtual void          Visit(FixedLot& aLot) = 0;
};


} // namespace weight
