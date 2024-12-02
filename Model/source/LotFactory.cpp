
#include "LotFactory.h"

#include "Lot.h"
#include "PointsCalculator.h"
#include "Portie.h"
#include "VoedingsMiddelDefinitie.h"

namespace weight {

class PointsCalculator;

namespace {

class VMDefLotVisitor: public VoedingsMiddelDefinitionVisitor
{
public:
    VMDefLotVisitor(std::shared_ptr<PointsCalculator> calculator, Portie& aPortie)
        : m_calculator(std::move(calculator))
        , m_portie(aPortie)
    {}

    std::unique_ptr<PortionedLot> Create(VMDefBase& base)
    {
        base.Accept(*this);
        return std::move(m_createdLot);
    }

private:
    void Visit(CalculatedVMDef& definition) override
    {
        auto clot = std::make_unique<CalculatedLot>(m_calculator, m_portie);
        clot->SetParameters(definition.GetParameters());
        clot->SetNumberOfPortions(1);
        m_createdLot = std::move(clot);
    }

    void Visit(FixedVMDef& definition) override
    {
        auto flot = std::make_unique<FixedLot>(m_portie);
        flot->SetPointsPer100Units(definition.GetPointsPer100Units());
        flot->SetNumberOfPortions(1);
        m_createdLot = std::move(flot);
    }

    std::shared_ptr<PointsCalculator> m_calculator;
    Portie& m_portie;
    std::unique_ptr<PortionedLot> m_createdLot;
};

}

LotFactory::LotFactory(std::shared_ptr<PointsCalculator> calculator) noexcept
    : m_calculator(calculator)
{
}


std::unique_ptr<PortionedLot> LotFactory::Create(VMDefinitie& aDefinitie, Portie& aPortie)
{
    VMDefLotVisitor lotVisitor(m_calculator, aPortie);
    return lotVisitor.Create(*aDefinitie.GetVMDef());
}


} // namespace weight
