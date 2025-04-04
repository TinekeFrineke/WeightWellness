#include "FoodDefinitionEditor.h"

#include "stdafx.h"

#include "model/IStringRepository.h"
#include "model/NutritionalValue.h"
#include "model/VoedingsmiddelDefinitie.h"

#include "EditFoodDefDialog.h"


FoodDefinitionEditor::FoodDefinitionEditor(std::shared_ptr<weight::IFoodDefinitionRepository> foodDefinitions,
                                           std::shared_ptr<weight::PointsCalculator> calculator,
                                           std::shared_ptr<weight::IStringRepository> categories,
                                           std::shared_ptr<weight::IStringRepository> brands,
                                           std::shared_ptr<weight::IStringRepository> units, CWnd* parent)
    : m_foodDefinitions(std::move(foodDefinitions))
    , m_calculator(std::move(calculator))
    , m_categories(std::move(categories))
    , m_brands(std::move(brands))
    , m_units(std::move(units))
    , m_parent(parent)
{
}

bool FoodDefinitionEditor::Edit(weight::VMDefinitie& definition) const
{
    CEditFoodDefDialog dialog(m_foodDefinitions, m_units, m_categories, m_brands, definition,
                              m_isNewDefinition, m_calculator, m_parent);
    INT_PTR nResponse = dialog.DoModal();
    if (nResponse != IDOK)
        return false;

    m_categories->Add(definition.GetCategory());
    m_brands->Add(definition.GetMerk());
    return true;
}

std::unique_ptr<weight::VMDefinitie> FoodDefinitionEditor::Create() const
{
    m_isNewDefinition = true;
    auto nutritionalValue = std::make_unique<weight::NutritionalValue>(m_calculator);
    auto definition = std::make_unique<weight::VMDefinitie>(m_calculator, L"", L"g", std::move(nutritionalValue));
    if (Edit(*definition)) {
        m_isNewDefinition = false;
        return std::move(definition);
    }

    m_isNewDefinition = false;
    return {};
}
