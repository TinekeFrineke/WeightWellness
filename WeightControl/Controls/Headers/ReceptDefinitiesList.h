#pragma once

#include "afxcmn.h"
#include <memory>
#include <vector>

#include "Utilities/StrUtils.h"

namespace weight
{
class CategorieNaam;
class Model;
class ReceptDefinitie;
}


class ReceptDefinitiesFilter
{
public:
    ReceptDefinitiesFilter() {}
    ReceptDefinitiesFilter(const std::tstring& aDescription);

    std::tstring                GetDescription() const { return mDescription; }

private:
    std::tstring                mDescription;
};

class ReceptDefinitiesListItem
{
public:
    ReceptDefinitiesListItem(weight::ReceptDefinitie* anItem)
        : mItem(anItem) {}

    void Write(CListCtrl& aControl, int iItemIndex);

    weight::ReceptDefinitie* GetItem() { return mItem; }

private:
    weight::ReceptDefinitie* mItem;
};


class ReceptDefinitiesList: public CListCtrl
{
public:
    ReceptDefinitiesList(weight::Model& aModel);
    ~ReceptDefinitiesList() override;

    void Initialize();
    void SetFilter(const ReceptDefinitiesFilter& aFilter);
    void View(const std::vector<std::unique_ptr<weight::ReceptDefinitie>>& aItems);

    ReceptDefinitiesListItem* GetSelectedItem();
    void  SelectItem(weight::ReceptDefinitie& aDefinition);
    void  SelectItem(int iIndex);
    int  IndexOf(const ReceptDefinitiesListItem* item) const;
    void  DeleteItem(const ReceptDefinitiesListItem* item);

    DECLARE_MESSAGE_MAP()

private:
    void                        ClearItems();
    static bool                 Complies(const weight::ReceptDefinitie& anItem,
                                         const ReceptDefinitiesFilter& aFilter);

    std::vector<std::unique_ptr<ReceptDefinitiesListItem>> mItems;
    weight::Model& mModel;
    ReceptDefinitiesFilter      mFilter;
};

// NM_DBLCLK
