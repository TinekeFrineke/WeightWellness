
#include <assert.h>

#include "XmlVMCreateVisitor.h"

#include "generated/XmlPuntenper100.h"
#include "generated/XmlVoedingsmiddeldef.h"
#include "generated/XmlVoedingswaarde.h"

#include "model/Lot.h"
#include "model/PointsCalculator.h"

namespace ww2019
{


//void XmlVMCreateVisitor::Visit(weight::CalculatedVMDef & aDefinitie)
//{
//  WW_GENERATED_NAMESPACE::XmlVoedingswaarde * xmlvoedingswaarde = new WW_GENERATED_NAMESPACE::XmlVoedingswaarde;
//  mDefinition.Add(xmlvoedingswaarde);
//  xmlvoedingswaarde->Setkcalper100(Str::ToTString(aDefinitie.GetKCalPer100Units()));
//  xmlvoedingswaarde->Seteiwitper100(Str::ToTString(aDefinitie.GetEiwitPer100Units()));
//  xmlvoedingswaarde->Setkoolhydratenper100(Str::ToTString(aDefinitie.GetKoolhydratenPer100Units()));
//  xmlvoedingswaarde->Setvetper100(Str::ToTString(aDefinitie.GetVetPer100Units()));
//  xmlvoedingswaarde->Setvezelsper100(Str::ToTString(aDefinitie.GetVezelsPer100Units()));
//}
//
//
//void XmlVMCreateVisitor::Visit(weight::FixedVMDef & aDefinitie)
//{
//  WW_GENERATED_NAMESPACE::XmlPuntenper100 * xmlpuntenper100 = new WW_GENERATED_NAMESPACE::XmlPuntenper100;
//  mDefinition.Add(xmlpuntenper100);
//  xmlpuntenper100->Setpunten(Str::ToTString(aDefinitie.GetPointsPer100Units()));
//}


weight::PortionedLot* CreateLotFromVMDef::Create(weight::VMDefinitie& aDefinitie,
                                             weight::Portie& aPortie)
{
    weight::PortionedLot* lot;

    if (aDefinitie.IsCalculated())
    {
        weight::CalculatedVMDef* def = aDefinitie.GetCalculatedVMDef();
        assert(def != NULL);
        weight::CalculatedLot* clot = new weight::CalculatedLot(m_calculator, aPortie);
        clot->SetParameters(def->GetParameters());
        lot = clot;
    }
    else if (aDefinitie.IsFixed())
    {
        weight::FixedVMDef* def = aDefinitie.GetFixedVMDef();
        assert(def != NULL);
        weight::FixedLot* flot = new weight::FixedLot(aPortie);
        flot->SetPointsPer100Units(def->GetPointsPer100Units());
        lot = flot;
    }
    else
    {
        weight::FixedLot* flot = new weight::FixedLot(aPortie);
        lot = flot;
    }

    lot->SetNumberOfPortions(1);
    return lot;
}


} // namespace ww2019
