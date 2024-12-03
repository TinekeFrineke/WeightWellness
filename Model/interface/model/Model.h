#pragma once

#include <vector>

#include "Utilities/Date.h"
#include "Utilities/StrUtils.h"

#include "BonusPointsMap.h"
#include "PointsCalculator.h"

namespace weight
{

class Day;
class IBrandRepository;
class ICategoryRepository;
class IFoodDefinitionRepository;
class IRepository;
class Personalia;
class Recept;
class ReceptDefinitie;
class GerechtDefinitie;
class VMDefinitie;
class Week;

class Model
{
public:
    Model();
    ~Model();

    STRATEGY_TYPE                           GetStrategy() const noexcept { return mStrategyType; }
    void                                    SetStrategy(STRATEGY_TYPE eType);

    bool                                    Add(std::unique_ptr<Week> aWeek);
    bool                                    Add(std::unique_ptr<VMDefinitie> aDefinitie);
    bool                                    Add(std::unique_ptr<ReceptDefinitie> aReceptDef);
    bool                                    Add(std::unique_ptr<Personalia> aPersonalia);

    void                                    AddUnit(const std::wstring& aUnit);
    void                                    AddCategory(const std::wstring& aCategory);
    void                                    AddBrand(const std::wstring& brand);

    bool                                    Remove(const VMDefinitie* aDefinitie);
    bool                                    Remove(const ReceptDefinitie* aRecept);
    bool                                    Remove(const Personalia* aPersonalia);

    Week* FindWeek(const Utils::Date& aDate);
    bool                                    SetEndDate(Week& aWeek, const Utils::Date& aDate);

    VMDefinitie* FindVoedingsmiddelDefinitie(const std::tstring& aName);
    ReceptDefinitie* FindReceptDefinitie(const std::tstring& aName);

    std::shared_ptr<IRepository> GetUnitRepository() const noexcept;
    std::shared_ptr<IRepository> GetCategoryRepository() const noexcept;
    std::shared_ptr<IRepository> GetBrandRepository() const noexcept;
    std::shared_ptr<IFoodDefinitionRepository> GetFoodDefinitionRepository() const noexcept;

    const std::vector<std::unique_ptr<ReceptDefinitie>>& GetReceptDefs() const noexcept { return mReceptDefinities; }
    const std::vector<std::unique_ptr<Week>>& GetWeeks() const noexcept { return mWeeks; }
    const std::vector<std::unique_ptr<Personalia>>& GetPersonalia() const noexcept { return mPersonalia; }
    const BonusPointsMap& GetBonusPointsMap() const noexcept { return mBonusPointsMap; }

    double GetPuntenTotaal(STRATEGY_TYPE eType) const;
    double GetWeekPuntenTotaal() const;
    double GetVrijePunten() const;

    bool HasPersonalia(const std::tstring& name) const;
    Personalia* GetActivePersonalia();
    const Personalia* GetActivePersonalia() const;
    Personalia* AddPersonalia(const std::tstring& aName);

    std::shared_ptr<PointsCalculator> GetCalculator() const noexcept { return m_calculator; }

private:
    std::vector<std::unique_ptr<Week>> mWeeks;
    std::shared_ptr<IFoodDefinitionRepository> m_foodDefinitions;
    std::vector<std::unique_ptr<ReceptDefinitie>> mReceptDefinities;
    //std::vector<std::unique_ptr<GerechtDefinitie>> mGerechtDefinities;
    std::vector<std::unique_ptr<Personalia>> mPersonalia;
    std::shared_ptr<IRepository> m_units;
    std::shared_ptr<IRepository> m_categories;
    std::shared_ptr<IRepository> m_brands;

    BonusPointsMap mBonusPointsMap;

    std::shared_ptr<PointsCalculator> m_calculator;
    STRATEGY_TYPE mStrategyType;
};


}
