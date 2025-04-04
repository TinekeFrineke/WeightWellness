
#include "Model.h"

#include <tchar.h>
#include <assert.h>
#include <sstream>

#include "FoodDefinitionRepository.h"
#include "IWeek.h"
#include "Lot.h"
#include "ModelFactory.h"
#include "Personalia.h"
#include "ReceptDefinitie.h"
#include "Repository.h"
#include "StringRepository.h"
#include "VoedingsmiddelDefinitie.h"
#include "WeekRepository.h"

namespace weight
{


Model::Model()
    : mStrategyType(STRATEGY_TYPE::KCal)
    , m_weeks(std::make_shared<WeekRepository>())
    , m_foodDefinitions(std::make_shared<FoodDefinitionRepository>())
    , m_recipeDefinitions(std::make_shared<Repository<ReceptDefinitie>>())
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

    IWeek* week = m_weeks->FindWeekContaining(Utils::Today());

    if (week != nullptr)
        week->SetStrategy(eType, *this);
}


IWeek* Model::CreateWeek(const Utils::Date& aDate)
{
    auto week = m_weeks->FindWeekContaining(aDate);
    if (week != nullptr)
        return week;

    week = m_weeks->Create(aDate);
    if (week == nullptr)
        return week;

    week->SetPoints(GetPersonalia()->GetPuntenTotaal(GetStrategy()));
    week->SetSaveablePoints(GetVrijePunten());
    week->SetStrategy(GetStrategy(), *this);
    week->SetStartWeight(GetPersonalia()->GetHuidigGewicht());
    return week;
}


std::shared_ptr<IFoodDefinitionRepository> Model::GetFoodDefinitionRepository() const noexcept
{
    return m_foodDefinitions;
}

std::shared_ptr<IRepository<ReceptDefinitie>> Model::GetRecipeDefinitionRepository() const noexcept
{
    return m_recipeDefinitions;
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
