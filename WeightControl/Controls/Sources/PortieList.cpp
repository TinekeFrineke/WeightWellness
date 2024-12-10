#include "stdafx.h"

#include "PortieList.h"

#include <algorithm>

#include "model/Portie.h"
#include "model/Model.h"
#include "model/VoedingsmiddelDefinitie.h"

#include "EditPortieDialog.h"
#include "PortieEditor.h"

//   ON_NOTIFY(NM_DBLCLK, IDC_ITEMLIST, OnNMDblclkItemlist)

BEGIN_MESSAGE_MAP(PortieList, CListCtrl)
    //{{AFX_MSG_MAP(PortieList)
    ON_WM_LBUTTONDBLCLK()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()


void PortieListItem::Write(CListCtrl& aControl, int iItemIndex)
{
    if (aControl.GetItemCount() <= iItemIndex) {
        LV_ITEM lvi;
        lvi.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_STATE;
        lvi.iItem = iItemIndex;
        lvi.iSubItem = 0;
        TCHAR* name = _tcsdup(mPortie->GetName().c_str());
        lvi.pszText = name;
        lvi.iImage = 0;
        lvi.stateMask = LVIS_STATEIMAGEMASK;
        lvi.state = INDEXTOSTATEIMAGEMASK(1);
        aControl.InsertItem(&lvi);
        free(name);
    }
    else {
        aControl.SetItemText(iItemIndex, 1, mPortie->GetName().c_str());
    }

    TCHAR units[256];
    _stprintf_s(units, _T("%.2f"), (mPortie->GetUnits() * m_pointsPer100Units) / 100);
    aControl.SetItemText(iItemIndex, 1, units);

}


PortieList::PortieList() = default;


PortieList::~PortieList() = default;


void PortieList::Initialize()
{
    InsertColumn(1, _T("Naam"), LVCFMT_LEFT, 200);
    InsertColumn(3, _T("Punten/portie"), LVCFMT_RIGHT, 80);
}


void PortieList::ClearItems()
{
    mItems.clear();
}


void PortieList::Update(PortieListItem* anItem)
{
    // TODO ww2024: Place code here to handle when the dialog is
    // dismissed with OK
    for (size_t i = 0; i < mItems.size(); ++i)
    {
        if (mItems[i].get() == anItem)
        {
            anItem->Write(*this, (int)i);
            break;
        }
    }
}


void PortieList::SetPorties(const std::vector<std::reference_wrapper<weight::Portie>>& aPortieList)
{
    mPorties = aPortieList;

    DeleteAllItems();
    ClearItems();
    for (size_t i = 0; i < mPorties.size(); ++i)
        mItems.push_back(std::make_unique<PortieListItem>(m_pointsPer100Units, &mPorties[i].get()));
    
    for (size_t i = 0; i < mItems.size(); ++i)
        mItems[i]->Write(*this, (int)i);
}


PortieListItem* PortieList::GetSelectedItem()
{
    POSITION pos = GetFirstSelectedItemPosition();
    if (pos == nullptr)
        return nullptr;

    int nItem = GetNextSelectedItem(pos);

    if (nItem >= 0 && nItem < int(mItems.size()))
        return mItems[nItem].get();

    return nullptr;
}

void PortieList::SetPointsPer100Units(double points)
{
    if (m_pointsPer100Units == points)
        return;

    m_pointsPer100Units = points;
    for (auto& item : mItems) {
        item->SetPointsPer100Units(points);
        Update(item.get());
    }
}
