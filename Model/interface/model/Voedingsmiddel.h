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
    Voedingsmiddel(const std::tstring& aName,
                   std::unique_ptr<Lot> aLot,
                   const std::wstring& aUnit);
    Voedingsmiddel(std::unique_ptr<Lot> aLot,
                   const VMDefinitie& aDefinitie);
    ~Voedingsmiddel() override;

    virtual std::wstring  GetName() const { return mName; }
    virtual double        GetPoints() const;

    virtual void          Accept(ItemVisitor& aVisitor) override;

    std::wstring         GetCategory() const { return mCategory; }
    Lot& GetLot() { return *mLot; }
    const Lot& GetConstLot() const { return *mLot; }

    void                  SetLot(std::unique_ptr<Lot> aLot);

    void                  SetUnit(const std::wstring& aUnit) { mUnit = aUnit; }

    std::wstring GetUnit() const { return mUnit; }

    void                  SetName(const std::wstring& aName) { mName = aName; }
    void                  SetCategory(const std::wstring& aCategory) { mCategory = aCategory; }

private:
    std::wstring                  mUnit;
    std::wstring          mName;
    std::wstring         mCategory;
    std::unique_ptr<Lot> mLot;
};


} // namespace weight
