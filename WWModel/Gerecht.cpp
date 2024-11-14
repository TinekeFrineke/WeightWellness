#include "stdafx.h"

#include "Gerecht.h"


namespace WW
{


double Gerecht::GetPoints() const
{
  return mNumberOfPortions * mPointsPerPortion;
}


void Gerecht::Accept(ItemVisitor & aVisitor)
{
  aVisitor.Visit(*this);
}


} // namespace WW
