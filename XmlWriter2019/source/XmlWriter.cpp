
#include "XmlWriter.h"

#include <assert.h>
#include <tchar.h>

#include "Utilities/Date.h"
#include "Utilities/MathUtils.h"

#include "generated/XmlBonuscell.h"
#include "generated/XmlDag.h"
#include "generated/XmlGerecht.h"
#include "generated/XmlGerechtdef.h"
#include "generated/XmlGerechtdefs.h"
#include "generated/XmlGerechtdefsWriter.h"
#include "generated/XmlHandmatigitem.h"
#include "generated/XmlPortie.h"
#include "generated/XmlPersonalia.h"
#include "generated/XmlPersonaliaWriter.h"
#include "generated/XmlPuntenPer100.h"
#include "generated/XmlRecept.h"
#include "generated/XmlReceptdef.h"
#include "generated/XmlReceptdefs.h"
#include "generated/XmlReceptdefsWriter.h"
#include "generated/XmlStandardLot.h"
#include "generated/XmlUnit.h"
#include "generated/XmlUnits.h"
#include "generated/XmlUnitsWriter.h"
#include "generated/XmlVoedingsmiddel.h"
#include "generated/XmlVoedingsmiddeldef.h"
#include "generated/XmlVoedingsmiddeldefs.h"
#include "generated/XmlVoedingsmiddeldefsWriter.h"
#include "generated/XmlVoedingswaarde.h"
#include "generated/XmlWeek.h"
#include "generated/XmlWeekWriter.h"

#include "model/Day.h"
#include "model/IFoodDefinitionRepository.h"
#include "model/IRepository.h"
#include "model/ManualItem.h"
#include "model/Personalia.h"
#include "model/Recept.h"
#include "model/ReceptDefinitie.h"
#include "model/Gerecht.h"
#include "model/GerechtDefinitie.h"
#include "model/VoedingsmiddelDefinitie.h"
#include "model/Week.h"
#include "model/Model.h"

#include "XmlItemCreateVisitor.h"
#include "XmlLotCreateVisitor.h"
#include "XmlVMCreateVisitor.h"

namespace ww2019
{


weight::Result XmlWriter::Write(const std::tstring& aDirectory)
{
    weight::Result result = WritePersonalia(aDirectory + _T("\\personalia.xml"));
    if (result == weight::Result::Ok)
        result = WriteUnits(aDirectory + _T("\\units.xml"));
    if (result == weight::Result::Ok)
        result = WriteVoedingsmiddelDefinities(aDirectory + _T("\\voedingsmiddeldefinities.xml"));
    if (result == weight::Result::Ok)
        result = WriteRecepten(aDirectory + _T("\\recepten.xml"));
    //if (result == weight::Result::Ok)
    //    result = WriteGerechten(aDirectory + _T("\\restaurantgerechten.xml"));
    if (result == weight::Result::Ok)
        result = WriteWeeks(aDirectory);

    return result;
}


weight::Result XmlWriter::WritePersonalia(const std::tstring& aFilename)
{
    if (mModel.GetPersonalia().empty())
        return weight::Result::Ok;

    weight::Personalia* personalia = mModel.GetActivePersonalia();

    if (personalia->GetUserName().empty())
        return weight::Result::Ok;

    XmlPersonalia* xmlpersonalia = new XmlPersonalia;
    xmlpersonalia->Setgebruikersnaam(personalia->GetUserName());
    xmlpersonalia->Setnaam(personalia->GetName());
    xmlpersonalia->Setgeboren(Utils::ToString(personalia->GetDateOfBirth()));
    xmlpersonalia->Setgeslacht(personalia->GetGeslacht() == weight::Personalia::GESLACHT::Mannelijk
                               ? XmlPersonalia::geslacht::Mannelijk
                               : XmlPersonalia::geslacht::Vrouwelijk);
    xmlpersonalia->Setgewicht(Str::ToTString(personalia->GetStreefGewicht()));
    xmlpersonalia->Setlengte(Str::ToTString(personalia->GetLengte()));
    xmlpersonalia->Setkcpunten(Str::ToTString(personalia->GetKCPuntenTotaal()));
    xmlpersonalia->Setkcweekpunten(Str::ToTString(personalia->GetKCWeekPuntenTotaal()));
    xmlpersonalia->Setstreefgewicht(Str::ToTString(personalia->GetStreefGewicht()));
    xmlpersonalia->Setstartgewicht(Str::ToTString(personalia->GetStartGewicht()));
    xmlpersonalia->Sethuidiggewicht(Str::ToTString(personalia->GetHuidigGewicht()));
    switch (personalia->GetStrategy())
    {
        case weight::STRATEGY_TYPE::KCal:
            xmlpersonalia->Setstrategie(XmlPersonalia::strategie::KCal);
            break;
        case weight::STRATEGY_TYPE::CarboHydrates:
            xmlpersonalia->Setstrategie(XmlPersonalia::strategie::CarboHydrates);
            break;
        default:
            return weight::Result::InterpretError;
    }

    XmlPersonaliaWriter writer;
    writer.Write(aFilename, *xmlpersonalia);

    delete xmlpersonalia;

    return weight::Result::Ok;
}


weight::Result XmlWriter::WriteUnits(const std::tstring& aFilename)
{
    XmlUnits xmlunits;

    const auto units = mModel.GetUnitRepository()->Get();
    for (auto unit : units)
    {
        auto xmlUnit = std::make_unique<XmlUnit>();
        xmlUnit->Setnaam(unit);
        xmlunits.Add(std::move(xmlUnit));
    }

    XmlUnitsWriter writer;
    writer.Write(aFilename, xmlunits);

    return weight::Result::Ok;
}


weight::Result XmlWriter::WriteVoedingsmiddelDefinities(const std::tstring& aFilename)
{
    auto xmlvmdefinities = std::make_unique<XmlVoedingsmiddeldefs>();

    auto vmdefinities = mModel.GetFoodDefinitionRepository()->GetAll();
    for (size_t i = 0; i < vmdefinities.size(); ++i)
    {
        auto xmlvmdefinitie = std::make_unique<XmlVoedingsmiddeldef>();
        xmlvmdefinitie->GetVoedingsmiddelheader().Setnaam(vmdefinities[i]->GetName());
        if (!vmdefinities[i]->GetCategory().empty())
            xmlvmdefinitie->GetVoedingsmiddelheader().Setcategorie(vmdefinities[i]->GetCategory());
        if (!vmdefinities[i]->GetMerk().empty())
            xmlvmdefinitie->GetVoedingsmiddelheader().Setmerk(vmdefinities[i]->GetMerk());

        if (vmdefinities[i]->IsCalculated())
        {
            weight::CalculatedVMDef* definitie = vmdefinities[i]->GetCalculatedVMDef();
            assert(definitie != NULL);
            auto xmlwaarde = std::make_unique<XmlVoedingswaarde>();
            xmlwaarde->Setkcalper100(Str::ToTString(definitie->GetKCalPer100Units()));
            xmlwaarde->Seteiwitper100(Str::ToTString(definitie->GetEiwitPer100Units()));
            xmlwaarde->Setvetper100(Str::ToTString(definitie->GetVetPer100Units()));
            xmlwaarde->Setvezelsper100(Str::ToTString(definitie->GetVezelsPer100Units()));
            xmlwaarde->Setkoolhydratenper100(Str::ToTString(definitie->GetKoolhydratenPer100Units()));

            xmlvmdefinitie->Add(std::move(xmlwaarde));
        }
        else if (vmdefinities[i]->IsFixed())
        {
            weight::FixedVMDef* definitie = vmdefinities[i]->GetFixedVMDef();
            assert(definitie != NULL);

            auto xmlpuntenper100 = std::make_unique<XmlPuntenper100>();
            xmlpuntenper100->Setpunten(Str::ToTString(definitie->GetPointsPer100Units()));

            xmlvmdefinitie->Add(std::move(xmlpuntenper100));
        }

        xmlvmdefinitie->GetVoedingsmiddelheader().Setunit(vmdefinities[i]->GetUnit());
        xmlvmdefinitie->Setfavoriet(vmdefinities[i]->IsFavourite()
                                    ? XmlVoedingsmiddeldef::favoriet::yes
                                    : XmlVoedingsmiddeldef::favoriet::no);

        const std::vector<std::unique_ptr<weight::Portie>>& portielist = vmdefinities[i]->GetPortieList();
        for (size_t p = 0; p < vmdefinities[i]->GetPortieList().size(); ++p) {
            auto portie = std::make_unique<XmlPortie>();
            portie->Setnaam(portielist[p]->GetName());
            portie->Seteenheden(Str::ToTString(portielist[p]->GetUnits()));
            xmlvmdefinitie->Add(std::move(portie));
        }

        xmlvmdefinities->Add(std::move(xmlvmdefinitie));
    }

    XmlVoedingsmiddeldefsWriter writer;
    writer.Write(aFilename, *xmlvmdefinities);

    return weight::Result::Ok;
}


weight::Result XmlWriter::WriteRecepten(const std::tstring& aFilename)
{
    XmlReceptdefs* xmlrecepten = new XmlReceptdefs;

    const auto& recepten = mModel.GetReceptDefs();
    for (size_t i = 0; i < recepten.size(); ++i)
    {
        auto recept = std::make_unique<XmlReceptdef>();
        recept->Setnaam(recepten[i]->GetName());
        recept->Setporties(Str::ToTString(recepten[i]->GetPortions()));

        XmlReceptItemCreateVisitor visitor(*this, *recept);

        for (size_t j = 0; j < recepten[i]->GetItems().size(); ++j)
            recepten[i]->GetItems()[j]->Accept(visitor);

        xmlrecepten->Add(std::move(recept));
    }

    XmlReceptdefsWriter writer;
    writer.Write(aFilename, *xmlrecepten);
    delete xmlrecepten;

    return weight::Result::Ok;
}


//weight::Result XmlWriter::WriteGerechten(const std::tstring& aFilename)
//{
//    XmlGerechtdefs* xmlgerechten = new XmlGerechtdefs;
//
//    const auto& restaurantgerechten = mModel.GetGerechtDefs();
//    for (size_t i = 0; i < restaurantgerechten.size(); ++i)
//    {
//        auto restaurantgerecht = std::make_unique<XmlGerechtdef>();
//        restaurantgerecht->Setnaam(restaurantgerechten[i]->GetName());
//        xmlgerechten->Add(std::move(restaurantgerecht));
//    }
//
//    XmlGerechtdefsWriter xmlwriter;
//    xmlwriter.Write(aFilename, *xmlgerechten);
//    delete xmlgerechten;
//    return weight::Result::Ok;
//}


weight::Result XmlWriter::WriteWeeks(const std::tstring& aDirectory)
{
    weight::Result result = weight::Result::Ok;

    const auto& weeks = mModel.GetWeeks();
    for (size_t i = 0; i < weeks.size() && result == weight::Result::Ok; ++i)
    {
        Utils::Date startdate = weeks[i]->GetStartDate();
        result = Write(*weeks[i], aDirectory + _T("\\week") + Utils::ToString(startdate) + _T(".xml"));
    }

    return result;
}


weight::Result XmlWriter::Create(const weight::Portie& aPortie, XmlPortie& anXmlPortie)
{
    anXmlPortie.Seteenheden(Str::ToTString(aPortie.GetUnits()));
    anXmlPortie.Setnaam(aPortie.GetName());
    return weight::Result::Ok;
}


weight::Result XmlWriter::Create(const weight::CalculatedLot& aLot, XmlStandardlot& anXmlLot)
{
    anXmlLot.Sethoeveelheid(Str::ToTString(aLot.GetNumberOfPortions()));

    auto xmlVoedingswaarde = std::make_unique<XmlVoedingswaarde>();
    assert(anXmlLot.GetPuntenper100() == NULL);
    assert(anXmlLot.GetVoedingswaarde() == NULL);

    xmlVoedingswaarde->Setkcalper100(Str::ToTString(aLot.GetKCalPer100Units()));
    xmlVoedingswaarde->Setvetper100(Str::ToTString(aLot.GetVetPer100Units()));
    xmlVoedingswaarde->Setkoolhydratenper100(Str::ToTString(aLot.GetKoolhydratenPer100Units()));
    xmlVoedingswaarde->Seteiwitper100(Str::ToTString(aLot.GetEiwitPer100Units()));
    xmlVoedingswaarde->Setvezelsper100(Str::ToTString(aLot.GetVezelsPer100Units()));

    anXmlLot.Add(std::move(xmlVoedingswaarde));

    Create(aLot.GetPortie(), anXmlLot.GetPortie());
    return weight::Result::Ok;
}


weight::Result XmlWriter::Create(const weight::FixedLot& aLot, XmlStandardlot& anXmlLot)
{
    anXmlLot.Sethoeveelheid(Str::ToTString(aLot.GetNumberOfPortions()));

    auto xmlpuntenper100 = std::make_unique<XmlPuntenper100>();
    assert(anXmlLot.GetPuntenper100() == nullptr);
    assert(anXmlLot.GetVoedingswaarde() == nullptr);

    xmlpuntenper100->Setpunten(Str::ToTString(aLot.GetPointsPer100Units()));
    anXmlLot.Add(std::move(xmlpuntenper100));

    Create(aLot.GetPortie(), anXmlLot.GetPortie());
    return weight::Result::Ok;
}


weight::Result XmlWriter::Create(const weight::Voedingsmiddel& aMiddel,
                             XmlVoedingsmiddel& anXmlMiddel)
{
    anXmlMiddel.Setnaam(aMiddel.GetName());
    anXmlMiddel.Setcategorie(aMiddel.GetCategory());
    anXmlMiddel.Setunit(aMiddel.GetUnit());

    XmlLotCreateVisitor visitor(*this, anXmlMiddel);
    const_cast<weight::Voedingsmiddel&>(aMiddel).GetLot().Accept(visitor);

    return weight::Result::Ok;
}


weight::Result XmlWriter::Create(const weight::Recept& aRecept,
                             XmlRecept& anXmlRecept)
{
    anXmlRecept.Setnaam(aRecept.GetName());
    anXmlRecept.Sethoeveelheid(Str::ToTString(aRecept.GetNumberOfPortions()));
    anXmlRecept.Setpunten(Str::ToTString(aRecept.GetPointsPerPortion()));
    return weight::Result::Ok;
}


weight::Result XmlWriter::Create(const weight::Gerecht& aGerecht,
                             XmlGerecht& anXmlGerecht)
{
    anXmlGerecht.Setnaam(aGerecht.GetName());
    anXmlGerecht.Sethoeveelheid(Str::ToTString(aGerecht.GetNumberOfPortions()));
    anXmlGerecht.Setpunten(Str::ToTString(aGerecht.GetPointsPerPortion()));
    return weight::Result::Ok;
}


weight::Result XmlWriter::Create(const weight::ManualItem& anItem,
                             XmlHandmatigitem& anXmlItem)
{
    anXmlItem.Setnaam(anItem.GetName());
    anXmlItem.Sethoeveelheid(Str::ToTString(anItem.GetAmount()));
    anXmlItem.Setpunten(Str::ToTString(anItem.GetPoints()));
    return weight::Result::Ok;
}


weight::Result XmlWriter::Create(const weight::Day& aDay,
                             XmlDag& aDag)
{
    aDag.Setdatum(Utils::ToString(aDay.GetDate()));
    if (!Math::Equals(aDay.GetWeight(), 0))
        aDag.Setgewicht(Str::ToTString(aDay.GetWeight()));
    if (!Math::Equals(aDay.GetFreeBonusPoints(), 0))
        aDag.Setbonuspunten(Str::ToTString(aDay.GetFreeBonusPoints()));

    for (std::list<weight::Bonus>::const_iterator citer = aDay.GetBonuses().begin();
         citer != aDay.GetBonuses().end();
         ++citer)
    {
        auto xmlcell = std::make_unique<XmlBonuscell>();
        xmlcell->Setgewicht((int)aDay.GetWeight());
        switch (citer->GetIntensity())
        {
            case weight::Bonus::INTENSITY::High:
                xmlcell->Setintensiteit(XmlBonuscell::intensiteit::hoog);
                break;
            case weight::Bonus::INTENSITY::Medium:
                xmlcell->Setintensiteit(XmlBonuscell::intensiteit::middel);
                break;
            case weight::Bonus::INTENSITY::Low:
                xmlcell->Setintensiteit(XmlBonuscell::intensiteit::laag);
                break;
        }

        xmlcell->Setminuten(citer->GetDuration());
        xmlcell->Setpunten(citer->GetPoints());

        aDag.Add(std::move(xmlcell));
    }

    aDag.Setbonuspunten(Str::ToTString(aDay.GetFreeBonusPoints()));

    const std::vector<std::unique_ptr<weight::Item>>& items = aDay.GetItems();
    XmlDagItemCreateVisitor visitor(*this, aDag);
    for (auto& item : items)
        item->Accept(visitor);

    return weight::Result::Ok;
}


weight::Result XmlWriter::Write(weight::Week& aWeek, const std::tstring& aFilename)
{
    XmlWeek* xmlweek = new XmlWeek;

    xmlweek->Setbegindatum(Utils::ToString(aWeek.GetStartDate()));
    xmlweek->Seteinddatum(Utils::ToString(aWeek.GetEndDate()));
    xmlweek->Setpunten(static_cast<int>(aWeek.GetPoints()));
    xmlweek->Setweekpunten(static_cast<int>(aWeek.GetSaveablePoints()));
    xmlweek->Setstartweight(Str::ToTString(aWeek.GetStartWeight()));

    switch (aWeek.GetStrategy())
    {
        case weight::STRATEGY_TYPE::KCal:
            xmlweek->Setstrategie(XmlWeek::strategie::KCal);
            break;
        case weight::STRATEGY_TYPE::CarboHydrates:
            xmlweek->Setstrategie(XmlWeek::strategie::Koolhydraten);
            break;
        default:
            assert(false);
    }

    const std::vector<std::unique_ptr<weight::Day>>& days = aWeek.GetDays();
    for (size_t i = 0; i < days.size(); ++i)
    {
        if (days[i]->IsEmpty())
            continue;
        auto dag = std::make_unique<XmlDag>();
        Create(*days[i], *dag);
        xmlweek->Add(std::move(dag));
    }

    XmlWeekWriter xmlwriter;
    xmlwriter.Write(aFilename, *xmlweek);
    delete xmlweek;

    return weight::Result::Ok;
}


} // namespace ww2019