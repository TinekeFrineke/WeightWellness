#pragma once


#include <memory>
#include <vector>

#include "Entity.h"
#include "PointsCalculator.h"
#include "Portie.h"
#include "WWDefinitions.h"

namespace weight
{

class NutritionalValue;

struct FoodParameters;


// This is the voedingsmiddel instance in the items page, wchich can be used
// in a concrete voedingsmiddel portion
class VMDefinitie: public Entity<VMDefinitie>
{
public:
    VMDefinitie(std::shared_ptr<weight::PointsCalculator> calculator,
                const std::string& aName,
                const std::string& aUnit,
                std::unique_ptr<NutritionalValue> aDefinition);
    VMDefinitie(const VMDefinitie&);
    VMDefinitie& operator=(const VMDefinitie&);

    virtual ~VMDefinitie();

    std::string GetName() const { return mName; }
    std::string GetCategory() const { return mCategory; }
    std::string GetMerk() const { return mMerk; }
    bool IsFavourite() const noexcept { return mFavourite; }

    virtual double GetPointsPer100Units() const;

    // Transfers ownership
    bool AddPortie(std::unique_ptr<Portie> aPortie);
    bool RemovePortie(Portie* aPortie);
    bool RemovePortie(const std::string& name);

    void SetName(const std::string& name) { mName = name; }
    void SetCategory(const std::string& aCategory) { mCategory = aCategory; }
    void SetMerk(const std::string& aMerk) { mMerk = aMerk; }
    void SetUnit(const std::string& aUnit) { mUnit = aUnit; }
    void SetFavourite(bool aFavourite) noexcept { mFavourite = aFavourite; }
    void SetKCalPer100Units(double value);
    void SetVetPer100Units(double value);
    void SetEiwitPer100Units(double value);
    void SetKoolhydratenPer100Units(double value);
    void SetVezelsPer100Units(double value);
    void SetNutritionalValues(const FoodParameters& parameters);

    std::string GetUnit() const { return mUnit; }

    const std::vector<std::unique_ptr<Portie>>& GetPortieList() const noexcept { return mPortieList; }

    const NutritionalValue& GetNutritionalValue() const noexcept { return *mPoints; }

    // Entity overrides
    std::string GetInstanceName() const noexcept override { return mName; }
    static std::string GetClassName() { return "VMDefinitie"; }

private:
    std::string mUnit;
    std::string mName;
    std::string mCategory;
    std::string mMerk;
    std::vector<std::unique_ptr<Portie>> mPortieList;
    bool mFavourite;

    // Can calculate the amount of points based upon the strategy used
    std::shared_ptr<PointsCalculator> m_calculator;
    // A voedingsmiddel definition can either be fixed (x points for any amount)
    // or calculated based upon the kcal, fat, protein etc.
    std::unique_ptr<NutritionalValue> mPoints;
}; // class VMDefinitie


} // namespace weight
