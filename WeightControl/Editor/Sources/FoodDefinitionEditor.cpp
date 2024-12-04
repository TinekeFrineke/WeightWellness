#include "FoodDefinitionEditor.h"

#include "stdafx.h"

#include "model/VoedingsmiddelDefinitie.h"

#include "EditFoodDefDialog.h"

namespace weight {



}

FoodDefinitionEditor::FoodDefinitionEditor(weight::Model& model, CWnd* parent)
    : m_model(model)
    , m_parent(parent)
{
}

bool FoodDefinitionEditor::Edit(weight::VMDefinitie& definition) const
{
    CEditFoodDefDialog dialog(m_model, m_model.GetUnitRepository(), m_model.GetCategoryRepository(), m_model.GetBrandRepository(), definition, m_newDefinition, m_model.GetCalculator(), m_parent);
    INT_PTR nResponse = dialog.DoModal();
    return nResponse == IDOK;
}

std::unique_ptr<weight::VMDefinitie> FoodDefinitionEditor::Create() const
{
    m_newDefinition = true;
    auto vmdefBase = std::make_unique<weight::CalculatedVMDef>(m_model.GetCalculator());
    auto definition = std::make_unique<weight::VMDefinitie>(m_model.GetCalculator(), L"", L"g", std::move(vmdefBase));
    if (Edit(*definition)) {
        m_newDefinition = false;
        return std::move(definition);
    }

    m_newDefinition = false;
    return {};
}
