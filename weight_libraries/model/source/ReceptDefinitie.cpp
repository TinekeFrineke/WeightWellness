
#include "ReceptDefinitie.h"


namespace weight
{


double ReceptDefinitie::GetPointsPerPortion() const
{
    if (mPorties.Get() == 0)
        return 0;

    double points = 0;
    for (const auto& item : mItems)
        points += item->GetPoints();

    return points / (double)mPorties.Get();
}


void ReceptDefinitie::Add(std::unique_ptr<Item> anItem)
{
    mItems.push_back(std::move(anItem));
}


void ReceptDefinitie::Remove(Item* anItem)
{
    for (auto i = mItems.begin(); i != mItems.end(); ++i)
    {
        if (i->get() == anItem)
        {
            mItems.erase(i);
            return;
        }
    }
}


} // namespace weight
