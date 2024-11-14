#pragma once


#include "WW/WWModel/Day.h"
#include "doubleedit.h"
#include "intedit.h"

// EditBonusDialog dialog
namespace WW { class BonusPointsMap; }

class EditBonusDialog : public CDialog
{
	DECLARE_DYNAMIC(EditBonusDialog)

public:
  EditBonusDialog(const WW::BonusPointsMap & aMap, double aWeight, CWnd* pParent = NULL);   // standard constructor
  EditBonusDialog(const WW::BonusPointsMap & aMap, double aWeight, const WW::Bonus & aBonus, CWnd* pParent = NULL);   // standard constructor

  virtual ~EditBonusDialog();

// Dialog Data
	enum { IDD = IDD_EDIT_BONUS };

  BOOL          OnInitDialog();

  afx_msg void OnBnClickedRadioLow();
  afx_msg void OnBnClickedRadioMedium();
  afx_msg void OnBnClickedRadioHigh();
  afx_msg void OnEnChangeGewicht();

  const WW::Bonus &   GetBonus() const { return mBonus; }

protected:
	virtual void        DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

private:
  WW::Bonus           mBonus;
  double              mWeight;
  const WW::BonusPointsMap &
                      mBonusMap;
  CDoubleEdit         mWeightEdit;
  CIntEdit            mDurationEdit;
  CIntEdit            mPointsEdit;

public:
  afx_msg void OnEnChangeDuur();
};
