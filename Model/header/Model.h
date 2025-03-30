#pragma once

#include "Utilities/Date.h"
#include "Utilities/StrUtils.h"

#include "BonusPointsMap.h"
#include "IModel.h"
#include "PointsCalculator.h"

namespace weight
{

class IBrandRepository;
class ICategoryRepository;
class IStringRepository;
class IWeek;
class Personalia;
class Recept;
class ReceptDefinitie;
class GerechtDefinitie;
class VMDefinitie;

class Model: public IModel
{
public:
    Model();
    ~Model() override;

    Personalia* GetPersonalia() const override;
    void SetPersonalia(std::unique_ptr<Personalia> personalia);

    STRATEGY_TYPE GetStrategy() const noexcept override { return mStrategyType; }
    void SetStrategy(STRATEGY_TYPE eType) override;

    IWeek* CreateWeek(const Utils::Date& aDate) override;

    bool Add(std::unique_ptr<VMDefinitie> aDefinitie) override;

    std::shared_ptr<IStringRepository> GetUnitRepository() const noexcept override;
    std::shared_ptr<IStringRepository> GetCategoryRepository() const noexcept override;
    std::shared_ptr<IStringRepository> GetBrandRepository() const noexcept override;
    std::shared_ptr<IRepository<VMDefinitie>> GetFoodDefinitionRepository() const noexcept override;
    std::shared_ptr<IRepository<ReceptDefinitie>> GetRecipeDefinitionRepository() const noexcept override;

    std::shared_ptr<IWeekRepository> GetWeekRepository() const noexcept override { return m_weeks; }
    std::shared_ptr<BonusPointsMap> GetBonusPointsMap() const noexcept override { return mBonusPointsMap; }

    double GetPuntenTotaal(STRATEGY_TYPE eType) const override;
    double GetWeekPuntenTotaal() const override;
    double GetVrijePunten() const override;

    std::shared_ptr<PointsCalculator> GetCalculator() const noexcept override { return m_calculator; }

private:
    std::shared_ptr<IWeekRepository> m_weeks;
    std::shared_ptr<IRepository<VMDefinitie>> m_foodDefinitions;
    std::shared_ptr<IRepository<ReceptDefinitie>> m_recipeDefinitions;
    std::unique_ptr<Personalia> mPersonalia;
    std::shared_ptr<IStringRepository> m_units;
    std::shared_ptr<IStringRepository> m_categories;
    std::shared_ptr<IStringRepository> m_brands;

    std::shared_ptr<BonusPointsMap> mBonusPointsMap;

    std::shared_ptr<PointsCalculator> m_calculator;
    STRATEGY_TYPE mStrategyType;
};


}
