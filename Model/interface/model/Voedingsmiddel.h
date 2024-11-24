#pragma once

#include "CategorieNaam.h"
#include "Item.h"
#include "Lot.h"
#include "Portie.h"
#include "Unit.h"

namespace WW
{


class VMDefinitie;

class Voedingsmiddel: public Item
{
public:
    Voedingsmiddel(const std::tstring& aName,
                   std::unique_ptr<Lot> aLot,
                   const Unit& aUnit);
    Voedingsmiddel(std::unique_ptr<Lot> aLot,
                   const VMDefinitie& aDefinitie);
    virtual               ~Voedingsmiddel();

    virtual std::tstring  GetName() const { return mName; }
    virtual double        GetPoints() const;

    virtual void          Accept(ItemVisitor& aVisitor) override;

    CategorieNaam         GetCategory() const { return mCategory; }
    Lot& GetLot() { return *mLot; }
    const Lot& GetConstLot() const { return *mLot; }

    void                  SetLot(std::unique_ptr<Lot> aLot);

    void                  SetUnit(const Unit& aUnit) { mUnit = aUnit; }

    const Unit& GetUnit() const { return mUnit; }

    void                  SetName(const std::tstring& aName) { mName = aName; }
    void                  SetCategory(const CategorieNaam& aCategory) { mCategory = aCategory; }

private:
    Unit                  mUnit;
    std::tstring          mName;
    CategorieNaam         mCategory;
    std::unique_ptr<Lot> mLot;
};


}
