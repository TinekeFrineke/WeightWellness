
#include "Model.h"

#include <tchar.h>
#include <assert.h>

#include "IWeek.h"
#include "Lot.h"
#include "ModelFactory.h"
#include "Personalia.h"
#include "ReceptDefinitie.h"
#include "Repository.h"
#include "StringRepository.h"
#include "VoedingsmiddelDefinitie.h"

namespace weight
{


Model::Model()
    : mStrategyType(STRATEGY_TYPE::KCal)
    , m_foodDefinitions(std::make_shared<Repository<VMDefinitie>>())
    , m_recipeDefinitions(std::make_shared<Repository<ReceptDefinitie>>())
    , m_units(std::make_shared<StringRepository>())
    , m_categories(std::make_shared<StringRepository>())
    , m_brands(std::make_shared<StringRepository>())
    , m_calculator(std::make_shared< PointsCalculator>())
{
    m_calculator->SetStrategy(STRATEGY_TYPE::KCal);
}


Model::~Model() = default;


void Model::SetStrategy(STRATEGY_TYPE eType)
{
    if (eType == mStrategyType)
        return;

    mStrategyType = eType;
    m_calculator->SetStrategy(eType);
    if (GetPersonalia() != nullptr)
        GetPersonalia()->SetStrategy(eType);

    IWeek* week = FindWeek(Utils::Date::Today());

    if (week != nullptr)
        week->SetStrategy(eType, *this);
}


IWeek* Model::FindWeek(const Utils::Date& aDate)
{
    for (const auto& week : mWeeks)
        if (week->Includes(aDate))
            return week.get();

    return nullptr;
}

IWeek* Model::CreateWeek(const Utils::Date& aDate)
{
    auto weekptr = FindWeek(aDate);
    if (weekptr != nullptr)
        return weekptr;

    // Week not found, create a new week
    Utils::Date enddate(aDate);
    enddate.AddDays(6);
    while (FindWeek(enddate) != nullptr && enddate != aDate)
        enddate.SubtractDays(1);

    auto week = ModelFactory().CreateWeek(aDate, enddate);
    week->SetPoints(GetPersonalia()->GetPuntenTotaal(GetStrategy()));
    week->SetSaveablePoints(GetVrijePunten());
    week->SetStrategy(GetStrategy(), *this);
    week->SetStartWeight(GetPersonalia()->GetHuidigGewicht());
    weekptr = week.get();
    Add(std::move(week));
    return weekptr;
}


std::shared_ptr<IStringRepository> Model::GetUnitRepository() const noexcept
{
    return m_units;
}

std::shared_ptr<IStringRepository> Model::GetCategoryRepository() const noexcept
{
    return m_categories;
}

std::shared_ptr<IStringRepository> Model::GetBrandRepository() const noexcept
{
    return m_brands;
}

std::shared_ptr<IRepository<VMDefinitie>> Model::GetFoodDefinitionRepository() const noexcept
{
    return m_foodDefinitions;
}

std::shared_ptr<IRepository<ReceptDefinitie>> Model::GetRecipeDefinitionRepository() const noexcept
{
    return m_recipeDefinitions;
}

bool Model::Add(std::unique_ptr<IWeek> aWeek)
{
    for (const auto& week: mWeeks)
    {
        if (week->GetStartDate() == aWeek->GetStartDate())
        {
            TCHAR smsg[1024];
            _stprintf_s(smsg, _T("Could not add week with startdate %s\n"), ToString(aWeek->GetStartDate()).c_str());
            ::MessageBox(0, smsg, _T("ERROR"), MB_OK);
            return false;
        }
    }

    mWeeks.push_back(std::move(aWeek));
    return true;
}


bool Model::Add(std::unique_ptr<VMDefinitie> aDefinitie)
{
    auto definition(aDefinitie.get());
    if (!m_foodDefinitions->Add(std::move(aDefinitie)))
        return false;

    m_units->Add(definition->GetUnit());
    m_categories->Add(definition->GetCategory());
    return true;
}


double Model::GetVrijePunten() const
{
    switch (mStrategyType) {
        case STRATEGY_TYPE::KCal:
            return GetPersonalia()->GetKCWeekPuntenTotaal();
        case STRATEGY_TYPE::CarboHydrates:
            return GetPersonalia()->GetCHWeekPuntenTotaal() / 7 - GetPersonalia()->GetCHPuntenTotaal();
        default:
            assert(false);
            return 0;
    }
}

Personalia* Model::GetPersonalia() const
{
    return mPersonalia.get();
}


void Model::SetPersonalia(std::unique_ptr<Personalia> personalia)
{
    mPersonalia = std::move(personalia);
}

double Model::GetPuntenTotaal(STRATEGY_TYPE eType) const
{
    return GetPersonalia()->GetPuntenTotaal(eType);
}


double Model::GetWeekPuntenTotaal() const
{
    switch (mStrategyType)
    {
        case STRATEGY_TYPE::KCal:
            return GetPersonalia()->GetKCWeekPuntenTotaal();
        case STRATEGY_TYPE::CarboHydrates:
            return GetPersonalia()->GetCHWeekPuntenTotaal();
        default:
            return 0;
    }
}


}
