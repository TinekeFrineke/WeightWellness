#pragma once

#include "IRecipeDefinitionEditor.h"

class CWnd;

namespace weight {
class IFoodDefinitionRepository;
class IStringRepository;
class PointsCalculator;
class VMDefinitie;

template <typename TYPE> class IRepository;
}

class RecipeDefinitionEditor
    : public IRecipeDefinitionEditor
{
public:
    RecipeDefinitionEditor(std::shared_ptr<weight::IRepository<weight::ReceptDefinitie>> recipes,
                           std::shared_ptr<weight::IFoodDefinitionRepository> foodDefinitions,
                           std::shared_ptr<weight::PointsCalculator> calculator,
                           std::shared_ptr<weight::IStringRepository> categories,
                           std::shared_ptr<weight::IStringRepository> brands,
                           CWnd* parent)
        : m_recipes(std::move(recipes))
        , m_foodDefinitions(std::move(foodDefinitions))
        , m_calculator(std::move(calculator))
        , m_categories(std::move(categories))
        , m_brands(std::move(brands))
        , m_parent(parent) {}

    bool Edit(weight::ReceptDefinitie& portie) const override;
    std::unique_ptr<weight::ReceptDefinitie> Create() const override;

private:
    std::shared_ptr<weight::IRepository<weight::ReceptDefinitie>> m_recipes;
    std::shared_ptr<weight::IFoodDefinitionRepository> m_foodDefinitions;
    std::shared_ptr<weight::PointsCalculator> m_calculator;
    std::shared_ptr<weight::IStringRepository> m_categories;
    std::shared_ptr<weight::IStringRepository> m_brands;
    CWnd* m_parent;
};
