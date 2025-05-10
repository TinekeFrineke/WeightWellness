
#include <assert.h>

#include "XmlVMCreateVisitor.h"

#include "generated/XmlVoedingsmiddeldef.h"
#include "generated/XmlVoedingswaarde.h"

#include "model/Lot.h"
#include "model/NutritionalValue.h"
#include "model/PointsCalculator.h"
#include "model/VoedingsmiddelDefinitie.h"

namespace ww2024
{


std::unique_ptr<weight::PortionedLot> CreateLotFromVMDef::Create(weight::VMDefinitie& aDefinitie,
                                                                 weight::Portie& aPortie)
{
    auto lot = std::make_unique<weight::PortionedLot>(m_calculator, aPortie);
    lot->SetParameters(aDefinitie.GetNutritionalValue().GetParameters());
    lot->SetNumberOfPortions(1);
    return lot;
}


} // namespace ww2024
