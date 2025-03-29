#pragma once

#include "bonuslist.h"
#include "resource.h"


// CEditBonuses dialog

namespace weight {
class BonusPointsMap;
}

class CEditBonuses : public CDialog
{
	DECLARE_DYNAMIC(CEditBonuses)

public:
	CEditBonuses(std::shared_ptr<weight::BonusPointsMap> bonusPoints, const std::list<weight::Bonus> & aBonuses, double aWeight, CWnd* pParent = NULL);   // standard constructor
	virtual ~CEditBonuses();

// Dialog Data
	enum { IDD = IDD_BONUSLIST };

  const std::list<weight::Bonus> &  GetBonuses() const { return mBonuses; }

protected:
	virtual void                  DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

  BOOL                          OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnBnClickedCancel();
  afx_msg void OnBnClickedAdd();
  afx_msg void OnBnClickedEdit();
  afx_msg void OnBnClickedDelete();
  afx_msg void OnNMDblclkBonuslistjbj(NMHDR* pNMHDR, LRESULT* pResult);

private:
  void                  EditBonus();

  double mWeight;
  std::shared_ptr<weight::BonusPointsMap> m_bonusPointsMap;
  std::list<weight::Bonus> mBonuses;
  BonusList mBonusList;
};
