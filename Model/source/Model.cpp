
#include "Model.h"

#include <tchar.h>
#include <assert.h>

#include "FoodDefinitionRepository.h"
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
    , m_foodDefinitions(std::make_shared<FoodDefinitionRepository>())
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
    if (GetActivePersonalia() != nullptr)
        GetActivePersonalia()->SetStrategy(eType);

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
    week->SetPoints(GetActivePersonalia()->GetPuntenTotaal(GetStrategy()));
    week->SetSaveablePoints(GetVrijePunten());
    week->SetStrategy(GetStrategy(), *this);
    week->SetStartWeight(GetActivePersonalia()->GetHuidigGewicht());
    weekptr = week.get();
    Add(std::move(week));
    return weekptr;
}


VMDefinitie* Model::FindVoedingsmiddelDefinitie(const std::tstring& aName)
{
    return m_foodDefinitions->Find(aName);
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

std::shared_ptr<IFoodDefinitionRepository> Model::GetFoodDefinitionRepository() const noexcept
{
    return m_foodDefinitions;
}

std::shared_ptr<IRepository<ReceptDefinitie>> Model::GetRecipeDefinitionRepository() const noexcept
{
    return m_recipeDefinitions;
}

void Model::AddUnit(const std::wstring& aUnit)
{
    m_units->Add(aUnit);
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

    AddUnit(definition->GetUnit());
    AddCategory(definition->GetCategory());
    return true;
}


bool Model::Add(std::unique_ptr<Personalia> aPersonalia)
{
    if (HasPersonalia(aPersonalia->GetUserName()))
        throw std::runtime_error("Personalia already exists");

    if (mPersonalia.empty())
        SetStrategy(aPersonalia->GetStrategy());

    mPersonalia.push_back(std::move(aPersonalia));
    return true;
}


void Model::AddCategory(const std::wstring& aCategory)
{
    m_categories->Add(aCategory);
}


void Model::AddBrand(const std::wstring& brand)
{
    m_brands->Add(brand);
}


bool Model::Remove(const VMDefinitie* aDefinitie)
{
    return aDefinitie != nullptr && m_foodDefinitions->Remove(aDefinitie->GetName());
}


bool Model::Remove(const Personalia* aPersonalia)
{
    for (auto iter = mPersonalia.begin(); iter != mPersonalia.end(); ++iter)
    {
        if (iter->get() == aPersonalia)
        {
            mPersonalia.erase(iter);
            return true;
        }
    }

    return false;
}


double Model::GetVrijePunten() const
{
    switch (mStrategyType) {
        case STRATEGY_TYPE::KCal:
            return GetPersonalia().front()->GetKCWeekPuntenTotaal();
        case STRATEGY_TYPE::CarboHydrates:
            return GetPersonalia().front()->GetCHWeekPuntenTotaal() / 7 - GetPersonalia().front()->GetCHPuntenTotaal();
        default:
            assert(false);
            return 0;
    }
}

bool Model::HasPersonalia(const std::tstring& name) const
{
    return std::find_if(mPersonalia.begin(),
                        mPersonalia.end(),
                        [name](const std::unique_ptr<Personalia>& personalia) { return personalia->GetUserName() == name; })
        != mPersonalia.end();
}

Personalia* Model::GetActivePersonalia()
{
    if (mPersonalia.empty())
        return nullptr;

    return mPersonalia.front().get();
}


const Personalia* Model::GetActivePersonalia() const
{
    if (mPersonalia.empty())
        return nullptr;

    return mPersonalia.front().get();
}

Personalia* Model::AddPersonalia(const std::tstring& aName)
{
    if (HasPersonalia(aName))
        throw std::runtime_error("Personalia already exists");

    // Temporary until more persons are supported
    if (!mPersonalia.empty())
        throw std::runtime_error("Personalia not empty");

    mPersonalia.push_back(std::make_unique<Personalia>(aName));
    return mPersonalia.back().get();
}

double Model::GetPuntenTotaal(STRATEGY_TYPE eType) const
{
    return GetActivePersonalia()->GetPuntenTotaal(eType);
}


double Model::GetWeekPuntenTotaal() const
{
    switch (mStrategyType)
    {
        case STRATEGY_TYPE::KCal:
            return GetActivePersonalia()->GetKCWeekPuntenTotaal();
        case STRATEGY_TYPE::CarboHydrates:
            return GetActivePersonalia()->GetCHWeekPuntenTotaal();
        default:
            return 0;
    }
}


}
