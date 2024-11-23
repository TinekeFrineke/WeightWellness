#pragma once

#include "afxcmn.h"

#include <memory>
#include <vector>

#include "resource.h"


namespace WW
{
class Model;
class Portie;
class VMDefinitie;
}


class PortieListItem
{
public:
                      PortieListItem(const WW::VMDefinitie & aDefinitie, WW::Portie * aPortie)
                        : mDefinitie(aDefinitie), mPortie(aPortie) {}

  void                Write(CListCtrl & aControl, int iItemIndex);

  WW::Portie *        GetPortie() { return mPortie; }

private:
  const WW::VMDefinitie &
                      mDefinitie;
  WW::Portie *        mPortie;
};


class PortieList : public CListCtrl
{
public:
                                PortieList(WW::Model &                   aModel,
                                           WW::VMDefinitie * aDefinitie);
                                ~PortieList();

  void                          Initialize();
  void                          Fill();

  void                          SetDefinition(WW::VMDefinitie * aDefinitie) { mDefinitie = aDefinitie; }
  // Transfers ownership
  void                          SetPorties(const std::vector<std::unique_ptr<WW::Portie>> & aPortieList);
  //
  const std::vector<std::unique_ptr<WW::Portie>>& GetPorties() const { return mPorties; }
  //
  bool                          AddPortie(WW::Portie * aPortie);
  // Destroys the removed portie
  bool                          RemovePortie(WW::Portie * aPortie);
  // Copies porties to aPortieList, clears itemlist
  void                          ReleasePorties(std::vector<std::unique_ptr<WW::Portie>> & aPortieList);
  // Clears itemlist and porties with it.
  void                          DeletePorties();

  PortieListItem *              GetSelectedItem();
  void                          SelectItem(WW::Portie & aPortie);
  void                          SelectItem(int iIndex);

  void                          Update(PortieListItem * anItem);

	//{{AFX_MSG(PortieList)
  afx_msg void OnLButtonDblClk( UINT, CPoint );
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

private:
  void                          ClearItems();

  std::vector<PortieListItem *> mItems;
  WW::Model &                   mModel;
  WW::VMDefinitie * mDefinitie;
  std::vector<std::unique_ptr<WW::Portie>> mPorties;
};

// NM_DBLCLK
