
#pragma once

#include <memory>
#include <string>
#include <vector>

#include "WWDefinitions.h"

namespace Utils {
class Date;
}

namespace weight {

class BonusPointsMap;
class IFoodDefinitionRepository;
class IStringRepository;
class IWeek;
class Personalia;
class PointsCalculator;
class ReceptDefinitie;
class VMDefinitie;

template<typename TYPE> class IRepository;

class IModel
{
public:
    virtual ~IModel() = default;

    virtual Personalia* GetActivePersonalia() = 0;
    virtual const Personalia* GetActivePersonalia() const = 0;
    virtual Personalia* AddPersonalia(const std::wstring& aName) = 0;

    virtual STRATEGY_TYPE GetStrategy() const noexcept = 0;
    virtual void SetStrategy(STRATEGY_TYPE eType) = 0;

    virtual IWeek* FindWeek(const Utils::Date& aDate) = 0;
    virtual bool Add(std::unique_ptr<IWeek> aWeek) = 0;

    virtual bool Add(std::unique_ptr<VMDefinitie> aDefinitie) = 0;
    virtual bool Add(std::unique_ptr<Personalia> aPersonalia) = 0;

    virtual void AddUnit(const std::wstring& aUnit) = 0;
    virtual void AddCategory(const std::wstring& aCategory) = 0;
    virtual void AddBrand(const std::wstring& brand) = 0;

    virtual bool Remove(const VMDefinitie* aDefinitie) = 0;

    virtual std::shared_ptr<IStringRepository> GetUnitRepository() const noexcept = 0;
    virtual std::shared_ptr<IStringRepository> GetCategoryRepository() const noexcept = 0;
    virtual std::shared_ptr<IStringRepository> GetBrandRepository() const noexcept = 0;
    virtual std::shared_ptr<IFoodDefinitionRepository> GetFoodDefinitionRepository() const noexcept = 0;
    virtual std::shared_ptr<IRepository<ReceptDefinitie>> GetRecipeDefinitionRepository() const noexcept = 0;

    //virtual const std::vector<std::unique_ptr<ReceptDefinitie>>& GetReceptDefs() const noexcept = 0;
    virtual const std::vector<std::unique_ptr<IWeek>>& GetWeeks() const noexcept = 0;
    virtual const std::vector<std::unique_ptr<Personalia>>& GetPersonalia() const noexcept = 0;
    virtual const BonusPointsMap& GetBonusPointsMap() const noexcept = 0;

    virtual double GetPuntenTotaal(STRATEGY_TYPE eType) const = 0;
    virtual double GetWeekPuntenTotaal() const = 0;
    virtual double GetVrijePunten() const = 0;

    virtual std::shared_ptr<PointsCalculator> GetCalculator() const noexcept = 0;
};

}