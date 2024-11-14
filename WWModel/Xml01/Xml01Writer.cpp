#include "stdafx.h"

#include "Xml01Writer.h"

#include <tchar.h>

#include "Utilities/Date.h"
#include "Utilities/MathUtils.h"

#include "WW/WWGenerated01/XmlDag.h"
#include "WW/WWGenerated01/XmlFreeLot.h"
#include "WW/WWGenerated01/XmlGerecht.h"
#include "WW/WWGenerated01/XmlGerechtdef.h"
#include "WW/WWGenerated01/XmlGerechtdefs.h"
#include "WW/WWGenerated01/XmlGerechtdefsWriter.h"
#include "WW/WWGenerated01/XmlHandmatigitem.h"
#include "WW/WWGenerated01/XmlPortie.h"
#include "WW/WWGenerated01/XmlPersonalia.h"
#include "WW/WWGenerated01/XmlPersonaliaWriter.h"
#include "WW/WWGenerated01/XmlRecept.h"
#include "WW/WWGenerated01/XmlReceptdef.h"
#include "WW/WWGenerated01/XmlReceptdefs.h"
#include "WW/WWGenerated01/XmlReceptdefsWriter.h"
#include "WW/WWGenerated01/XmlStandardLot.h"
#include "WW/WWGenerated01/XmlUnit.h"
#include "WW/WWGenerated01/XmlUnits.h"
#include "WW/WWGenerated01/XmlUnitsWriter.h"
#include "WW/WWGenerated01/XmlVoedingsmiddel.h"
#include "WW/WWGenerated01/XmlVoedingsmiddeldef.h"
#include "WW/WWGenerated01/XmlVoedingsmiddeldefs.h"
#include "WW/WWGenerated01/XmlVoedingsmiddeldefsWriter.h"
#include "WW/WWGenerated01/XmlWeek.h"
#include "WW/WWGenerated01/XmlWeekWriter.h"

#include "../Day.h"
#include "../Personalia.h"
#include "../Recept.h"
#include "../ReceptDefinitie.h"
#include "../Gerecht.h"
#include "../GerechtDefinitie.h"
#include "../Unit.h"
#include "../VoedingsmiddelDefinitie.h"
#include "../Week.h"
#include "../WWModel.h"
#include "Xml01ItemCreateVisitor.h"
#include "Xml01LotCreateVisitor.h"

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
  xmlpersonalia->Setgeslacht(personalia->GetGeslacht() == WW::Personalia::GS_Mannelijk ? WW_GENERATED_NAMESPACE::XmlPersonalia::geslacht_Mannelijk : WW_GENERATED_NAMESPACE::XmlPersonalia::geslacht_Vrouwelijk);
  xmlpersonalia->Setgewicht(Str::ToTString(personalia->GetStreefGewicht()));
  xmlpersonalia->Setlengte(Str::ToTString(personalia->GetLengte()));
  xmlpersonalia->Setpunten(Str::ToTString(personalia->GetFPPuntenTotaal()));
  xmlpersonalia->Setpppunten(Str::ToTString(personalia->GetPPPuntenTotaal()));
  xmlpersonalia->Setppweekpunten(Str::ToTString(personalia->GetPPWeekPuntenTotaal()));
  xmlpersonalia->Setstreefgewicht(Str::ToTString(personalia->GetStreefGewicht()));
  xmlpersonalia->Setstartgewicht(Str::ToTString(personalia->GetStartGewicht()));
  xmlpersonalia->Sethuidiggewicht(Str::ToTString(personalia->GetHuidigGewicht()));
  xmlpersonalia->Setstreven(WW_GENERATED_NAMESPACE::XmlPersonalia::streven_Afvallen);
  switch (personalia->GetStrategy())
  {
  case WW::ST_FlexiPoints:
    xmlpersonalia->Setstrategie(WW_GENERATED_NAMESPACE::XmlPersonalia::strategie_FlexiPoints);
    break;
  case WW::ST_ProPoints:
    xmlpersonalia->Setstrategie(WW_GENERATED_NAMESPACE::XmlPersonalia::strategie_ProPoints);
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

  const std::vector<WW::VoedingsmiddelDefinitie *> & vmdefinities = mModel.GetVoedingsmiddelDefinities();
  for (size_t i = 0; i < vmdefinities.size(); ++i)
  {
    WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldef * vmdefinitie = new WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldef;
    vmdefinitie->Setnaam(vmdefinities[i]->GetName());
    if (!vmdefinities[i]->GetCategory().Get().empty())
      vmdefinitie->Setcategorie(vmdefinities[i]->GetCategory().Get());
    if (!vmdefinities[i]->GetMerk().Get().empty())
      vmdefinitie->Setmerk(vmdefinities[i]->GetMerk().Get());
    vmdefinitie->Setkcalper100(Str::ToTString(vmdefinities[i]->GetKCalPer100Units()));
    vmdefinitie->Setvetper100(Str::ToTString(vmdefinities[i]->GetVetPer100Units()));
    vmdefinitie->Setkoolhydratenper100(Str::ToTString(vmdefinities[i]->GetKoolhydratenPer100Units()));
    vmdefinitie->Seteiwitper100(Str::ToTString(vmdefinities[i]->GetEiwitPer100Units()));
    vmdefinitie->Setvezelsper100(Str::ToTString(vmdefinities[i]->GetVezelsPer100Units()));
    vmdefinitie->Setunit(vmdefinities[i]->GetUnit().GetName());
    vmdefinitie->Setvrijeportie(vmdefinities[i]->HasFreeFPPortion() ? WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldef::vrijeportie_true : WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldef::vrijeportie_false);
    if (vmdefinities[i]->HasFreeFPPortion())
      vmdefinitie->Setvrijepunten(Str::ToTString(vmdefinities[i]->GetFreeFPPortionPoints()));
    vmdefinitie->Setvrijeppportie(vmdefinities[i]->HasFreePPPortion() ? WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldef::vrijeppportie_true : WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldef::vrijeppportie_false);
    if (vmdefinities[i]->HasFreePPPortion())
      vmdefinitie->Setvrijepppunten(Str::ToTString(vmdefinities[i]->GetFreePPPortionPoints()));

    xmlvmdefinities->Add(vmdefinitie);

    const std::vector<WW::Portie *> & portielist = vmdefinities[i]->GetPortieList();
    for (size_t p = 0; p < vmdefinities[i]->GetPortieList().size(); ++p)
    {
      WW_GENERATED_NAMESPACE::XmlPortie * portie = new WW_GENERATED_NAMESPACE::XmlPortie;
      portie->Setnaam(portielist[p]->GetName().Get());
      portie->Seteenheden(Str::ToTString(portielist[p]->GetUnits()));
      vmdefinitie->Add(portie);
    }

    if (vmdefinities[i]->HasSterrePortion())
      vmdefinitie->Setsterreportie(vmdefinities[i]->GetSterrePortion()->GetName().Get());
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


XmlBase::eRESULT XmlWriter::Create(const WW::PortionedLot & aLot, WW_GENERATED_NAMESPACE::XmlStandardlot & anXmlLot)
{
  anXmlLot.Sethoeveelheid(Str::ToTString(aLot.GetAmount()));
  anXmlLot.Setkcalper100(Str::ToTString(aLot.GetKCalPer100Units()));
  anXmlLot.Setvetper100(Str::ToTString(aLot.GetVetPer100Units()));
  anXmlLot.Setkoolhydratenper100(Str::ToTString(aLot.GetKoolhydratenPer100Units()));
  anXmlLot.Seteiwitper100(Str::ToTString(aLot.GetEiwitPer100Units()));
  anXmlLot.Setvezelsper100(Str::ToTString(aLot.GetVezelsPer100Units()));
  Create(aLot.GetPortie(), anXmlLot.GetPortie());
  return RESULT_Ok;
}


XmlBase::eRESULT XmlWriter::Create(const WW::FreeLot & aLot, WW_GENERATED_NAMESPACE::XmlFreelot & anXmlLot)
{
  anXmlLot.Setpunten(Str::ToTString(aLot.GetPoints()));
  return RESULT_Ok;
}


XmlBase::eRESULT XmlWriter::Create(const WW::Voedingsmiddel &                   aMiddel,
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
  anXmlRecept.Sethoeveelheid(Str::ToTString(aRecept.GetAmount()));
  anXmlRecept.Setpunten(Str::ToTString(aRecept.GetPointsPerPortie()));
  return RESULT_Ok;
}


XmlBase::eRESULT XmlWriter::Create(const WW::Gerecht &  aGerecht,
                                   WW_GENERATED_NAMESPACE::XmlGerecht & anXmlGerecht)
{
  anXmlGerecht.Setnaam(aGerecht.GetName());
  anXmlGerecht.Sethoeveelheid(Str::ToTString(aGerecht.GetAmount()));
  anXmlGerecht.Setpunten(Str::ToTString(aGerecht.GetPointsPerPortie()));
  return RESULT_Ok;
}


XmlBase::eRESULT XmlWriter::Create(const WW::ManualItem &     anItem,
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

  aDag.Setbonuspunten(Str::ToTString(aDay.GetBonusPoints()));

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
  case WW::ST_FlexiPoints:
    xmlweek->Setstrategie(WW_GENERATED_NAMESPACE::XmlWeek::strategie_FlexiPoints);
    break;
  case WW::ST_ProPoints:
    xmlweek->Setstrategie(WW_GENERATED_NAMESPACE::XmlWeek::strategie_ProPoints);
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


} // namespace WW