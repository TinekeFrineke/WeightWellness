
#include "Gerecht.h"


namespace weight
{


double Gerecht::GetPoints() const
{
  return mNumberOfPortions * mPointsPerPortion;
}


void Gerecht::Accept(ItemVisitor & aVisitor)
{
  aVisitor.Visit(*this);
}


} // namespace weight
