#include "stdafx.h"

#include "XmlWriter.h"

#include <tchar.h>

#include "Utilities/Date.h"
#include "Utilities/MathUtils.h"

#include <Generated/XmlBonuscell.h>
#include <Generated/XmlDag.h>
#include <Generated/XmlFreeLot.h>
#include <Generated/XmlGerecht.h>
#include <Generated/XmlGerechtdef.h>
#include <Generated/XmlGerechtdefs.h>
#include <Generated/XmlGerechtdefsWriter.h>
#include <Generated/XmlHandmatigitem.h>
#include <Generated/XmlPortie.h>
#include <Generated/XmlPersonalia.h>
#include <Generated/XmlPersonaliaWriter.h>
#include <Generated/XmlPuntenPer100.h>
#include <Generated/XmlRecept.h>
#include <Generated/XmlReceptdef.h>
#include <Generated/XmlReceptdefs.h>
#include <Generated/XmlReceptdefsWriter.h>
#include <Generated/XmlStandardLot.h>
#include <Generated/XmlUnit.h>
#include <Generated/XmlUnits.h>
#include <Generated/XmlUnitsWriter.h>
#include <Generated/XmlVoedingsmiddel.h>
#include <Generated/XmlVoedingsmiddeldef.h>
#include <Generated/XmlVoedingsmiddeldefs.h>
#include <Generated/XmlVoedingsmiddeldefsWriter.h>
#include <Generated/XmlVoedingswaarde.h>
#include <Generated/XmlWeek.h>
#include <Generated/XmlWeekWriter.h>

#include "Day.h"
#include "ManualItem.h"
#include "Personalia.h"
#include "Recept.h"
#include "ReceptDefinitie.h"
#include "Gerecht.h"
#include "GerechtDefinitie.h"
#include "Unit.h"
#include "VoedingsmiddelDefinitie.h"
#include "Week.h"
#include "WWModel.h"
#include "XmlItemCreateVisitor.h"
#include "XmlLotCreateVisitor.h"
#include "XmlVMCreateVisitor.h"

namespace WW_NAMESPACE
{


XmlBase::eRESULT XmlWriter::Write(const std::tstring & aDirectory)
{
  eRESULT result = WritePersonalia(aDirectory + _T("\\personalia.xml"));
  if (result == RESULT_Ok)
    result = WriteUnits(aDirectory + _T("\\units.xml"));
  if (result == RESULT_Ok)
    result = WriteVoedingsmiddelDefinities(aDirectory + _T("\\voedingsmiddeldefinities.xml"));
  if (result == RESULT_Ok)
    result = WriteRecepten(aDirectory + _T("\\recepten.xml"));
  if (result == RESULT_Ok)
    result = WriteGerechten(aDirectory + _T("\\restaurantgerechten.xml"));
  if (result == RESULT_Ok)
    result = WriteWeeks(aDirectory);

  return result;
}


XmlBase::eRESULT XmlWriter::WritePersonalia(const std::tstring & aFilename)
{
  if (mModel.GetPersonalia().empty())
    return RESULT_Ok;

  WW::Personalia * personalia = mModel.GetActivePersonalia();

  if (personalia->GetUserName().empty())
    return RESULT_Ok;

  WW_GENERATED_NAMESPACE::XmlPersonalia * xmlpersonalia = new WW_GENERATED_NAMESPACE::XmlPersonalia;
  xmlpersonalia->Setgebruikersnaam(personalia->GetUserName());
  xmlpersonalia->Setnaam(personalia->GetName());
  xmlpersonalia->Setgeboren(Utils::ToString(personalia->GetDateOfBirth()));
  xmlpersonalia->Setgeslacht(personalia->GetGeslacht() == WW::Personalia::GESLACHT::Mannelijk
                                                            ? WW_GENERATED_NAMESPACE::XmlPersonalia::geslacht_Mannelijk
                                                            : WW_GENERATED_NAMESPACE::XmlPersonalia::geslacht_Vrouwelijk);
  xmlpersonalia->Setgewicht(Str::ToTString(personalia->GetStreefGewicht()));
  xmlpersonalia->Setlengte(Str::ToTString(personalia->GetLengte()));
  xmlpersonalia->Setpunten(Str::ToTString(personalia->GetFPPuntenTotaal()));
  xmlpersonalia->Setpppunten(Str::ToTString(personalia->GetPPPuntenTotaal()));
  xmlpersonalia->Setppweekpunten(Str::ToTString(personalia->GetPPWeekPuntenTotaal()));
  xmlpersonalia->Setkcpunten(Str::ToTString(personalia->GetKCPuntenTotaal()));
  xmlpersonalia->Setkcweekpunten(Str::ToTString(personalia->GetKCWeekPuntenTotaal()));
  xmlpersonalia->Setchpunten(Str::ToTString(personalia->GetCHPuntenTotaal()));
  xmlpersonalia->Setchweekpunten(Str::ToTString(personalia->GetCHWeekPuntenTotaal()));
  xmlpersonalia->Setstreefgewicht(Str::ToTString(personalia->GetStreefGewicht()));
  xmlpersonalia->Setstartgewicht(Str::ToTString(personalia->GetStartGewicht()));
  xmlpersonalia->Sethuidiggewicht(Str::ToTString(personalia->GetHuidigGewicht()));
  xmlpersonalia->Setstreven(WW_GENERATED_NAMESPACE::XmlPersonalia::streven_Afvallen);
  switch (personalia->GetStrategy())
  {
  case WW::STRATEGY_TYPE::FlexiPoints:
    xmlpersonalia->Setstrategie(WW_GENERATED_NAMESPACE::XmlPersonalia::strategie_FlexiPoints);
    break;
  case WW::STRATEGY_TYPE::ProPoints:
    xmlpersonalia->Setstrategie(WW_GENERATED_NAMESPACE::XmlPersonalia::strategie_ProPoints);
    break;
  case WW::STRATEGY_TYPE::KCal:
    xmlpersonalia->Setstrategie(WW_GENERATED_NAMESPACE::XmlPersonalia::strategie_KCal);
    break;
  case WW::STRATEGY_TYPE::CarboHydrates:
    xmlpersonalia->Setstrategie(WW_GENERATED_NAMESPACE::XmlPersonalia::strategie_CarboHydrates);
    break;
  default:
    return RESULT_InterpretError;
  }

  WW_GENERATED_NAMESPACE::XmlPersonaliaWriter writer;
  writer.Write(aFilename, *xmlpersonalia);

  delete xmlpersonalia;

  return RESULT_Ok;
}


XmlBase::eRESULT XmlWriter::WriteUnits(const std::tstring & aFilename)
{
  WW_GENERATED_NAMESPACE::XmlUnits * xmlunits = new WW_GENERATED_NAMESPACE::XmlUnits;

  const std::vector<WW::Unit> & units = mModel.GetUnits();
  for (size_t i = 0; i < units.size(); ++i)
  {
    WW_GENERATED_NAMESPACE::XmlUnit * unit = new WW_GENERATED_NAMESPACE::XmlUnit;
    unit->Setnaam(units[i].GetName());
    xmlunits->Add(unit);
  }

  WW_GENERATED_NAMESPACE::XmlUnitsWriter writer;
  writer.Write(aFilename, *xmlunits);

  delete xmlunits;

  return RESULT_Ok;
}


XmlBase::eRESULT XmlWriter::WriteVoedingsmiddelDefinities(const std::tstring & aFilename)
{
  WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldefs * xmlvmdefinities = new WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldefs;

  const std::vector<WW::VMDefinitie *> & vmdefinities = mModel.GetVoedingsmiddelDefinities();
  for (size_t i = 0; i < vmdefinities.size(); ++i)
  {
    WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldef * xmlvmdefinitie = new WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldef;
    xmlvmdefinitie->GetVoedingsmiddelbasis().GetVoedingsmiddelheader().Setnaam(vmdefinities[i]->GetName());
    if (!vmdefinities[i]->GetCategory().Get().empty())
      xmlvmdefinitie->GetVoedingsmiddelbasis().GetVoedingsmiddelheader().Setcategorie(vmdefinities[i]->GetCategory().Get());
    if (!vmdefinities[i]->GetMerk().Get().empty())
      xmlvmdefinitie->GetVoedingsmiddelbasis().GetVoedingsmiddelheader().Setmerk(vmdefinities[i]->GetMerk().Get());

    if (vmdefinities[i]->IsCalculated())
    {
      WW::CalculatedVMDef * definitie = vmdefinities[i]->GetCalculatedVMDef();
      assert(definitie != NULL);
      WW_GENERATED_NAMESPACE::XmlVoedingswaarde * xmlwaarde = new WW_GENERATED_NAMESPACE::XmlVoedingswaarde;
      xmlwaarde->Setkcalper100(Str::ToTString(definitie->GetKCalPer100Units()));
      xmlwaarde->Seteiwitper100(Str::ToTString(definitie->GetEiwitPer100Units()));
      xmlwaarde->Setvetper100(Str::ToTString(definitie->GetVetPer100Units()));
      xmlwaarde->Setvezelsper100(Str::ToTString(definitie->GetVezelsPer100Units()));
      xmlwaarde->Setkoolhydratenper100(Str::ToTString(definitie->GetKoolhydratenPer100Units()));

      xmlvmdefinitie->Add(xmlwaarde);
    }
    else if (vmdefinities[i]->IsFixed())
    {
      WW::FixedVMDef * definitie = vmdefinities[i]->GetFixedVMDef();
      assert(definitie != NULL);

      WW_GENERATED_NAMESPACE::XmlPuntenper100 * xmlpuntenper100 = new WW_GENERATED_NAMESPACE::XmlPuntenper100;
      xmlpuntenper100->Setpunten(Str::ToTString(definitie->GetPointsPer100Units()));

      xmlvmdefinitie->Add(xmlpuntenper100);
    }
    //XmlVMCreateVisitor writer(*xmlvmdefinitie);
    //vmdefinities[i]->Accept(writer);

    xmlvmdefinitie->GetVoedingsmiddelbasis().GetVoedingsmiddelheader().Setunit(vmdefinities[i]->GetUnit().GetName());
    xmlvmdefinitie->GetVoedingsmiddelbasis().Setvrijeportie(vmdefinities[i]->HasFreeFPPortion() ? WW_GENERATED_NAMESPACE::XmlVoedingsmiddelbasis::vrijeportie_true : WW_GENERATED_NAMESPACE::XmlVoedingsmiddelbasis::vrijeportie_false);
    if (vmdefinities[i]->HasFreeFPPortion())
      xmlvmdefinitie->GetVoedingsmiddelbasis().Setvrijepunten(Str::ToTString(vmdefinities[i]->GetFreeFPPortionPoints()));
    xmlvmdefinitie->GetVoedingsmiddelbasis().Setvrijeppportie(vmdefinities[i]->HasFreePPPortion() ? WW_GENERATED_NAMESPACE::XmlVoedingsmiddelbasis::vrijeppportie_true : WW_GENERATED_NAMESPACE::XmlVoedingsmiddelbasis::vrijeppportie_false);
    if (vmdefinities[i]->HasFreePPPortion())
      xmlvmdefinitie->GetVoedingsmiddelbasis().Setvrijepppunten(Str::ToTString(vmdefinities[i]->GetFreePPPortionPoints()));
    xmlvmdefinitie->Setfavoriet(vmdefinities[i]->IsFavourite()
              ? WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldef::favoriet_true
              : WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldef::favoriet_false);

    xmlvmdefinities->Add(xmlvmdefinitie);

    const std::vector<WW::Portie *> & portielist = vmdefinities[i]->GetPortieList();
    for (size_t p = 0; p < vmdefinities[i]->GetPortieList().size(); ++p)
    {
      WW_GENERATED_NAMESPACE::XmlPortie * portie = new WW_GENERATED_NAMESPACE::XmlPortie;
      portie->Setnaam(portielist[p]->GetName().Get());
      portie->Seteenheden(Str::ToTString(portielist[p]->GetUnits()));
      xmlvmdefinitie->Add(portie);
    }

    if (vmdefinities[i]->HasSterrePortion())
      xmlvmdefinitie->GetVoedingsmiddelbasis().Setsterreportie(vmdefinities[i]->GetSterrePortion()->GetName().Get());
  }

  WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldefsWriter writer;
  writer.Write(aFilename, *xmlvmdefinities);
  delete xmlvmdefinities;

  return RESULT_Ok;
}


XmlBase::eRESULT XmlWriter::WriteRecepten(const std::tstring & aFilename)
{
  WW_GENERATED_NAMESPACE::XmlReceptdefs * xmlrecepten = new WW_GENERATED_NAMESPACE::XmlReceptdefs;

  const std::vector<WW::ReceptDefinitie *> & recepten = mModel.GetReceptDefs();
  for (size_t i = 0; i < recepten.size(); ++i)
  {
    WW_GENERATED_NAMESPACE::XmlReceptdef * recept = new WW_GENERATED_NAMESPACE::XmlReceptdef;
    recept->Setnaam(recepten[i]->GetName());
    recept->Setporties(Str::ToTString(recepten[i]->GetPortions()));
    xmlrecepten->Add(recept);

    XmlReceptItemCreateVisitor visitor(*this, *recept);

    for (size_t j = 0; j < recepten[i]->GetItems().size(); ++j)
      recepten[i]->GetItems()[j]->Accept(visitor);
  }

  WW_GENERATED_NAMESPACE::XmlReceptdefsWriter writer;
  writer.Write(aFilename, *xmlrecepten);
  delete xmlrecepten;

  return RESULT_Ok;
}


XmlBase::eRESULT XmlWriter::WriteGerechten(const std::tstring & aFilename)
{
  WW_GENERATED_NAMESPACE::XmlGerechtdefs * xmlgerechten = new WW_GENERATED_NAMESPACE::XmlGerechtdefs;

  const std::vector<WW::GerechtDefinitie *> & restaurantgerechten = mModel.GetGerechtDefs();
  for (size_t i = 0; i < restaurantgerechten.size(); ++i)
  {
    WW_GENERATED_NAMESPACE::XmlGerechtdef * restaurantgerecht = new WW_GENERATED_NAMESPACE::XmlGerechtdef;
    restaurantgerecht->Setnaam(restaurantgerechten[i]->GetName());
    xmlgerechten->Add(restaurantgerecht);
  }

  WW_GENERATED_NAMESPACE::XmlGerechtdefsWriter xmlwriter;
  xmlwriter.Write(aFilename, *xmlgerechten);
  delete xmlgerechten;
  return RESULT_Ok;
}


XmlBase::eRESULT XmlWriter::WriteWeeks(const std::tstring & aDirectory)
{
  eRESULT result = RESULT_Ok;
 
  const std::vector<WW::Week *> & weeks = mModel.GetWeeks();
  for (size_t i = 0; i < weeks.size() && result == RESULT_Ok; ++i)
  {
    Utils::Date startdate = weeks[i]->GetStartDate();
    result = Write(*weeks[i], aDirectory + _T("\\week") + Utils::ToString(startdate) + _T(".xml"));
  }

  return result;
}


XmlBase::eRESULT XmlWriter::Create(const WW::Portie & aPortie, WW_GENERATED_NAMESPACE::XmlPortie & anXmlPortie)
{
  anXmlPortie.Seteenheden(Str::ToTString(aPortie.GetUnits()));
  anXmlPortie.Setnaam(aPortie.GetName().Get());
  return RESULT_Ok;
}


XmlBase::eRESULT XmlWriter::Create(const WW::CalculatedLot & aLot, WW_GENERATED_NAMESPACE::XmlStandardlot & anXmlLot)
{
  anXmlLot.Sethoeveelheid(Str::ToTString(aLot.GetNumberOfPortions()));

  WW_GENERATED_NAMESPACE::XmlVoedingswaarde * xmlVoedingswaarde = new WW_GENERATED_NAMESPACE::XmlVoedingswaarde;
  assert(anXmlLot.GetPuntenper100() == NULL);
  assert(anXmlLot.GetVoedingswaarde() == NULL);

  xmlVoedingswaarde->Setkcalper100(Str::ToTString(aLot.GetKCalPer100Units()));
  xmlVoedingswaarde->Setvetper100(Str::ToTString(aLot.GetVetPer100Units()));
  xmlVoedingswaarde->Setkoolhydratenper100(Str::ToTString(aLot.GetKoolhydratenPer100Units()));
  xmlVoedingswaarde->Seteiwitper100(Str::ToTString(aLot.GetEiwitPer100Units()));
  xmlVoedingswaarde->Setvezelsper100(Str::ToTString(aLot.GetVezelsPer100Units()));

  anXmlLot.Add(xmlVoedingswaarde);

  Create(aLot.GetPortie(), anXmlLot.GetPortie());
  return RESULT_Ok;
}


XmlBase::eRESULT XmlWriter::Create(const WW::FixedLot & aLot, WW_GENERATED_NAMESPACE::XmlStandardlot & anXmlLot)
{
  anXmlLot.Sethoeveelheid(Str::ToTString(aLot.GetNumberOfPortions()));

  WW_GENERATED_NAMESPACE::XmlPuntenper100 * xmlpuntenper100 = new WW_GENERATED_NAMESPACE::XmlPuntenper100;
  assert(anXmlLot.GetPuntenper100() == NULL);
  assert(anXmlLot.GetVoedingswaarde() == NULL);

  xmlpuntenper100->Setpunten(Str::ToTString(aLot.GetPointsPer100Units()));
  anXmlLot.Add(xmlpuntenper100);

  Create(aLot.GetPortie(), anXmlLot.GetPortie());
  return RESULT_Ok;
}


XmlBase::eRESULT XmlWriter::Create(const WW::FreeLot & aLot, WW_GENERATED_NAMESPACE::XmlFreelot & anXmlLot)
{
  anXmlLot.Setpunten(Str::ToTString(aLot.GetPoints()));
  return RESULT_Ok;
}


XmlBase::eRESULT XmlWriter::Create(const WW::Voedingsmiddel &   aMiddel,
                                   WW_GENERATED_NAMESPACE::XmlVoedingsmiddel &  anXmlMiddel)
{
  anXmlMiddel.Setnaam(aMiddel.GetName());
  anXmlMiddel.Setcategorie(aMiddel.GetCategory().Get());
  anXmlMiddel.Setunit(aMiddel.GetUnit().GetName());

  XmlLotCreateVisitor visitor(*this, anXmlMiddel);
  const_cast<WW::Voedingsmiddel &>(aMiddel).GetLot().Accept(visitor);

  return RESULT_Ok;
}


XmlBase::eRESULT XmlWriter::Create(const WW::Recept &   aRecept,
                                   WW_GENERATED_NAMESPACE::XmlRecept &  anXmlRecept)
{
  anXmlRecept.Setnaam(aRecept.GetName());
  anXmlRecept.Sethoeveelheid(Str::ToTString(aRecept.GetNumberOfPortions()));
  anXmlRecept.Setpunten(Str::ToTString(aRecept.GetPointsPerPortion()));
  return RESULT_Ok;
}


XmlBase::eRESULT XmlWriter::Create(const WW::Gerecht &                  aGerecht,
                                   WW_GENERATED_NAMESPACE::XmlGerecht & anXmlGerecht)
{
  anXmlGerecht.Setnaam(aGerecht.GetName());
  anXmlGerecht.Sethoeveelheid(Str::ToTString(aGerecht.GetNumberOfPortions()));
  anXmlGerecht.Setpunten(Str::ToTString(aGerecht.GetPointsPerPortion()));
  return RESULT_Ok;
}


XmlBase::eRESULT XmlWriter::Create(const WW::ManualItem &                     anItem,
                                   WW_GENERATED_NAMESPACE::XmlHandmatigitem & anXmlItem)
{
  anXmlItem.Setnaam(anItem.GetName());
  anXmlItem.Sethoeveelheid(Str::ToTString(anItem.GetAmount()));
  anXmlItem.Setpunten(Str::ToTString(anItem.GetPoints()));
  return RESULT_Ok;
}


XmlBase::eRESULT XmlWriter::Create(const WW::Day &  aDay,
                                   WW_GENERATED_NAMESPACE::XmlDag & aDag)
{
  aDag.Setdatum(Utils::ToString(aDay.GetDate()));
  if (!Math::Equals(aDay.GetWeight(), 0))
    aDag.Setgewicht(Str::ToTString(aDay.GetWeight()));
  if (!Math::Equals(aDay.GetFreeBonusPoints(), 0))
    aDag.Setbonuspunten(Str::ToTString(aDay.GetFreeBonusPoints()));

  for (std::list<WW::Bonus>::const_iterator citer = aDay.GetBonuses().begin();
       citer != aDay.GetBonuses().end();
       ++citer)
  {
    WW_GENERATED_NAMESPACE::XmlBonuscell * xmlcell = new WW_GENERATED_NAMESPACE::XmlBonuscell;
    xmlcell->Setgewicht((int)aDay.GetWeight());
    switch (citer->GetIntensity())
    {
      case WW::Bonus::INTENSITY::High:
        xmlcell->Setintensiteit(WW_GENERATED_NAMESPACE::XmlBonuscell::intensiteit_hoog);
        break;
      case WW::Bonus::INTENSITY::Medium:
        xmlcell->Setintensiteit(WW_GENERATED_NAMESPACE::XmlBonuscell::intensiteit_middel);
        break;
      case WW::Bonus::INTENSITY::Low:
        xmlcell->Setintensiteit(WW_GENERATED_NAMESPACE::XmlBonuscell::intensiteit_laag);
        break;
    }

    xmlcell->Setminuten(citer->GetDuration());
    xmlcell->Setpunten(citer->GetPoints());

    aDag.Add(xmlcell);
  }

  aDag.Setbonuspunten(Str::ToTString(aDay.GetFreeBonusPoints()));

  const std::vector<WW::Item *> & items = aDay.GetItems();
  XmlDagItemCreateVisitor visitor(*this, aDag);
  for (size_t i = 0; i < items.size(); ++i)
    items[i]->Accept(visitor);

  return RESULT_Ok;
}


XmlBase::eRESULT XmlWriter::Write(WW::Week & aWeek, const std::tstring & aFilename)
{
  WW_GENERATED_NAMESPACE::XmlWeek * xmlweek = new WW_GENERATED_NAMESPACE::XmlWeek;

  xmlweek->Setbegindatum(Utils::ToString(aWeek.GetStartDate()));
  xmlweek->Seteinddatum(Utils::ToString(aWeek.GetEndDate()));
  xmlweek->Setpunten(Str::ToTString(aWeek.GetPoints()));
  xmlweek->Setweekpunten(Str::ToTString(aWeek.GetSaveablePoints()));
  xmlweek->Setstartweight(Str::ToTString(aWeek.GetStartWeight()));

  switch (aWeek.GetStrategy())
  {
  case WW::STRATEGY_TYPE::FlexiPoints:
    xmlweek->Setstrategie(WW_GENERATED_NAMESPACE::XmlWeek::strategie_FlexiPoints);
    break;
  case WW::STRATEGY_TYPE::ProPoints:
    xmlweek->Setstrategie(WW_GENERATED_NAMESPACE::XmlWeek::strategie_ProPoints);
    break;
  case WW::STRATEGY_TYPE::KCal:
    xmlweek->Setstrategie(WW_GENERATED_NAMESPACE::XmlWeek::strategie_KCal);
    break;
  case WW::STRATEGY_TYPE::CarboHydrates:
    xmlweek->Setstrategie(WW_GENERATED_NAMESPACE::XmlWeek::strategie_CarboHydrates);
    break;
  default:
    assert(false);
  }

  const std::vector<WW::Day *> & days = aWeek.GetDays();
  for (size_t i = 0; i < days.size(); ++i)
  {
    if (days[i]->IsEmpty())
      continue;
    WW_GENERATED_NAMESPACE::XmlDag * dag = new WW_GENERATED_NAMESPACE::XmlDag;
    Create(*days[i], *dag);
    xmlweek->Add(dag);
  }

  WW_GENERATED_NAMESPACE::XmlWeekWriter xmlwriter;
  xmlwriter.Write(aFilename, *xmlweek);
  delete xmlweek;

  return RESULT_Ok;
}


} // namespace WW_NAMESPACE