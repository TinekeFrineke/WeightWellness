#include "stdafx.h"

#include "ReceptDefinitiesList.h"

#include "model/Model.h"
#include "model/ReceptDefinitie.h"

#include "EditFoodDefDialog.h"

//   ON_NOTIFY(NM_DBLCLK, IDC_ITEMLIST, OnNMDblclkItemlist)

BEGIN_MESSAGE_MAP(ReceptDefinitiesList, CListCtrl)
    //{{AFX_MSG_MAP(ReceptDefinitiesList)
    ON_WM_LBUTTONDBLCLK()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

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


ReceptDefinitiesFilter::ReceptDefinitiesFilter(const std::tstring& aDescription)
    : mDescription(aDescription)
{
}


bool ReceptDefinitiesList::Complies(const weight::ReceptDefinitie& anItem,
                                    const ReceptDefinitiesFilter& aFilter)
{
    bool bDescriptionComplies = aFilter.GetDescription().empty() ||
        Str::ToUpper(anItem.GetName()).find(Str::ToUpper(aFilter.GetDescription())) != std::tstring::npos;

    return bDescriptionComplies;
}


void ReceptDefinitiesListItem::Write(CListCtrl& aControl, int iItemIndex)
{
    LV_ITEM lvi;
    lvi.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_STATE;
    lvi.iItem = iItemIndex;
    lvi.iSubItem = 0;
    TCHAR* name = _tcsdup(mItem->GetName().c_str());
    lvi.pszText = name;
    lvi.iImage = 0;
    lvi.stateMask = LVIS_STATEIMAGEMASK;
    lvi.state = INDEXTOSTATEIMAGEMASK(1);

    int item = aControl.InsertItem(&lvi);

    TCHAR points[256];
    _stprintf_s(points, _T("%.2f"), mItem->GetPointsPerPortion());
    aControl.SetItemText(iItemIndex, 1, points);
    //_stprintf_s(points, _T("%d"), mItem->GetPortions());
    //aControl.SetItemText(iItemIndex, 2, points);
    aControl.SetItemData(item, (DWORD_PTR)this);


    delete name;
}


ReceptDefinitiesList::ReceptDefinitiesList(weight::Model& aModel)
    : mModel(aModel)
{
}


ReceptDefinitiesList::~ReceptDefinitiesList()
{
    ClearItems();
}


void ReceptDefinitiesList::Initialize()
{
    InsertColumn(1, _T("Naam"), LVCFMT_LEFT, 200);
    InsertColumn(2, _T("Punten/portie"), LVCFMT_RIGHT, 80);
}


void ReceptDefinitiesList::ClearItems()
{
    mItems.clear();
}


void ReceptDefinitiesList::View(const std::vector<std::unique_ptr<weight::ReceptDefinitie>>& aItems)
{
    DeleteAllItems();
    ClearItems();

    SetItemCount((int)aItems.size());

    for (size_t i = 0; i < aItems.size(); ++i)
        if (Complies(*aItems[i], mFilter))
            mItems.push_back(std::make_unique<ReceptDefinitiesListItem>(aItems[i].get()));

    int inIndex = 0;
    for (size_t i = 0; i < mItems.size(); ++i)
    {
        mItems[i]->Write(*this, inIndex);
        inIndex++;
    }

    if (mItems.size() > 0)
        SelectItem(0);
}


void ReceptDefinitiesList::SelectItem(weight::ReceptDefinitie& aDefinition)
{
    for (size_t i = 0; i < mItems.size(); ++i)
    {
        if (mItems[i]->GetItem()->GetName() == aDefinition.GetName())
        {
            SelectItem(static_cast<int>(i));
            return;
        }
    }
}


void ReceptDefinitiesList::SelectItem(int iIndex)
{
    if (iIndex >= static_cast<int>(mItems.size()))
        return;

    LVITEM item;
    item.iItem = iIndex;
    item.mask = LVIF_STATE;
    item.state = 1;//bSelect ? 1/*LIS_FOCUSED*/ : 0;
    SetItem(&item);
}


void ReceptDefinitiesList::SetFilter(const ReceptDefinitiesFilter& aFilter)
{
    mFilter = aFilter;
}

int ReceptDefinitiesList::IndexOf(const weight::ReceptDefinitie& anItem) const
{
    int nItem = GetNextItem(-1, LVNI_ALL);

    while (nItem >= 0 && nItem < int(mItems.size()))
    {
        ReceptDefinitiesListItem* item = (ReceptDefinitiesListItem*)GetItemData(nItem);
        if (item->GetItem() == &anItem)
            return nItem;

        nItem = GetNextItem(nItem, LVNI_ALL);
    }

    return -1;
}

weight::ReceptDefinitie* ReceptDefinitiesList::GetSelectedDefinition()
{
    POSITION pos = GetFirstSelectedItemPosition();
    if (pos == nullptr)
        return nullptr;

    int nItem = GetNextSelectedItem(pos);

    if (nItem >= 0 && nItem < int(mItems.size()))
    {
        ReceptDefinitiesListItem* item = (ReceptDefinitiesListItem*)GetItemData(nItem);
        return item->GetItem();
    }

    return nullptr;
}
