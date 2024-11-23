
#include "Recept.h"


namespace WW
{


Recept::~Recept() = default;


double Recept::GetPoints() const
{
    return mNumberOfPortions * mPointsPerPortion;
}


void Recept::Accept(ItemVisitor& aVisitor)
{
    aVisitor.Visit(*this);
}


} // namespace WW
