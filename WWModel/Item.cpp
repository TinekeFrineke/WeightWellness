#include "stdafx.h"

#include "item.h"
#include "wwmodel.h"
#include "voedingsmiddel.h"
#include "voedingsmiddeldefinitie.h"


namespace WW
{


void Item::Recalculate(Model & aModel, const PointsCalculator & aCalculator)
{
  Recalculator recalculator(aModel, aCalculator);
  Accept(recalculator);
}


Recalculator::Recalculator(Model & aModel, const PointsCalculator & aCalculator)
: mModel      (aModel),
  mCalculator (aCalculator)
{
}


void Recalculator::Visit(Recept & aRecept)
{
  (void)&aRecept;
}


void Recalculator::Visit(Gerecht & aGerecht)
{
  (void)&aGerecht;
}


void Recalculator::Visit(Voedingsmiddel & aVoedingsmiddel)
{
  if (aVoedingsmiddel.GetLot().GetFreeLot() == NULL)
    return;

  VMDefinitie * definitie = mModel.FindVoedingsmiddelDefinitie(aVoedingsmiddel.GetName());
  if (definitie == NULL)
    return;

  if (definitie->HasFreePortion(mCalculator.GetStrategy()))
    aVoedingsmiddel.SetLot(new FreeLot(mCalculator.GetStrategy(),
                           definitie->GetFreePortionPoints(mCalculator.GetStrategy())));
}


void Recalculator::Visit(ManualItem & anItem)
{
  (void)anItem;
}


} // namespace WW
