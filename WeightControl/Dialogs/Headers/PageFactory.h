
#pragma once

#include <memory>

#include "IPageFactory.h"

namespace weight {
class IFoodDefinitionRepository;
class IStringRepository;
class PointsCalculator;
class ReceptDefinitie;
class VMDefinitie;

template <typename TYPE> class IRepository;
}

class EditReceptDefDialog;

class PageFactory
    : public IPageFactory {
public:
    PageFactory(std::shared_ptr<weight::IRepository<weight::ReceptDefinitie>> recipes,
                std::shared_ptr<weight::IFoodDefinitionRepository> foodDefinitions,
                std::shared_ptr<weight::PointsCalculator> calculator);
    ~PageFactory() override;

    std::unique_ptr<ReceptenPage> CreateRecipesPage() const override;
    std::unique_ptr<EditReceptDefDialog> CreateEditRecipeDefinitionsDialog(weight::ReceptDefinitie& aRecept, CWnd* parent) const override;

    std::unique_ptr<FoodDefinitionEditor> CreateFoodDefinitionEditor(CWnd* parent) const override;

private:
    std::shared_ptr<weight::IRepository<weight::ReceptDefinitie>> m_recipes;
    std::shared_ptr<weight::IFoodDefinitionRepository> m_foodDefinitions;
    std::shared_ptr<weight::PointsCalculator> m_calculator;
    std::shared_ptr<weight::IStringRepository> m_categories;
    std::shared_ptr<weight::IStringRepository> m_brands;
    std::shared_ptr<weight::IStringRepository> m_units;
}; // class PageFactory