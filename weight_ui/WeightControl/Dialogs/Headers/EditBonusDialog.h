#pragma once


#include "model/Bonus.h"
#include "model/IDay.h"
#include "controls/doubleedit.h"
#include "controls/intedit.h"

// EditBonusDialog dialog
namespace weight { class BonusPointsMap; }

class EditBonusDialog: public CDialog
{
    DECLARE_DYNAMIC(EditBonusDialog)

public:
    EditBonusDialog(const weight::BonusPointsMap& aMap, double aWeight, CWnd* pParent = NULL);
    EditBonusDialog(const weight::BonusPointsMap& aMap, double aWeight, const weight::Bonus& aBonus, CWnd* pParent = NULL);

    virtual ~EditBonusDialog();

    // Dialog Data
    enum { IDD = IDD_EDIT_BONUS };

    BOOL          OnInitDialog();

    afx_msg void OnBnClickedRadioLow();
    afx_msg void OnBnClickedRadioMedium();
    afx_msg void OnBnClickedRadioHigh();
    afx_msg void OnEnChangeGewicht();

    const weight::Bonus& GetBonus() const { return mBonus; }

protected:
    virtual void        DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    DECLARE_MESSAGE_MAP()

private:
    weight::Bonus       mBonus;
    double              mWeight;
    const weight::BonusPointsMap& mBonusMap;
    CDoubleEdit         mWeightEdit;
    CIntEdit            mDurationEdit;
    CIntEdit            mPointsEdit;

public:
    afx_msg void OnEnChangeDuur();
};
