// PointsPerDay.cpp : implementation file
//

#include "stdafx.h"
#include "WeightControl.h"
#include "PointsPerDay.h"
#include ".\pointsperday.h"


// CPointsPerDay dialog

IMPLEMENT_DYNAMIC(CPointsPerDay, CDialog)
CPointsPerDay::CPointsPerDay(CWnd* pParent /*=NULL*/)
	: CDialog(CPointsPerDay::IDD, pParent)
{
}

CPointsPerDay::~CPointsPerDay()
{
}

void CPointsPerDay::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  DDX_Control(pDX, IDC_LENGTE, mLength);
  DDX_Control(pDX, IDC_GEBOORTEDATUM, mGeboorteDatum);
  DDX_Control(pDX, IDC_STARTGEWICHT, mStartGewicht);
  DDX_Control(pDX, IDC_STREEFGEWICHT, mStreefGewicht);
  DDX_Control(pDX, IDC_PUNTEN, mPunten);
}


BEGIN_MESSAGE_MAP(CPointsPerDay, CDialog)
  ON_BN_CLICKED(IDC_CALCULATE, OnBnClickedCalculate)
END_MESSAGE_MAP()


// CPointsPerDay message handlers
void CPointsPerDay::OnBnClickedCalculate()
{
  CString sweight;
  mStartGewicht.GetWindowText(sweight);
  double weight = _tstof(sweight);
  CString slength;
  mLength.GetWindowText(slength);
  double length = _tstof(slength) / 100;
  //float bmi = je gewicht in kg / het kwadraat van je lengte in cm
  double bmi = weight / (length * length);
  (void)bmi;
}
