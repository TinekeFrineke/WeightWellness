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
    VMDefinitiesFilter(const std::tstring& aName,
                       const std::tstring& aCategory,
                       const std::tstring& aMerk);

    std::tstring                GetDescription() const { return mName; }
    std::tstring                GetCategory() const { return mCategory; }
    std::tstring                GetBrand() const { return mMerk; }

    bool                        IsFavouritesOnly() const { return mFavouritesOnly; }
    void                        SetFavouritesOnly(bool bFilter);

private:
    std::tstring                mName;
    std::tstring                mCategory;
    std::tstring                mMerk;
    bool                        mFavouritesOnly;
};

class VMDefinitiesListItem
/*{
public:
    VMDefinitiesListItem(weight::VMDefinitie* anItem)
        : mItem(anItem) {}

    weight::VMDefinitie* GetItem() { return mItem; }

private:
    void Write(CListCtrl& aControl, int iItemIndex);

    weight::VMDefinitie* mItem;
}*/;


class VMDefinitiesList: public CListCtrl
{
public:
    VMDefinitiesList(const std::vector<weight::VMDefinitie*>& definitions);
    ~VMDefinitiesList();

    void                        Initialize();
    void SetDefinitions(const std::vector<weight::VMDefinitie*>& definitions);
    void                        SetFilter(const VMDefinitiesFilter& aFilter);
    void                        Fill();
    weight::VMDefinitie* GetSelectedDefinition();
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

    std::vector<std::unique_ptr<VMDefinitiesListItem>> mItems;
    std::vector<weight::VMDefinitie*> m_definitions;
    VMDefinitiesFilter mFilter;
};

// NM_DBLCLK
