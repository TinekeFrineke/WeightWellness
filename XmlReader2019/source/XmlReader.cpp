
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
#include "generated/XmlGerecht.h"
#include "generated/XmlGerechtDef.h"
#include "generated/XmlGerechtDefs.h"
#include "generated/XmlGerechtDefsReader.h"
#include "generated/XmlHandmatigitem.h"
#include "generated/XmlPersonalia.h"
#include "generated/XmlPersonaliaReader.h"
#include "generated/XmlPortie.h"
#include "generated/XmlPortieomschrijving.h"
#include "generated/XmlPuntenPer100.h"
#include "generated/XmlRecept.h"
#include "generated/XmlReceptdef.h"
#include "generated/XmlReceptdefs.h"
#include "generated/XmlReceptdefsReader.h"
#include "generated/XmlStandardlot.h"
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
#include "model/Gerecht.h"
#include "model/ManualItem.h"
#include "model/Personalia.h"
#include "model/Recept.h"
#include "model/ReceptDefinitie.h"
#include "model/VoedingsMiddel.h"
#include "model/VoedingsmiddelDefinitie.h"
#include "model/Week.h"
#include "model/WWDefinitions.h"
//#include "XmlVMCreateVisitor.h"

namespace ww2019
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
        for (size_t i = 0; i < vmlist.size(); ++i)
        {
            // TF_TODO: Improve!!!
            std::unique_ptr<weight::VMDefBase> base;

            if (vmlist[i]->GetVoedingswaarde() != nullptr)
            {
                weight::CalculatedVMDef* cdefinitie = new weight::CalculatedVMDef(mModel.GetCalculator());
                cdefinitie->SetKCalPer100Units(Str::ToDouble(vmlist[i]->GetVoedingswaarde()->Getkcalper100().c_str()));
                cdefinitie->SetVetPer100Units(Str::ToDouble(vmlist[i]->GetVoedingswaarde()->Getvetper100().c_str()));
                cdefinitie->SetKoolhydratenPer100Units(Str::ToDouble(vmlist[i]->GetVoedingswaarde()->Getkoolhydratenper100().c_str()));
                cdefinitie->SetEiwitPer100Units(Str::ToDouble(vmlist[i]->GetVoedingswaarde()->Geteiwitper100().c_str()));
                cdefinitie->SetVezelsPer100Units(Str::ToDouble(vmlist[i]->GetVoedingswaarde()->Getvezelsper100().c_str()));
                base.reset(cdefinitie);
            }
            else if (vmlist[i]->GetPuntenper100() != nullptr)
            {
                weight::FixedVMDef* fdefinitie = new weight::FixedVMDef;
                fdefinitie->SetPointsPer100Units(Str::ToDouble(vmlist[i]->GetPuntenper100()->Getpunten()));
                base.reset(fdefinitie);
            }
            else
            {
                assert(false);
                return weight::Result::InterpretError;
            }

            weight::VMDefinitie* definitie = new weight::VMDefinitie(mModel.GetCalculator(),
                                                             vmlist[i]->GetVoedingsmiddelheader().Getnaam(),
                                                             vmlist[i]->GetVoedingsmiddelheader().Getunit(),
                                                             std::move(base));


            if (!vmlist[i]->GetVoedingsmiddelheader().Getcategorie().empty())
                definitie->SetCategory(vmlist[i]->GetVoedingsmiddelheader().Getcategorie());
            if (!vmlist[i]->GetVoedingsmiddelheader().Getmerk().empty())
                definitie->SetMerk(vmlist[i]->GetVoedingsmiddelheader().Getmerk());
            definitie->SetFavourite(vmlist[i]->Getfavoriet() == XmlVoedingsmiddeldef::favoriet::yes);

            const auto& portielist = vmlist[i]->GetPortieList();
            for (size_t p = 0; p < portielist.size(); ++p) {
                auto portie = std::make_unique<weight::Portie>(portielist[p]->Getnaam());
                portie->SetUnits(Str::ToDouble(portielist[p]->Geteenheden().c_str()));
                definitie->AddPortie(std::move(portie));
            }

            auto uni = std::unique_ptr<weight::VMDefinitie>(definitie);
            mModel.Add(std::move(uni));
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
        for (size_t i = 0; i < receptlist.size(); ++i)
        {
            auto receptdef = std::make_unique<weight::ReceptDefinitie>(receptlist[i]->Getnaam());
            receptdef->SetPortions(Str::ToInt(receptlist[i]->Getporties()));
            const auto& voedingsmiddellist(receptlist[i]->GetVoedingsmiddelList());
            for (size_t j = 0; j < voedingsmiddellist.size(); ++j)
            {
                auto voedingsmiddel = Create(*voedingsmiddellist[j]);
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
        week->SetStartWeight(Str::ToDouble(xmlweek->Getstartweight()));

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
        for (size_t i = 0; i < dagen.size(); ++i)
        {
            auto dag = Create(*dagen[i]);
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
    portie.SetUnits(Str::ToDouble(aPortie.Geteenheden()));

    return portie;
}


std::unique_ptr<weight::Voedingsmiddel> XmlReader::Create(const XmlVoedingsmiddel& aVoedingsmiddel)
{
    std::unique_ptr<weight::Lot> lot;
    if (aVoedingsmiddel.GetStandardlot() != nullptr)
    {
        const XmlStandardlot* xmllot = aVoedingsmiddel.GetStandardlot();
        if (xmllot->GetVoedingswaarde() != nullptr)
        {
            auto plot = std::make_unique<weight::CalculatedLot>(mModel.GetCalculator(), Create(xmllot->GetPortie()));
            plot->SetNumberOfPortions(Str::ToDouble(xmllot->Gethoeveelheid()));
            plot->SetKCalPer100Units(Str::ToDouble(xmllot->GetVoedingswaarde()->Getkcalper100()));
            plot->SetVetPer100Units(Str::ToDouble(xmllot->GetVoedingswaarde()->Getvetper100()));
            plot->SetKoolhydratenPer100Units(Str::ToDouble(xmllot->GetVoedingswaarde()->Getkoolhydratenper100().c_str()));
            plot->SetEiwitPer100Units(Str::ToDouble(xmllot->GetVoedingswaarde()->Geteiwitper100().c_str()));
            plot->SetVezelsPer100Units(Str::ToDouble(xmllot->GetVoedingswaarde()->Getvezelsper100().c_str()));
            lot = std::move(plot);
        }
        else if (xmllot->GetPuntenper100() != nullptr)
        {
            auto plot = std::make_unique<weight::FixedLot>(Create(xmllot->GetPortie()));
            plot->SetNumberOfPortions(Str::ToDouble(xmllot->Gethoeveelheid()));
            plot->SetPointsPer100Units(Str::ToDouble(xmllot->GetPuntenper100()->Getpunten()));
            lot = std::move(plot);
        }
    }
    else
    {
        weight::VMDefinitie* def = mModel.FindVoedingsmiddelDefinitie(aVoedingsmiddel.Getnaam());
        if (def == nullptr)
        {
            ::MessageBox(0, (_T("Unable to interpret voedingsmiddel ") + aVoedingsmiddel.Getnaam()).c_str(),
                         _T("ERROR"), MB_OK);
        }
        else
        {
            if (!def->GetPortieList().empty())
            {
                weight::Portie& portie = *def->GetPortieList()[0];

                if (def->IsCalculated())
                {
                    weight::CalculatedVMDef* cvmdef = def->GetCalculatedVMDef();
                    assert(def != nullptr);
                    auto clot = std::make_unique<weight::CalculatedLot>(mModel.GetCalculator(), portie);
                    clot->SetNumberOfPortions(1);
                    clot->SetParameters(cvmdef->GetParameters());
                    lot = std::move(clot);
                    lot = std::move(clot);
                }
                else if (def->IsFixed())
                {
                    weight::FixedVMDef* fvmdef = def->GetFixedVMDef();
                    assert(def != nullptr);
                    auto flot = std::make_unique<weight::FixedLot>(portie);
                    flot->SetNumberOfPortions(1);
                    flot->SetPointsPer100Units(fvmdef->GetPointsPer100Units());
                    lot = std::move(flot);
                }
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
    recept->SetNumberOfPortions(Str::ToDouble(aRecept.Gethoeveelheid()));
    return std::move(recept);
}


std::unique_ptr<weight::Gerecht> XmlReader::Create(const XmlGerecht& aGerecht)
{
    auto gerecht = std::make_unique<weight::Gerecht>(aGerecht.Getnaam(), Str::ToDouble(aGerecht.Getpunten()));
    gerecht->SetNumberOfPortions(Str::ToDouble(aGerecht.Gethoeveelheid()));
    return std::move(gerecht);
}


std::unique_ptr<weight::ManualItem> XmlReader::Create(const XmlHandmatigitem& anItem)
{
    auto item = std::make_unique<weight::ManualItem>(anItem.Getnaam(), Str::ToDouble(anItem.Getpunten()));
    item->Set(Str::ToDouble(anItem.Getpunten()), Str::ToDouble(anItem.Gethoeveelheid()));
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
    for (size_t i = 0; i < vmiddelen.size(); ++i)
        day->Add(Create(*vmiddelen[i]));

    const auto& recepten(aDag.GetReceptList());
    for (size_t i = 0; i < recepten.size(); ++i)
        day->Add(Create(*recepten[i]));

    const auto& gerechten(aDag.GetGerechtList());
    for (size_t i = 0; i < gerechten.size(); ++i)
        day->Add(Create(*gerechten[i]));

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


} // namespace ww2019