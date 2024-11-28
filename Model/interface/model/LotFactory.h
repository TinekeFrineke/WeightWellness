#pragma once


#include "ILotFactory.h"
#include "VoedingsMiddelDefinitionVisitor.h"

namespace weight {

class PointsCalculator;

class LotFactory
    : public ILotFactory
{
public:
    explicit LotFactory(const PointsCalculator& aCalculator) noexcept;

    std::unique_ptr<PortionedLot> Create(VMDefinitie& aDefinitie, Portie& aPortie) override;

private:
    const PointsCalculator& m_calculator;
};

} // namespace weight
