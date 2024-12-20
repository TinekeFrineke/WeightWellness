#pragma once

#include <list>

#include "ItemList.h"

#include "model/Day.h"

namespace weight
{
class Bonus;
class Model;
}


class BonusListItem
{
public:
    BonusListItem(const weight::Bonus& aBonus) : mBonus(aBonus) {}

    void Write(CListCtrl& aControl, int iItemIndex);

    weight::Bonus& GetBonus() { return mBonus; }

private:
    weight::Bonus mBonus;
};


class BonusList: public ListControl/* , public Observer*/
{
    // Construction
public:
    BonusList(weight::Model& aModel);
    virtual                         ~BonusList();

    // // Operations
    void                            View(const std::list<weight::Bonus>& aBonuses);

    BonusListItem* GetItemAt(int iIndex);
    BonusListItem* GetSelectedItem();
    //void                            SelectItem(const weight::Bonus & anItem);
    void                            SelectItem(int iIndex, bool bSelect);

protected:
    //{{AFX_MSG(BonusList)
    //afx_msg void                    OnLButtonDown(UINT nFlags, CPoint point);
    //}}AFX_MSG

    DECLARE_MESSAGE_MAP()

    weight::Model& GetModel() { return mModel; }
    void ClearItems();

private:
    std::vector<std::unique_ptr<BonusListItem>> mItems;
    weight::Model& mModel;
};
