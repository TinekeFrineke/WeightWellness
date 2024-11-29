#pragma once
#include "bonuslist.h"


// CEditBonuses dialog

namespace weight { class Model; }

class CEditBonuses : public CDialog
{
	DECLARE_DYNAMIC(CEditBonuses)

public:
	CEditBonuses(weight::Model & aModel, const std::list<weight::Bonus> & aBonuses, double aWeight, CWnd* pParent = NULL);   // standard constructor
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

private:
  void                  EditBonus();

  weight::Model &           mModel;
  double                mWeight;
  std::list<weight::Bonus>  mBonuses;
  BonusList             mBonusList;
public:
  afx_msg void OnNMDblclkBonuslistjbj(NMHDR *pNMHDR, LRESULT *pResult);
};
