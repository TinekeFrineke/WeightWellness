#pragma once
#include "stringedit.h"
#include "categorycombobox.h"
#include "unitcombobox.h"
#include "doubleedit.h"
#include "portielist.h"
#include "afxwin.h"
#include "portiecombobox.h"


// CEditFoodDefDialogPP dialog

class CEditFoodDefDialogPP : public CDialog
{
	DECLARE_DYNAMIC(CEditFoodDefDialogPP)

public:
	                  CEditFoodDefDialogPP(WW::Model & aModel,
                                         WW::VMDefinitie * aDefinitie,
                                         CWnd* pParent = NULL);   // standard constructor
	virtual           ~CEditFoodDefDialogPP();

// Dialog Data
	enum { IDD = IDD_EDITFOOD_DIALOG_PP };

  BOOL              OnInitDialog();

  afx_msg void      OnBnClickedAdd();
  afx_msg void      OnBnClickedEdit();
  afx_msg void      OnBnClickedDelete();
  afx_msg void      OnBnClickedOk();
  afx_msg void      OnBnClickedVrijeportiecheck();
  afx_msg void      OnEnChangeEiwittenPer100();
  afx_msg void      OnEnChangeKoolhydratenPer100();
  afx_msg void      OnEnChangeVetper100();
  afx_msg void      OnEnChangeVezelsPer100();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

private:
  bool              CreateFood();
  void              UpdateSterrePortieBox();

  // The food's name
  CStringEdit       mName;
  CategoryComboBox  mCategorie;
  UnitComboBox      mUnitBox;
  CDoubleEdit       mEiwitPer100Edit;
  CDoubleEdit       mKoolhydratenPer100;
  CDoubleEdit       mVetPer100;
  CDoubleEdit       mVezelsPer100;
  PortieList        mPortieListView;
  CButton           mVrijePortieCheck;
  CStatic           mVrijePuntenStatic;
  CDoubleEdit       mVrijePunten;
  PortieComboBox    mSterrePortieBox;

  WW::VMDefinitie * mDefinitie;
  WW::Model &       mModel;
};
