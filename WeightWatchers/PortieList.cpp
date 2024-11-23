#include "stdafx.h"

#include "PortieList.h"

#include <algorithm>

#include "WW/WWModel/Portie.h"
#include "WW/WWModel/WWModel.h"
#include "WW/WWModel/VoedingsmiddelDefinitie.h"

#include "EditPortieDialog.h"

//   ON_NOTIFY(NM_DBLCLK, IDC_ITEMLIST, OnNMDblclkItemlist)

BEGIN_MESSAGE_MAP(PortieList, CListCtrl)
	//{{AFX_MSG_MAP(PortieList)
  ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


void PortieListItem::Write(CListCtrl & aControl, int iItemIndex)
{
  LV_ITEM lvi;
	lvi.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_STATE;
	lvi.iItem = iItemIndex;
	lvi.iSubItem = 0;
  TCHAR * name = _tcsdup(mPortie->GetName().Get().c_str());
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


PortieList::PortieList(WW::Model &                    aModel,
                       WW::VMDefinitie *  aDefinitie)
: mModel    (aModel),
  mDefinitie(aDefinitie)
{
}


void PortieList::SetPorties(const std::vector<WW::Portie> & aPortieList)
{
  // Destroys the current portions inside.
  for (size_t i = 0; i < mPorties.size(); ++i)
    delete mPorties[i];

  mPorties = aPortieList;
}


bool PortieList::AddPortie(WW::Portie * aPortie)
{
  if (aPortie == NULL)
    return false;

  for (size_t i = 0; i < mPorties.size(); ++i)
    if (mPorties[i] == aPortie || mPorties[i]->GetName() == aPortie->GetName())
      return false;

  mPorties.push_back(aPortie);
  Fill();
  return true;
}


bool PortieList::RemovePortie(WW::Portie * aPortie)
{
  if (aPortie == NULL)
    return false;

  std::vector<WW::Portie *>::iterator iter = std::find(mPorties.begin(), mPorties.end(), aPortie);
  if (iter != mPorties.end())
  {
    ClearItems();
    delete *iter;
    mPorties.erase(iter);
    Fill();
    return true;
  }

  return false;
}


void PortieList::ReleasePorties(std::vector<std::unique_ptr<WW::Portie> & aPortieList)
{
  // Releases the portions without destroying them.
  aPortieList = mPorties;
  mPorties.clear();
  ClearItems();
}


void PortieList::DeletePorties()
{
  // Destroys the remaining portions inside.
  for (size_t i = 0; i < mPorties.size(); ++i)
    delete mPorties[i];

  mPorties.clear();
  ClearItems();
}


PortieList::~PortieList()
{
  DeletePorties();
}


void PortieList::Initialize()
{
  InsertColumn(1, _T("Naam"),           LVCFMT_LEFT, 200);
  InsertColumn(3, _T("Punten/portie"),  LVCFMT_RIGHT, 80);

  Fill();
}


void PortieList::ClearItems()
{
  for (size_t i = 0; i < mItems.size(); ++i)
    delete mItems[i];

  mItems.clear();
}


void PortieList::Update(PortieListItem * anItem)
{
	// TODO: Place code here to handle when the dialog is
	//  dismissed with OK
  for (size_t i = 0; i < mItems.size(); ++i)
  {
    if (mItems[i] == anItem)
    {
      anItem->Write(*this, (int)i);
      break;
    }
  }
}


void PortieList::OnLButtonDblClk( UINT, CPoint )
{
  PortieListItem * item = GetSelectedItem();
  if (item != NULL)
  {
    WW::Portie * portie = item->GetPortie();
    CEditPortieDialog dlg(mModel, *mDefinitie, portie, mPorties, this);
    INT_PTR nResponse = dlg.DoModal();
    if (nResponse == IDOK)
	    Update(item);
  }
}


void PortieList::Fill()
{
  if (mDefinitie == NULL)
    return;

  DeleteAllItems();
  ClearItems();

  for (size_t i = 0; i < mPorties.size(); ++i)
    mItems.push_back(new PortieListItem(*mDefinitie, mPorties[i]));

  for (size_t i = 0; i < mItems.size(); ++i)
    mItems[i]->Write(*this, (int)i);
}


PortieListItem * PortieList::GetSelectedItem()
{
  POSITION pos = GetFirstSelectedItemPosition();
  if (pos == NULL)
    return NULL;

  int nItem = GetNextSelectedItem(pos);

  if (nItem >= 0 && nItem < int(mItems.size()))
    return mItems[nItem];
  
  return NULL;
}

