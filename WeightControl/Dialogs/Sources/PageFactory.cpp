
#include "PageFactory.h"

#include "EditReceptDefDialog.h"
#include "FoodDefinitionEditor.h"
#include "ReceptenPage.h"

PageFactory::PageFactory(std::shared_ptr<weight::IRepository<weight::ReceptDefinitie>> recipes,
                         std::shared_ptr<weight::IRepository<weight::VMDefinitie>> foodDefinitions,
                         std::shared_ptr<weight::PointsCalculator> calculator,
                         std::shared_ptr<weight::IStringRepository> categories,
                         std::shared_ptr<weight::IStringRepository> brands,
                         std::shared_ptr<weight::IStringRepository> units)
    : m_recipes(std::move(recipes))
    , m_foodDefinitions(std::move(foodDefinitions))
    , m_calculator(std::move(calculator))
    , m_categories(std::move(categories))
    , m_brands(std::move(brands))
    , m_units(std::move(units))
{
}

PageFactory::~PageFactory()
{
}

std::unique_ptr<ReceptenPage> PageFactory::CreateRecipesPage() const
{
    return std::make_unique<ReceptenPage>(m_recipes, m_foodDefinitions, m_calculator, m_categories, m_brands);
}

std::unique_ptr<EditReceptDefDialog> PageFactory::CreateEditRecipeDefinitionsDialog(weight::ReceptDefinitie& aRecept, CWnd* parent) const
{
    return std::make_unique<EditReceptDefDialog>(m_recipes, m_foodDefinitions, m_calculator, m_categories, m_brands, aRecept, parent);
}

std::unique_ptr<FoodDefinitionEditor> PageFactory::CreateFoodDefinitionEditor(CWnd* parent) const
{
    return std::make_unique<FoodDefinitionEditor>(m_foodDefinitions, m_calculator, m_categories, m_brands, m_units, parent);
}
