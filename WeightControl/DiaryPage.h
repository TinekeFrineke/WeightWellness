#pragma once

#include "afxwin.h"
#include "afxcmn.h"
#include "afxdtctl.h"
#include "resource.h"

#include "model/Model.h"

#include "TabPage.h"
#include "DiaryItemList.h"
#include "doubleedit.h"
#include "stringedit.h"
#include "intedit.h"


// CDiaryPage dialog

class CDiaryPage : public CDialog, public TabPage
{
	DECLARE_DYNAMIC(CDiaryPage)

public:
                    CDiaryPage(weight::Model & aModel, CWnd* pParent = NULL);   // standard constructor
	virtual           ~CDiaryPage();

// Dialog Data
	enum              { IDD = IDD_DIARY_PAGE };

  virtual CDialog * GetDialog() { return this; }

protected:
	virtual void      DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

  BOOL              OnInitDialog();
  virtual void      OnCancel();
  virtual void      OnOK() {}

	DECLARE_MESSAGE_MAP()

  afx_msg void      OnDtnDatetimechangeDiarydate(NMHDR *pNMHDR, LRESULT *pResult);
  afx_msg void      OnBnClickedAddFood();
  afx_msg void      OnDeltaposSpinWeekEinde(NMHDR *pNMHDR, LRESULT *pResult);
  afx_msg void      OnEnChangeBonuspunten();
  afx_msg void      OnBnClickedDayMinus();
  afx_msg void      OnBnClickedDayPlus();
  afx_msg void      OnBnClickedAddRecept();
  afx_msg void      OnBnClickedAddGerecht();
  afx_msg void      OnBnClickedEdit();
  afx_msg void      OnBnClickedDelete();
  afx_msg void      OnEnChangeWeight();
  afx_msg void      OnBnClickedAddHandmatig();

private:
  void              EditItem(weight::Item & item);
  bool              ProcessDate(const Utils::Date & aDate);
  void              UpdatePointsLeft();

  CDiaryItemList mItemList;

  weight::Model& mModel;
  weight::Week* mWeek{};
  weight::Day* mDay{};

  CStringEdit mDate;
  CDoubleEdit mPunten;
  CStringEdit mStartOfWeek;
  CStringEdit mEndOfWeek;
  CDoubleEdit mBonusPoints;
  CDoubleEdit mCalculatedBonusPoints;
  CDoubleEdit mPointsLeft;
  CDoubleEdit mWeight;
  CDoubleEdit mTotaal;
  CStringEdit mStrategie;
  CDoubleEdit mWeekPunten;
  CStatic     mWeekpuntenStatic;

public:
  afx_msg void OnNMDblclkItemlist(NMHDR *pNMHDR, LRESULT *pResult);
  afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
private:
public:
  afx_msg void OnEnChangeWeekEinde();
private:
public:
  afx_msg void OnBnClickedAddbinus();
  afx_msg void OnBnClickedButton1();
  afx_msg void OnBnClickedAddbonus();
};
