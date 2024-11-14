#include "stdafx.h"

#include "Lot.h"


namespace WW
{


double CalculatedLot::GetPoints() const
{
  double points = (GetNumberOfPortions() * GetPortie().GetUnits() * GetCalculator().GetPointsPer100Units(GetFoodParameters())) / 100;
  return points;
}


void CalculatedLot::Accept(LotVisitor & aVisitor)
{
  aVisitor.Visit(*this);
}


void FreeLot::Accept(LotVisitor & aVisitor)
{
  aVisitor.Visit(*this);
}


double FixedLot::GetPoints() const
{
  return (GetNumberOfPortions() * GetPortie().GetUnits() * mPointsPer100Units) / 100;
}


void FixedLot::Accept(LotVisitor & aVisitor)
{
  aVisitor.Visit(*this);
}


} // namespace WW
