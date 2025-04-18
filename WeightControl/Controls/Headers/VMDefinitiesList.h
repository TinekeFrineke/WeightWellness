#pragma once

#include "afxcmn.h"

#include <vector>

#include "Utilities/StrUtils.h"

namespace weight
{
class CategorieNaam;
class VMDefinitie;
}


class VMDefinitiesFilter
{
public:
    VMDefinitiesFilter() : mFavouritesOnly(false) {}
    VMDefinitiesFilter(const std::string& aName,
                       const std::string& aCategory,
                       const std::string& aMerk);

    std::string GetDescription() const { return mName; }
    std::string GetCategory() const { return mCategory; }
    std::string GetBrand() const { return mMerk; }

    bool         IsFavouritesOnly() const { return mFavouritesOnly; }
    void         SetFavouritesOnly(bool bFilter);

private:
    std::string mName;
    std::string mCategory;
    std::string mMerk;
    bool        mFavouritesOnly;
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
