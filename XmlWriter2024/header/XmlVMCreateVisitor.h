#pragma once

#include "model/VoedingsmiddelDefinitie.h"

namespace weight
{
class PortionedLot;
}

namespace ww2024
{
class XmlVoedingsmiddeldef;


class CreateLotFromVMDef
{
public:
    CreateLotFromVMDef(std::shared_ptr<weight::PointsCalculator> calculator)
        : m_calculator(calculator)
    {
    }

    std::unique_ptr<weight::PortionedLot> Create(weight::VMDefinitie& aDefinitie,
                                                 weight::Portie& aPortie);

private:
    CreateLotFromVMDef(const CreateLotFromVMDef&) = delete;
    CreateLotFromVMDef& operator=(const CreateLotFromVMDef&) = delete;

    std::shared_ptr<weight::PointsCalculator> m_calculator;
};

} // namespace ww2024
