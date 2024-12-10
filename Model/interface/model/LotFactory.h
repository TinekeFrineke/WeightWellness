#pragma once


#include "ILotFactory.h"

namespace weight {

class PointsCalculator;

class LotFactory
    : public ILotFactory
{
public:
    explicit LotFactory(std::shared_ptr<PointsCalculator> calculator) noexcept;

    std::unique_ptr<PortionedLot> Create(const VMDefinitie& aDefinitie, Portie& aPortie) override;

private:
    std::shared_ptr<PointsCalculator> m_calculator;
};

} // namespace weight
