
#include "PageFactory.h"

#include "model/IFoodDefinitionRepository.h"

#include "DiaryPage.h"
#include "EditReceptDefDialog.h"
#include "FoodDefinitionEditor.h"
#include "ReceptenPage.h"

PageFactory::PageFactory(std::shared_ptr<weight::IMessageHandler> messageHandler,
                         weight::IModel& model,
                         std::shared_ptr<weight::IRepository<weight::ReceptDefinitie>> recipes,
                         std::shared_ptr<weight::IFoodDefinitionRepository> foodDefinitions,
                         std::shared_ptr<weight::PointsCalculator> calculator)
    : m_messageHandler(std::move(messageHandler))
    , m_model(model)
    , m_recipes(std::move(recipes))
    , m_foodDefinitions(std::move(foodDefinitions))
    , m_calculator(std::move(calculator))
    , m_categories(std::move(m_foodDefinitions->GetCategoryRepository()))
    , m_brands(std::move(m_foodDefinitions->GetBrandRepository()))
    , m_units(std::move(m_foodDefinitions->GetUnitRepository()))
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

std::unique_ptr<CDiaryPage> PageFactory::CreateDiaryPage(CWnd* parent) const
{
    return std::make_unique<CDiaryPage>(m_model, m_messageHandler, parent);
}

std::unique_ptr<FoodDefinitionEditor> PageFactory::CreateFoodDefinitionEditor(CWnd* parent) const
{
    return std::make_unique<FoodDefinitionEditor>(m_foodDefinitions, m_calculator, m_categories, m_brands, m_units, parent);
}
