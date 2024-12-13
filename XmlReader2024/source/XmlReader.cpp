
#include "XmlReader.h"

#include <assert.h>
#include <stdlib.h>
#include <tchar.h>

#include "Utilities/FileUtils.h"

#include "generated/XmlBonusCell.h"
#include "generated/XmlBonusCellReader.h"
#include "generated/XmlBonusList.h"
#include "generated/XmlBonusListReader.h"
#include "generated/XmlDag.h"
#include "generated/XmlHandmatigitem.h"
#include "generated/XmlPersonalia.h"
#include "generated/XmlPersonaliaReader.h"
#include "generated/XmlPortie.h"
#include "generated/XmlRecept.h"
#include "generated/XmlReceptdef.h"
#include "generated/XmlReceptdefs.h"
#include "generated/XmlReceptdefsReader.h"
#include "generated/XmlUnit.h"
#include "generated/XmlUnits.h"
#include "generated/XmlUnitsReader.h"
#include "generated/XmlVoedingsmiddel.h"
#include "generated/XmlVoedingsmiddelDef.h"
#include "generated/XmlVoedingsmiddelDefs.h"
#include "generated/XmlVoedingsmiddelDefsReader.h"
#include "generated/XmlVoedingswaarde.h"
#include "generated/XmlWeek.h"
#include "generated/XmlWeekReader.h"

#include "model/BonusPointsMap.h"
#include "model/ManualItem.h"
#include "model/NutritionalValue.h"
#include "model/Personalia.h"
#include "model/Recept.h"
#include "model/ReceptDefinitie.h"
#include "model/VoedingsMiddel.h"
#include "model/VoedingsmiddelDefinitie.h"
#include "model/Week.h"
#include "model/WWDefinitions.h"

namespace ww2024
{


XmlReader::XmlReader(weight::Model& aModel)
    : mModel(aModel)
{
}


weight::Result XmlReader::Read(const std::tstring& aDirectory)
{
    weight::Result result = ReadPersonalia(aDirectory + _T("\\personalia.xml"));
    if (result == weight::Result::Ok)
        result = ReadVoedingsmiddelDefinities(aDirectory + _T("\\voedingsmiddeldefinities.xml"));
    if (result == weight::Result::Ok)
        result = ReadUnits(aDirectory + _T("\\units.xml"));
    if (result == weight::Result::Ok)
        result = ReadRecepten(aDirectory + _T("\\recepten.xml"));
    if (result == weight::Result::Ok)
        result = ReadGerechten(aDirectory + _T("\\restaurantgerechten.xml"));
    if (result == weight::Result::Ok)
        result = ReadWeeks(aDirectory);
    if (result == weight::Result::Ok)
        result = ReadBonusCells(aDirectory);

    return result;
}


weight::Result XmlReader::ReadPersonalia(const std::tstring& aDirectory)
{
    XmlPersonaliaReader reader;

    try {
        auto xmlpersonalia = reader.Read(aDirectory);
        if (xmlpersonalia == nullptr)
            return weight::Result::Ok;
        auto personalia = std::make_unique<weight::Personalia>(xmlpersonalia->Getgebruikersnaam());
        personalia->SetName(xmlpersonalia->Getnaam());
        Utils::Date date(Utils::Date::Today());
        if (Utils::ToDate(xmlpersonalia->Getgeboren(), date))
            personalia->SetDateOfBirth(date);
        personalia->SetGeslacht(xmlpersonalia->Getgeslacht() == XmlPersonalia::geslacht::Mannelijk
                                ? weight::Personalia::GESLACHT::Mannelijk : weight::Personalia::GESLACHT::Vrouwelijk);
        switch (xmlpersonalia->Getwerk())
        {
            case XmlPersonalia::werk::Zittend:
                personalia->SetTypeOfWork(weight::Personalia::WERKTYPE::Zittend);
                break;
            case XmlPersonalia::werk::Staand:
                personalia->SetTypeOfWork(weight::Personalia::WERKTYPE::Staand);
                break;
            case XmlPersonalia::werk::Lopend:
                personalia->SetTypeOfWork(weight::Personalia::WERKTYPE::Lopend);
                break;
            case XmlPersonalia::werk::Zwaar:
                personalia->SetTypeOfWork(weight::Personalia::WERKTYPE::Zwaar);
                break;
        }

        personalia->SetKCPuntenTotaal(xmlpersonalia->Getkcpunten());
        personalia->SetKCWeekPuntenTotaal(xmlpersonalia->Getkcweekpunten());
        personalia->SetCHPuntenTotaal(xmlpersonalia->Getchpunten());
        personalia->SetCHWeekPuntenTotaal(xmlpersonalia->Getchweekpunten());
        personalia->SetStreefGewicht(xmlpersonalia->Getstreefgewicht());
        personalia->SetStartGewicht(xmlpersonalia->Getstartgewicht());
        personalia->SetHuidigGewicht(xmlpersonalia->Gethuidiggewicht());
        personalia->SetLengte(xmlpersonalia->Getlengte());

        switch (xmlpersonalia->Getstrategie())
        {
            case XmlPersonalia::strategie::KCal:
                personalia->SetStrategy(weight::STRATEGY_TYPE::KCal);
                break;
            case XmlPersonalia::strategie::CarboHydrates:
                personalia->SetStrategy(weight::STRATEGY_TYPE::CarboHydrates);
                break;
            default:
                return weight::Result::InterpretError;
        }

        mModel.Add(std::move(personalia));

        return weight::Result::Ok;
    }
    catch (XmlClass::Result result) {
        switch (result)
        {
            case XmlClass::Result::FileNotFound:
                return weight::Result::FileNotFound;
            case XmlClass::Result::ErrorInFilename:
                return weight::Result::ErrorInFilename;
            case XmlClass::Result::FileOpenError:
                return weight::Result::FileOpenError;
            case XmlClass::Result::ErrorInFile:
                return weight::Result::ErrorInFile;
            case XmlClass::Result::ParserError:
                return weight::Result::ParserError;
            case XmlClass::Result::InterpretError:
            case XmlClass::Result::WriteError:
            default:
                return weight::Result::InterpretError;
        }
    }


}

weight::Result XmlReader::ReadUnits(const std::tstring& aDirectory)
{
    XmlUnitsReader reader;
    try {
        auto xmlunits = reader.Read(aDirectory);
        if (xmlunits == nullptr)
            return weight::Result::Ok;
        const auto& units(xmlunits->GetUnitList());
        for (size_t i = 0; i < units.size(); ++i)
            mModel.AddUnit(units[i]->Getnaam());

        return weight::Result::Ok;
    }
    catch (XmlClass::Result result) {
        switch (result) {
            case XmlClass::Result::FileNotFound:
                return weight::Result::FileNotFound;
            case XmlClass::Result::ErrorInFilename:
                return weight::Result::ErrorInFilename;
            case XmlClass::Result::FileOpenError:
                return weight::Result::FileOpenError;
            case XmlClass::Result::ErrorInFile:
                return weight::Result::ErrorInFile;
            case XmlClass::Result::ParserError:
                return weight::Result::ParserError;
            case XmlClass::Result::InterpretError:
            case XmlClass::Result::WriteError:
            default:
                return weight::Result::InterpretError;
        }
    }
}


weight::Result XmlReader::ReadVoedingsmiddelDefinities(const std::tstring& aDirectory)
{
    XmlVoedingsmiddeldefsReader reader;
    try {
        auto xmlvoedingsmiddeldefs = reader.Read(aDirectory);
        if (xmlvoedingsmiddeldefs == nullptr)
            return weight::Result::Ok;

        const auto& vmlist = xmlvoedingsmiddeldefs->GetVoedingsmiddeldefList();
        for (const auto& vm : vmlist)
        {
            auto nutritionalValue = std::make_unique<weight::NutritionalValue>(mModel.GetCalculator());
            nutritionalValue->SetKCalPer100Units(vm->GetVoedingswaarde().Getkcalper100());
            nutritionalValue->SetFatPer100Units(vm->GetVoedingswaarde().Getvetper100());
            nutritionalValue->SetCarbohydratesPer100Units(vm->GetVoedingswaarde().Getkoolhydratenper100());
            nutritionalValue->SetProteiPer100Units(vm->GetVoedingswaarde().Geteiwitper100());
            nutritionalValue->SetFibersPer100Units(vm->GetVoedingswaarde().Getvezelsper100());

            auto definitie = std::make_unique<weight::VMDefinitie>(mModel.GetCalculator(),
                                                                   vm->Getnaam(),
                                                                   vm->Getunit(),
                                                                   std::move(nutritionalValue));

            definitie->SetCategory(vm->Getcategorie());
            definitie->SetMerk(vm->Getmerk());
            definitie->SetFavourite(vm->Getfavoriet() == XmlVoedingsmiddeldef::favoriet::yes);

            const auto& portielist = vm->GetPortieList();
            for (const auto& p : portielist) {
                auto portie = std::make_unique<weight::Portie>(p->Getnaam());
                portie->SetUnits(p->Geteenheden());
                definitie->AddPortie(std::move(portie));
            }

            mModel.Add(std::move(definitie));
        }
    }
    catch (XmlClass::Result result) {
        switch (result) {
            case XmlClass::Result::FileNotFound:
                return weight::Result::FileNotFound;
            case XmlClass::Result::ErrorInFilename:
                return weight::Result::ErrorInFilename;
            case XmlClass::Result::FileOpenError:
                return weight::Result::FileOpenError;
            case XmlClass::Result::ErrorInFile:
                return weight::Result::ErrorInFile;
            case XmlClass::Result::ParserError:
                return weight::Result::ParserError;
            case XmlClass::Result::InterpretError:
            case XmlClass::Result::WriteError:
            default:
                return weight::Result::InterpretError;
                break;
        }
    }

    return weight::Result::Ok;
}


weight::Result XmlReader::ReadRecepten(const std::tstring& aDirectory)
{
    XmlReceptdefsReader reader;
    try {
        auto xmlreceptdefs = reader.Read(aDirectory);
        if (xmlreceptdefs == nullptr)
            return weight::Result::Ok;

        const auto& receptlist = xmlreceptdefs->GetReceptdefList();
        for (const auto& xmlrecept : receptlist)
        {
            auto receptdef = std::make_unique<weight::ReceptDefinitie>(xmlrecept->Getnaam());
            receptdef->SetPortions(static_cast<int>(xmlrecept->Getporties()));
            const auto& voedingsmiddellist(xmlrecept->GetVoedingsmiddelList());
            for (const auto& xmlvm : voedingsmiddellist)
            {
                auto voedingsmiddel = Create(*xmlvm);
                if (voedingsmiddel != nullptr)
                    receptdef->Add(std::move(voedingsmiddel));
            }

            mModel.Add(std::move(receptdef));
        }
    }
    catch (XmlClass::Result result) {
        switch (result)
        {
            case XmlClass::Result::FileNotFound:
                return weight::Result::FileNotFound;
            case XmlClass::Result::ErrorInFilename:
                return weight::Result::ErrorInFilename;
            case XmlClass::Result::FileOpenError:
                return weight::Result::FileOpenError;
            case XmlClass::Result::ErrorInFile:
                return weight::Result::ErrorInFile;
            case XmlClass::Result::ParserError:
                return weight::Result::ParserError;
            case XmlClass::Result::InterpretError:
            case XmlClass::Result::WriteError:
            default:
                return weight::Result::InterpretError;
                break;
        }
    }

    return weight::Result::Ok;
}


weight::Result XmlReader::ReadWeeks(const std::tstring& aDirectory)
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

    return weight::Result::Ok;
}


weight::Result XmlReader::ReadWeek(const std::tstring& aDirectory)
{
    XmlWeekReader reader;
    try {
        auto xmlweek = reader.Read(aDirectory);
        if (xmlweek == nullptr)
            return weight::Result::Ok;

        auto week = std::make_unique<weight::Week>(Utils::ToDate(xmlweek->Getbegindatum()),
                                               Utils::ToDate(xmlweek->Geteinddatum()));
        week->SetPoints(xmlweek->Getpunten());
        week->SetSaveablePoints(xmlweek->Getweekpunten());
        week->SetStartWeight(xmlweek->Getstartweight());

        switch (xmlweek->Getstrategie())
        {
            case XmlWeek::strategie::KCal:
                week->SetStrategy(weight::STRATEGY_TYPE::KCal, mModel);
                break;
            case XmlWeek::strategie::Koolhydraten:
                week->SetStrategy(weight::STRATEGY_TYPE::CarboHydrates, mModel);
                break;
        }

        const auto& dagen(xmlweek->GetDagList());
        for (const auto& xmldag : dagen)
        {
            auto dag = Create(*xmldag);
            if (!week->Add(std::move(dag)))
                return weight::Result::InterpretError;
        }

        if (!mModel.Add(std::move(week)))
            return weight::Result::InterpretError;

        return weight::Result::Ok;
    }
    catch (XmlClass::Result result) {
        switch (result) {
            case XmlClass::Result::FileNotFound:
                return weight::Result::FileNotFound;
            case XmlClass::Result::ErrorInFilename:
                return weight::Result::ErrorInFilename;
            case XmlClass::Result::FileOpenError:
                return weight::Result::FileOpenError;
            case XmlClass::Result::ErrorInFile:
                return weight::Result::ErrorInFile;
            case XmlClass::Result::ParserError:
                return weight::Result::ParserError;
            case XmlClass::Result::InterpretError:
            case XmlClass::Result::WriteError:
            default:
                return weight::Result::InterpretError;
        }
    }
}


weight::Result XmlReader::ReadGerechten(const std::tstring& aDirectory)
{
    (void)aDirectory;

    return weight::Result::Ok;
}


weight::Result XmlReader::ReadBonusCells(const std::tstring& aDirectory)
{
    //XmlBonuslistReader reader;
    //try {
    //    auto xmlbonuslist = reader.Read(aDirectory + _T("\\bonuspoints.xml"));


    //    for (size_t i = 0; i < xmlbonuslist->GetBonuscellList().size(); ++i)
    //    {
    //        XmlBonuscell* cell = xmlbonuslist->GetBonuscellList()[i];
    //        weight::BonusPointsMap::MOVEMENT_INTENSITY intensity = weight::BonusPointsMap::MI_High;
    //        switch (cell->Getintensiteit())
    //        {
    //            case XmlBonuscell::intensiteit::hoog:
    //                intensity = weight::BonusPointsMap::MI_High;
    //                break;
    //            case XmlBonuscell::intensiteit::middel:
    //                intensity = weight::BonusPointsMap::MI_Medium;
    //                break;
    //            case XmlBonuscell::intensiteit::laag:
    //                intensity = weight::BonusPointsMap::MI_Low;
    //                break;
    //            default:
    //                delete xmlbonuslist;
    //                return weight::Result::InterpretError;
    //        }

    //        mModel.GetBonusPointsMap()[intensity][cell->Getgewicht()][(cell->Getminuten())] = cell->Getpunten();
    //    }
    //}
    //catch (XmlClass::Result result) {
    //    switch (result) {
    //        case XmlClass::Result::FileNotFound:
    //            return weight::Result::FileNotFound;
    //        case XmlClass::Result::ErrorInFilename:
    //            return weight::Result::ErrorInFilename;
    //        case XmlClass::Result::FileOpenError:
    //            return weight::Result::FileOpenError;
    //        case XmlClass::Result::ErrorInFile:
    //            return weight::Result::ErrorInFile;
    //        case XmlClass::Result::ParserError:
    //            return weight::Result::ParserError;
    //        case XmlClass::Result::InterpretError:
    //        case XmlClass::Result::WriteError:
    //        default:
    //            return weight::Result::InterpretError;
    //            break;
    //    }
    //}

    return weight::Result::Ok;
}


weight::Portie XmlReader::Create(const XmlPortie& aPortie)
{
    weight::Portie portie(aPortie.Getnaam());
    portie.SetUnits(aPortie.Geteenheden());

    return portie;
}


std::unique_ptr<weight::Voedingsmiddel> XmlReader::Create(const XmlVoedingsmiddel& aVoedingsmiddel)
{
    const auto& xmlportie = aVoedingsmiddel.GetPortie();
    weight::Portie portie(xmlportie.Getnaam());
    portie.SetUnits(xmlportie.Geteenheden());
    auto lot = std::make_unique<weight::PortionedLot>(mModel.GetCalculator(), portie);
    lot->SetKCalPer100Units(aVoedingsmiddel.GetVoedingswaarde().Getkcalper100());
    lot->SetVetPer100Units(aVoedingsmiddel.GetVoedingswaarde().Getvetper100());
    lot->SetEiwitPer100Units(aVoedingsmiddel.GetVoedingswaarde().Geteiwitper100());
    lot->SetKoolhydratenPer100Units(aVoedingsmiddel.GetVoedingswaarde().Getkoolhydratenper100());
    lot->SetVezelsPer100Units(aVoedingsmiddel.GetVoedingswaarde().Getvezelsper100());

    auto voedingsmiddel = std::make_unique<weight::Voedingsmiddel>(aVoedingsmiddel.Getnaam(), std::move(lot),
                                                                   aVoedingsmiddel.Getunit());
    voedingsmiddel->SetCategory(aVoedingsmiddel.Getcategorie());
    voedingsmiddel->SetUnit(aVoedingsmiddel.Getunit());
    return std::move(voedingsmiddel);
}


std::unique_ptr<weight::Recept> XmlReader::Create(const XmlRecept& aRecept)
{
    auto recept = std::make_unique<weight::Recept>(aRecept.Getnaam());
    recept->SetPointsPerPortion(aRecept.Getpunten());
    recept->SetNumberOfPortions(aRecept.Getaantalporties());
    return std::move(recept);
}


std::unique_ptr<weight::ManualItem> XmlReader::Create(const XmlHandmatigitem& anItem)
{
    auto item = std::make_unique<weight::ManualItem>(anItem.Getnaam(), anItem.Getpunten());
    item->Set(anItem.Getpunten());
    return item;
}


std::unique_ptr<weight::Day> XmlReader::Create(const XmlDag& aDag)
{
    auto day = std::make_unique<weight::Day>(Utils::ToDate(aDag.Getdatum()));
    if (!aDag.Getgewicht().empty())
        day->SetWeight(Str::ToDouble(aDag.Getgewicht().c_str()));

    if (!aDag.Getbonuspunten().empty())
        day->SetFreeBonusPoints(Str::ToDouble(aDag.Getbonuspunten().c_str()));

    const auto& vmiddelen(aDag.GetVoedingsmiddelList());
    for (const auto& xmlvm : vmiddelen)
        day->Add(Create(*xmlvm));

    const auto& recepten(aDag.GetReceptList());
    for (size_t i = 0; i < recepten.size(); ++i)
        day->Add(Create(*recepten[i]));

    const auto& handmatig(aDag.GetHandmatigitemList());
    for (size_t i = 0; i < handmatig.size(); ++i)
        day->Add(Create(*handmatig[i]));

    const auto& bonuslist(aDag.GetBonuscellList());
    for (size_t i = 0; i < bonuslist.size(); ++i)
        day->Add(Create(*bonuslist[i]));

    return std::move(day);
}


weight::Bonus XmlReader::Create(const XmlBonuscell& aCell)
{
    weight::Bonus::INTENSITY intensity =
        aCell.Getintensiteit() == XmlBonuscell::intensiteit::hoog ? weight::Bonus::INTENSITY::High :
        aCell.Getintensiteit() == XmlBonuscell::intensiteit::middel ? weight::Bonus::INTENSITY::Medium :
        weight::Bonus::INTENSITY::Low;
    return weight::Bonus(intensity, aCell.Getminuten(), aCell.Getpunten());
}


} // namespace ww2024