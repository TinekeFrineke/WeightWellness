
#include "XmlReader.h"

#include <assert.h>
#include <filesystem>
#include <stdlib.h>

#include "Utilities/PathUtilities.h"

#include <generated/XmlBonusCell.h>
#include <generated/XmlBonusCellReader.h>
#include <generated/XmlBonusList.h>
#include <generated/XmlBonusListReader.h>
#include <generated/XmlDag.h>
#include <generated/XmlFreelot.h>
#include <generated/XmlGerecht.h>
#include <generated/XmlGerechtDef.h>
#include <generated/XmlGerechtDefs.h>
#include <generated/XmlGerechtDefsReader.h>
#include <generated/XmlHandmatigitem.h>
#include <generated/XmlPersonalia.h>
#include <generated/XmlPersonaliaReader.h>
#include <generated/XmlPortie.h>
#include <generated/XmlPortieomschrijving.h>
#include <generated/XmlPuntenPer100.h>
#include <generated/XmlRecept.h>
#include <generated/XmlReceptdef.h>
#include <generated/XmlReceptdefs.h>
#include <generated/XmlReceptdefsReader.h>
#include <generated/XmlStandardlot.h>
#include <generated/XmlUnit.h>
#include <generated/XmlUnits.h>
#include <generated/XmlUnitsReader.h>
#include <generated/XmlVoedingsmiddel.h>
#include <generated/XmlVoedingsmiddelbasis.h>
#include <generated/XmlVoedingsmiddeldef.h>
#include <generated/XmlVoedingsmiddeldefs.h>
#include <generated/XmlVoedingsmiddeldefsReader.h>
#include <generated/XmlVoedingsmiddelheader.h>
#include <generated/XmlVoedingswaarde.h>
#include <generated/XmlWeek.h>
#include <generated/XmlWeekReader.h>

#include "model/Bonus.h"
#include "model/BonusPointsMap.h"
#include "model/IFoodDefinitionRepository.h"
#include "model/IMessageHandler.h"
#include "model/IRepository.h"
#include "model/IStringRepository.h"
#include "model/IWeek.h"
#include "model/IWeekRepository.h"
#include "model/ManualItem.h"
#include "model/ModelFactory.h"
#include "model/NutritionalValue.h"
#include "model/Personalia.h"
#include "model/Recept.h"
#include "model/ReceptDefinitie.h"
#include "model/VoedingsMiddel.h"
#include "model/VoedingsmiddelDefinitie.h"
#include "model/WWDefinitions.h"

namespace ww_1_2
{


XmlReader::XmlReader(const std::string& logfile, weight::IModel& aModel, std::shared_ptr<weight::IMessageHandler> messageHandler)
    : m_logfile(logfile)
    , mModel(aModel)
{
}


weight::Result XmlReader::Read(const std::string& aDirectory)
{
    weight::Result result = ReadPersonalia(aDirectory + "\\personalia.xml");
    if (result == weight::Result::Ok)
        result = ReadVoedingsmiddelDefinities(aDirectory + "\\voedingsmiddeldefinities.xml");
    if (result == weight::Result::Ok)
        result = ReadUnits(aDirectory + "\\units.xml");
    if (result == weight::Result::Ok)
        result = ReadRecepten(aDirectory + "\\recepten.xml");
    if (result == weight::Result::Ok)
        result = ReadGerechten(aDirectory + "\\restaurantgerechten.xml");
    if (result == weight::Result::Ok)
        result = ReadWeeks(aDirectory);
    if (result == weight::Result::Ok)
        result = ReadBonusCells(aDirectory);

    return result;
}


weight::Result XmlReader::ReadPersonalia(const std::string& aDirectory)
{
    XmlPersonaliaReader reader;

    try {
        auto xmlpersonalia = reader.Read(aDirectory);
        if (xmlpersonalia == nullptr)
            return weight::Result::Ok;

        auto personalia = std::make_unique<weight::Personalia>(xmlpersonalia->Getgebruikersnaam());
        personalia->SetName(xmlpersonalia->Getnaam());
        personalia->SetDateOfBirth(Utils::ToDate(xmlpersonalia->Getgeboren()));
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

        personalia->SetKCPuntenTotaal(Str::ToInt(xmlpersonalia->Getkcpunten()));
        personalia->SetKCWeekPuntenTotaal(Str::ToInt(xmlpersonalia->Getkcweekpunten()));
        personalia->SetCHPuntenTotaal(Str::ToDouble(xmlpersonalia->Getchpunten()));
        personalia->SetCHWeekPuntenTotaal(Str::ToDouble(xmlpersonalia->Getchweekpunten()));
        personalia->SetStreefGewicht(Str::ToDouble(xmlpersonalia->Getstreefgewicht()));
        personalia->SetStartGewicht(Str::ToDouble(xmlpersonalia->Getstartgewicht()));
        personalia->SetHuidigGewicht(Str::ToDouble(xmlpersonalia->Gethuidiggewicht()));
        personalia->SetLengte(Str::ToInt(xmlpersonalia->Getlengte()));

        switch (xmlpersonalia->Getstrategie())
        {
            case XmlPersonalia::strategie::KCal:
                mModel.SetStrategy(weight::STRATEGY_TYPE::KCal);
                break;
            case XmlPersonalia::strategie::CarboHydrates:
                mModel.SetStrategy(weight::STRATEGY_TYPE::CarboHydrates);
                break;
            default:
                return weight::Result::InterpretError;
        }

        mModel.SetPersonalia(std::move(personalia));

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

weight::Result XmlReader::ReadUnits(const std::string& aDirectory)
{
    XmlUnitsReader reader;
    try {
        auto xmlunits = reader.Read(aDirectory);
        if (xmlunits == nullptr)
            return weight::Result::Ok;
        const auto& units(xmlunits->GetUnitList());
        for (size_t i = 0; i < units.size(); ++i)
            mModel.GetFoodDefinitionRepository()->GetUnitRepository()->Add(units[i]->Getnaam());

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


weight::Result XmlReader::ReadVoedingsmiddelDefinities(const std::string& aDirectory)
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
            nutritionalValue->SetKCalPer100Units(Str::ToDouble(vm->GetVoedingswaarde()->Getkcalper100()));
            nutritionalValue->SetFatPer100Units(Str::ToDouble(vm->GetVoedingswaarde()->Getvetper100()));
            nutritionalValue->SetCarbohydratesPer100Units(Str::ToDouble(vm->GetVoedingswaarde()->Getkoolhydratenper100()));
            nutritionalValue->SetProteiPer100Units(Str::ToDouble(vm->GetVoedingswaarde()->Geteiwitper100()));
            nutritionalValue->SetFibersPer100Units(Str::ToDouble(vm->GetVoedingswaarde()->Getvezelsper100()));

            auto definitie = std::make_unique<weight::VMDefinitie>(mModel.GetCalculator(),
                                                                   vm->GetVoedingsmiddelbasis().GetVoedingsmiddelheader().Getnaam(),
                                                                   vm->GetVoedingsmiddelbasis().GetVoedingsmiddelheader().Getunit(),
                                                                   std::move(nutritionalValue));

            definitie->SetCategory(vm->GetVoedingsmiddelbasis().GetVoedingsmiddelheader().Getcategorie());
            definitie->SetMerk(vm->GetVoedingsmiddelbasis().GetVoedingsmiddelheader().Getmerk());
            definitie->SetFavourite(vm->Getfavoriet() == XmlVoedingsmiddeldef::favoriet::yes);

            const auto& portielist = vm->GetPortieList();
            for (const auto& p : portielist) {
                auto portie = std::make_unique<weight::Portie>(p->Getnaam());
                portie->SetUnits(Str::ToDouble(p->Geteenheden()));
                definitie->AddPortie(std::move(portie));
            }

            mModel.GetFoodDefinitionRepository()->Add(std::move(definitie));
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


weight::Result XmlReader::ReadRecepten(const std::string& aDirectory)
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
            receptdef->SetPortions(Str::ToInt(xmlrecept->Getporties()));
            const auto& voedingsmiddellist(xmlrecept->GetVoedingsmiddelList());
            for (const auto& xmlvm : voedingsmiddellist)
            {
                auto voedingsmiddel = Create(*xmlvm);
                if (voedingsmiddel != nullptr)
                    receptdef->Add(std::move(voedingsmiddel));
            }

            mModel.GetRecipeDefinitionRepository()->Add(std::move(receptdef));
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


weight::Result XmlReader::ReadWeeks(const std::string& aDirectory)
{
    if (!std::filesystem::exists(aDirectory) || !std::filesystem::is_directory(aDirectory))
        return weight::Result::InterpretError;

    const std::string mask("week*.xml");
    const auto files = path_utilities::FindFiles(aDirectory, mask);

    for (const auto& file : files) {
        ReadWeek(aDirectory + "\\" + file);
    }

    return weight::Result::Ok;
}


weight::Result XmlReader::ReadWeek(const std::string& aDirectory)
{
    XmlWeekReader reader;
    try {
        auto xmlweek = reader.Read(aDirectory);
        if (xmlweek == nullptr)
            return weight::Result::Ok;

        auto week = weight::ModelFactory(m_messageHandler).CreateWeek(Utils::ToDate(xmlweek->Getbegindatum()),
                                                                      Utils::ToDate(xmlweek->Geteinddatum()));
        week->SetPoints(Str::ToDouble(xmlweek->Getpunten()));
        week->SetSaveablePoints(Str::ToDouble(xmlweek->Getweekpunten()));
        week->SetStartWeight(Str::ToDouble(xmlweek->Getstartweight()));

        switch (xmlweek->Getstrategie())
        {
            case XmlWeek::strategie::KCal:
                week->SetStrategy(weight::STRATEGY_TYPE::KCal, mModel);
                break;
            case XmlWeek::strategie::CarboHydrates:
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

        if (!mModel.GetWeekRepository()->Add(std::move(week)))
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


weight::Result XmlReader::ReadGerechten(const std::string& aDirectory)
{
    (void)aDirectory;

    return weight::Result::Ok;
}


weight::Result XmlReader::ReadBonusCells(const std::string& aDirectory)
{
    //XmlBonuslistReader reader;
    //XmlBonuslist* xmlbonuslist;

    //switch (reader.Read(aDirectory + _T("\\bonuspoints.xml"), xmlbonuslist))
    //{
    //    case XmlWeekReader::Result::Ok:
    //        if (xmlbonuslist == nullptr)
    //            return weight::Result::Ok;
    //        break;
    //    case XmlWeekReader::Result::FileNotFound:
    //        delete xmlbonuslist;
    //        return weight::Result::FileNotFound;
    //    case XmlWeekReader::Result::ErrorInFilename:
    //        delete xmlbonuslist;
    //        return weight::Result::ErrorInFilename;
    //    case XmlWeekReader::Result::FileOpenError:
    //        delete xmlbonuslist;
    //        return weight::Result::FileOpenError;
    //    case XmlWeekReader::Result::ErrorInFile:
    //        delete xmlbonuslist;
    //        return weight::Result::ErrorInFile;
    //    case XmlWeekReader::Result::ParserError:
    //        delete xmlbonuslist;
    //        return weight::Result::ParserError;
    //    case XmlWeekReader::Result::InterpretError:
    //    case XmlWeekReader::Result::WriteError:
    //    default:
    //        delete xmlbonuslist;
    //        return weight::Result::InterpretError;
    //        break;
    //}

    //for (size_t i = 0; i < xmlbonuslist->GetBonuscellList().size(); ++i)
    //{
    //    XmlBonuscell* cell = xmlbonuslist->GetBonuscellList()[i];
    //    weight::BonusPointsMap::MOVEMENT_INTENSITY intensity = weight::BonusPointsMap::MI_High;
    //    switch (cell->Getintensiteit())
    //    {
    //        case XmlBonuscell::intensiteit_hoog:
    //            intensity = weight::BonusPointsMap::MI_High;
    //            break;
    //        case XmlBonuscell::intensiteit_middel:
    //            intensity = weight::BonusPointsMap::MI_Medium;
    //            break;
    //        case XmlBonuscell::intensiteit_laag:
    //            intensity = weight::BonusPointsMap::MI_Low;
    //            break;
    //        default:
    //            delete xmlbonuslist;
    //            return weight::Result::InterpretError;
    //    }

    //    mModel.GetBonusPointsMap()[intensity][cell->Getgewicht()][(cell->Getminuten())] = cell->Getpunten();
    //}

    ////mModel.GetBonusPointsMap().Debug();
    //delete xmlbonuslist;
    return weight::Result::Ok;
}


weight::Portie XmlReader::Create(const XmlPortie& aPortie)
{
    weight::Portie portie(aPortie.Getnaam());
    portie.SetUnits(Str::ToDouble(aPortie.Geteenheden()));

    return portie;
}


std::unique_ptr<weight::Voedingsmiddel> XmlReader::Create(const XmlVoedingsmiddel& aVoedingsmiddel)
{
    std::unique_ptr<weight::PortionedLot> lot;

    if (aVoedingsmiddel.GetStandardlot() != nullptr)
    {
        const XmlStandardlot* xmllot = aVoedingsmiddel.GetStandardlot();
        const auto voedingswaarde = xmllot->GetVoedingswaarde();
        if (voedingswaarde == nullptr)
            // Obsolete food type, don't convert
            return {};

        weight::Portie portie(xmllot->GetPortie().Getnaam());
        portie.SetUnits(Str::ToDouble(xmllot->GetPortie().Geteenheden()));

        lot = std::make_unique<weight::PortionedLot>(mModel.GetCalculator(), portie);
        lot->SetNumberOfPortions(Str::ToDouble(xmllot->Gethoeveelheid()));
        lot->SetKCalPer100Units(Str::ToDouble(xmllot->GetVoedingswaarde()->Getkcalper100()));
        lot->SetVetPer100Units(Str::ToDouble(xmllot->GetVoedingswaarde()->Getvetper100()));
        lot->SetKoolhydratenPer100Units(Str::ToDouble(xmllot->GetVoedingswaarde()->Getkoolhydratenper100().c_str()));
        lot->SetEiwitPer100Units(Str::ToDouble(xmllot->GetVoedingswaarde()->Geteiwitper100().c_str()));
        lot->SetVezelsPer100Units(Str::ToDouble(xmllot->GetVoedingswaarde()->Getvezelsper100().c_str()));
    }
    else
    {
        weight::VMDefinitie* def = mModel.GetFoodDefinitionRepository()->Find(aVoedingsmiddel.Getnaam());
        if (def == nullptr)
        {
            m_messageHandler->error("Unable to interpret voedingsmiddel " + aVoedingsmiddel.Getnaam());
            return {};
        }
        else
        {
            if (!def->GetPortieList().empty())
            {
                weight::Portie& portie = *def->GetPortieList()[0];
                lot = std::make_unique< weight::PortionedLot>(mModel.GetCalculator(), portie);
                lot->SetNumberOfPortions(1);
                lot->SetParameters(def->GetNutritionalValue().GetParameters());
            }
            else
            {
                assert(false);
            }
        }
    }

    auto voedingsmiddel = std::make_unique<weight::Voedingsmiddel>(aVoedingsmiddel.Getnaam(), std::move(lot),
                                                                   aVoedingsmiddel.Getunit());
    voedingsmiddel->SetCategory(aVoedingsmiddel.Getcategorie());
    return std::move(voedingsmiddel);
}


std::unique_ptr<weight::Recept> XmlReader::Create(const XmlRecept& aRecept)
{
    auto recept = std::make_unique<weight::Recept>(aRecept.Getnaam());
    recept->SetPointsPerPortion(Str::ToDouble(aRecept.Getpunten()));
    recept->SetNumberOfPortions(static_cast<int>(Str::ToDouble(aRecept.Gethoeveelheid()) + 0.5));
    return std::move(recept);
}


std::unique_ptr<weight::ManualItem> XmlReader::Create(const XmlHandmatigitem& anItem)
{
    auto item = std::make_unique<weight::ManualItem>(anItem.Getnaam(), Str::ToDouble(anItem.Getpunten()));
    item->Set(Str::ToDouble(anItem.Getpunten()));
    return item;
}


std::unique_ptr<weight::IDay> XmlReader::Create(const XmlDag& aDag)
{
    auto day = weight::ModelFactory(m_messageHandler).CreateDay(Utils::ToDate(aDag.Getdatum()));
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

void XmlReader::LogMessage(const std::wstring& message) const
{
    std::wcout << message << std::endl;
    std::wofstream output(m_logfile, std::ios::app | std::ios::out);
    output << message << std::endl;
}


} // namespace ww_1_2