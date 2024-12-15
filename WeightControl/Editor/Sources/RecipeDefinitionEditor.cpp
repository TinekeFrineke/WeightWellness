
#include "RecipeDefinitionEditor.h"

#include "stdafx.h"

#include "model/ReceptDefinitie.h"

#include "EditReceptDefDialog.h"
#include "RecipeDefinitionEditor.h"

bool RecipeDefinitionEditor::Edit(weight::ReceptDefinitie& definition) const
{
    EditReceptDefDialog dialog(m_model, definition, m_parent);

    INT_PTR nResponse = dialog.DoModal();
    if (nResponse != IDOK)
        return false;

    //m_model.AddCategory(definition.GetCategory());
    //m_model.AddBrand(definition.GetMerk());
    return true;
}

std::unique_ptr<weight::ReceptDefinitie> RecipeDefinitionEditor::Create() const
{
    auto definition(std::make_unique<weight::ReceptDefinitie>(L""));

    if (Edit(*definition))
        return definition;

    return {};
}
