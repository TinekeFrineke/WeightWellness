#include "stdafx.h"

#include <assert.h>

#include "XmlVMCreateVisitor.h"

#include <Generated/XmlPuntenper100.h>
#include <Generated/XmlVoedingsmiddeldef.h>
#include <Generated/XmlVoedingswaarde.h>

#include "Lot.h"
#include "PointsCalculator.h"

namespace WW_NAMESPACE
{


//void XmlVMCreateVisitor::Visit(WW::CalculatedVMDef & aDefinitie)
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
//void XmlVMCreateVisitor::Visit(WW::FixedVMDef & aDefinitie)
//{
//  WW_GENERATED_NAMESPACE::XmlPuntenper100 * xmlpuntenper100 = new WW_GENERATED_NAMESPACE::XmlPuntenper100;
//  mDefinition.Add(xmlpuntenper100);
//  xmlpuntenper100->Setpunten(Str::ToTString(aDefinitie.GetPointsPer100Units()));
//}


WW::PortionedLot * CreateLotFromVMDef::Create(WW::VMDefinitie & aDefinitie,
                                              WW::Portie &      aPortie)
{
  WW::PortionedLot * lot;

  if (aDefinitie.IsCalculated())
  {
    WW::CalculatedVMDef * def = aDefinitie.GetCalculatedVMDef();
    assert(def != NULL);
    WW::CalculatedLot *clot = new WW::CalculatedLot(mCalculator, aPortie);
    clot->SetParameters(def->GetParameters());
    lot = clot;
  }
  else if (aDefinitie.IsFixed())
  {
    WW::FixedVMDef * def = aDefinitie.GetFixedVMDef();
    assert(def != NULL);
    WW::FixedLot * flot = new WW::FixedLot(aPortie);
    flot->SetPointsPer100Units(def->GetPointsPer100Units());
    lot = flot;
  }
  else
  {
    WW::FixedLot * flot = new WW::FixedLot(aPortie);
    lot = flot;
  }

  lot->SetNumberOfPortions(1);
  lot->SetSterreLot(aDefinitie.IsSterrePortion(&aPortie));
  return lot;
}


} // namespace WW_NAMESPACE
