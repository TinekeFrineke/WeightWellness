
#include "stdafx.h"

#include <assert.h>

#include "ItemEditVisitor.h"

#include "model/ManualItem.h"
#include "model/Model.h"
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
    weight::ReceptDefinitie* definitie = mModel.FindReceptDefinitie(aRecept.GetName());
    if (definitie == NULL)
    {
        auto newDefinition = std::make_unique<weight::ReceptDefinitie>(aRecept.GetName());
        definitie = newDefinition.get();
        definitie->SetPortions(1);
        definitie->Add(std::make_unique<weight::ManualItem>(aRecept.GetName(), aRecept.GetPoints()));

        mModel.Add(std::move(newDefinition));
    }

    EditReceptDialog dialog(mModel, aRecept, /**definitie,*/ mParent);
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
