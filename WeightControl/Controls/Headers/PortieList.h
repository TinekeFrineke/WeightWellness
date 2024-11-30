#pragma once

#include "afxcmn.h"

#include <memory>
#include <vector>

#include "resource.h"


namespace weight
{
class Model;
class Portie;
class VMDefinitie;
}


class PortieListItem
{
public:
    PortieListItem(double pointsPer100Units, weight::Portie* aPortie)
        : m_pointsPer100Units(pointsPer100Units)
        , mPortie(aPortie) {}

    void Write(CListCtrl& aControl, int iItemIndex);

    weight::Portie* GetPortie() { return mPortie; }
    void SetPointsPer100Units(double points) { m_pointsPer100Units = points; }

private:
    //const weight::VMDefinitie&
    //    mDefinitie;
    double m_pointsPer100Units;
    weight::Portie* mPortie;
};


class PortieList: public CListCtrl
{
public:
    PortieList();
    ~PortieList();

    void Initialize();

    void SetPointsPer100Units(double points);
    void SetPorties(const std::vector<std::reference_wrapper<weight::Portie>>& aPortieList);

    PortieListItem* GetSelectedItem();
    //void SelectItem(weight::Portie& aPortie);
    //void SelectItem(int iIndex);

    void Update(PortieListItem* anItem);

    ////{{AFX_MSG(PortieList)
    //afx_msg void OnLButtonDblClk(UINT, CPoint);
    ////}}AFX_MSG

    DECLARE_MESSAGE_MAP()

private:
    void ClearItems();

    std::vector<std::unique_ptr<PortieListItem>> mItems;
    double m_pointsPer100Units{};
    std::vector<std::reference_wrapper<weight::Portie>> mPorties;
};

// NM_DBLCLK
