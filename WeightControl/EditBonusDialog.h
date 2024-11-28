#pragma once


#include "model/Day.h"
#include "doubleedit.h"
#include "intedit.h"

// EditBonusDialog dialog
namespace weight { class BonusPointsMap; }

class EditBonusDialog : public CDialog
{
	DECLARE_DYNAMIC(EditBonusDialog)

public:
  EditBonusDialog(const weight::BonusPointsMap & aMap, double aWeight, CWnd* pParent = NULL);   // standard constructor
  EditBonusDialog(const weight::BonusPointsMap & aMap, double aWeight, const weight::Bonus & aBonus, CWnd* pParent = NULL);   // standard constructor

  virtual ~EditBonusDialog();

// Dialog Data
	enum { IDD = IDD_EDIT_BONUS };

  BOOL          OnInitDialog();

  afx_msg void OnBnClickedRadioLow();
  afx_msg void OnBnClickedRadioMedium();
  afx_msg void OnBnClickedRadioHigh();
  afx_msg void OnEnChangeGewicht();

  const weight::Bonus &   GetBonus() const { return mBonus; }

protected:
	virtual void        DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

private:
  weight::Bonus           mBonus;
  double              mWeight;
  const weight::BonusPointsMap &
                      mBonusMap;
  CDoubleEdit         mWeightEdit;
  CIntEdit            mDurationEdit;
  CIntEdit            mPointsEdit;

public:
  afx_msg void OnEnChangeDuur();
};
