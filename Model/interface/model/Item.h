#pragma once


#include "Utilities/StrUtils.h"

namespace weight
{


class Item;
class Recept;
class ManualItem;
class Model;
class PointsCalculator;
class Voedingsmiddel;

class ItemVisitor
{
public:
    virtual               ~ItemVisitor() = default;

    virtual void          Visit(Recept& aRecept) = 0;
    virtual void          Visit(Voedingsmiddel& aVoedingsmiddel) = 0;
    virtual void          Visit(ManualItem& anItem) = 0;
};


// An item is a concrete item of food that can return the amount of points
class Item
{
public:
    virtual               ~Item() = default;
    virtual std::tstring  GetName() const = 0;
    virtual double        GetPoints() const = 0;
    virtual void          Accept(ItemVisitor& aVisitor) = 0;

    virtual void          Recalculate(Model& /*aModel*/, const PointsCalculator& /*aCalculator*/) {}
};



} // namespace wieght
