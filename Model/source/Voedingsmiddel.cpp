
#include "Voedingsmiddel.h"

#include <assert.h>

#include "VoedingsmiddelDefinitie.h"


namespace WW
{


Voedingsmiddel::Voedingsmiddel(const std::tstring& aName,
                               Lot* aLot,
                               const Unit& aUnit)
    : mName(aName),
    mLot(aLot),
    mUnit(aUnit)
{
    assert(mLot != NULL);
}


Voedingsmiddel::Voedingsmiddel(Lot* aLot,
                               const VMDefinitie& aDefinitie)
    : mLot(aLot),
    mUnit(aDefinitie.GetUnit()),
    mName(aDefinitie.GetName()),
    mCategory(aDefinitie.GetCategory())
{
    assert(mLot != NULL);
}


Voedingsmiddel::~Voedingsmiddel() = default;


double Voedingsmiddel::GetPoints() const
{
    assert(mLot != NULL);
    return mLot->GetPoints();
}


void Voedingsmiddel::SetLot(std::unique_ptr<Lot> aLot)
{
    assert(aLot != NULL);
    mLot = std::move(aLot);
}


void Voedingsmiddel::Accept(ItemVisitor& aVisitor)
{
    aVisitor.Visit(*this);
}


} // namespace WW
