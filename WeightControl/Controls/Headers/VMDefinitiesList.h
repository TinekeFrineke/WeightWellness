#pragma once

#include "afxcmn.h"

#include <vector>

#include "Utilities/StrUtils.h"

namespace weight
{
class CategorieNaam;
class Model;
class VMDefinitie;
}


class VMDefinitiesFilter
{
public:
    VMDefinitiesFilter() : mFavouritesOnly(false) {}
    VMDefinitiesFilter(const std::tstring& aDescription,
                       const std::tstring& aCategory,
                       const std::tstring& aMerk);

    std::tstring                GetDescription() const { return mDescription; }
    std::tstring                GetCategory() const { return mCategory; }
    std::tstring                GetBrand() const { return mMerk; }

    bool                        IsFavouritesOnly() const { return mFavouritesOnly; }
    void                        SetFavouritesOnly(bool bFilter);

private:
    std::tstring                mDescription;
    std::tstring                mCategory;
    std::tstring                mMerk;
    bool                        mFavouritesOnly;
};

class VMDefinitiesListItem
{
public:
    VMDefinitiesListItem(weight::VMDefinitie* anItem)
        : mItem(anItem) {}

    void                          Write(CListCtrl& aControl, int iItemIndex);

    weight::VMDefinitie* GetItem() { return mItem; }

    bool                          Complies(const VMDefinitiesFilter& aFilter) const;

private:
    weight::VMDefinitie* mItem;
};


class VMDefinitiesList: public CListCtrl
{
public:
    VMDefinitiesList(weight::Model& aModel);
    ~VMDefinitiesList();

    void                        Initialize();
    void                        SetFilter(const VMDefinitiesFilter& aFilter);
    void                        Fill();

    VMDefinitiesListItem* GetSelectedItem();
    void                        SelectItem(weight::VMDefinitie& aDefinition);
    void                        SelectItem(int iIndex, bool bSelect);

    void                        SetFavouritesOnly(bool bFilter);

    //{{AFX_MSG(VMDefinitiesList)
  //afx_msg void OnLButtonDblClk( UINT, CPoint );
    //}}AFX_MSG

    DECLARE_MESSAGE_MAP()

    // afx_msg void OnNMDblclkItemlist(NMHDR *pNMHDR, LRESULT *pResult);

private:
    void                        ClearItems();
    static bool                 Complies(const weight::VMDefinitie& anItem,
                                         const VMDefinitiesFilter& aFilter);

    std::vector<std::unique_ptr<VMDefinitiesListItem>> mItems;
    weight::Model& mModel;
    VMDefinitiesFilter mFilter;
};

// NM_DBLCLK
