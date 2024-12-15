#pragma once

#include "Item.h"
#include "Portie.h"
#include "Subject.h"
#include "Voedingsmiddel.h"

namespace weight
{


class ReceptDefinitie
{
public:
    explicit ReceptDefinitie(const std::tstring& aName) : mName(aName) {}
    virtual ~ReceptDefinitie() noexcept = default;

    virtual std::tstring          GetName() const { return mName; }
    virtual double                GetPointsPerPortion() const;
    int                           GetPortions() const { return mPorties.Get(); }

    void                          SetName(const std::wstring& name) { mName = name; }
    void                          SetPortions(int aPorties) { mPorties.Set(aPorties); }
    void                          Add(std::unique_ptr<Item> anItem);
    void                          Remove(Item* anItem);

    const std::vector<std::unique_ptr<Item>>& GetItems() const noexcept { return mItems; }

    Subject<int>& NumberOfPortions() noexcept { return mPorties; }

private:
    std::tstring mName;
    std::vector<std::unique_ptr<Item>> mItems;
#ifdef NEW_TRAIL
    IntSubject mPorties;
#else
    Subject<int> mPorties;
#endif
};


} // namespace weight
