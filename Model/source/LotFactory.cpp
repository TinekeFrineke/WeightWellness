
#include "LotFactory.h"

#include "Lot.h"
#include "NutritionalValue.h"
#include "PointsCalculator.h"
#include "Portie.h"
#include "VoedingsMiddelDefinitie.h"

namespace weight {

LotFactory::LotFactory(std::shared_ptr<PointsCalculator> calculator) noexcept
    : m_calculator(calculator)
{
}


std::unique_ptr<PortionedLot> LotFactory::Create(const VMDefinitie& aDefinitie, Portie& aPortie)
{
    auto lot = std::make_unique<PortionedLot>(m_calculator, aPortie);
    lot->SetParameters(aDefinitie.GetNutritionalValue().GetParameters());
    lot->SetNumberOfPortions(1);
    return lot;
}


} // namespace weight
