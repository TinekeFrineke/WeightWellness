#pragma once

#include <memory>

class CWnd;

namespace weight {
class IFoodDefinitionRepository;
class IStringRepository;
class PointsCalculator;
class VMDefinitie;

template <typename TYPE> class IRepository;
}

class FoodDefinitionEditor
{
public:
    FoodDefinitionEditor(std::shared_ptr<weight::IFoodDefinitionRepository> foodDefinitions,
                         std::shared_ptr<weight::PointsCalculator> calculator,
                         std::shared_ptr<weight::IStringRepository> categories,
                         std::shared_ptr<weight::IStringRepository> brands,
                         std::shared_ptr<weight::IStringRepository> units, CWnd* parent);

    bool Edit(weight::VMDefinitie& definition) const;
    std::unique_ptr<weight::VMDefinitie> Create() const;

private:
    mutable bool m_isNewDefinition{ false };
    std::shared_ptr<weight::IFoodDefinitionRepository> m_foodDefinitions;
    std::shared_ptr<weight::PointsCalculator> m_calculator;
    std::shared_ptr<weight::IStringRepository> m_categories;
    std::shared_ptr<weight::IStringRepository> m_brands;
    std::shared_ptr<weight::IStringRepository> m_units;

    CWnd* m_parent;
};

