
#include "RecipeDefinitionEditor.h"

#include "stdafx.h"

#include "model/ReceptDefinitie.h"

#include "EditReceptDefDialog.h"
#include "RecipeDefinitionEditor.h"

bool RecipeDefinitionEditor::Edit(weight::ReceptDefinitie& definition) const
{
    EditReceptDefDialog dialog(m_recipes, m_foodDefinitions, m_calculator,
                               m_categories, m_brands, definition, m_parent);

    INT_PTR nResponse = dialog.DoModal();
    return nResponse == IDOK;
}

std::unique_ptr<weight::ReceptDefinitie> RecipeDefinitionEditor::Create() const
{
    auto definition(std::make_unique<weight::ReceptDefinitie>(L""));

    if (Edit(*definition))
        return definition;

    return {};
}
