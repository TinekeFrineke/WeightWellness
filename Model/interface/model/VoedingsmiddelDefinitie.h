#pragma once

#include "Entity.h"
#include "PointsCalculator.h"
#include "Portie.h"
#include "VoedingsMiddelDefinitionVisitor.h"
#include "WWDefinitions.h"

namespace weight
{

class CalculatedVMDef;
class FixedVMDef;


class VMDefBase;
// This is the voedingsmiddel instance in the items page, wchich can be used
// in a concrete voedingsmiddel portion
class VMDefinitie: public Entity<VMDefinitie>
{
public:
    VMDefinitie(std::shared_ptr<weight::PointsCalculator> calculator,
                const std::wstring& aName,
                const std::wstring& aUnit,
                std::unique_ptr<VMDefBase> aDefinition);
    VMDefinitie(const VMDefinitie&);
    VMDefinitie& operator=(const VMDefinitie&);

    virtual ~VMDefinitie();

    std::wstring GetName() const { return mName; }
    std::wstring GetCategory() const { return mCategory; }
    std::wstring GetMerk() const { return mMerk; }

    virtual double GetPointsPer100Units() const;

    // Transfers ownership
    bool AddPortie(std::unique_ptr<Portie> aPortie);
    bool RemovePortie(Portie* aPortie);

    void SetCategory(const std::wstring& aCategory) { mCategory = aCategory; }
    void SetMerk(const std::wstring& aMerk) { mMerk = aMerk; }
    void SetUnit(const std::wstring& aUnit) { mUnit = aUnit; }
    void SetFavourite(bool aFavourite) noexcept { mFavourite = aFavourite; }

    std::wstring GetUnit() const { return mUnit; }

    const std::vector<std::unique_ptr<Portie>>& GetPortieList() const noexcept { return mPortieList; }

    bool IsCalculated() const;
    bool IsFixed() const;
    bool IsFavourite() const noexcept { return mFavourite; }

    VMDefBase* GetVMDef() { return mPoints.get(); }
    CalculatedVMDef* GetCalculatedVMDef();
    FixedVMDef* GetFixedVMDef();

    void SetCalculated(const FoodParameters& oParameters);
    void SetFixed();

    // Entity overrides
    virtual std::tstring GetInstanceName() const noexcept { return mName; }
    static std::tstring GetClassName() { return _T("VMDefinitie"); }

private:
    std::wstring mUnit;
    std::wstring mName;
    std::wstring mCategory;
    std::wstring mMerk;
    std::vector<std::unique_ptr<Portie>> mPortieList;
    bool mFavourite;

    // Can calculate the amount of points based upon the strategy used
    std::shared_ptr<PointsCalculator> m_calculator;
    // A voedingsmiddel definition can either be fixed (x points for any amount)
    // or calculated based upon the kcal, fat, protein etc.
    std::unique_ptr<VMDefBase> mPoints;
}; // class VMDefinitie


class CalculatedVMDef;
class FixedVMDef;


class VMDefBase
{
public:
    virtual ~VMDefBase() noexcept = default;

    virtual void Accept(VoedingsMiddelDefinitionVisitor& visitor) = 0;
    virtual std::unique_ptr<VMDefBase> Copy() const = 0;
    virtual double GetPointsPer100Units() const = 0;

    virtual bool IsCalculated() const noexcept { return false; }
    virtual bool IsFixed() const noexcept { return false; }

    virtual CalculatedVMDef* GetCalculatedVMDef() noexcept { return nullptr; }
    virtual FixedVMDef* GetFixedVMDef() noexcept { return nullptr; }
};

class CalculatedVMDef: public VMDefBase, public Entity<CalculatedVMDef>
{
public:
    explicit CalculatedVMDef(std::shared_ptr<weight::PointsCalculator> calculator);
    CalculatedVMDef(const CalculatedVMDef&);
    CalculatedVMDef& operator=(const CalculatedVMDef&);

    ~CalculatedVMDef() override;

    // VMDefBase
    void Accept(VoedingsMiddelDefinitionVisitor& visitor) override;
    const FoodParameters& GetParameters() const noexcept { return mParameters; }
    double GetPointsPer100Units() const override { return m_calculator->GetPointsPer100Units(mParameters); }

    bool              IsCalculated() const noexcept override { return true; }
    CalculatedVMDef* GetCalculatedVMDef() noexcept override { return this; }
    std::unique_ptr<VMDefBase> Copy() const override;

    // Entity overrides
    std::tstring GetInstanceName() const override { return _T("None"); }

    void SetParameters(const FoodParameters& aParameters);
    void SetKCalPer100Units(double aKCalPer100) { mParameters.SetKCalPer100Units(aKCalPer100); }
    void SetVetPer100Units(double aVetPer100) { mParameters.SetVetPer100Units(aVetPer100); }
    void SetEiwitPer100Units(double anEiwit) { mParameters.SetEiwitPer100Units(anEiwit); }
    void SetKoolhydratenPer100Units(double akh) { mParameters.SetKoolhydratenPer100Units(akh); }
    void SetVezelsPer100Units(double aVezels) { mParameters.SetVezelsPer100Units(aVezels); }

    double GetKCalPer100Units() const { return mParameters.GetKCalPer100Units(); }
    double GetVetPer100Units() const { return mParameters.GetVetPer100Units(); }
    double GetEiwitPer100Units() const { return mParameters.GetEiwitPer100Units(); }
    double GetKoolhydratenPer100Units() const { return mParameters.GetKoolhydratenPer100Units(); }
    double GetVezelsPer100Units() const { return mParameters.GetVezelsPer100Units(); }

    static std::tstring       GetClassName() { return _T("CalculatedVMDef"); }

private:

    std::shared_ptr<weight::PointsCalculator> m_calculator;
    FoodParameters mParameters;
};


class FixedVMDef: public VMDefBase, public Entity<FixedVMDef>
{
public:
    FixedVMDef();
    FixedVMDef(const FixedVMDef&);
    ~FixedVMDef() override;

    // VMDefBase
    void Accept(VoedingsMiddelDefinitionVisitor& visitor) override;

    double GetPointsPer100Units() const noexcept override { return mPointsPer100Units; }
    bool IsFixed() const noexcept override { return true; }
    FixedVMDef* GetFixedVMDef() noexcept override { return this; }
    std::unique_ptr<VMDefBase> Copy() const override;

    // Entity overrides
    std::tstring      GetInstanceName() const override { return _T("None"); }

    void SetPointsPer100Units(double aPoints) noexcept { mPointsPer100Units = aPoints; }

    static std::tstring       GetClassName() { return _T("FixedVMDef"); }

private:
    double                    mPointsPer100Units;
};


} // namespace weight
