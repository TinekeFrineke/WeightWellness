#include "stdafx.h"

#include "Recept.h"


namespace WW
{


Recept::~Recept()
{
}


double Recept::GetPoints() const
{
  return mNumberOfPortions * mPointsPerPortion;
}


void Recept::Accept(ItemVisitor & aVisitor)
{
  aVisitor.Visit(*this);
}


} // namespace WW
