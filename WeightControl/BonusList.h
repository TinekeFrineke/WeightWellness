#pragma once

#include <list>

#include "ItemList.h"

#include "model/Day.h"

namespace WW
{
class Bonus;
class Model;
}


class BonusListItem
{
public:
                                  BonusListItem(const WW::Bonus & aBonus) : mBonus(aBonus) {}

  void                            Write(CListCtrl & aControl, int iItemIndex);

  WW::Bonus &                     GetBonus() { return mBonus; }

private:
  WW::Bonus                       mBonus;
};


class BonusList : public ListControl/* , public Observer*/
{
// Construction
public:
                                  BonusList(WW::Model & aModel);
	virtual                         ~BonusList();

 // // Operations
  void                            View(const std::list<WW::Bonus> & aBonuses);

  BonusListItem *                 GetItemAt(int iIndex);
  BonusListItem *                 GetSelectedItem();
  //void                            SelectItem(const WW::Bonus & anItem);
  void                            SelectItem(int iIndex, bool bSelect);

protected:
	//{{AFX_MSG(BonusList)
	//afx_msg void                    OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

  WW::Model &                     GetModel() { return mModel; }
  void                            ClearItems();

private:
  std::vector<BonusListItem *>    mItems;
  WW::Model &                     mModel;
};
