#pragma once

#include "resource.h"
#include "categorycombobox.h"
#include "stringedit.h"
#include "vmdefinitieslist.h"
#include "doubleedit.h"
#include "portiecombobox.h"
#include "afxwin.h"
#include "brandcombobox.h"


class VMState;

namespace WW
{
class Day;
class Voedingsmiddel;
}

// CFindVoedingsmiddel dialog

class CFindVoedingsmiddel : public CDialog
{
	DECLARE_DYNAMIC(CFindVoedingsmiddel)

public:
                      CFindVoedingsmiddel(WW::Model &                   aModel,
                                          WW::VMDefinitie * aDefinitie,
                                          CWnd * pParent = NULL);   // standard constructor
	virtual             ~CFindVoedingsmiddel();

// Dialog Data
	enum { IDD = IDD_FIND_VOEDINGSMIDDEL };

  WW::Voedingsmiddel *GetVoedingsMiddel() { return mFood; }

protected:
	virtual void        DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

  BOOL                OnInitDialog();

  afx_msg void        OnBnClickedOk();
  afx_msg void        OnBnClickedCancel();
  afx_msg void        OnEnChangeNaam();
  afx_msg void        OnCbnSelchangeCombo1();
  afx_msg void        OnLvnItemchangedItemlist(NMHDR *pNMHDR, LRESULT *pResult);
  afx_msg void        OnCbnSelchangePortienaam();
  afx_msg void        OnEnChangePorties();
  afx_msg void        OnEnChangeUnits();
  afx_msg void        OnNMDblclkItemlist(NMHDR *pNMHDR, LRESULT *pResult);
  afx_msg void        OnBnClickedVrijeportieCheck();
  afx_msg void        OnCbnSelchangeBrand();
  afx_msg void        OnBnClickedCheckFavourites();

  VMState *           CreateState(WW::VMDefinitie & aDefinitie);
  void                SetState(VMState * aState);

private:
  friend class        VMState;

  void                UpdateItemFilter();

  CategoryComboBox    mCategorieBox;
  BrandComboBox       mMerkBox;
  CStringEdit         mNaam;
  // Food items to pick from
  VMDefinitiesList    mItemList;
  // The number of porties
  CDoubleEdit         mPorties;
  // The number of units
  CDoubleEdit         mUnits;
  PortieComboBox      mPortieNaam;
  CStringEdit         mUnitNaam;
  CDoubleEdit         mPoints;
  CButton             mVrijePortieCheck;

  WW::Model &         mModel;
  WW::Voedingsmiddel *
                      mFood;
  WW::VMDefinitie *
                      mDefinitie;

  bool                mUpdating;
  bool                mUpdatingFilter;

  VMState *           mState;
};


class VMState
{
public:
                            VMState(CFindVoedingsmiddel &         aDialog,
                                    WW::VMDefinitie & aDefinitie,
                                    WW::Model &                   aModel)
                                    : mDialog   (aDialog),
                                      mDefinitie(aDefinitie),
                                      mModel    (aModel)
                            {}

  virtual void              Initialize() = 0;
  virtual void              OnCheckFreePortion() = 0;

  void                      UpdateFreeStateValues();
  void                      UpdatePortionValues(const WW::Portie & aPortie);

protected:
  CFindVoedingsmiddel &     GetDialog()           { return mDialog; }
  // The number of porties
  CDoubleEdit &             GetPorties()          { return mDialog.mPorties; }
  // The number of units
  CDoubleEdit &             GetUnits()            { return mDialog.mUnits; }
  CStringEdit &             GetUnitNaam()         { return mDialog.mUnitNaam; }

  PortieComboBox &          GetPortieBox()        { return mDialog.mPortieNaam; }
  CDoubleEdit &             GetPoints()           { return mDialog.mPoints; }
  CButton &                 GetVrijePortieCheck() { return mDialog.mVrijePortieCheck; }

  WW::VMDefinitie &
                            GetDefinitie()        { return mDefinitie; }
  const WW::Model &         GetModel() const      { return mModel; }

private:
  CFindVoedingsmiddel &     mDialog;
  WW::VMDefinitie &
                            mDefinitie;
  WW::Model &               mModel;
};


class VMNoPortionsState : public VMState
{
public:
                            VMNoPortionsState(CFindVoedingsmiddel &         aDialog,
                                              WW::VMDefinitie & aDefinitie,
                                              WW::Model &                   aModel)
                            : VMState(aDialog, aDefinitie, aModel) {}

  virtual void              Initialize();
  virtual void              OnCheckFreePortion();
};


class VMFreePortionState : public VMState
{
public:
                            VMFreePortionState(CFindVoedingsmiddel &         aDialog,
                                               WW::VMDefinitie & aDefinitie,
                                               WW::Model &                   aModel)
                            : VMState(aDialog, aDefinitie, aModel) {}

  virtual void              Initialize();
  virtual void              OnCheckFreePortion();
};


class VMStandardPortionsState : public VMState
{
public:
                            VMStandardPortionsState(CFindVoedingsmiddel &         aDialog,
                                                    WW::VMDefinitie & aDefinitie,
                                                    WW::Model &                   aModel)
                            : VMState(aDialog, aDefinitie, aModel) {}

  virtual void              Initialize();
  virtual void              OnCheckFreePortion();
};


class VMBothState : public VMState
{
public:
                            VMBothState(CFindVoedingsmiddel &         aDialog,
                                        WW::VMDefinitie & aDefinitie,
                                        WW::Model &                   aModel)
                            : VMState(aDialog, aDefinitie, aModel) {}

  virtual void              Initialize();
  virtual void              OnCheckFreePortion();
};
