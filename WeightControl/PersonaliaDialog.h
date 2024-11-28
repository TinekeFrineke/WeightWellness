#pragma once
#include "afxwin.h"

#include "TabPage.h"

#include "StringEdit.h"
#include "intedit.h"
#include "doubleedit.h"

namespace weight { class Model; }

// CPersonaliaDialog dialog

class CPersonaliaDialog : public CDialog, public TabPage
{
	DECLARE_DYNAMIC(CPersonaliaDialog)

public:
  CPersonaliaDialog(weight::Model & aModel, CWnd* pParent = NULL);   // standard constructor
	virtual ~CPersonaliaDialog();

// Dialog Data
	enum { IDD = IDD_PERSONALIA_PAGE };

  virtual CDialog * GetDialog() { return this; }

  BOOL              OnInitDialog();

protected:
	virtual void      DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
  afx_msg void      OnBnClickedMannelijk();
  afx_msg void      OnBnClickedVrouwelijk();

	DECLARE_MESSAGE_MAP()

  virtual bool      CanExit(bool bLeaveApplication);
  virtual void      OnOK() {}
  virtual void      OnCancel();

private:
  enum GESLACHT { GS_Mannelijk, GS_Vrouwelijk };
  CStringEdit       mNaam;
  CStringEdit       mUsername;
  CButton           mButtonMannelijk;
  CButton           mButtonVrouwelijk;
  CDoubleEdit       mPuntenTotaal;
  CStatic           mWeekPuntenStatic;
  CDoubleEdit       mWeekPunten;
  CDoubleEdit       mStreefGewicht;
  CDoubleEdit       mStartWeight;
  CIntEdit          mLengte;
  CDoubleEdit       mCurrentWeight;

  weight::Model &       mModel;
  weight::Personalia *  mPersonalia;

  GESLACHT          mGeslacht;

public:
  afx_msg void      OnEnKillfocusNaam();
  afx_msg void      OnEnKillfocusUserNaam();
  afx_msg void      OnEnKillfocusEdit4();
  afx_msg void      OnEnKillfocusLengte();
  afx_msg void      OnEnKillfocusPuntentotaal();
  afx_msg void      OnEnChangeStartgewicht();
  afx_msg void      OnEnKillfocusStartgewicht();
  afx_msg void      OnEnKillfocusWeekpunten();
  afx_msg void      OnBnClickedRadioKcal();
  afx_msg void OnBnClickedCarbohydrates();
};
