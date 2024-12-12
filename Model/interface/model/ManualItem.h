#pragma once


#include "Item.h"

namespace weight
{

// A manual item has a fixed number of points for a fixed amount of food.
class ManualItem: public Item
{
public:
    ManualItem(const std::tstring& aName, double aPoints)
        : mName(aName)
        , mPoints(aPoints) {}

    virtual               ~ManualItem() {}
    virtual std::tstring  GetName() const { return mName; }
    virtual double        GetPoints() const { return mPoints; }
    virtual void          Accept(ItemVisitor& aVisitor);

    void                  Set(double aPoints) { mPoints = aPoints; }

private:
    std::tstring          mName;
    double                mPoints;
};


inline void ManualItem::Accept(ItemVisitor& aVisitor)
{
    aVisitor.Visit(*this);
}

} // namespace weight
