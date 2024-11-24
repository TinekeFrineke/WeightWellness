
#include "Voedingsmiddel.h"

#include <assert.h>

#include "VoedingsmiddelDefinitie.h"


namespace WW
{


Voedingsmiddel::Voedingsmiddel(const std::tstring& aName,
                               std::unique_ptr<Lot> aLot,
                               const Unit& aUnit)
    : mName(aName),
    mLot(std::move(aLot)),
    mUnit(aUnit)
{
    assert(mLot != NULL);
}


Voedingsmiddel::Voedingsmiddel(std::unique_ptr<Lot> aLot,
                               const VMDefinitie& aDefinitie)
    : mLot(std::move(aLot)),
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
