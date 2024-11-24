
#include "LotFactory.h"

#include "Lot.h"
#include "PointsCalculator.h"
#include "Portie.h"
#include "VoedingsMiddelDefinitie.h"

namespace WW {

class PointsCalculator;

namespace {

class VMDefLotVisitor: public VoedingsMiddelDefinitionVisitor
{
public:
    VMDefLotVisitor(const WW::PointsCalculator& aCalculator, WW::Portie& aPortie)
        : m_calculator(aCalculator)
        , m_portie(aPortie)
    {}

    std::unique_ptr<WW::PortionedLot> Create(VMDefBase& base)
    {
        base.Accept(*this);
        return std::move(m_createdLot);
    }

private:
    void Visit(CalculatedVMDef& definition) override
    {
        auto clot = std::make_unique<WW::CalculatedLot>(m_calculator, m_portie);
        clot->SetParameters(definition.GetParameters());
        clot->SetNumberOfPortions(1);
        m_createdLot = std::move(clot);
    }

    void Visit(FixedVMDef& definition) override
    {
        auto flot = std::make_unique<WW::FixedLot>(m_portie);
        flot->SetPointsPer100Units(definition.GetPointsPer100Units());
        flot->SetNumberOfPortions(1);
        m_createdLot = std::move(flot);
    }

    const WW::PointsCalculator& m_calculator;
    WW::Portie& m_portie;
    std::unique_ptr<WW::PortionedLot> m_createdLot;
};

}

LotFactory::LotFactory(const PointsCalculator& aCalculator) noexcept
    : m_calculator(aCalculator)
{
}


std::unique_ptr<PortionedLot> LotFactory::Create(VMDefinitie& aDefinitie, Portie& aPortie)
{
    VMDefLotVisitor lotVisitor(m_calculator, aPortie);
    return lotVisitor.Create(*aDefinitie.GetVMDef());
}


} // namespace WW
