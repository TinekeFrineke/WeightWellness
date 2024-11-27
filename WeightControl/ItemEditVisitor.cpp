
#include "stdafx.h"

#include <assert.h>

#include "ItemEditVisitor.h"

#include "model/ManualItem.h"
#include "model/WWmodel.h"
#include "model/Recept.h"
#include "model/ReceptDefinitie.h"
#include "model/Voedingsmiddel.h"
#include "model/VoedingsmiddelDefinitie.h"

#include "EditReceptDialog.h"
#include "EditVoedingsmiddelDialog.h"
#include "Handmatigeitemdlg.h"



void ItemEditVisitor::Visit(WW::Recept& aRecept)
{
    WW::ReceptDefinitie* definitie = mModel.FindReceptDefinitie(aRecept.GetName());
    if (definitie == NULL)
    {
        auto newDefinition = std::make_unique<WW::ReceptDefinitie>(aRecept.GetName());
        definitie = newDefinition.get();
        definitie->SetPortions(1);
        definitie->Add(std::make_unique<WW::ManualItem>(aRecept.GetName(), aRecept.GetPoints()));

        mModel.Add(std::move(newDefinition));
    }

    EditReceptDialog dialog(mModel, aRecept, /**definitie,*/ mParent);
    dialog.DoModal();
}


void ItemEditVisitor::Visit(WW::Gerecht& aGerecht)
{
    (void)&aGerecht;
}


void ItemEditVisitor::Visit(WW::Voedingsmiddel& aVoedingsmiddel)
{
    WW::VMDefinitie* definitie = mModel.FindVoedingsmiddelDefinitie(aVoedingsmiddel.GetName());
    if (definitie == NULL)
    {
        auto fixedDefinition = std::make_unique<WW::FixedVMDef>();
        auto newDefinition = std::make_unique<WW::VMDefinitie>(mModel.GetCalculator(),
                                                      aVoedingsmiddel.GetName(),
                                                      aVoedingsmiddel.GetUnit(),
                                                      std::move(fixedDefinition));
        newDefinition->SetCategory(aVoedingsmiddel.GetCategory());
        definitie = newDefinition.get();
        mModel.Add(std::move(newDefinition));
    }

    EditVoedingsmiddelDialog dialog(mModel, aVoedingsmiddel, *definitie, mParent);
    dialog.DoModal();
}


void ItemEditVisitor::Visit(WW::ManualItem& anItem)
{
    HandmatigeItemDlg dialog(&anItem, mParent);
    dialog.DoModal();
}
