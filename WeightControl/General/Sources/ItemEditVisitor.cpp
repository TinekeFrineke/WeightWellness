
#include "stdafx.h"

#include <assert.h>

#include "ItemEditVisitor.h"

#include "model/IModel.h"
#include "model/IRepository.h"
#include "model/ManualItem.h"
#include "model/NutritionalValue.h"
#include "model/Recept.h"
#include "model/ReceptDefinitie.h"
#include "model/Voedingsmiddel.h"
#include "model/VoedingsmiddelDefinitie.h"

#include "EditFoodDialog.h"
#include "EditReceptDialog.h"
#include "Handmatigeitemdlg.h"
#include "FoodEditor.h"



void ItemEditVisitor::Visit(weight::Recept& aRecept)
{
    weight::ReceptDefinitie* definitie = m_recipes->Find(aRecept.GetName());
    if (definitie == NULL)
    {
        auto newDefinition = std::make_unique<weight::ReceptDefinitie>(aRecept.GetName());
        definitie = newDefinition.get();
        definitie->SetPortions(1);
        definitie->Add(std::make_unique<weight::ManualItem>(aRecept.GetName(), aRecept.GetPoints()));

        m_recipes->Add(std::move(newDefinition));
    }

    EditReceptDialog dialog(aRecept, mParent);
    dialog.DoModal();
}


void ItemEditVisitor::Visit(weight::Voedingsmiddel& aVoedingsmiddel)
{
    FoodEditor editor(mModel.GetFoodDefinitionRepository(), mModel.GetCalculator(), mParent);
    editor.Edit(aVoedingsmiddel);
}


void ItemEditVisitor::Visit(weight::ManualItem& anItem)
{
    HandmatigeItemDlg dialog(&anItem, mParent);
    dialog.DoModal();
}
