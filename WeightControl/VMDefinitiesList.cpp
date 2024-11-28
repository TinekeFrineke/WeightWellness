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


VMDefinitiesFilter::VMDefinitiesFilter(const std::tstring& aDescription,
                                       const std::tstring& aCategory,
                                       const std::tstring& aMerk)
    : mDescription(aDescription),
    mCategory(aCategory),
    mMerk(aMerk),
    mFavouritesOnly(false)
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

    TCHAR* category = _tcsdup(mItem->GetCategory().Get().c_str());
    aControl.SetItemText(item, 1, category);

    TCHAR* unit = _tcsdup(mItem->GetUnit().GetName().c_str());
    aControl.SetItemText(item, 2, unit);

    TCHAR points[256];
    _stprintf_s(points, _T("%.2f"), mItem->GetPointsPer100Units());
    aControl.SetItemText(item, 3, points);

    aControl.SetItemData(item, (DWORD_PTR)this);

    delete name;
    delete category;
    delete unit;
}


VMDefinitiesList::VMDefinitiesList(weight::Model& aModel)
    : mModel(aModel)
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


void VMDefinitiesList::ClearItems()
{
    mItems.clear();
}


void VMDefinitiesList::Fill()
{
    DeleteAllItems();
    ClearItems();

    for (size_t i = 0; i < mModel.GetVoedingsmiddelDefinities().size(); ++i)
        if (Complies(*mModel.GetVoedingsmiddelDefinities()[i], mFilter))
            mItems.push_back(std::make_unique<VMDefinitiesListItem>(mModel.GetVoedingsmiddelDefinities()[i].get()));

    SetItemCount((int)mItems.size());

    int inIndex = 0;
    for (size_t i = 0; i < mItems.size(); ++i)
    {
        mItems[i]->Write(*this, inIndex);
        inIndex++;
    }

    if (GetItemCount() > 0)
        SelectItem(0, true);
}


void VMDefinitiesList::SetFilter(const VMDefinitiesFilter& aFilter)
{
    mFilter = aFilter;
}


VMDefinitiesListItem* VMDefinitiesList::GetSelectedItem()
{
    POSITION pos = GetFirstSelectedItemPosition();
    if (pos == NULL)
        return NULL;

    int nItem = GetNextSelectedItem(pos);

    if (nItem >= 0 && nItem < int(mItems.size()))
    {
        VMDefinitiesListItem* item = (VMDefinitiesListItem*)GetItemData(nItem);
        return item;
    }

    return NULL;
}


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


bool VMDefinitiesList::Complies(const weight::VMDefinitie& anItem,
                                const VMDefinitiesFilter& aFilter)
{
    if (aFilter.IsFavouritesOnly() && !anItem.IsFavourite())
        return false;

    bool bCategoryComplies = aFilter.GetCategory().empty() || anItem.GetCategory().Get() == aFilter.GetCategory();
    bool bBrandComplies = aFilter.GetBrand().empty() ||
        aFilter.GetBrand() == _T("<alles>") ||
        anItem.GetMerk().Get() == aFilter.GetBrand() ||
        (aFilter.GetBrand() == _T("<merkloos>") && anItem.GetMerk().Get().empty());
    bool bDescriptionComplies = aFilter.GetDescription().empty() ||
        Str::ToUpper(anItem.GetName()).find(Str::ToUpper(aFilter.GetDescription())) != std::tstring::npos;

    return bCategoryComplies && bBrandComplies && bDescriptionComplies;
}


void VMDefinitiesList::SetFavouritesOnly(bool bFilter)
{
    mFilter.SetFavouritesOnly(bFilter);
}
