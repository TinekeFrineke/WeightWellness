#include "stdafx.h"

#include <commctrl.h>
#include "ItemList.h"

/////////////////////////////////////////////////////
// This class is provided as is and Ben Hill takes no
// responsibility for any loss of any kind in connection
// to this code.
/////////////////////////////////////////////////////
// Is is meant purely as a educational tool and may
// contain bugs.
/////////////////////////////////////////////////////
// ben@shido.fsnet.co.uk
// http://www.shido.fsnet.co.uk
/////////////////////////////////////////////////////
// Thanks to a mystery poster in the C++ forum on 
// www.codeguru.com I can't find your name to say thanks
// for your Control drawing code. If you are that person 
// thank you very much. I have been able to use some of 
// you ideas to produce this sample application.
/////////////////////////////////////////////////////


#include "model/Day.h"
#include "model/Item.h"


ListControl::ListControl()
    : mNumberOfColumns(0)
{
}


void ListControl::SetNumberOfColumns(int aColumns)
{
    mNumberOfColumns = aColumns;
    mColumnInfo.resize(aColumns);
}


void ListControl::SetColumnInfo(int iColumn, const ColInfo& aInfo)
{
    if (iColumn >= mNumberOfColumns)
        throw 0;

    mColumnInfo[iColumn] = aInfo;
}


void ListControl::Initialize()
{
    for (int i = 0; i < mNumberOfColumns; ++i)
        InsertColumn(i + 1, mColumnInfo[i].mHeader, mColumnInfo[i].mAlignment, mColumnInfo[i].mMinWidth);
}


ItemListItem::ItemListItem(weight::Item* anItem)
    : mItem(anItem) {}

void ItemListItem::Write(CListCtrl& aControl, int iItemIndex)
{
    LV_ITEM lvi;
    memset(&lvi, 0, sizeof(LV_ITEM));

    lvi.mask = LVIF_TEXT | LVIF_PARAM/* | LVIF_IMAGE | LVIF_STATE*/;
    lvi.iItem = iItemIndex;
    lvi.iSubItem = 0;
    TCHAR* name = _tcsdup(mItem->GetName().c_str());
    lvi.pszText = name;
    lvi.lParam = (LPARAM)mItem;

    int index = aControl.InsertItem(&lvi);

    TCHAR points[256];
    _stprintf_s(points, _T("%.2f"), mItem->GetPoints());
    aControl.SetItemText(index, 1, points);
    aControl.SetItemData(index, (DWORD_PTR)this);

    delete name;
}

weight::Item* ItemListItem::GetItem()
{
    return mItem;
}


/////////////////////////////////////////////////////////////////////////////
// ItemList

ItemList::ItemList(weight::Model& aModel)
    : mModel(aModel)
{
    SetNumberOfColumns(2);
    SetColumnInfo(0, ColInfo(80, LVCFMT_LEFT, _T("Naam")));
    SetColumnInfo(1, ColInfo(100, LVCFMT_RIGHT, _T("Punten")));
}

ItemList::~ItemList()
{
    ClearItems();
}


void ItemList::View(const std::vector<std::unique_ptr<weight::Item>>& aItems)
{
    DeleteAllItems();
    ClearItems();

    SetItemCount((int)aItems.size());
    for (size_t i = 0; i < aItems.size(); ++i)
        mItems.push_back(std::make_unique<ItemListItem>(aItems[i].get()));

    for (size_t i = 0; i < mItems.size(); ++i)
        mItems[i]->Write(*this, (int)i);

    if (mItems.size() > 0)
    {
        LVITEM item;
        item.iItem = 0;
        item.mask = LVIF_STATE;
        SelectItem(0, true);
    }

    for (int i = 0; i < 2; ++i)
        SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
}


ItemListItem* ItemList::GetItemAt(int iIndex)
{
    if (iIndex >= static_cast<int>(mItems.size()))
        return NULL;

    return mItems[iIndex].get();
}


void ItemList::SelectItem(const weight::Item& anItem)
{
    for (size_t i = 0; i < mItems.size(); ++i)
        SelectItem(static_cast<int>(i), mItems[i]->GetItem()->GetName() == anItem.GetName());
}


void ItemList::SelectItem(int iIndex, bool bSelect)
{
    if (iIndex >= static_cast<int>(mItems.size()))
        return;

    LVITEM item;
    item.iItem = iIndex;
    item.mask = LVIF_STATE;
    item.state = bSelect ? 1/*LIS_FOCUSED*/ : 0;
    SetItem(&item);
}


void ItemList::ClearItems()
{
    mItems.clear();
}


ItemListItem* ItemList::GetSelectedItem()
{
    POSITION pos = GetFirstSelectedItemPosition();
    if (pos == NULL)
        return NULL;

    int nItem = GetNextSelectedItem(pos);

    if (nItem >= 0 && nItem < int(mItems.size()))
        return (ItemListItem*)GetItemData(nItem);

    return NULL;
}


BEGIN_MESSAGE_MAP(ItemList, CListCtrl)
    //{{AFX_MSG_MAP(ItemList)
    //ON_WM_LBUTTONDOWN()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ItemList message handlers
