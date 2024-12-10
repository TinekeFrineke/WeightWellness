
#include "XmlWriter.h"

#include <assert.h>
#include <tchar.h>

#include "Utilities/Date.h"
#include "Utilities/MathUtils.h"

#include "generated/XmlBonuscell.h"
#include "generated/XmlDag.h"
#include "generated/XmlHandmatigitem.h"
#include "generated/XmlPortie.h"
#include "generated/XmlPersonalia.h"
#include "generated/XmlPersonaliaWriter.h"
#include "generated/XmlRecept.h"
#include "generated/XmlReceptdef.h"
#include "generated/XmlReceptdefs.h"
#include "generated/XmlReceptdefsWriter.h"
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
#include "model/NutritionalValue.h"
#include "model/Personalia.h"
#include "model/Recept.h"
#include "model/ReceptDefinitie.h"
#include "model/VoedingsmiddelDefinitie.h"
#include "model/Week.h"
#include "model/Model.h"

#include "XmlItemCreateVisitor.h"
#include "XmlVMCreateVisitor.h"

namespace ww2024
{

namespace{
std::unique_ptr<XmlVoedingswaarde> CreateVoedingswaarde(const weight::FoodParameters& parameters)
{
    auto xmlVoedingswaarde = std::make_unique<XmlVoedingswaarde>();
    xmlVoedingswaarde->Setkcalper100(parameters.GetKCalPer100Units());
    xmlVoedingswaarde->Setvetper100(parameters.GetVetPer100Units());
    xmlVoedingswaarde->Seteiwitper100(parameters.GetVetPer100Units());
    xmlVoedingswaarde->Setkoolhydratenper100(parameters.GetVetPer100Units());
    xmlVoedingswaarde->Setvezelsper100(parameters.GetVetPer100Units());
    return xmlVoedingswaarde;
}

}


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

    auto xmlpersonalia = std::make_unique<XmlPersonalia>();
    xmlpersonalia->Setgebruikersnaam(personalia->GetUserName());
    xmlpersonalia->Setnaam(personalia->GetName());
    xmlpersonalia->Setgeboren(Utils::ToString(personalia->GetDateOfBirth()));
    xmlpersonalia->Setgeslacht(personalia->GetGeslacht() == weight::Personalia::GESLACHT::Mannelijk
                               ? XmlPersonalia::geslacht::Mannelijk
                               : XmlPersonalia::geslacht::Vrouwelijk);
    xmlpersonalia->Setgewicht(personalia->GetStreefGewicht());
    xmlpersonalia->Setlengte(personalia->GetLengte());
    xmlpersonalia->Setkcpunten(personalia->GetKCPuntenTotaal());
    xmlpersonalia->Setkcweekpunten(personalia->GetKCWeekPuntenTotaal());
    xmlpersonalia->Setstreefgewicht(personalia->GetStreefGewicht());
    xmlpersonalia->Setstartgewicht(personalia->GetStartGewicht());
    xmlpersonalia->Sethuidiggewicht(personalia->GetHuidigGewicht());
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

    //weight::IFoodDefinitionRepository* pos;
    auto vmdefinities = mModel.GetFoodDefinitionRepository()->GetAll();
    for (size_t i = 0; i < vmdefinities.size(); ++i)
    {
        auto xmlvmdefinitie = std::make_unique<XmlVoedingsmiddeldef>();
        xmlvmdefinitie->Setnaam(vmdefinities[i]->GetName());
        if (!vmdefinities[i]->GetCategory().empty())
            xmlvmdefinitie->Setcategorie(vmdefinities[i]->GetCategory());
        if (!vmdefinities[i]->GetMerk().empty())
            xmlvmdefinitie->Setmerk(vmdefinities[i]->GetMerk());

        const auto& nutritionalValue = vmdefinities[i]->GetNutritionalValue();
        auto xmlwaarde = std::make_unique<XmlVoedingswaarde>();
        xmlwaarde->Setkcalper100(nutritionalValue.GetKCalPer100Units());
        xmlwaarde->Seteiwitper100(nutritionalValue.GetProteinPer100Units());
        xmlwaarde->Setvetper100(nutritionalValue.GetFatPer100Units());
        xmlwaarde->Setvezelsper100(nutritionalValue.GetFibersPer100Units());
        xmlwaarde->Setkoolhydratenper100(nutritionalValue.GetCarbohydratesPer100Units());

        xmlvmdefinitie->SetXmlVoedingswaarde(std::move(xmlwaarde));
        xmlvmdefinitie->Setunit(vmdefinities[i]->GetUnit());
        xmlvmdefinitie->Setfavoriet(vmdefinities[i]->IsFavourite()
                                    ? XmlVoedingsmiddeldef::favoriet::yes
                                    : XmlVoedingsmiddeldef::favoriet::no);

        const std::vector<std::unique_ptr<weight::Portie>>& portielist = vmdefinities[i]->GetPortieList();
        for (size_t p = 0; p < vmdefinities[i]->GetPortieList().size(); ++p) {
            auto portie = std::make_unique<XmlPortie>();
            portie->Setnaam(portielist[p]->GetName());
            portie->Seteenheden(portielist[p]->GetUnits());
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
    auto xmlrecepten = std::make_unique<XmlReceptdefs>();

    const auto& recepten = mModel.GetReceptDefs();
    for (size_t i = 0; i < recepten.size(); ++i)
    {
        auto recept = std::make_unique<XmlReceptdef>();
        recept->Setnaam(recepten[i]->GetName());
        recept->Setporties(recepten[i]->GetPortions());

        XmlReceptItemCreateVisitor visitor(*this, *recept);

        for (size_t j = 0; j < recepten[i]->GetItems().size(); ++j)
            recepten[i]->GetItems()[j]->Accept(visitor);

        xmlrecepten->Add(std::move(recept));
    }

    XmlReceptdefsWriter writer;
    writer.Write(aFilename, *xmlrecepten);

    return weight::Result::Ok;
}


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
    anXmlPortie.Seteenheden(aPortie.GetUnits());
    anXmlPortie.Setnaam(aPortie.GetName());
    return weight::Result::Ok;
}


//weight::Result XmlWriter::Create(const weight::PortionedLot& aLot, XmlStandardlot& anXmlLot)
//{
//    anXmlLot.Sethoeveelheid(Str::ToTString(aLot.GetNumberOfPortions()));
//
//    auto xmlVoedingswaarde = std::make_unique<XmlVoedingswaarde>();
//
//    xmlVoedingswaarde->Setkcalper100(Str::ToTString(aLot.GetKCalPer100Units()));
//    xmlVoedingswaarde->Setvetper100(Str::ToTString(aLot.GetVetPer100Units()));
//    xmlVoedingswaarde->Setkoolhydratenper100(Str::ToTString(aLot.GetKoolhydratenPer100Units()));
//    xmlVoedingswaarde->Seteiwitper100(Str::ToTString(aLot.GetEiwitPer100Units()));
//    xmlVoedingswaarde->Setvezelsper100(Str::ToTString(aLot.GetVezelsPer100Units()));
//
//    anXmlLot.SetXmlVoedingswaarde(std::move(xmlVoedingswaarde));
//
//    auto xmlPortie = std::make_unique<XmlPortie>();
//    xmlPortie->Seteenheden(std::to_wstring(aLot.GetPortie().GetUnits()));
//    xmlPortie->Setnaam(aLot.GetPortie().GetName());
//
//    anXmlLot.SetXmlPortie(std::move(xmlPortie));
//    return weight::Result::Ok;
//}
//
//

weight::Result XmlWriter::Create(const weight::Voedingsmiddel& aMiddel,
                                 XmlVoedingsmiddel& anXmlMiddel)
{
    anXmlMiddel.Setnaam(aMiddel.GetName());
    anXmlMiddel.Setcategorie(aMiddel.GetCategory());
    anXmlMiddel.Setunit(aMiddel.GetUnit());
    anXmlMiddel.Setaantalporties(aMiddel.GetConstLot().GetNumberOfPortions());

    auto portie = std::make_unique<XmlPortie>();
    Create(aMiddel.GetConstLot().GetPortie(), *portie);
    anXmlMiddel.SetXmlPortie(std::move(portie));

    auto voedingswaarde = CreateVoedingswaarde(aMiddel.GetConstLot().GetParameters());
    anXmlMiddel.SetXmlVoedingswaarde(std::move(voedingswaarde));

    return weight::Result::Ok;
}


weight::Result XmlWriter::Create(const weight::Recept& aRecept,
                                 XmlRecept& anXmlRecept)
{
    anXmlRecept.Setnaam(aRecept.GetName());
    anXmlRecept.Setaantalporties(aRecept.GetNumberOfPortions());
    anXmlRecept.Setpunten(aRecept.GetPointsPerPortion());
    return weight::Result::Ok;
}


weight::Result XmlWriter::Create(const weight::ManualItem& anItem,
                                 XmlHandmatigitem& anXmlItem)
{
    anXmlItem.Setnaam(anItem.GetName());
    anXmlItem.Sethoeveelheid(anItem.GetAmount());
    anXmlItem.Setpunten(anItem.GetPoints());
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
    auto xmlweek = std::make_unique<XmlWeek>();

    xmlweek->Setbegindatum(Utils::ToString(aWeek.GetStartDate()));
    xmlweek->Seteinddatum(Utils::ToString(aWeek.GetEndDate()));
    xmlweek->Setpunten(static_cast<int>(aWeek.GetPoints()));
    xmlweek->Setweekpunten(static_cast<int>(aWeek.GetSaveablePoints()));
    xmlweek->Setstartweight(aWeek.GetStartWeight());

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

    return weight::Result::Ok;
}


} // namespace ww2024