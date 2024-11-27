#include "stdafx.h"

#include "PortieList.h"

#include <algorithm>

#include "model/Portie.h"
#include "model/WWModel.h"
#include "model/VoedingsmiddelDefinitie.h"

#include "EditPortieDialog.h"

//   ON_NOTIFY(NM_DBLCLK, IDC_ITEMLIST, OnNMDblclkItemlist)

BEGIN_MESSAGE_MAP(PortieList, CListCtrl)
    //{{AFX_MSG_MAP(PortieList)
    ON_WM_LBUTTONDBLCLK()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()


void PortieListItem::Write(CListCtrl& aControl, int iItemIndex)
{
    LV_ITEM lvi;
    lvi.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_STATE;
    lvi.iItem = iItemIndex;
    lvi.iSubItem = 0;
    TCHAR* name = _tcsdup(mPortie->GetName().Get().c_str());
    lvi.pszText = name;
    lvi.iImage = 0;
    lvi.stateMask = LVIS_STATEIMAGEMASK;
    lvi.state = INDEXTOSTATEIMAGEMASK(1);

    if (aControl.GetItemCount() <= iItemIndex)
        aControl.InsertItem(&lvi);
    else
        aControl.SetItem(&lvi);

    TCHAR units[256];
    _stprintf_s(units, _T("%.2f"), (mPortie->GetUnits() * mDefinitie.GetPointsPer100Units()) / 100);
    aControl.SetItemText(iItemIndex, 1, units);

    delete name;
}


PortieList::PortieList(WW::Model& aModel,
                       WW::VMDefinitie* aDefinitie)
    : mModel(aModel),
    mDefinitie(aDefinitie)
{
}


bool PortieList::AddPortie(std::unique_ptr<WW::Portie> aPortie)
{
    if (aPortie == nullptr)
        return false;

    for (size_t i = 0; i < mPorties.size(); ++i)
        if (mPorties[i].get() == aPortie.get() || mPorties[i]->GetName() == aPortie->GetName())
            return false;

    mPorties.push_back(std::move(aPortie));
    Fill();
    return true;
}


bool PortieList::RemovePortie(WW::Portie* aPortie)
{
    if (aPortie == nullptr)
        return false;

    std::vector<std::unique_ptr<WW::Portie>>::iterator iter
        = std::find_if(mPorties.begin(), mPorties.end(), [aPortie] (const std::unique_ptr<WW::Portie>& portie) {
        return aPortie == portie.get();
    });
    if (iter != mPorties.end())
    {
        ClearItems();
        mPorties.erase(iter);
        Fill();
        return true;
    }

    return false;
}


void PortieList::ReleasePorties(std::vector<std::unique_ptr<WW::Portie>>& aPortieList)
{
    // Releases the portions without destroying them.
    aPortieList = std::move(mPorties);
    mPorties.clear();
    ClearItems();
}


void PortieList::DeletePorties()
{
    // Destroys the remaining portions inside.
    mPorties.clear();
    ClearItems();
}


PortieList::~PortieList() = default;


void PortieList::Initialize()
{
    InsertColumn(1, _T("Naam"), LVCFMT_LEFT, 200);
    InsertColumn(3, _T("Punten/portie"), LVCFMT_RIGHT, 80);

    Fill();
}


void PortieList::ClearItems()
{
    mItems.clear();
}


void PortieList::Update(PortieListItem* anItem)
{
    // TODO ww2019: Place code here to handle when the dialog is
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


void PortieList::OnLButtonDblClk(UINT, CPoint)
{
    PortieListItem* item = GetSelectedItem();
    if (item != nullptr)
    {
        WW::Portie* portie = item->GetPortie();
        CEditPortieDialog dlg(mModel, *mDefinitie, portie, mPorties, this);
        INT_PTR nResponse = dlg.DoModal();
        if (nResponse == IDOK)
            Update(item);
    }
}


void PortieList::Fill()
{
    if (mDefinitie == nullptr)
        return;

    DeleteAllItems();
    ClearItems();

    for (size_t i = 0; i < mPorties.size(); ++i)
        mItems.push_back(std::make_unique<PortieListItem>(*mDefinitie, mPorties[i].get()));

    for (size_t i = 0; i < mItems.size(); ++i)
        mItems[i]->Write(*this, (int)i);
}

void PortieList::SetDefinition(WW::VMDefinitie* aDefinitie)
{
    mDefinitie = aDefinitie;
}

// Transfers ownership

void PortieList::SetPorties(std::vector<std::unique_ptr<WW::Portie>>& aPortieList)
{
    // Destroys the current portions inside.

    mPorties = std::move(aPortieList);
    aPortieList.clear();
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

