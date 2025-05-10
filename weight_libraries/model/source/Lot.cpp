
#include "Lot.h"


namespace weight
{


double PortionedLot::GetPoints() const
{
    double points = (GetNumberOfPortions() * GetPortie().GetUnits() * m_calculator->GetPointsPer100Units(mParameters)) / 100;
    return points;
}


} // namespace weight
