#include "stdafx.h"

#include "Xml01Reader.h"

#include <stdlib.h>
#include <tchar.h>

#include "Utilities/FileUtils.h"

#include "WW/WWGenerated01/XmlDag.h"
#include "WW/WWGenerated01/XmlFreelot.h"
#include "WW/WWGenerated01/XmlGerecht.h"
#include "WW/WWGenerated01/XmlGerechtDef.h"
#include "WW/WWGenerated01/XmlGerechtDefs.h"
#include "WW/WWGenerated01/XmlGerechtDefsReader.h"
#include "WW/WWGenerated01/XmlHandmatigitem.h"
#include "WW/WWGenerated01/XmlPersonalia.h"
#include "WW/WWGenerated01/XmlPersonaliaReader.h"
#include "WW/WWGenerated01/XmlPortie.h"
#include "WW/WWGenerated01/XmlPortieomschrijving.h"
#include "WW/WWGenerated01/XmlRecept.h"
#include "WW/WWGenerated01/XmlReceptdef.h"
#include "WW/WWGenerated01/XmlReceptdefs.h"
#include "WW/WWGenerated01/XmlReceptdefsReader.h"
#include "WW/WWGenerated01/XmlStandardlot.h"
#include "WW/WWGenerated01/XmlUnit.h"
#include "WW/WWGenerated01/XmlUnits.h"
#include "WW/WWGenerated01/XmlUnitsReader.h"
#include "WW/WWGenerated01/XmlVoedingsmiddel.h"
#include "WW/WWGenerated01/XmlVoedingsmiddelDef.h"
#include "WW/WWGenerated01/XmlVoedingsmiddelDefs.h"
#include "WW/WWGenerated01/XmlVoedingsmiddelDefsReader.h"
#include "WW/WWGenerated01/XmlWeek.h"
#include "WW/WWGenerated01/XmlWeekReader.h"

#include "../Gerecht.h"
#include "../Personalia.h"
#include "../Recept.h"
#include "../ReceptDefinitie.h"
#include "../VoedingsMiddel.h"
#include "../VoedingsmiddelDefinitie.h"
#include "../Week.h"
#include "../WWDefinitions.h"

namespace WW_NAMESPACE
{


  XmlReader::XmlReader(WW::Model & aModel)
: mModel(aModel)
{
}


XmlBase::eRESULT XmlReader::Read(const std::tstring & aDirectory)
{
  eRESULT result = ReadPersonalia(aDirectory + _T("\\personalia.xml"));
  if (result == RESULT_Ok)
    result = ReadVoedingsmiddelDefinities(aDirectory + _T("\\voedingsmiddeldefinities.xml"));
  if (result == RESULT_Ok)
    result = ReadUnits(aDirectory + _T("\\units.xml"));
  if (result == RESULT_Ok)
    result = ReadRecepten(aDirectory + _T("\\recepten.xml"));
  if (result == RESULT_Ok)
    result = ReadGerechten(aDirectory + _T("\\restaurantgerechten.xml"));
  if (result == RESULT_Ok)
    result = ReadWeeks(aDirectory);

  return result;
}


XmlBase::eRESULT XmlReader::ReadPersonalia(const std::tstring & aDirectory)
{
  WW_GENERATED_NAMESPACE::XmlPersonaliaReader reader;
  WW_GENERATED_NAMESPACE::XmlPersonalia * xmlpersonalia;
  switch (reader.Read(aDirectory, xmlpersonalia))
  {
  case WW_GENERATED_NAMESPACE::XmlPersonaliaReader::RESULT_Ok:
    if (xmlpersonalia == NULL)
      return RESULT_Ok;
    break;
  case WW_GENERATED_NAMESPACE::XmlPersonaliaReader::RESULT_FileNotFound:
    return RESULT_FileNotFound;
  case WW_GENERATED_NAMESPACE::XmlPersonaliaReader::RESULT_ErrorInFilename:
    return RESULT_ErrorInFilename;
  case WW_GENERATED_NAMESPACE::XmlPersonaliaReader::RESULT_FileOpenError:
    return RESULT_FileOpenError;
  case WW_GENERATED_NAMESPACE::XmlPersonaliaReader::RESULT_ErrorInFile:
    return RESULT_ErrorInFile;
  case WW_GENERATED_NAMESPACE::XmlPersonaliaReader::RESULT_ParserError:
    return RESULT_ParserError;
  case WW_GENERATED_NAMESPACE::XmlPersonaliaReader::RESULT_InterpretError:
  case WW_GENERATED_NAMESPACE::XmlPersonaliaReader::RESULT_WriteError:
  default:
    return RESULT_InterpretError;
    break;
  }

  WW::Personalia * personalia = new WW::Personalia(xmlpersonalia->Getgebruikersnaam());
  personalia->SetName(xmlpersonalia->Getnaam());
  Utils::Date date(Utils::Date::Today());
  if (Utils::ToDate(xmlpersonalia->Getgeboren(), date))
    personalia->SetDateOfBirth(date);
  personalia->SetGeslacht(xmlpersonalia->Getgeslacht() == WW_GENERATED_NAMESPACE::XmlPersonalia::geslacht_Mannelijk ? WW::Personalia::GS_Mannelijk : WW::Personalia::GS_Vrouwelijk);
  switch (xmlpersonalia->Getwerk())
  {
  case WW_GENERATED_NAMESPACE::XmlPersonalia::werk_Zittend:
    personalia->SetTypeOfWork(WW::Personalia::WT_Zittend);
    break;
  case WW_GENERATED_NAMESPACE::XmlPersonalia::werk_Staand:
    personalia->SetTypeOfWork(WW::Personalia::WT_Staand);
    break;
  case WW_GENERATED_NAMESPACE::XmlPersonalia::werk_Lopend:
    personalia->SetTypeOfWork(WW::Personalia::WT_Lopend);
    break;
  case WW_GENERATED_NAMESPACE::XmlPersonalia::werk_Zwaar:
    personalia->SetTypeOfWork(WW::Personalia::WT_Zwaar);
    break;
  }

  personalia->SetFPPuntenTotaal(_ttoi(xmlpersonalia->Getpunten().c_str()));
  personalia->SetPPPuntenTotaal(_ttoi(xmlpersonalia->Getpppunten().c_str()));
  personalia->SetPPWeekPuntenTotaal(_ttoi(xmlpersonalia->Getppweekpunten().c_str()));
  personalia->SetStreefGewicht(Str::ToDouble(xmlpersonalia->Getstreefgewicht().c_str()));
  personalia->SetStartGewicht(Str::ToDouble(xmlpersonalia->Getstartgewicht().c_str()));
  personalia->SetHuidigGewicht(Str::ToDouble(xmlpersonalia->Gethuidiggewicht().c_str()));
  personalia->SetLengte(Str::ToInt(xmlpersonalia->Getlengte().c_str()));

  switch (xmlpersonalia->Getstrategie())
  {
  case WW_GENERATED_NAMESPACE::XmlPersonalia::strategie_FlexiPoints:
    personalia->SetStrategy(WW::ST_FlexiPoints);
    break;
  case WW_GENERATED_NAMESPACE::XmlPersonalia::strategie_ProPoints:
    personalia->SetStrategy(WW::ST_ProPoints);
    break;
  default:
    return RESULT_InterpretError;
  }

  mModel.Add(personalia);

  delete xmlpersonalia;

  return RESULT_Ok;

}

XmlBase::eRESULT XmlReader::ReadUnits(const std::tstring & aDirectory)
{
  WW_GENERATED_NAMESPACE::XmlUnitsReader reader;
  WW_GENERATED_NAMESPACE::XmlUnits * xmlunits;
  switch (reader.Read(aDirectory, xmlunits))
  {
  case WW_GENERATED_NAMESPACE::XmlUnitsReader::RESULT_Ok:
    if (xmlunits == NULL)
      return RESULT_Ok;
    break;
  case WW_GENERATED_NAMESPACE::XmlUnitsReader::RESULT_FileNotFound:
    return RESULT_FileNotFound;
  case WW_GENERATED_NAMESPACE::XmlUnitsReader::RESULT_ErrorInFilename:
    return RESULT_ErrorInFilename;
  case WW_GENERATED_NAMESPACE::XmlUnitsReader::RESULT_FileOpenError:
    return RESULT_FileOpenError;
  case WW_GENERATED_NAMESPACE::XmlUnitsReader::RESULT_ErrorInFile:
    return RESULT_ErrorInFile;
  case WW_GENERATED_NAMESPACE::XmlUnitsReader::RESULT_ParserError:
    return RESULT_ParserError;
  case WW_GENERATED_NAMESPACE::XmlUnitsReader::RESULT_InterpretError:
  case WW_GENERATED_NAMESPACE::XmlUnitsReader::RESULT_WriteError:
  default:
    return RESULT_InterpretError;
    break;
  }

  const std::vector<WW_GENERATED_NAMESPACE::XmlUnit *> & units(xmlunits->GetUnitList());
  for (size_t i = 0; i < units.size(); ++i) 
    mModel.Add(WW::Unit(mModel, units[i]->Getnaam()));

  delete xmlunits;

  return RESULT_Ok;
}


XmlBase::eRESULT XmlReader::ReadVoedingsmiddelDefinities(const std::tstring & aDirectory)
{
  WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldefsReader reader;
  WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldefs * xmlvoedingsmiddeldefs;
  switch (reader.Read(aDirectory, xmlvoedingsmiddeldefs))
  {
  case WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldefsReader::RESULT_Ok:
    if (xmlvoedingsmiddeldefs == NULL)
      return RESULT_Ok;
    break;
  case WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldefsReader::RESULT_FileNotFound:
    return RESULT_FileNotFound;
  case WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldefsReader::RESULT_ErrorInFilename:
    return RESULT_ErrorInFilename;
  case WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldefsReader::RESULT_FileOpenError:
    return RESULT_FileOpenError;
  case WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldefsReader::RESULT_ErrorInFile:
    return RESULT_ErrorInFile;
  case WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldefsReader::RESULT_ParserError:
    return RESULT_ParserError;
  case WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldefsReader::RESULT_InterpretError:
  case WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldefsReader::RESULT_WriteError:
  default:
    return RESULT_InterpretError;
    break;
  }

  const std::vector<WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldef *> vmlist = xmlvoedingsmiddeldefs->GetVoedingsmiddeldefList();
  for (size_t i = 0; i < vmlist.size(); ++i)
  {
    WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldef * vm = vmlist[i];
    WW::VoedingsmiddelDefinitie * definitie = new WW::VoedingsmiddelDefinitie(vm->Getnaam(),
                                                                              mModel.GetCalculator(),
                                                                              WW::Unit(mModel, vm->Getunit()));
    if (!vm->Getcategorie().empty())
      definitie->SetCategory(WW::CategorieNaam(mModel, vmlist[i]->Getcategorie()));
    if (!vm->Getmerk().empty())
      definitie->SetMerk(WW::MerkNaam(mModel, vmlist[i]->Getmerk()));
    definitie->SetKCalPer100Units(Str::ToDouble(vmlist[i]->Getkcalper100().c_str()));
    definitie->SetVetPer100Units(Str::ToDouble(vmlist[i]->Getvetper100().c_str()));
    definitie->SetKoolhydratenPer100Units(Str::ToDouble(vmlist[i]->Getkoolhydratenper100().c_str()));
    definitie->SetEiwitPer100Units(Str::ToDouble(vmlist[i]->Geteiwitper100().c_str()));
    definitie->SetVezelsPer100Units(Str::ToDouble(vmlist[i]->Getvezelsper100().c_str()));
    definitie->SetHasFreeFPPortion(vmlist[i]->Getvrijeportie() == WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldef::vrijeportie_true);
    if (definitie->HasFreeFPPortion())
      definitie->SetFreeFPPortionPoints(Str::ToDouble(vmlist[i]->Getvrijepunten()));
    definitie->SetHasFreePPPortion(vmlist[i]->Getvrijeppportie() == WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldef::vrijeppportie_true);
    if (definitie->HasFreePPPortion())
      definitie->SetFreePPPortionPoints(Str::ToDouble(vmlist[i]->Getvrijepppunten()));

    const std::vector<WW_GENERATED_NAMESPACE::XmlPortie *> & portielist = vmlist[i]->GetPortieList();
    for (size_t p = 0; p < portielist.size(); ++p)
    {
      WW::Portie * portie = new WW::Portie(WW::PortieNaam(mModel, portielist[p]->Getnaam()));
      portie->SetUnits(Str::ToDouble(portielist[p]->Geteenheden().c_str()));
      mModel.Add(portie->GetName());
      definitie->AddPortie(portie);
    }

    if (!vmlist[i]->Getsterreportie().empty())
      definitie->SetSterrePortie(WW::PortieNaam(mModel, vmlist[i]->Getsterreportie()));

    mModel.Add(definitie);
  }

  delete xmlvoedingsmiddeldefs;

  return RESULT_Ok;
}


XmlBase::eRESULT XmlReader::ReadRecepten(const std::tstring & aDirectory)
{
  WW_GENERATED_NAMESPACE::XmlReceptdefsReader reader;
  WW_GENERATED_NAMESPACE::XmlReceptdefs * xmlreceptdefs;
  switch (reader.Read(aDirectory, xmlreceptdefs))
  {
  case WW_GENERATED_NAMESPACE::XmlReceptdefsReader::RESULT_Ok:
    if (xmlreceptdefs == NULL)
      return RESULT_Ok;
    break;
  case WW_GENERATED_NAMESPACE::XmlReceptdefsReader::RESULT_FileNotFound:
    return RESULT_FileNotFound;
  case WW_GENERATED_NAMESPACE::XmlReceptdefsReader::RESULT_ErrorInFilename:
    return RESULT_ErrorInFilename;
  case WW_GENERATED_NAMESPACE::XmlReceptdefsReader::RESULT_FileOpenError:
    return RESULT_FileOpenError;
  case WW_GENERATED_NAMESPACE::XmlReceptdefsReader::RESULT_ErrorInFile:
    return RESULT_ErrorInFile;
  case WW_GENERATED_NAMESPACE::XmlReceptdefsReader::RESULT_ParserError:
    return RESULT_ParserError;
  case WW_GENERATED_NAMESPACE::XmlReceptdefsReader::RESULT_InterpretError:
  case WW_GENERATED_NAMESPACE::XmlReceptdefsReader::RESULT_WriteError:
  default:
    return RESULT_InterpretError;
    break;
  }

  const std::vector<WW_GENERATED_NAMESPACE::XmlReceptdef *> receptlist = xmlreceptdefs->GetReceptdefList();
  for (size_t i = 0; i < receptlist.size(); ++i)
  {
    WW::ReceptDefinitie * receptdef = new WW::ReceptDefinitie(receptlist[i]->Getnaam());
    receptdef->SetPortions(Str::ToInt(receptlist[i]->Getporties()));
    const std::vector<WW_GENERATED_NAMESPACE::XmlVoedingsmiddel *> & voedingsmiddellist(receptlist[i]->GetVoedingsmiddelList());
    for (size_t j = 0; j < voedingsmiddellist.size(); ++j)
    {
      WW::Voedingsmiddel * voedingsmiddel = Create(*voedingsmiddellist[j]);
      if (voedingsmiddel != NULL)
        receptdef->Add(voedingsmiddel);
    }

    mModel.Add(receptdef);
  }

  delete xmlreceptdefs;

  return RESULT_Ok;
}


XmlBase::eRESULT XmlReader::ReadWeeks(const std::tstring & aDirectory)
{
  std::tstring filename(aDirectory + _T("\\week*.xml"));
  WIN32_FIND_DATA finddata;
  HANDLE hFind = FindFirstFile(filename.c_str(), &finddata);
  bool bContinue = true;
  while (bContinue) {
    ReadWeek(aDirectory + _T("\\") + finddata.cFileName);
    bContinue = FindNextFile(hFind, &finddata) != FALSE;
  }

  FindClose(hFind);

  return RESULT_Ok;
}


XmlBase::eRESULT XmlReader::ReadWeek(const std::tstring & aDirectory)
{
  WW_GENERATED_NAMESPACE::XmlWeekReader reader;
  WW_GENERATED_NAMESPACE::XmlWeek * xmlweek;
  switch (reader.Read(aDirectory, xmlweek))
  {
  case WW_GENERATED_NAMESPACE::XmlWeekReader::RESULT_Ok:
    if (xmlweek == NULL)
      return RESULT_Ok;
    break;
  case WW_GENERATED_NAMESPACE::XmlWeekReader::RESULT_FileNotFound:
    return RESULT_FileNotFound;
  case WW_GENERATED_NAMESPACE::XmlWeekReader::RESULT_ErrorInFilename:
    return RESULT_ErrorInFilename;
  case WW_GENERATED_NAMESPACE::XmlWeekReader::RESULT_FileOpenError:
    return RESULT_FileOpenError;
  case WW_GENERATED_NAMESPACE::XmlWeekReader::RESULT_ErrorInFile:
    return RESULT_ErrorInFile;
  case WW_GENERATED_NAMESPACE::XmlWeekReader::RESULT_ParserError:
    return RESULT_ParserError;
  case WW_GENERATED_NAMESPACE::XmlWeekReader::RESULT_InterpretError:
  case WW_GENERATED_NAMESPACE::XmlWeekReader::RESULT_WriteError:
  default:
    return RESULT_InterpretError;
    break;
  }

  WW::Week * week = new WW::Week(Utils::ToDate(xmlweek->Getbegindatum()),
                                 Utils::ToDate(xmlweek->Geteinddatum()));
  week->SetPoints(Str::ToDouble(xmlweek->Getpunten()));
  week->SetSaveablePoints(Str::ToDouble(xmlweek->Getweekpunten()));
  week->SetStartWeight(Str::ToDouble(xmlweek->Getstartweight()));

  switch (xmlweek->Getstrategie())
  {
  case WW_GENERATED_NAMESPACE::XmlWeek::strategie_FlexiPoints:
    week->SetStrategy(WW::ST_FlexiPoints, mModel);
    break;
  case WW_GENERATED_NAMESPACE::XmlWeek::strategie_ProPoints:
    week->SetStrategy(WW::ST_ProPoints, mModel);
    break;
  }

  if (!mModel.Add(week))
  {
    delete week;
    return RESULT_InterpretError;
  }

  const std::vector<WW_GENERATED_NAMESPACE::XmlDag *> dagen(xmlweek->GetDagList());
  for (size_t i = 0; i < dagen.size(); ++i)
  {
    WW::Day * dag = Create(*dagen[i]);
    if (!week->Add(dag))
    {
      delete dag;
      return RESULT_InterpretError;
    }
  }

  delete xmlweek;

  return RESULT_Ok;
}


XmlBase::eRESULT XmlReader::ReadGerechten(const std::tstring & aDirectory)
{
  (void)aDirectory;

  return RESULT_Ok;
}


WW::Portie XmlReader::Create(const WW_GENERATED_NAMESPACE::XmlPortie & aPortie)
{
  WW::Portie portie(WW::PortieNaam(mModel, aPortie.Getnaam()));
  portie.SetUnits(Str::ToDouble(aPortie.Geteenheden()));

  return portie;
}


WW::Voedingsmiddel * XmlReader::Create(const WW_GENERATED_NAMESPACE::XmlVoedingsmiddel & aVoedingsmiddel)
{
  WW::Lot * lot = NULL;
  if (aVoedingsmiddel.GetStandardlot() != NULL)
  {
    const WW_GENERATED_NAMESPACE::XmlStandardlot * xmllot = aVoedingsmiddel.GetStandardlot();
    WW::PortionedLot * plot = NULL;
    if (xmllot->Getsterrelot() == WW_GENERATED_NAMESPACE::XmlStandardlot::sterrelot_false)
      plot = new WW::StandardLot(mModel.GetCalculator(), Create(aVoedingsmiddel.GetStandardlot()->GetPortie()));
    else
      plot = new WW::SterreLot(mModel.GetCalculator(), Create(aVoedingsmiddel.GetStandardlot()->GetPortie()));
    plot->SetAmount(Str::ToDouble(aVoedingsmiddel.GetStandardlot()->Gethoeveelheid()));
    plot->SetKCalPer100Units(Str::ToDouble(aVoedingsmiddel.GetStandardlot()->Getkcalper100()));
    plot->SetVetPer100Units(Str::ToDouble(aVoedingsmiddel.GetStandardlot()->Getvetper100()));
    plot->SetKoolhydratenPer100Units(Str::ToDouble(aVoedingsmiddel.GetStandardlot()->Getkoolhydratenper100().c_str()));
    plot->SetEiwitPer100Units(Str::ToDouble(aVoedingsmiddel.GetStandardlot()->Geteiwitper100().c_str()));
    plot->SetVezelsPer100Units(Str::ToDouble(aVoedingsmiddel.GetStandardlot()->Getvezelsper100().c_str()));
    lot = plot;
  }
  else if (aVoedingsmiddel.GetFreelot() != NULL)
  {
    WW::FreeLot * flot = new WW::FreeLot(mModel.GetStrategy(), Str::ToDouble(aVoedingsmiddel.GetFreelot()->Getpunten()));
    lot = flot;
  }
  else
  {
    WW::VoedingsmiddelDefinitie * def = mModel.FindVoedingsmiddelDefinitie(aVoedingsmiddel.Getnaam());
    if (def == NULL)
    {
      ::MessageBox(0, (_T("Unable to interpret voedingsmiddel ") + aVoedingsmiddel.Getnaam()).c_str(),
                   _T("ERROR"), MB_OK);
    }
    else
    {
      if (def->HasFreePortion(mModel.GetStrategy()))
      {
        lot = new WW::FreeLot(mModel.GetStrategy(), def->GetFreePortionPoints(mModel.GetStrategy()));
      }
      else if (!def->GetPortieList().empty())
      {
        WW::StandardLot * slot = new WW::StandardLot(mModel.GetCalculator(), *def->GetPortieList()[0]);
        slot->SetAmount(1);
        slot->SetKCalPer100Units(def->GetKCalPer100Units());
        slot->SetVetPer100Units(def->GetVetPer100Units());
        slot->SetKoolhydratenPer100Units(def->GetKoolhydratenPer100Units());
        slot->SetEiwitPer100Units(def->GetEiwitPer100Units());
        slot->SetVezelsPer100Units(def->GetVezelsPer100Units());
        lot = slot;
      }
      else
      {
        assert(false);
      }
    }
  }

  WW::Voedingsmiddel * voedingsmiddel = new WW::Voedingsmiddel(aVoedingsmiddel.Getnaam(),
                                                               lot,
                                                               WW::Unit(mModel, aVoedingsmiddel.Getunit()));
  voedingsmiddel->SetCategory(WW::CategorieNaam(mModel, aVoedingsmiddel.Getcategorie()));
  return voedingsmiddel;
}


WW::Recept * XmlReader::Create(const WW_GENERATED_NAMESPACE::XmlRecept & aRecept)
{
  WW::Recept * recept = new WW::Recept(aRecept.Getnaam());
  recept->SetPointsPerPortie(Str::ToDouble(aRecept.Getpunten()));
  recept->SetAmount(Str::ToDouble(aRecept.Gethoeveelheid()));
  return recept;
}


WW::Gerecht * XmlReader::Create(const WW_GENERATED_NAMESPACE::XmlGerecht & aGerecht)
{
  WW::Gerecht * gerecht = new WW::Gerecht(aGerecht.Getnaam(), Str::ToDouble(aGerecht.Getpunten()));
  gerecht->SetAmount(Str::ToDouble(aGerecht.Gethoeveelheid()));
  return gerecht;
}


WW::ManualItem * XmlReader::Create(const WW_GENERATED_NAMESPACE::XmlHandmatigitem & anItem)
{
  WW::ManualItem * item = new WW::ManualItem(anItem.Getnaam(), Str::ToDouble(anItem.Getpunten()));
  item->Set(Str::ToDouble(anItem.Getpunten()), Str::ToDouble(anItem.Gethoeveelheid()));
  return item;
}


WW::Day * XmlReader::Create(const WW_GENERATED_NAMESPACE::XmlDag & aDag)
{
  WW::Day * day = new WW::Day(Utils::ToDate(aDag.Getdatum()));
  if (!aDag.Getgewicht().empty())
    day->SetWeight(Str::ToDouble(aDag.Getgewicht().c_str()));

  if (!aDag.Getbonuspunten().empty())
    day->SetBonusPoints(Str::ToDouble(aDag.Getbonuspunten()));

  const std::vector<WW_GENERATED_NAMESPACE::XmlVoedingsmiddel *> & vmiddelen(aDag.GetVoedingsmiddelList());
  for (size_t i = 0; i < vmiddelen.size(); ++i)
    day->Add(Create(*vmiddelen[i]));

  const std::vector<WW_GENERATED_NAMESPACE::XmlRecept *> & recepten(aDag.GetReceptList());
  for (size_t i = 0; i < recepten.size(); ++i)
    day->Add(Create(*recepten[i]));

  const std::vector<WW_GENERATED_NAMESPACE::XmlGerecht *> & gerechten(aDag.GetGerechtList());
  for (size_t i = 0; i < gerechten.size(); ++i)
    day->Add(Create(*gerechten[i]));

  const std::vector<WW_GENERATED_NAMESPACE::XmlHandmatigitem *> & handmatig(aDag.GetHandmatigitemList());
  for (size_t i = 0; i < handmatig.size(); ++i)
    day->Add(Create(*handmatig[i]));

  return day;
}


} // namespace WW