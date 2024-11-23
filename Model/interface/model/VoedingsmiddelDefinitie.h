#pragma once

#include "CategorieNaam.h"
#include "Entity.h"
#include "MerkNaam.h"
#include "PointsCalculator.h"
#include "Portie.h"
#include "PortieNaam.h"
#include "Unit.h"
#include "VoedingsMiddelDefinitionVisitor.h"
#include "WWDefinitions.h"

namespace WW
{

class CalculatedVMDef;
class FixedVMDef;


class VMDefBase;
// This is the voedingsmiddel instance in the items page, wchich can be used
// in a concrete voedingsmiddel portion
class VMDefinitie: public Entity<VMDefinitie>
{
public:
    VMDefinitie(const PointsCalculator& aCalculator,
                const std::tstring& aName,
                const Unit& aUnit,
                VMDefBase* aDefinition);
    VMDefinitie(const VMDefinitie&);
    VMDefinitie& operator=(const VMDefinitie&);

    virtual                   ~VMDefinitie();

    virtual std::tstring      GetName() const { return mName; }
    const CategorieNaam& GetCategory() const { return mCategory; }
    const MerkNaam& GetMerk() const { return mMerk; }

    virtual double            GetPointsPer100Units() const;

    // Transfers ownership
    bool                      AddPortie(std::unique_ptr<Portie> aPortie);
    bool                      RemovePortie(Portie* aPortie);

    void                      SetCategory(const CategorieNaam& aCategory) { mCategory = aCategory; }
    void                      SetMerk(const MerkNaam& aMerk) { mMerk = aMerk; }
    void                      SetUnit(const Unit& aUnit) { mUnit = aUnit; }

    void                      SetFavourite(bool aFavourite) { mFavourite = aFavourite; }

    bool                      ReleasePorties(std::vector<std::unique_ptr<Portie>>& aPorties);

    const Unit& GetUnit() const { return mUnit; }

    //std::vector<std::unique_ptr<Portie>>& GetPortieList() { return mPortieList; }
    const std::vector< std::unique_ptr<Portie>>& GetPortieList() const { return mPortieList; }

    bool                      IsCalculated() const;
    bool                      IsFixed() const;
    bool                      IsFavourite() const { return mFavourite; }

    VMDefBase* GetVMDef() { return mPoints.get(); }
    CalculatedVMDef* GetCalculatedVMDef();
    FixedVMDef* GetFixedVMDef();

    void                      SetCalculated(const FoodParameters& oParameters);
    void                      SetFixed();

    // Entity overrides
    virtual std::tstring      GetInstanceName() const { return mName; }
    static std::tstring       GetClassName() { return _T("VMDefinitie"); }

private:
    Unit                      mUnit;
    std::tstring              mName;
    CategorieNaam             mCategory;
    MerkNaam                  mMerk;
    std::vector<std::unique_ptr<Portie>>      mPortieList;
    bool                      mFavourite;

    // Can calculate the amount of points based upon the strategy used
    const PointsCalculator& mCalculator;
    // A voedingsmiddel definition can either be fixed (x points for any amount)
    // or calculated based upon the kcal, fat, protein etc.
    std::unique_ptr<VMDefBase> mPoints;
}; // class VMDefinitie


class CalculatedVMDef;
class FixedVMDef;


class VMDefBase
{
public:
    virtual                   ~VMDefBase() = default;

    virtual void Accept(VoedingsMiddelDefinitionVisitor& visitor) = 0;
    virtual VMDefBase* Copy() const = 0;
    virtual double            GetPointsPer100Units() const = 0;

    virtual bool              IsCalculated() const { return false; }
    virtual bool              IsFixed() const { return false; }

    virtual CalculatedVMDef* GetCalculatedVMDef() { return nullptr; }
    virtual FixedVMDef* GetFixedVMDef() { return nullptr; }
};

class CalculatedVMDef: public VMDefBase, public Entity<CalculatedVMDef>
{
public:
    explicit CalculatedVMDef(const PointsCalculator& aCalculator);
    CalculatedVMDef(const CalculatedVMDef&);
    CalculatedVMDef& operator=(const CalculatedVMDef&);

    virtual                   ~CalculatedVMDef();

    void Accept(VoedingsMiddelDefinitionVisitor& visitor) override;

    void                      SetParameters(const FoodParameters& aParameters)
    {
        mParameters = aParameters;
    }
    void                      SetKCalPer100Units(double aKCalPer100) { mParameters.SetKCalPer100Units(aKCalPer100); }
    void                      SetVetPer100Units(double aVetPer100) { mParameters.SetVetPer100Units(aVetPer100); }
    void                      SetEiwitPer100Units(double anEiwit) { mParameters.SetEiwitPer100Units(anEiwit); }
    void                      SetKoolhydratenPer100Units(double akh) { mParameters.SetKoolhydratenPer100Units(akh); }
    void                      SetVezelsPer100Units(double aVezels) { mParameters.SetVezelsPer100Units(aVezels); }

    const FoodParameters& GetParameters() const { return mParameters; }
    double                    GetPointsPer100Units() const { return mCalculator.GetPointsPer100Units(mParameters); }
    double                    GetKCalPer100Units() const { return mParameters.GetKCalPer100Units(); }
    double                    GetVetPer100Units() const { return mParameters.GetVetPer100Units(); }
    double                    GetEiwitPer100Units() const { return mParameters.GetEiwitPer100Units(); }
    double                    GetKoolhydratenPer100Units() const { return mParameters.GetKoolhydratenPer100Units(); }
    double                    GetVezelsPer100Units() const { return mParameters.GetVezelsPer100Units(); }

    virtual bool              IsCalculated() const { return true; }
    virtual CalculatedVMDef* GetCalculatedVMDef() { return this; }
    virtual VMDefBase* Copy() const override;

    // Entity overrides
    virtual std::tstring      GetInstanceName() const { return _T("None"); }
    static std::tstring       GetClassName() { return _T("CalculatedVMDef"); }

private:

    const PointsCalculator& mCalculator;
    FoodParameters            mParameters;
};


class FixedVMDef: public VMDefBase, public Entity<FixedVMDef>
{
public:
    FixedVMDef();
    FixedVMDef(const FixedVMDef&);
    virtual                   ~FixedVMDef();

    void Accept(VoedingsMiddelDefinitionVisitor& visitor) override;

    void                      SetPointsPer100Units(double aPoints) { mPointsPer100Units = aPoints; }
    double                    GetPointsPer100Units() const { return mPointsPer100Units; }

    virtual bool              IsFixed() const { return true; }
    virtual FixedVMDef* GetFixedVMDef() { return this; }
    virtual VMDefBase* Copy() const override;

    // Entity overrides
    virtual std::tstring      GetInstanceName() const { return _T("None"); }
    static std::tstring       GetClassName() { return _T("FixedVMDef"); }

private:
    double                    mPointsPer100Units;
};


} // namespace WW
