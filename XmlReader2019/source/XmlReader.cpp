
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


XmlReader::XmlReader(WW::Model& aModel)
    : mModel(aModel)
{
}


WW::Result XmlReader::Read(const std::tstring& aDirectory)
{
    WW::Result result = ReadPersonalia(aDirectory + _T("\\personalia.xml"));
    if (result == WW::Result::Ok)
        result = ReadVoedingsmiddelDefinities(aDirectory + _T("\\voedingsmiddeldefinities.xml"));
    if (result == WW::Result::Ok)
        result = ReadUnits(aDirectory + _T("\\units.xml"));
    if (result == WW::Result::Ok)
        result = ReadRecepten(aDirectory + _T("\\recepten.xml"));
    if (result == WW::Result::Ok)
        result = ReadGerechten(aDirectory + _T("\\restaurantgerechten.xml"));
    if (result == WW::Result::Ok)
        result = ReadWeeks(aDirectory);
    if (result == WW::Result::Ok)
        result = ReadBonusCells(aDirectory);

    return result;
}


WW::Result XmlReader::ReadPersonalia(const std::tstring& aDirectory)
{
    XmlPersonaliaReader reader;

    try {
        auto xmlpersonalia = reader.Read(aDirectory);
        if (xmlpersonalia == nullptr)
            return WW::Result::Ok;
        auto personalia = std::make_unique<WW::Personalia>(xmlpersonalia->Getgebruikersnaam());
        personalia->SetName(xmlpersonalia->Getnaam());
        Utils::Date date(Utils::Date::Today());
        if (Utils::ToDate(xmlpersonalia->Getgeboren(), date))
            personalia->SetDateOfBirth(date);
        personalia->SetGeslacht(xmlpersonalia->Getgeslacht() == XmlPersonalia::geslacht::Mannelijk
                                ? WW::Personalia::GESLACHT::Mannelijk : WW::Personalia::GESLACHT::Vrouwelijk);
        switch (xmlpersonalia->Getwerk())
        {
            case XmlPersonalia::werk::Zittend:
                personalia->SetTypeOfWork(WW::Personalia::WERKTYPE::Zittend);
                break;
            case XmlPersonalia::werk::Staand:
                personalia->SetTypeOfWork(WW::Personalia::WERKTYPE::Staand);
                break;
            case XmlPersonalia::werk::Lopend:
                personalia->SetTypeOfWork(WW::Personalia::WERKTYPE::Lopend);
                break;
            case XmlPersonalia::werk::Zwaar:
                personalia->SetTypeOfWork(WW::Personalia::WERKTYPE::Zwaar);
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
                personalia->SetStrategy(WW::STRATEGY_TYPE::KCal);
                break;
            case XmlPersonalia::strategie::CarboHydrates:
                personalia->SetStrategy(WW::STRATEGY_TYPE::CarboHydrates);
                break;
            default:
                return WW::Result::InterpretError;
        }

        mModel.Add(std::move(personalia));

        return WW::Result::Ok;
    }
    catch (XmlClass::Result result) {
        switch (result)
        {
            case XmlClass::Result::FileNotFound:
                return WW::Result::FileNotFound;
            case XmlClass::Result::ErrorInFilename:
                return WW::Result::ErrorInFilename;
            case XmlClass::Result::FileOpenError:
                return WW::Result::FileOpenError;
            case XmlClass::Result::ErrorInFile:
                return WW::Result::ErrorInFile;
            case XmlClass::Result::ParserError:
                return WW::Result::ParserError;
            case XmlClass::Result::InterpretError:
            case XmlClass::Result::WriteError:
            default:
                return WW::Result::InterpretError;
        }
    }


}

WW::Result XmlReader::ReadUnits(const std::tstring& aDirectory)
{
    XmlUnitsReader reader;
    try {
        auto xmlunits = reader.Read(aDirectory);
        if (xmlunits == nullptr)
            return WW::Result::Ok;
        const auto& units(xmlunits->GetUnitList());
        for (size_t i = 0; i < units.size(); ++i)
            mModel.Add(WW::Unit(mModel, units[i]->Getnaam()));

        return WW::Result::Ok;
    }
    catch (XmlClass::Result result) {
        switch (result) {
            case XmlClass::Result::FileNotFound:
                return WW::Result::FileNotFound;
            case XmlClass::Result::ErrorInFilename:
                return WW::Result::ErrorInFilename;
            case XmlClass::Result::FileOpenError:
                return WW::Result::FileOpenError;
            case XmlClass::Result::ErrorInFile:
                return WW::Result::ErrorInFile;
            case XmlClass::Result::ParserError:
                return WW::Result::ParserError;
            case XmlClass::Result::InterpretError:
            case XmlClass::Result::WriteError:
            default:
                return WW::Result::InterpretError;
        }
    }
}


WW::Result XmlReader::ReadVoedingsmiddelDefinities(const std::tstring& aDirectory)
{
    XmlVoedingsmiddeldefsReader reader;
    try {
        auto xmlvoedingsmiddeldefs = reader.Read(aDirectory);
        if (xmlvoedingsmiddeldefs == nullptr)
            return WW::Result::Ok;

        const auto& vmlist = xmlvoedingsmiddeldefs->GetVoedingsmiddeldefList();
        for (size_t i = 0; i < vmlist.size(); ++i)
        {
            // TF_TODO: Improve!!!
            std::unique_ptr<WW::VMDefBase> base;

            if (vmlist[i]->GetVoedingswaarde() != nullptr)
            {
                WW::CalculatedVMDef* cdefinitie = new WW::CalculatedVMDef(mModel.GetCalculator());
                cdefinitie->SetKCalPer100Units(Str::ToDouble(vmlist[i]->GetVoedingswaarde()->Getkcalper100().c_str()));
                cdefinitie->SetVetPer100Units(Str::ToDouble(vmlist[i]->GetVoedingswaarde()->Getvetper100().c_str()));
                cdefinitie->SetKoolhydratenPer100Units(Str::ToDouble(vmlist[i]->GetVoedingswaarde()->Getkoolhydratenper100().c_str()));
                cdefinitie->SetEiwitPer100Units(Str::ToDouble(vmlist[i]->GetVoedingswaarde()->Geteiwitper100().c_str()));
                cdefinitie->SetVezelsPer100Units(Str::ToDouble(vmlist[i]->GetVoedingswaarde()->Getvezelsper100().c_str()));
                base.reset(cdefinitie);
            }
            else if (vmlist[i]->GetPuntenper100() != nullptr)
            {
                WW::FixedVMDef* fdefinitie = new WW::FixedVMDef;
                fdefinitie->SetPointsPer100Units(Str::ToDouble(vmlist[i]->GetPuntenper100()->Getpunten()));
                base.reset(fdefinitie);
            }
            else
            {
                assert(false);
                return WW::Result::InterpretError;
            }

            WW::VMDefinitie* definitie = new WW::VMDefinitie(mModel.GetCalculator(),
                                                             vmlist[i]->GetVoedingsmiddelheader().Getnaam(),
                                                             WW::Unit(mModel, vmlist[i]->GetVoedingsmiddelheader().Getunit()),
                                                             std::move(base));


            if (!vmlist[i]->GetVoedingsmiddelheader().Getcategorie().empty())
                definitie->SetCategory(WW::CategorieNaam(mModel, vmlist[i]->GetVoedingsmiddelheader().Getcategorie()));
            if (!vmlist[i]->GetVoedingsmiddelheader().Getmerk().empty())
                definitie->SetMerk(WW::MerkNaam(mModel, vmlist[i]->GetVoedingsmiddelheader().Getmerk()));
            definitie->SetFavourite(vmlist[i]->Getfavoriet() == XmlVoedingsmiddeldef::favoriet::yes);

            const auto& portielist = vmlist[i]->GetPortieList();
            for (size_t p = 0; p < portielist.size(); ++p) {
                auto portie = std::make_unique<WW::Portie>(WW::PortieNaam(mModel, portielist[p]->Getnaam()));
                portie->SetUnits(Str::ToDouble(portielist[p]->Geteenheden().c_str()));
                mModel.Add(portie->GetName());
                definitie->AddPortie(std::move(portie));
            }

            auto uni = std::unique_ptr<WW::VMDefinitie>(definitie);
            mModel.Add(std::move(uni));
        }
    }
    catch (XmlClass::Result result) {
        switch (result) {
            case XmlClass::Result::FileNotFound:
                return WW::Result::FileNotFound;
            case XmlClass::Result::ErrorInFilename:
                return WW::Result::ErrorInFilename;
            case XmlClass::Result::FileOpenError:
                return WW::Result::FileOpenError;
            case XmlClass::Result::ErrorInFile:
                return WW::Result::ErrorInFile;
            case XmlClass::Result::ParserError:
                return WW::Result::ParserError;
            case XmlClass::Result::InterpretError:
            case XmlClass::Result::WriteError:
            default:
                return WW::Result::InterpretError;
                break;
        }
    }

    return WW::Result::Ok;
}


WW::Result XmlReader::ReadRecepten(const std::tstring& aDirectory)
{
    XmlReceptdefsReader reader;
    try {
        auto xmlreceptdefs = reader.Read(aDirectory);
        if (xmlreceptdefs == nullptr)
            return WW::Result::Ok;

        const auto& receptlist = xmlreceptdefs->GetReceptdefList();
        for (size_t i = 0; i < receptlist.size(); ++i)
        {
            auto receptdef = std::make_unique<WW::ReceptDefinitie>(receptlist[i]->Getnaam());
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
                return WW::Result::FileNotFound;
            case XmlClass::Result::ErrorInFilename:
                return WW::Result::ErrorInFilename;
            case XmlClass::Result::FileOpenError:
                return WW::Result::FileOpenError;
            case XmlClass::Result::ErrorInFile:
                return WW::Result::ErrorInFile;
            case XmlClass::Result::ParserError:
                return WW::Result::ParserError;
            case XmlClass::Result::InterpretError:
            case XmlClass::Result::WriteError:
            default:
                return WW::Result::InterpretError;
                break;
        }
    }

    return WW::Result::Ok;
}


WW::Result XmlReader::ReadWeeks(const std::tstring& aDirectory)
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

    return WW::Result::Ok;
}


WW::Result XmlReader::ReadWeek(const std::tstring& aDirectory)
{
    XmlWeekReader reader;
    try {
        auto xmlweek = reader.Read(aDirectory);
        if (xmlweek == nullptr)
            return WW::Result::Ok;

        auto week = std::make_unique<WW::Week>(Utils::ToDate(xmlweek->Getbegindatum()),
                                               Utils::ToDate(xmlweek->Geteinddatum()));
        week->SetPoints(xmlweek->Getpunten());
        week->SetSaveablePoints(xmlweek->Getweekpunten());
        week->SetStartWeight(Str::ToDouble(xmlweek->Getstartweight()));

        switch (xmlweek->Getstrategie())
        {
            case XmlWeek::strategie::KCal:
                week->SetStrategy(WW::STRATEGY_TYPE::KCal, mModel);
                break;
            case XmlWeek::strategie::Koolhydraten:
                week->SetStrategy(WW::STRATEGY_TYPE::CarboHydrates, mModel);
                break;
        }

        const auto& dagen(xmlweek->GetDagList());
        for (size_t i = 0; i < dagen.size(); ++i)
        {
            auto dag = Create(*dagen[i]);
            if (!week->Add(std::move(dag)))
                return WW::Result::InterpretError;
        }

        if (!mModel.Add(std::move(week)))
            return WW::Result::InterpretError;

        return WW::Result::Ok;
    }
    catch (XmlClass::Result result) {
        switch (result) {
            case XmlClass::Result::FileNotFound:
                return WW::Result::FileNotFound;
            case XmlClass::Result::ErrorInFilename:
                return WW::Result::ErrorInFilename;
            case XmlClass::Result::FileOpenError:
                return WW::Result::FileOpenError;
            case XmlClass::Result::ErrorInFile:
                return WW::Result::ErrorInFile;
            case XmlClass::Result::ParserError:
                return WW::Result::ParserError;
            case XmlClass::Result::InterpretError:
            case XmlClass::Result::WriteError:
            default:
                return WW::Result::InterpretError;
        }
    }
}


WW::Result XmlReader::ReadGerechten(const std::tstring& aDirectory)
{
    (void)aDirectory;

    return WW::Result::Ok;
}


WW::Result XmlReader::ReadBonusCells(const std::tstring& aDirectory)
{
    //XmlBonuslistReader reader;
    //try {
    //    auto xmlbonuslist = reader.Read(aDirectory + _T("\\bonuspoints.xml"));


    //    for (size_t i = 0; i < xmlbonuslist->GetBonuscellList().size(); ++i)
    //    {
    //        XmlBonuscell* cell = xmlbonuslist->GetBonuscellList()[i];
    //        WW::BonusPointsMap::MOVEMENT_INTENSITY intensity = WW::BonusPointsMap::MI_High;
    //        switch (cell->Getintensiteit())
    //        {
    //            case XmlBonuscell::intensiteit::hoog:
    //                intensity = WW::BonusPointsMap::MI_High;
    //                break;
    //            case XmlBonuscell::intensiteit::middel:
    //                intensity = WW::BonusPointsMap::MI_Medium;
    //                break;
    //            case XmlBonuscell::intensiteit::laag:
    //                intensity = WW::BonusPointsMap::MI_Low;
    //                break;
    //            default:
    //                delete xmlbonuslist;
    //                return WW::Result::InterpretError;
    //        }

    //        mModel.GetBonusPointsMap()[intensity][cell->Getgewicht()][(cell->Getminuten())] = cell->Getpunten();
    //    }
    //}
    //catch (XmlClass::Result result) {
    //    switch (result) {
    //        case XmlClass::Result::FileNotFound:
    //            return WW::Result::FileNotFound;
    //        case XmlClass::Result::ErrorInFilename:
    //            return WW::Result::ErrorInFilename;
    //        case XmlClass::Result::FileOpenError:
    //            return WW::Result::FileOpenError;
    //        case XmlClass::Result::ErrorInFile:
    //            return WW::Result::ErrorInFile;
    //        case XmlClass::Result::ParserError:
    //            return WW::Result::ParserError;
    //        case XmlClass::Result::InterpretError:
    //        case XmlClass::Result::WriteError:
    //        default:
    //            return WW::Result::InterpretError;
    //            break;
    //    }
    //}

    return WW::Result::Ok;
}


WW::Portie XmlReader::Create(const XmlPortie& aPortie)
{
    WW::Portie portie(WW::PortieNaam(mModel, aPortie.Getnaam()));
    portie.SetUnits(Str::ToDouble(aPortie.Geteenheden()));

    return portie;
}


std::unique_ptr<WW::Voedingsmiddel> XmlReader::Create(const XmlVoedingsmiddel& aVoedingsmiddel)
{
    std::unique_ptr<WW::Lot> lot;
    if (aVoedingsmiddel.GetStandardlot() != nullptr)
    {
        const XmlStandardlot* xmllot = aVoedingsmiddel.GetStandardlot();
        if (xmllot->GetVoedingswaarde() != nullptr)
        {
            auto plot = std::make_unique<WW::CalculatedLot>(mModel.GetCalculator(), Create(xmllot->GetPortie()));
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
            auto plot = std::make_unique<WW::FixedLot>(Create(xmllot->GetPortie()));
            plot->SetNumberOfPortions(Str::ToDouble(xmllot->Gethoeveelheid()));
            plot->SetPointsPer100Units(Str::ToDouble(xmllot->GetPuntenper100()->Getpunten()));
            lot = std::move(plot);
        }
    }
    else
    {
        WW::VMDefinitie* def = mModel.FindVoedingsmiddelDefinitie(aVoedingsmiddel.Getnaam());
        if (def == nullptr)
        {
            ::MessageBox(0, (_T("Unable to interpret voedingsmiddel ") + aVoedingsmiddel.Getnaam()).c_str(),
                         _T("ERROR"), MB_OK);
        }
        else
        {
            if (!def->GetPortieList().empty())
            {
                WW::Portie& portie = *def->GetPortieList()[0];

                if (def->IsCalculated())
                {
                    WW::CalculatedVMDef* cvmdef = def->GetCalculatedVMDef();
                    assert(def != nullptr);
                    auto clot = std::make_unique<WW::CalculatedLot>(mModel.GetCalculator(), portie);
                    clot->SetNumberOfPortions(1);
                    clot->SetParameters(cvmdef->GetParameters());
                    lot = std::move(clot);
                    lot = std::move(clot);
                }
                else if (def->IsFixed())
                {
                    WW::FixedVMDef* fvmdef = def->GetFixedVMDef();
                    assert(def != nullptr);
                    auto flot = std::make_unique<WW::FixedLot>(portie);
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

    auto voedingsmiddel = std::make_unique<WW::Voedingsmiddel>(aVoedingsmiddel.Getnaam(), std::move(lot),
                                                               WW::Unit(mModel, aVoedingsmiddel.Getunit()));
    voedingsmiddel->SetCategory(WW::CategorieNaam(mModel, aVoedingsmiddel.Getcategorie()));
    return std::move(voedingsmiddel);
}


std::unique_ptr<WW::Recept> XmlReader::Create(const XmlRecept& aRecept)
{
    auto recept = std::make_unique<WW::Recept>(aRecept.Getnaam());
    recept->SetPointsPerPortion(Str::ToDouble(aRecept.Getpunten()));
    recept->SetNumberOfPortions(Str::ToDouble(aRecept.Gethoeveelheid()));
    return std::move(recept);
}


std::unique_ptr<WW::Gerecht> XmlReader::Create(const XmlGerecht& aGerecht)
{
    auto gerecht = std::make_unique<WW::Gerecht>(aGerecht.Getnaam(), Str::ToDouble(aGerecht.Getpunten()));
    gerecht->SetNumberOfPortions(Str::ToDouble(aGerecht.Gethoeveelheid()));
    return std::move(gerecht);
}


std::unique_ptr<WW::ManualItem> XmlReader::Create(const XmlHandmatigitem& anItem)
{
    auto item = std::make_unique<WW::ManualItem>(anItem.Getnaam(), Str::ToDouble(anItem.Getpunten()));
    item->Set(Str::ToDouble(anItem.Getpunten()), Str::ToDouble(anItem.Gethoeveelheid()));
    return item;
}


std::unique_ptr<WW::Day> XmlReader::Create(const XmlDag& aDag)
{
    auto day = std::make_unique<WW::Day>(Utils::ToDate(aDag.Getdatum()));
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


WW::Bonus XmlReader::Create(const XmlBonuscell& aCell)
{
    WW::Bonus::INTENSITY intensity =
        aCell.Getintensiteit() == XmlBonuscell::intensiteit::hoog ? WW::Bonus::INTENSITY::High :
        aCell.Getintensiteit() == XmlBonuscell::intensiteit::middel ? WW::Bonus::INTENSITY::Medium :
        WW::Bonus::INTENSITY::Low;
    return WW::Bonus(intensity, aCell.Getminuten(), aCell.Getpunten());
}


} // namespace ww2019