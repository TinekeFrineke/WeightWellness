#pragma once

#include "afxcmn.h"
#include <memory>
#include <vector>

#include "Utilities/StrUtils.h"

namespace WW
{
class CategorieNaam;
class Model;
class ReceptDefinitie;
}


class ReceptDefinitiesFilter
{
public:
                              ReceptDefinitiesFilter() {}
                              ReceptDefinitiesFilter(const std::tstring & aDescription);

  std::tstring                GetDescription() const  { return mDescription; }

private:
  std::tstring                mDescription;
};

class ReceptDefinitiesListItem
{
public:
                              ReceptDefinitiesListItem(WW::ReceptDefinitie * anItem)
                                : mItem(anItem) {}

  void                        Write(CListCtrl & aControl, int iItemIndex);

  WW::ReceptDefinitie *       GetItem() { return mItem; }

  bool                        Complies(const ReceptDefinitiesFilter & aFilter) const; 

private:
  WW::ReceptDefinitie *       mItem;
};


class ReceptDefinitiesList : public CListCtrl
{
public:
                              ReceptDefinitiesList(WW::Model & aModel);
                              ~ReceptDefinitiesList();

  void                        Initialize();
  void                        SetFilter(const ReceptDefinitiesFilter & aFilter);
  void                        View(const std::vector<std::unique_ptr<WW::ReceptDefinitie>> & aItems);

  ReceptDefinitiesListItem *  GetSelectedItem();
  void                        SelectItem(WW::ReceptDefinitie & aDefinition);
  void                        SelectItem(int iIndex);
  int                         IndexOf(const ReceptDefinitiesListItem * item) const;
  void                        DeleteItem(const ReceptDefinitiesListItem * item);

	DECLARE_MESSAGE_MAP()

private:
  void                        ClearItems();
  static bool                 Complies(const WW::ReceptDefinitie & anItem,
                                       const ReceptDefinitiesFilter & aFilter);

  std::vector<std::unique_ptr<ReceptDefinitiesListItem>> mItems;
  WW::Model &                 mModel;
  ReceptDefinitiesFilter      mFilter;
};

// NM_DBLCLK
