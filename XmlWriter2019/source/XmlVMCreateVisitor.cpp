
#include <assert.h>

#include "XmlVMCreateVisitor.h"

#include "generated/XmlPuntenper100.h"
#include "generated/XmlVoedingsmiddeldef.h"
#include "generated/XmlVoedingswaarde.h"

#include "model/Lot.h"
#include "model/PointsCalculator.h"

namespace ww2019
{


std::unique_ptr<weight::PortionedLot> CreateLotFromVMDef::Create(weight::VMDefinitie& aDefinitie,
                                                                 weight::Portie& aPortie)
{
    std::unique_ptr<weight::PortionedLot> lot;

    if (aDefinitie.IsCalculated())
    {
        weight::CalculatedVMDef* def = aDefinitie.GetCalculatedVMDef();
        assert(def != NULL);
        auto clot = std::make_unique<weight::CalculatedLot>(m_calculator, aPortie);
        clot->SetParameters(def->GetParameters());
        lot = std::move(clot);
    }
    else if (aDefinitie.IsFixed())
    {
        weight::FixedVMDef* def = aDefinitie.GetFixedVMDef();
        assert(def != NULL);
        auto flot = std::make_unique<weight::FixedLot>(aPortie);
        flot->SetPointsPer100Units(def->GetPointsPer100Units());
        lot = std::move(flot);
    }
    else
    {
        auto flot = std::make_unique<weight::FixedLot>(aPortie);
        lot = std::move(flot);
    }

    lot->SetNumberOfPortions(1);
    return lot;
}


} // namespace ww2019
