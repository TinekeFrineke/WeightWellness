#pragma once


#include "Utilities/StrUtils.h"

namespace WW
{


class Item;
class Recept;
class Gerecht;
class ManualItem;
class Model;
class PointsCalculator;
class Voedingsmiddel;

class ItemVisitor
{
public:
  virtual               ~ItemVisitor() = 0 {}

  virtual void          Visit(Recept & aRecept) = 0;
  virtual void          Visit(Gerecht & aGerecht) = 0;
  virtual void          Visit(Voedingsmiddel & aVoedingsmiddel) = 0;
  virtual void          Visit(ManualItem & anItem) = 0;
};


// An item is a concrete item of food that can return the amount of points
class Item
{
public:
  virtual               ~Item() = 0 {}
  virtual std::tstring  GetName() const = 0;
  virtual double        GetPoints() const = 0;
  virtual void          Accept(ItemVisitor & aVisitor) = 0;
  virtual bool          IsFreePortion() const { return false; }

  virtual void          Recalculate(Model & aModel, const PointsCalculator & aCalculator);
};

class Recalculator : public ItemVisitor
{
public:
                            Recalculator(Model &                  aModel,
                                         const PointsCalculator & aCalculator);
  virtual                   ~Recalculator() {}

  virtual void              Visit(Recept & aRecept);
  virtual void              Visit(Gerecht & aGerecht);
  virtual void              Visit(Voedingsmiddel & aVoedingsmiddel);
  virtual void              Visit(ManualItem & anItem);

private:
                            Recalculator(const Recalculator &);
  Recalculator &            operator=(const Recalculator &);
  const PointsCalculator &  mCalculator;
  Model &                   mModel;
};


}
