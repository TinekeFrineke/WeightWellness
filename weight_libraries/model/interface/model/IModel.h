
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
class IWeekRepository;
class Personalia;
class PointsCalculator;
class ReceptDefinitie;
class VMDefinitie;

template<typename TYPE> class IRepository;

class IModel
{
public:
    virtual ~IModel() = default;

    virtual Personalia* GetPersonalia() const = 0;
    virtual void SetPersonalia(std::unique_ptr<Personalia> personalia) = 0;

    virtual STRATEGY_TYPE GetStrategy() const noexcept = 0;
    virtual void SetStrategy(STRATEGY_TYPE eType) = 0;

    virtual IWeek* CreateWeek(const Utils::Date& aDate) = 0;

    virtual std::shared_ptr<IFoodDefinitionRepository> GetFoodDefinitionRepository() const noexcept = 0;
    virtual std::shared_ptr<IRepository<ReceptDefinitie>> GetRecipeDefinitionRepository() const noexcept = 0;

    virtual std::shared_ptr<IWeekRepository> GetWeekRepository() const noexcept = 0;
    virtual std::shared_ptr<BonusPointsMap> GetBonusPointsMap() const noexcept = 0;

    virtual double GetPuntenTotaal(STRATEGY_TYPE eType) const = 0;
    virtual double GetWeekPuntenTotaal() const = 0;
    virtual double GetVrijePunten() const = 0;

    virtual std::shared_ptr<PointsCalculator> GetCalculator() const noexcept = 0;
};

}