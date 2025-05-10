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
class IMessageHandler;

class Model: public IModel
{
public:
    Model(std::shared_ptr<IMessageHandler> messageHandler);
    ~Model() override;

    Personalia* GetPersonalia() const override;
    void SetPersonalia(std::unique_ptr<Personalia> personalia) noexcept override;

    STRATEGY_TYPE GetStrategy() const noexcept override { return mStrategyType; }
    void SetStrategy(STRATEGY_TYPE eType) override;

    IWeek* CreateWeek(const Utils::Date& aDate) override;

    std::shared_ptr<IFoodDefinitionRepository> GetFoodDefinitionRepository() const noexcept override;
    std::shared_ptr<IRepository<ReceptDefinitie>> GetRecipeDefinitionRepository() const noexcept override;

    std::shared_ptr<IWeekRepository> GetWeekRepository() const noexcept override { return m_weeks; }
    std::shared_ptr<BonusPointsMap> GetBonusPointsMap() const noexcept override { return mBonusPointsMap; }

    double GetPuntenTotaal(STRATEGY_TYPE eType) const noexcept override;
    double GetWeekPuntenTotaal() const override;
    double GetVrijePunten() const override;

    std::shared_ptr<PointsCalculator> GetCalculator() const noexcept override { return m_calculator; }

private:
    std::shared_ptr<IWeekRepository> m_weeks;
    std::shared_ptr<IFoodDefinitionRepository> m_foodDefinitions;
    std::shared_ptr<IRepository<ReceptDefinitie>> m_recipeDefinitions;
    std::unique_ptr<Personalia> mPersonalia;

    std::shared_ptr<BonusPointsMap> mBonusPointsMap;

    std::shared_ptr<PointsCalculator> m_calculator;
    STRATEGY_TYPE mStrategyType;
};


}
