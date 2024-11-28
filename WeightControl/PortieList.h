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
                      PortieListItem(const weight::VMDefinitie & aDefinitie, weight::Portie * aPortie)
                        : mDefinitie(aDefinitie), mPortie(aPortie) {}

  void                Write(CListCtrl & aControl, int iItemIndex);

  weight::Portie *        GetPortie() { return mPortie; }

private:
  const weight::VMDefinitie &
                      mDefinitie;
  weight::Portie *        mPortie;
};


class PortieList : public CListCtrl
{
public:
                                PortieList(weight::Model &                   aModel,
                                           weight::VMDefinitie * aDefinitie);
                                ~PortieList();

  void                          Initialize();
  void                          Fill();

  void                          SetDefinition(weight::VMDefinitie* aDefinitie);
  // Transfers ownership
  void SetPorties(std::vector<std::unique_ptr<weight::Portie>>& aPortieList);
  //
  const std::vector<std::unique_ptr<weight::Portie>>& GetPorties() const { return mPorties; }
  //
  bool                          AddPortie(std::unique_ptr<weight::Portie> aPortie);
  // Destroys the removed portie
  bool                          RemovePortie(weight::Portie * aPortie);
  // Copies porties to aPortieList, clears itemlist
  void                          ReleasePorties(std::vector<std::unique_ptr<weight::Portie>> & aPortieList);
  // Clears itemlist and porties with it.
  void                          DeletePorties();

  PortieListItem *              GetSelectedItem();
  void                          SelectItem(weight::Portie & aPortie);
  void                          SelectItem(int iIndex);

  void                          Update(PortieListItem * anItem);

	//{{AFX_MSG(PortieList)
  afx_msg void OnLButtonDblClk( UINT, CPoint );
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

private:
  void                          ClearItems();

  std::vector<std::unique_ptr<PortieListItem>> mItems;
  weight::Model& mModel;
  weight::VMDefinitie * mDefinitie;
  std::vector<std::unique_ptr<weight::Portie>> mPorties;
};

// NM_DBLCLK
