#include "stdafx.h"

#include "VMDefinitiesList.h"

#include "model/Model.h"
#include "model/VoedingsmiddelDefinitie.h"

#include "EditFoodDefDialog.h"

//   ON_NOTIFY(NM_DBLCLK, IDC_ITEMLIST, OnNMDblclkItemlist)

BEGIN_MESSAGE_MAP(VMDefinitiesList, CListCtrl)
    //{{AFX_MSG_MAP(VMDefinitiesList)
    ON_WM_LBUTTONDBLCLK()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()


namespace {

bool CategoryMatches(const std::wstring& itemCategory, const std::wstring& categoryFilter)
{
    if (categoryFilter.empty())
        return true;
    return itemCategory == categoryFilter;
}

bool BrandMatches(const std::wstring& itemBrand, const std::wstring& brandFilter)
{
    if (brandFilter.empty() || brandFilter == L"<alles>")
        return true;
    if (brandFilter == _T("<merkloos>") && itemBrand.empty())
        return true;
    return itemBrand == brandFilter;
}

bool NameMatches(const std::wstring& itemName, const std::wstring& nameFilter)
{
    if (nameFilter.empty())
        return true;
    
    return Str::ToUpper(itemName).find(Str::ToUpper(nameFilter)) != std::tstring::npos;
}

bool Complies(const weight::VMDefinitie& anItem,
              const VMDefinitiesFilter& aFilter)
{
    if (aFilter.IsFavouritesOnly() && !anItem.IsFavourite())
        return false;

    return CategoryMatches(anItem.GetCategory(), aFilter.GetCategory())
        && BrandMatches(anItem.GetMerk(), aFilter.GetBrand())
        && NameMatches(anItem.GetName(), aFilter.GetDescription());
}

}


class VMDefinitiesListItem
{
public:
    VMDefinitiesListItem(weight::VMDefinitie* anItem)
        : mItem(anItem) {}

    weight::VMDefinitie* GetItem() { return mItem; }

    void Write(CListCtrl& aControl, int iItemIndex);
private:

    weight::VMDefinitie* mItem;
};



VMDefinitiesFilter::VMDefinitiesFilter(const std::tstring& aName,
                                       const std::tstring& aCategory,
                                       const std::tstring& aMerk)
    : mName(aName)
    , mCategory(aCategory)
    , mMerk(aMerk)
    , mFavouritesOnly(false)
{
}


void VMDefinitiesFilter::SetFavouritesOnly(bool bFilter)
{
    mFavouritesOnly = bFilter;
}


void VMDefinitiesListItem::Write(CListCtrl& aControl, int iItemIndex)
{
    LV_ITEM lvi;
    memset(&lvi, 0, sizeof(LV_ITEM));
    lvi.mask = LVIF_TEXT;
    lvi.iItem = iItemIndex;
    lvi.iSubItem = 0;
    TCHAR* name = _tcsdup(mItem->GetName().c_str());
    lvi.pszText = name;
    lvi.lParam = (LPARAM)mItem;

    int item = aControl.InsertItem(&lvi);

    // Will fill with opposite order
    //aControl.SetItemText(item, 0, mItem->GetName().c_str());
    aControl.SetItemText(item, 1, mItem->GetCategory().c_str());
    aControl.SetItemText(item, 2, mItem->GetUnit().c_str());

    TCHAR points[256];
    _stprintf_s(points, _T("%.2f"), mItem->GetPointsPer100Units());
    aControl.SetItemText(item, 3, points);

    aControl.SetItemData(item, (DWORD_PTR)this);

    delete name;
}


VMDefinitiesList::VMDefinitiesList(const std::vector<weight::VMDefinitie*>& definitions)
    : m_definitions(definitions)
{
}


VMDefinitiesList::~VMDefinitiesList()
{
    ClearItems();
}


void VMDefinitiesList::Initialize()
{
    InsertColumn(1, _T("Naam"), LVCFMT_LEFT, 200);
    InsertColumn(2, _T("Categorie"), LVCFMT_LEFT, 100);
    InsertColumn(3, _T("Eenheid"), LVCFMT_LEFT, 80);
    InsertColumn(4, _T("Punten/100 eenh."), LVCFMT_RIGHT, 80);

    Fill();
}

void VMDefinitiesList::SetDefinitions(const std::vector<weight::VMDefinitie*>& definitions)
{
    m_definitions = definitions;
    Fill();
}


void VMDefinitiesList::ClearItems()
{
    mItems.clear();
}


void VMDefinitiesList::Fill()
{
    SetRedraw(FALSE);
    DeleteAllItems();
    ClearItems();

    for (auto& definition : m_definitions)
        if (Complies(*definition, mFilter))
            mItems.push_back(std::make_unique<VMDefinitiesListItem>(definition));

    SetItemCount(static_cast<int>(mItems.size()));

    for (size_t i = 0; i < mItems.size(); ++i)
        mItems[i]->Write(*this, static_cast<int>(i));

    if (GetItemCount() > 0)
        SelectItem(0, true);

    SetRedraw(TRUE);
}

weight::VMDefinitie* VMDefinitiesList::GetSelectedDefinition()
{
    POSITION pos = GetFirstSelectedItemPosition();
    if (pos == nullptr)
        return nullptr;

    int nItem = GetNextSelectedItem(pos);

    if (nItem >= 0 && nItem < int(mItems.size())) {
        VMDefinitiesListItem* item = (VMDefinitiesListItem*)GetItemData(nItem);
        return item->GetItem();
    }

    return nullptr;
}


void VMDefinitiesList::SetFilter(const VMDefinitiesFilter& aFilter)
{
    mFilter = aFilter;
}


//VMDefinitiesListItem* VMDefinitiesList::GetSelectedItem()
//{
//    POSITION pos = GetFirstSelectedItemPosition();
//    if (pos == nullptr)
//        return nullptr;
//
//    int nItem = GetNextSelectedItem(pos);
//
//    if (nItem >= 0 && nItem < int(mItems.size()))
//    {
//        VMDefinitiesListItem* item = (VMDefinitiesListItem*)GetItemData(nItem);
//        return item;
//    }
//
//    return nullptr;
//}


void VMDefinitiesList::SelectItem(weight::VMDefinitie& aDefinition)
{
    for (size_t i = 0; i < mItems.size(); ++i)
        SelectItem(static_cast<int>(i), mItems[i]->GetItem()->GetName() == aDefinition.GetName());
}


void VMDefinitiesList::SelectItem(int iIndex, bool bSelect)
{
    if (iIndex >= static_cast<int>(mItems.size()))
        return;

    LVITEM item;
    item.iItem = iIndex;
    item.mask = LVIF_STATE;
    item.state = bSelect ? 1/*LIS_FOCUSED*/ : 0;
    SetItem(&item);
}


void VMDefinitiesList::SetFavouritesOnly(bool bFilter)
{
    mFilter.SetFavouritesOnly(bFilter);
}
