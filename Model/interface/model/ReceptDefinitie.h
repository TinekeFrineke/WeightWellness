#pragma once

#include "Portie.h"
#include "Voedingsmiddel.h"

namespace WW
{


class ReceptDefinitie
{
public:
    explicit ReceptDefinitie(const std::tstring& aName) : mName(aName) {}

    virtual std::tstring          GetName() const { return mName; }
    virtual double                GetPointsPerPortion() const;
    int                           GetPortions() const { return mPorties; }

    void                          SetPortions(int aPorties) { mPorties = aPorties; }
    void                          Add(std::unique_ptr<Item> anItem);
    void                          Remove(Item* anItem);

    std::vector<std::unique_ptr<Item>>& GetItems() { return mItems; }
    const std::vector<std::unique_ptr<Item>>& GetItems() const { return mItems; }



private:
    std::tstring                  mName;
    std::vector<std::unique_ptr<Item>>           mItems;
    int                           mPorties;
};


} // namespace WW
