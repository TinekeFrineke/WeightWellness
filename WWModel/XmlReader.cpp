#include "stdafx.h"

#include "XmlReader.h"

#include <stdlib.h>
#include <tchar.h>

#include "Utilities/FileUtils.h"

#include <Generated/XmlBonusCell.h>
#include <Generated/XmlBonusCellReader.h>
#include <Generated/XmlBonusList.h>
#include <Generated/XmlBonusListReader.h>
#include <Generated/XmlDag.h>
#include <Generated/XmlFreelot.h>
#include <Generated/XmlGerecht.h>
#include <Generated/XmlGerechtDef.h>
#include <Generated/XmlGerechtDefs.h>
#include <Generated/XmlGerechtDefsReader.h>
#include <Generated/XmlHandmatigitem.h>
#include <Generated/XmlPersonalia.h>
#include <Generated/XmlPersonaliaReader.h>
#include <Generated/XmlPortie.h>
#include <Generated/XmlPortieomschrijving.h>
#include <Generated/XmlPuntenPer100.h>
#include <Generated/XmlRecept.h>
#include <Generated/XmlReceptdef.h>
#include <Generated/XmlReceptdefs.h>
#include <Generated/XmlReceptdefsReader.h>
#include <Generated/XmlStandardlot.h>
#include <Generated/XmlUnit.h>
#include <Generated/XmlUnits.h>
#include <Generated/XmlUnitsReader.h>
#include <Generated/XmlVoedingsmiddel.h>
#include <Generated/XmlVoedingsmiddelDef.h>
#include <Generated/XmlVoedingsmiddelDefs.h>
#include <Generated/XmlVoedingsmiddelDefsReader.h>
#include <Generated/XmlVoedingswaarde.h>
#include <Generated/XmlWeek.h>
#include <Generated/XmlWeekReader.h>

#include "BonusPointsMap.h"
#include "Gerecht.h"
#include "ManualItem.h"
#include "Personalia.h"
#include "Recept.h"
#include "ReceptDefinitie.h"
#include "VoedingsMiddel.h"
#include "VoedingsmiddelDefinitie.h"
#include "Week.h"
#include "WWDefinitions.h"
#include "XmlVMCreateVisitor.h"

namespace WW_NAMESPACE
{


XmlReader::XmlReader(WW::Model & aModel)
: mModel(aModel)
{
}


XmlBase::Result XmlReader::Read(const std::tstring & aDirectory)
{
  Result result = ReadPersonalia(aDirectory + _T("\\personalia.xml"));
  if (result == Result::RESULT_Ok)
    result = ReadVoedingsmiddelDefinities(aDirectory + _T("\\voedingsmiddeldefinities.xml"));
  if (result == Result::RESULT_Ok)
    result = ReadUnits(aDirectory + _T("\\units.xml"));
  if (result == Result::RESULT_Ok)
    result = ReadRecepten(aDirectory + _T("\\recepten.xml"));
  if (result == Result::RESULT_Ok)
    result = ReadGerechten(aDirectory + _T("\\restaurantgerechten.xml"));
  if (result == Result::RESULT_Ok)
    result = ReadWeeks(aDirectory);
  if (result == Result::RESULT_Ok)
    result = ReadBonusCells(aDirectory);

  return result;
}


XmlBase::Result XmlReader::ReadPersonalia(const std::tstring & aDirectory)
{
  WW_GENERATED_NAMESPACE::XmlPersonaliaReader reader;
  WW_GENERATED_NAMESPACE::XmlPersonalia * xmlpersonalia;
  switch (reader.Read(aDirectory, xmlpersonalia))
  {
  case WW_GENERATED_NAMESPACE::XmlPersonaliaReader::RESULT_Ok:
    if (xmlpersonalia == NULL)
      return Result::RESULT_Ok;
    break;
  case WW_GENERATED_NAMESPACE::XmlPersonaliaReader::RESULT_FileNotFound:
    return Result::RESULT_FileNotFound;
  case WW_GENERATED_NAMESPACE::XmlPersonaliaReader::RESULT_ErrorInFilename:
    return Result::RESULT_ErrorInFilename;
  case WW_GENERATED_NAMESPACE::XmlPersonaliaReader::RESULT_FileOpenError:
    return Result::RESULT_FileOpenError;
  case WW_GENERATED_NAMESPACE::XmlPersonaliaReader::RESULT_ErrorInFile:
    return Result::RESULT_ErrorInFile;
  case WW_GENERATED_NAMESPACE::XmlPersonaliaReader::RESULT_ParserError:
    return Result::RESULT_ParserError;
  case WW_GENERATED_NAMESPACE::XmlPersonaliaReader::RESULT_InterpretError:
  case WW_GENERATED_NAMESPACE::XmlPersonaliaReader::RESULT_WriteError:
  default:
    return Result::RESULT_InterpretError;
    break;
  }

  WW::Personalia * personalia = new WW::Personalia(xmlpersonalia->Getgebruikersnaam());
  personalia->SetName(xmlpersonalia->Getnaam());
  Utils::Date date(Utils::Date::Today());
  if (Utils::ToDate(xmlpersonalia->Getgeboren(), date))
    personalia->SetDateOfBirth(date);
  personalia->SetGeslacht(xmlpersonalia->Getgeslacht() == WW_GENERATED_NAMESPACE::XmlPersonalia::geslacht_Mannelijk
    ? WW::Personalia::GESLACHT::Mannelijk : WW::Personalia::GESLACHT::Vrouwelijk);
  switch (xmlpersonalia->Getwerk())
  {
  case WW_GENERATED_NAMESPACE::XmlPersonalia::werk_Zittend:
    personalia->SetTypeOfWork(WW::Personalia::WERKTYPE::Zittend);
    break;
  case WW_GENERATED_NAMESPACE::XmlPersonalia::werk_Staand:
    personalia->SetTypeOfWork(WW::Personalia::WERKTYPE::Staand);
    break;
  case WW_GENERATED_NAMESPACE::XmlPersonalia::werk_Lopend:
    personalia->SetTypeOfWork(WW::Personalia::WERKTYPE::Lopend);
    break;
  case WW_GENERATED_NAMESPACE::XmlPersonalia::werk_Zwaar:
    personalia->SetTypeOfWork(WW::Personalia::WERKTYPE::Zwaar);
    break;
  }

  personalia->SetFPPuntenTotaal(_ttoi(xmlpersonalia->Getpunten().c_str()));
  personalia->SetPPPuntenTotaal(_ttoi(xmlpersonalia->Getpppunten().c_str()));
  personalia->SetPPWeekPuntenTotaal(_ttoi(xmlpersonalia->Getppweekpunten().c_str()));
  personalia->SetKCPuntenTotaal(_ttoi(xmlpersonalia->Getkcpunten().c_str()));
  personalia->SetKCWeekPuntenTotaal(_ttoi(xmlpersonalia->Getkcweekpunten().c_str()));
  personalia->SetCHPuntenTotaal(Str::ToDouble(xmlpersonalia->Getchpunten().c_str()));
  personalia->SetCHWeekPuntenTotaal(Str::ToDouble(xmlpersonalia->Getchweekpunten().c_str()));
  personalia->SetStreefGewicht(Str::ToDouble(xmlpersonalia->Getstreefgewicht().c_str()));
  personalia->SetStartGewicht(Str::ToDouble(xmlpersonalia->Getstartgewicht().c_str()));
  personalia->SetHuidigGewicht(Str::ToDouble(xmlpersonalia->Gethuidiggewicht().c_str()));
  personalia->SetLengte(Str::ToInt(xmlpersonalia->Getlengte().c_str()));

  switch (xmlpersonalia->Getstrategie())
  {
  case WW_GENERATED_NAMESPACE::XmlPersonalia::strategie_FlexiPoints:
    personalia->SetStrategy(WW::STRATEGY_TYPE::FlexiPoints);
    break;
  case WW_GENERATED_NAMESPACE::XmlPersonalia::strategie_ProPoints:
    personalia->SetStrategy(WW::STRATEGY_TYPE::ProPoints);
    break;
  case WW_GENERATED_NAMESPACE::XmlPersonalia::strategie_KCal:
    personalia->SetStrategy(WW::STRATEGY_TYPE::KCal);
    break;
  case WW_GENERATED_NAMESPACE::XmlPersonalia::strategie_CarboHydrates:
    personalia->SetStrategy(WW::STRATEGY_TYPE::CarboHydrates);
    break;
  default:
    return Result::RESULT_InterpretError;
  }

  mModel.Add(personalia);

  delete xmlpersonalia;

  return Result::RESULT_Ok;

}

XmlBase::Result XmlReader::ReadUnits(const std::tstring & aDirectory)
{
  WW_GENERATED_NAMESPACE::XmlUnitsReader reader;
  WW_GENERATED_NAMESPACE::XmlUnits * xmlunits;
  switch (reader.Read(aDirectory, xmlunits))
  {
  case WW_GENERATED_NAMESPACE::XmlUnitsReader::RESULT_Ok:
    if (xmlunits == NULL)
      return Result::RESULT_Ok;
    break;
  case WW_GENERATED_NAMESPACE::XmlUnitsReader::RESULT_FileNotFound:
    return Result::RESULT_FileNotFound;
  case WW_GENERATED_NAMESPACE::XmlUnitsReader::RESULT_ErrorInFilename:
    return Result::RESULT_ErrorInFilename;
  case WW_GENERATED_NAMESPACE::XmlUnitsReader::RESULT_FileOpenError:
    return Result::RESULT_FileOpenError;
  case WW_GENERATED_NAMESPACE::XmlUnitsReader::RESULT_ErrorInFile:
    return Result::RESULT_ErrorInFile;
  case WW_GENERATED_NAMESPACE::XmlUnitsReader::RESULT_ParserError:
    return Result::RESULT_ParserError;
  case WW_GENERATED_NAMESPACE::XmlUnitsReader::RESULT_InterpretError:
  case WW_GENERATED_NAMESPACE::XmlUnitsReader::RESULT_WriteError:
  default:
    return Result::RESULT_InterpretError;
    break;
  }

  const std::vector<WW_GENERATED_NAMESPACE::XmlUnit *> & units(xmlunits->GetUnitList());
  for (size_t i = 0; i < units.size(); ++i) 
    mModel.Add(WW::Unit(mModel, units[i]->Getnaam()));

  delete xmlunits;

  return Result::RESULT_Ok;
}


XmlBase::Result XmlReader::ReadVoedingsmiddelDefinities(const std::tstring & aDirectory)
{
  WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldefsReader reader;
  WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldefs * xmlvoedingsmiddeldefs;
  switch (reader.Read(aDirectory, xmlvoedingsmiddeldefs))
  {
  case WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldefsReader::RESULT_Ok:
    if (xmlvoedingsmiddeldefs == NULL)
      return Result::RESULT_Ok;
    break;
  case WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldefsReader::RESULT_FileNotFound:
    return Result::RESULT_FileNotFound;
  case WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldefsReader::RESULT_ErrorInFilename:
    return Result::RESULT_ErrorInFilename;
  case WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldefsReader::RESULT_FileOpenError:
    return Result::RESULT_FileOpenError;
  case WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldefsReader::RESULT_ErrorInFile:
    return Result::RESULT_ErrorInFile;
  case WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldefsReader::RESULT_ParserError:
    return Result::RESULT_ParserError;
  case WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldefsReader::RESULT_InterpretError:
  case WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldefsReader::RESULT_WriteError:
  default:
    return Result::RESULT_InterpretError;
    break;
  }

  const std::vector<WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldef *> & vmlist = xmlvoedingsmiddeldefs->GetVoedingsmiddeldefList();
  for (size_t i = 0; i < vmlist.size(); ++i)
  {
    WW::VMDefBase * base = NULL;

    if (vmlist[i]->GetVoedingswaarde() != NULL)
    {
      WW::CalculatedVMDef * cdefinitie = new WW::CalculatedVMDef(mModel.GetCalculator());
      cdefinitie->SetKCalPer100Units(Str::ToDouble(vmlist[i]->GetVoedingswaarde()->Getkcalper100().c_str()));
      cdefinitie->SetVetPer100Units(Str::ToDouble(vmlist[i]->GetVoedingswaarde()->Getvetper100().c_str()));
      cdefinitie->SetKoolhydratenPer100Units(Str::ToDouble(vmlist[i]->GetVoedingswaarde()->Getkoolhydratenper100().c_str()));
      cdefinitie->SetEiwitPer100Units(Str::ToDouble(vmlist[i]->GetVoedingswaarde()->Geteiwitper100().c_str()));
      cdefinitie->SetVezelsPer100Units(Str::ToDouble(vmlist[i]->GetVoedingswaarde()->Getvezelsper100().c_str()));
      base = cdefinitie;
    }
    else if (vmlist[i]->GetPuntenper100() != NULL)
    {
      WW::FixedVMDef * fdefinitie = new WW::FixedVMDef;
      fdefinitie->SetPointsPer100Units(Str::ToDouble(vmlist[i]->GetPuntenper100()->Getpunten()));
      base = fdefinitie;
    }
    else
    {
      assert(false);
      return Result::RESULT_InterpretError;
    }

    WW::VMDefinitie * definitie = new WW::VMDefinitie(mModel.GetCalculator(),
                                                                              vmlist[i]->GetVoedingsmiddelbasis().GetVoedingsmiddelheader().Getnaam(),
                                                                              WW::Unit(mModel, vmlist[i]->GetVoedingsmiddelbasis().GetVoedingsmiddelheader().Getunit()),
                                                                              base);


    if (!vmlist[i]->GetVoedingsmiddelbasis().GetVoedingsmiddelheader().Getcategorie().empty())
      definitie->SetCategory(WW::CategorieNaam(mModel, vmlist[i]->GetVoedingsmiddelbasis().GetVoedingsmiddelheader().Getcategorie()));
    if (!vmlist[i]->GetVoedingsmiddelbasis().GetVoedingsmiddelheader().Getmerk().empty())
      definitie->SetMerk(WW::MerkNaam(mModel, vmlist[i]->GetVoedingsmiddelbasis().GetVoedingsmiddelheader().Getmerk()));
    definitie->SetHasFreeFPPortion(vmlist[i]->GetVoedingsmiddelbasis().Getvrijeportie() == WW_GENERATED_NAMESPACE::XmlVoedingsmiddelbasis::vrijeportie_true);
    if (definitie->HasFreeFPPortion())
      definitie->SetFreeFPPortionPoints(Str::ToDouble(vmlist[i]->GetVoedingsmiddelbasis().Getvrijepunten()));
    definitie->SetHasFreePPPortion(vmlist[i]->GetVoedingsmiddelbasis().Getvrijeppportie() == WW_GENERATED_NAMESPACE::XmlVoedingsmiddelbasis::vrijeppportie_true);
    if (definitie->HasFreePPPortion())
      definitie->SetFreePPPortionPoints(Str::ToDouble(vmlist[i]->GetVoedingsmiddelbasis().Getvrijepppunten()));
    definitie->SetFavourite(vmlist[i]->Getfavoriet() == WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldef::favoriet_true);

    const std::vector<WW_GENERATED_NAMESPACE::XmlPortie *> & portielist = vmlist[i]->GetPortieList();
    for (size_t p = 0; p < portielist.size(); ++p)
    {
      WW::Portie * portie = new WW::Portie(WW::PortieNaam(mModel, portielist[p]->Getnaam()));
      portie->SetUnits(Str::ToDouble(portielist[p]->Geteenheden().c_str()));
      mModel.Add(portie->GetName());
      definitie->AddPortie(portie);
    }

    if (!vmlist[i]->GetVoedingsmiddelbasis().Getsterreportie().empty())
      definitie->SetSterrePortie(WW::PortieNaam(mModel, vmlist[i]->GetVoedingsmiddelbasis().Getsterreportie()));

    mModel.Add(definitie);
  }

  delete xmlvoedingsmiddeldefs;

  return Result::RESULT_Ok;
}


XmlBase::Result XmlReader::ReadRecepten(const std::tstring & aDirectory)
{
  WW_GENERATED_NAMESPACE::XmlReceptdefsReader reader;
  WW_GENERATED_NAMESPACE::XmlReceptdefs * xmlreceptdefs;
  switch (reader.Read(aDirectory, xmlreceptdefs))
  {
  case WW_GENERATED_NAMESPACE::XmlReceptdefsReader::RESULT_Ok:
    if (xmlreceptdefs == NULL)
      return Result::RESULT_Ok;
    break;
  case WW_GENERATED_NAMESPACE::XmlReceptdefsReader::RESULT_FileNotFound:
    return Result::RESULT_FileNotFound;
  case WW_GENERATED_NAMESPACE::XmlReceptdefsReader::RESULT_ErrorInFilename:
    return Result::RESULT_ErrorInFilename;
  case WW_GENERATED_NAMESPACE::XmlReceptdefsReader::RESULT_FileOpenError:
    return Result::RESULT_FileOpenError;
  case WW_GENERATED_NAMESPACE::XmlReceptdefsReader::RESULT_ErrorInFile:
    return Result::RESULT_ErrorInFile;
  case WW_GENERATED_NAMESPACE::XmlReceptdefsReader::RESULT_ParserError:
    return Result::RESULT_ParserError;
  case WW_GENERATED_NAMESPACE::XmlReceptdefsReader::RESULT_InterpretError:
  case WW_GENERATED_NAMESPACE::XmlReceptdefsReader::RESULT_WriteError:
  default:
    return Result::RESULT_InterpretError;
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

  return Result::RESULT_Ok;
}


XmlBase::Result XmlReader::ReadWeeks(const std::tstring & aDirectory)
{
  std::tstring filename(aDirectory + _T("\\week*.xml"));
  //TCHAR filemask[_MAX_PATH];
  //_stprintf(filemask, _T("%sweek????????.xml"), aDirectory.c_str());
  WIN32_FIND_DATA finddata;
  HANDLE hFind = FindFirstFile(filename.c_str(), &finddata);
  bool bContinue = true;
  while (bContinue) {
    ReadWeek(aDirectory + _T("\\") + finddata.cFileName);
    bContinue = FindNextFile(hFind, &finddata) != FALSE;
  }

  FindClose(hFind);

  return Result::RESULT_Ok;
}


XmlBase::Result XmlReader::ReadWeek(const std::tstring & aDirectory)
{
  WW_GENERATED_NAMESPACE::XmlWeekReader reader;
  WW_GENERATED_NAMESPACE::XmlWeek * xmlweek;
  switch (reader.Read(aDirectory, xmlweek))
  {
  case WW_GENERATED_NAMESPACE::XmlWeekReader::RESULT_Ok:
    if (xmlweek == NULL)
      return Result::RESULT_Ok;
    break;
  case WW_GENERATED_NAMESPACE::XmlWeekReader::RESULT_FileNotFound:
    return Result::RESULT_FileNotFound;
  case WW_GENERATED_NAMESPACE::XmlWeekReader::RESULT_ErrorInFilename:
    return Result::RESULT_ErrorInFilename;
  case WW_GENERATED_NAMESPACE::XmlWeekReader::RESULT_FileOpenError:
    return Result::RESULT_FileOpenError;
  case WW_GENERATED_NAMESPACE::XmlWeekReader::RESULT_ErrorInFile:
    return Result::RESULT_ErrorInFile;
  case WW_GENERATED_NAMESPACE::XmlWeekReader::RESULT_ParserError:
    return Result::RESULT_ParserError;
  case WW_GENERATED_NAMESPACE::XmlWeekReader::RESULT_InterpretError:
  case WW_GENERATED_NAMESPACE::XmlWeekReader::RESULT_WriteError:
  default:
    return Result::RESULT_InterpretError;
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
    week->SetStrategy(WW::STRATEGY_TYPE::FlexiPoints, mModel);
    break;
  case WW_GENERATED_NAMESPACE::XmlWeek::strategie_ProPoints:
    week->SetStrategy(WW::STRATEGY_TYPE::ProPoints, mModel);
    break;
  case WW_GENERATED_NAMESPACE::XmlWeek::strategie_KCal:
    week->SetStrategy(WW::STRATEGY_TYPE::KCal, mModel);
    break;
  case WW_GENERATED_NAMESPACE::XmlWeek::strategie_CarboHydrates:
    week->SetStrategy(WW::STRATEGY_TYPE::CarboHydrates, mModel);
    break;
  }

  if (!mModel.Add(week))
  {
    delete week;
    return Result::RESULT_InterpretError;
  }

  const std::vector<WW_GENERATED_NAMESPACE::XmlDag *> dagen(xmlweek->GetDagList());
  for (size_t i = 0; i < dagen.size(); ++i)
  {
    WW::Day * dag = Create(*dagen[i]);
    if (!week->Add(dag))
    {
      delete dag;
      return Result::RESULT_InterpretError;
    }
  }

  delete xmlweek;

  return Result::RESULT_Ok;
}


XmlBase::Result XmlReader::ReadGerechten(const std::tstring & aDirectory)
{
  (void)aDirectory;

  return Result::RESULT_Ok;
}


XmlBase::Result XmlReader::ReadBonusCells(const std::tstring & aDirectory)
{
  WW_GENERATED_NAMESPACE::XmlBonuslistReader reader;
  WW_GENERATED_NAMESPACE::XmlBonuslist * xmlbonuslist;

  switch (reader.Read(aDirectory + _T("\\bonuspoints.xml"), xmlbonuslist))
  {
  case WW_GENERATED_NAMESPACE::XmlWeekReader::RESULT_Ok:
    if (xmlbonuslist == NULL)
      return Result::RESULT_Ok;
    break;
  case WW_GENERATED_NAMESPACE::XmlWeekReader::RESULT_FileNotFound:
    delete xmlbonuslist;
    return Result::RESULT_FileNotFound;
  case WW_GENERATED_NAMESPACE::XmlWeekReader::RESULT_ErrorInFilename:
    delete xmlbonuslist;
    return Result::RESULT_ErrorInFilename;
  case WW_GENERATED_NAMESPACE::XmlWeekReader::RESULT_FileOpenError:
    delete xmlbonuslist;
    return Result::RESULT_FileOpenError;
  case WW_GENERATED_NAMESPACE::XmlWeekReader::RESULT_ErrorInFile:
    delete xmlbonuslist;
    return Result::RESULT_ErrorInFile;
  case WW_GENERATED_NAMESPACE::XmlWeekReader::RESULT_ParserError:
    delete xmlbonuslist;
    return Result::RESULT_ParserError;
  case WW_GENERATED_NAMESPACE::XmlWeekReader::RESULT_InterpretError:
  case WW_GENERATED_NAMESPACE::XmlWeekReader::RESULT_WriteError:
  default:
    delete xmlbonuslist;
    return Result::RESULT_InterpretError;
    break;
  }

  for (size_t i = 0; i < xmlbonuslist->GetBonuscellList().size(); ++i)
  {
    WW_GENERATED_NAMESPACE::XmlBonuscell * cell = xmlbonuslist->GetBonuscellList()[i];
    WW::BonusPointsMap::MOVEMENT_INTENSITY intensity = WW::BonusPointsMap::MI_High;
    switch (cell->Getintensiteit())
    {
    case WW_GENERATED_NAMESPACE::XmlBonuscell::intensiteit_hoog:
      intensity = WW::BonusPointsMap::MI_High;
      break;
    case WW_GENERATED_NAMESPACE::XmlBonuscell::intensiteit_middel:
      intensity = WW::BonusPointsMap::MI_Medium;
      break;
    case WW_GENERATED_NAMESPACE::XmlBonuscell::intensiteit_laag:
      intensity = WW::BonusPointsMap::MI_Low;
      break;
    default:
      delete xmlbonuslist;
      return Result::RESULT_InterpretError;
    }

    mModel.GetBonusPointsMap()[intensity][cell->Getgewicht()][(cell->Getminuten())] = cell->Getpunten();
  }

  //mModel.GetBonusPointsMap().Debug();
  delete xmlbonuslist;
  return Result::RESULT_Ok;
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
    if (xmllot->GetVoedingswaarde() != NULL)
    {
      WW::CalculatedLot * plot = new WW::CalculatedLot(mModel.GetCalculator(), Create(xmllot->GetPortie()));
      plot->SetSterreLot(xmllot->Getsterrelot() == WW_GENERATED_NAMESPACE::XmlStandardlot::sterrelot_true);
      plot->SetNumberOfPortions(Str::ToDouble(xmllot->Gethoeveelheid()));
      plot->SetKCalPer100Units(Str::ToDouble(xmllot->GetVoedingswaarde()->Getkcalper100()));
      plot->SetVetPer100Units(Str::ToDouble(xmllot->GetVoedingswaarde()->Getvetper100()));
      plot->SetKoolhydratenPer100Units(Str::ToDouble(xmllot->GetVoedingswaarde()->Getkoolhydratenper100().c_str()));
      plot->SetEiwitPer100Units(Str::ToDouble(xmllot->GetVoedingswaarde()->Geteiwitper100().c_str()));
      plot->SetVezelsPer100Units(Str::ToDouble(xmllot->GetVoedingswaarde()->Getvezelsper100().c_str()));
      lot = plot;
    }
    else if (xmllot->GetPuntenper100() != NULL)
    {
      WW::FixedLot * plot = new WW::FixedLot(Create(xmllot->GetPortie()));
      plot->SetSterreLot(xmllot->Getsterrelot() == WW_GENERATED_NAMESPACE::XmlStandardlot::sterrelot_true);
      plot->SetNumberOfPortions(Str::ToDouble(xmllot->Gethoeveelheid()));
      plot->SetPointsPer100Units(Str::ToDouble(xmllot->GetPuntenper100()->Getpunten()));
      lot = plot;
    }
  }
  else if (aVoedingsmiddel.GetFreelot() != NULL)
  {
    WW::FreeLot * flot = new WW::FreeLot(mModel.GetStrategy(), Str::ToDouble(aVoedingsmiddel.GetFreelot()->Getpunten()));
    lot = flot;
  }
  else
  {
    WW::VMDefinitie * def = mModel.FindVoedingsmiddelDefinitie(aVoedingsmiddel.Getnaam());
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
        WW::Portie & portie = *def->GetPortieList()[0];

        if (def->IsCalculated())
        {
          WW::CalculatedVMDef * cvmdef = def->GetCalculatedVMDef();
          assert(def != NULL);
          WW::CalculatedLot * clot = new WW::CalculatedLot(mModel.GetCalculator(), portie);
          clot->SetNumberOfPortions(1);
          clot->SetSterreLot(def->IsSterrePortion(&portie));
          clot->SetParameters(cvmdef->GetParameters());
          lot = clot;
        }
        else if (def->IsFixed())
        {
          WW::FixedVMDef * fvmdef = def->GetFixedVMDef();
          assert(def != NULL);
          WW::FixedLot * flot = new WW::FixedLot(portie);
          flot->SetNumberOfPortions(1);
          flot->SetSterreLot(def->IsSterrePortion(&portie));
          flot->SetPointsPer100Units(fvmdef->GetPointsPer100Units());
          lot = flot;
        }
      }
      else
      {
        assert(false);
      }
    }
  }

  WW::Voedingsmiddel * voedingsmiddel = new WW::Voedingsmiddel(aVoedingsmiddel.Getnaam(), lot,
                                                               WW::Unit(mModel, aVoedingsmiddel.Getunit()));
  voedingsmiddel->SetCategory(WW::CategorieNaam(mModel, aVoedingsmiddel.Getcategorie()));
  return voedingsmiddel;
}


WW::Recept * XmlReader::Create(const WW_GENERATED_NAMESPACE::XmlRecept & aRecept)
{
  WW::Recept * recept = new WW::Recept(aRecept.Getnaam());
  recept->SetPointsPerPortion(Str::ToDouble(aRecept.Getpunten()));
  recept->SetNumberOfPortions(Str::ToDouble(aRecept.Gethoeveelheid()));
  return recept;
}


WW::Gerecht * XmlReader::Create(const WW_GENERATED_NAMESPACE::XmlGerecht & aGerecht)
{
  WW::Gerecht * gerecht = new WW::Gerecht(aGerecht.Getnaam(), Str::ToDouble(aGerecht.Getpunten()));
  gerecht->SetNumberOfPortions(Str::ToDouble(aGerecht.Gethoeveelheid()));
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
    day->SetFreeBonusPoints(Str::ToDouble(aDag.Getbonuspunten().c_str()));

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

  const std::vector<WW_GENERATED_NAMESPACE::XmlBonuscell *> & bonuslist(aDag.GetBonuscellList());
  for (size_t i = 0; i < bonuslist.size(); ++i)
    day->Add(Create(*bonuslist[i]));

  return day;
}


WW::Bonus XmlReader::Create(const WW_GENERATED_NAMESPACE::XmlBonuscell & aCell)
{
  WW::Bonus::INTENSITY intensity =
    aCell.Getintensiteit() == WW_GENERATED_NAMESPACE::XmlBonuscell::intensiteit_hoog  ? WW::Bonus::INTENSITY::High :
    aCell.Getintensiteit() == WW_GENERATED_NAMESPACE::XmlBonuscell::intensiteit_middel ? WW::Bonus::INTENSITY::Medium :
                                                                                          WW::Bonus::INTENSITY::Low;
  return WW::Bonus(intensity, aCell.Getminuten(), aCell.Getpunten());
}


} // namespace WW