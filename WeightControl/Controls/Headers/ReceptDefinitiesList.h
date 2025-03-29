#pragma once

#include "afxcmn.h"
#include <memory>
#include <vector>

#include "Utilities/StrUtils.h"

namespace weight
{
class CategorieNaam;
class ReceptDefinitie;

template <typename TYPE> class IRepository;
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

class ReceptDefinitiesListItem;


class ReceptDefinitiesList: public CListCtrl
{
public:
    explicit ReceptDefinitiesList();
    ~ReceptDefinitiesList() override;

    void Initialize();
    void SetFilter(const ReceptDefinitiesFilter& aFilter);
    void View(const std::vector<weight::ReceptDefinitie*>& aItems);

    weight::ReceptDefinitie* GetSelectedDefinition();
    void SelectItem(weight::ReceptDefinitie& aDefinition);
    void SelectItem(int iIndex);
    int IndexOf(const weight::ReceptDefinitie& recipe) const;

    DECLARE_MESSAGE_MAP()

private:
    void                        ClearItems();
    static bool                 Complies(const weight::ReceptDefinitie& anItem,
                                         const ReceptDefinitiesFilter& aFilter);

    std::vector<std::unique_ptr<ReceptDefinitiesListItem>> mItems;
    ReceptDefinitiesFilter      mFilter;
};

// NM_DBLCLK
