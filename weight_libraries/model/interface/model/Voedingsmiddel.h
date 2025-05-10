#pragma once

#include "Item.h"
#include "Lot.h"
#include "Portie.h"

namespace weight
{


class VMDefinitie;

class Voedingsmiddel: public Item
{
public:
    Voedingsmiddel(const std::string& aName, std::unique_ptr<Lot> aLot, const std::string& aUnit);
    Voedingsmiddel(std::unique_ptr<Lot> aLot, const VMDefinitie& aDefinitie);
    ~Voedingsmiddel() override;

    virtual std::string GetName() const { return mName; }
    virtual double GetPoints() const;

    virtual void Accept(ItemVisitor& aVisitor) override;

    std::string GetCategory() const { return mCategory; }
    Lot& GetLot() { return *mLot; }
    const Lot& GetConstLot() const { return *mLot; }

    void SetLot(std::unique_ptr<Lot> aLot);
    void SetUnit(const std::string& aUnit) { mUnit = aUnit; }

    std::string GetUnit() const { return mUnit; }

    void SetName(const std::string& aName) { mName = aName; }
    void SetCategory(const std::string& aCategory) { mCategory = aCategory; }

private:
    std::string mUnit;
    std::string mName;
    std::string mCategory;
    std::unique_ptr<Lot> mLot;
};


} // namespace weight
