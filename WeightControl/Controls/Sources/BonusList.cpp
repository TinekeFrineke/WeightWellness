#include "stdafx.h"

#include <commctrl.h>
#include "BonusList.h"

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
//#include "WW/Model/Bonus.h"

/*
ListControl::ListControl()
: mNumberOfColumns(0)
{
}


void ListControl::SetNumberOfColumns(int aColumns)
{
  mNumberOfColumns = aColumns;
  mColumnInfo.resize(aColumns);
}


void ListControl::SetColumnInfo(int iColumn, const ColInfo & aInfo)
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
*/


void BonusListItem::Write(CListCtrl& aControl, int iItemIndex)
{
    LV_ITEM lvi;
    memset(&lvi, 0, sizeof(LV_ITEM));

    lvi.mask = LVIF_TEXT | LVIF_PARAM;///* | LVIF_IMAGE | LVIF_STATE* /;
    lvi.iItem = iItemIndex;
    lvi.iSubItem = 0;

    //TCHAR intensity[256];
    switch (mBonus.GetIntensity())
    {
        case weight::Bonus::INTENSITY::Low:
            lvi.pszText = _T("low");
            break;

        case weight::Bonus::INTENSITY::Medium:
            lvi.pszText = _T("medium");
            break;

        case weight::Bonus::INTENSITY::High:
            lvi.pszText = _T("high");
            break;
    }

    lvi.lParam = (LPARAM)&mBonus;

    int index = aControl.InsertItem(&lvi);

    int count = aControl.GetItemCount();
    count = count;
    (void)index;

    TCHAR duration[256];
    _stprintf_s(duration, _T("%d"), mBonus.GetDuration());
    BOOL bResult = aControl.SetItemText(index, 1, duration);

    TCHAR points[256];
    _stprintf_s(points, _T("%d"), mBonus.GetPoints());
    bResult = aControl.SetItemText(index, 2, points);
    bResult = aControl.SetItemData(index, (DWORD_PTR)this);
    bResult = bResult;
}


/////////////////////////////////////////////////////////////////////////////
// BonusList

BonusList::BonusList(weight::Model& aModel)
    : mModel(aModel)
{
    SetNumberOfColumns(3);
    SetColumnInfo(0, ColInfo(100, LVCFMT_LEFT, _T("Naam")));
    SetColumnInfo(1, ColInfo(80, LVCFMT_RIGHT, _T("Tijd")));
    SetColumnInfo(2, ColInfo(100, LVCFMT_RIGHT, _T("Punten")));
}

BonusList::~BonusList()
{
}


void BonusList::View(const std::list<weight::Bonus>& aBonuses)
{
    DeleteAllItems();
    ClearItems();

    for (std::list<weight::Bonus>::const_iterator citer = aBonuses.begin();
         citer != aBonuses.end();
         ++citer)
        mItems.push_back(std::make_unique<BonusListItem>(*citer));

    SetItemCount((int)mItems.size());

    for (size_t i = 0; i < mItems.size(); ++i)
        mItems[i]->Write(*this, (int)i);

    if (mItems.size() > 0)
    {
        LVITEM item;
        item.iItem = 0;
        item.mask = LVIF_STATE;
        SelectItem(0, true);
    }

    for (int i = 0; i < 3; ++i)
        SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
}


BonusListItem* BonusList::GetItemAt(int iIndex)
{
    if (iIndex >= static_cast<int>(mItems.size()))
        return NULL;

    return mItems[iIndex].get();
}


//void BonusList::SelectItem(const weight::Bonus & aBonus)
//{
//  //for (size_t i = 0; i < mItems.size(); ++i)
//  //  SelectItem(static_cast<int>(i), mItems[i]->GetBonus()->GetName() == aBonus.GetName());
//}


void BonusList::SelectItem(int iIndex, bool bSelect)
{
    if (iIndex >= static_cast<int>(mItems.size()))
        return;

    LVITEM item;
    item.iItem = iIndex;
    item.mask = LVIF_STATE;
    item.state = bSelect ? 1/*LIS_FOCUSED*/ : 0;
    SetItem(&item);
}


void BonusList::ClearItems()
{
    mItems.clear();
}


BonusListItem* BonusList::GetSelectedItem()
{
    POSITION pos = GetFirstSelectedItemPosition();
    if (pos == NULL)
        return NULL;

    int nItem = GetNextSelectedItem(pos);

    if (nItem >= 0 && nItem < int(mItems.size()))
    {
        int count = this->GetItemCount(); (void)count;
        DWORD_PTR itemdata = GetItemData(nItem);
        return (BonusListItem*)itemdata;
    }

    return NULL;
}


BEGIN_MESSAGE_MAP(BonusList, CListCtrl)
    //{{AFX_MSG_MAP(BonusList)
    //ON_WM_LBUTTONDOWN()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// BonusList message handlers
