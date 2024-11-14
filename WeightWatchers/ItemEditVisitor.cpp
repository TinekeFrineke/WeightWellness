
#include "stdafx.h"

#include <assert.h>

#include "ItemEditVisitor.h"

#include "WW/WWModel/ManualItem.h"
#include "WW/WWModel/WWmodel.h"
#include "WW/WWModel/Recept.h"
#include "WW/WWModel/ReceptDefinitie.h"
#include "WW/WWModel/Voedingsmiddel.h"
#include "WW/WWModel/VoedingsmiddelDefinitie.h"

#include "EditReceptDialog.h"
#include "EditVoedingsmiddelDialog.h"
#include "Handmatigeitemdlg.h"



void ItemEditVisitor::Visit(WW::Recept & aRecept)
{
  WW::ReceptDefinitie * definitie = mModel.FindReceptDefinitie(aRecept.GetName());
  if (definitie == NULL)
  {
    definitie = new WW::ReceptDefinitie(aRecept.GetName());
    definitie->SetPortions(1);
    definitie->Add(new WW::ManualItem(aRecept.GetName(), aRecept.GetPoints()));

    mModel.Add(definitie);
  }

  EditReceptDialog dialog(mModel, aRecept, /**definitie,*/ mParent);
  dialog.DoModal();
}


void ItemEditVisitor::Visit(WW::Gerecht & aGerecht)
{
  (void)&aGerecht;
}


void ItemEditVisitor::Visit(WW::Voedingsmiddel & aVoedingsmiddel)
{
  WW::VMDefinitie * definitie = mModel.FindVoedingsmiddelDefinitie(aVoedingsmiddel.GetName());
  if (definitie == NULL)
  {
    WW::FixedVMDef * def = new WW::FixedVMDef;
    definitie = new WW::VMDefinitie(mModel.GetCalculator(),
                                                aVoedingsmiddel.GetName(),
                                                aVoedingsmiddel.GetUnit(),
                                                def);
    definitie->SetCategory(aVoedingsmiddel.GetCategory());
    definitie->SetHasFreePortion(mModel.GetStrategy(), true);
    /// TF_TODO too lazy now
    definitie->SetFreePortionPoints(mModel.GetStrategy(), aVoedingsmiddel.GetPoints());

    mModel.Add(definitie);
  }

  EditVoedingsmiddelDialog dialog(mModel, aVoedingsmiddel, *definitie, mParent);
  dialog.DoModal();
}


void ItemEditVisitor::Visit(WW::ManualItem & anItem)
{
  HandmatigeItemDlg dialog(&anItem, mParent);
  dialog.DoModal();
}
