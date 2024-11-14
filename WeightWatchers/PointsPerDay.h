#pragma once
#include "afxwin.h"
#include "afxdtctl.h"


// CPointsPerDay dialog

class CPointsPerDay : public CDialog
{
	DECLARE_DYNAMIC(CPointsPerDay)

public:
	CPointsPerDay(CWnd* pParent = NULL);   // standard constructor
	virtual ~CPointsPerDay();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
private:
  CEdit mLength;
  CDateTimeCtrl mGeboorteDatum;
  CEdit mStartGewicht;
public:
  CEdit mStreefGewicht;
  CEdit mPunten;
  afx_msg void OnBnClickedCalculate();
};
