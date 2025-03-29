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

    bool HasPersonalia(const std::tstring& name) const;
    Personalia* GetActivePersonalia();
    const Personalia* GetActivePersonalia() const;
    Personalia* AddPersonalia(const std::tstring& aName);

    STRATEGY_TYPE GetStrategy() const noexcept override { return mStrategyType; }
    void SetStrategy(STRATEGY_TYPE eType) override;

    IWeek* FindWeek(const Utils::Date& aDate) override;
    IWeek* CreateWeek(const Utils::Date& aDate);
    bool Add(std::unique_ptr<IWeek> aWeek) override;

    bool Add(std::unique_ptr<VMDefinitie> aDefinitie) override;
    bool Add(std::unique_ptr<Personalia> aPersonalia) override;

    void AddUnit(const std::wstring& aUnit) override;
    void AddCategory(const std::wstring& aCategory) override;
    void AddBrand(const std::wstring& brand) override;

    bool Remove(const VMDefinitie* aDefinitie) override;
    bool Remove(const Personalia* aPersonalia);

    VMDefinitie* FindVoedingsmiddelDefinitie(const std::wstring& aName);

    std::shared_ptr<IStringRepository> GetUnitRepository() const noexcept override;
    std::shared_ptr<IStringRepository> GetCategoryRepository() const noexcept override;
    std::shared_ptr<IStringRepository> GetBrandRepository() const noexcept override;
    std::shared_ptr<IRepository<VMDefinitie>> GetFoodDefinitionRepository() const noexcept override;
    std::shared_ptr<IRepository<ReceptDefinitie>> GetRecipeDefinitionRepository() const noexcept override;

    const std::vector<std::unique_ptr<IWeek>>& GetWeeks() const noexcept override { return mWeeks; }
    const std::vector<std::unique_ptr<Personalia>>& GetPersonalia() const noexcept override { return mPersonalia; }
    std::shared_ptr<BonusPointsMap> GetBonusPointsMap() const noexcept override { return mBonusPointsMap; }

    double GetPuntenTotaal(STRATEGY_TYPE eType) const;
    double GetWeekPuntenTotaal() const;
    double GetVrijePunten() const;

    std::shared_ptr<PointsCalculator> GetCalculator() const noexcept override { return m_calculator; }

private:
    std::vector<std::unique_ptr<IWeek>> mWeeks;
    std::shared_ptr<IRepository<VMDefinitie>> m_foodDefinitions;
    std::shared_ptr<IRepository<ReceptDefinitie>> m_recipeDefinitions;
    std::vector<std::unique_ptr<Personalia>> mPersonalia;
    std::shared_ptr<IStringRepository> m_units;
    std::shared_ptr<IStringRepository> m_categories;
    std::shared_ptr<IStringRepository> m_brands;

    std::shared_ptr<BonusPointsMap> mBonusPointsMap;

    std::shared_ptr<PointsCalculator> m_calculator;
    STRATEGY_TYPE mStrategyType;
};


}
