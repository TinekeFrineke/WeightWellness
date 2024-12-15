#include "FoodDefinitionEditor.h"

#include "stdafx.h"

#include "model/NutritionalValue.h"
#include "model/VoedingsmiddelDefinitie.h"

#include "EditFoodDefDialog.h"


FoodDefinitionEditor::FoodDefinitionEditor(weight::Model& model, CWnd* parent)
    : m_model(model)
    , m_parent(parent)
{
}

bool FoodDefinitionEditor::Edit(weight::VMDefinitie& definition) const
{
    CEditFoodDefDialog dialog(m_model.GetFoodDefinitionRepository(), m_model.GetUnitRepository(),
                              m_model.GetCategoryRepository(), m_model.GetBrandRepository(), definition,
                              m_isNewDefinition, m_model.GetCalculator(), m_parent);
    INT_PTR nResponse = dialog.DoModal();
    if (nResponse != IDOK)
        return false;

    m_model.AddCategory(definition.GetCategory());
    m_model.AddBrand(definition.GetMerk());
    return true;
}

std::unique_ptr<weight::VMDefinitie> FoodDefinitionEditor::Create() const
{
    m_isNewDefinition = true;
    auto nutritionalValue = std::make_unique<weight::NutritionalValue>(m_model.GetCalculator());
    auto definition = std::make_unique<weight::VMDefinitie>(m_model.GetCalculator(), L"", L"g", std::move(nutritionalValue));
    if (Edit(*definition)) {
        m_isNewDefinition = false;
        return std::move(definition);
    }

    m_isNewDefinition = false;
    return {};
}
