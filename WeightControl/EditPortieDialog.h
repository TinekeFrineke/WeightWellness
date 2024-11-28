#pragma once


#include "model/Model.h"
#include "model/Portie.h"
#include "afxwin.h"

#include "DoubleEdit.h"
#include "IntEdit.h"
#include "PortieComboBox.h"
#include "StringEdit.h"

// CEditPortieDialog dialog

class CEditPortieDialog : public CDialog
{
	DECLARE_DYNAMIC(CEditPortieDialog)

public:
                    CEditPortieDialog(weight::Model & aModel, weight::VMDefinitie & aDefinitie,
                                      weight::Portie * aPortie,
                                      const std::vector<std::unique_ptr<weight::Portie>> & aPorties,
                                      CWnd* pParent = NULL);   // standard constructor
	virtual           ~CEditPortieDialog();

  weight::Portie *      GetPortie() { return mPortie; }

// Dialog Data
	enum { IDD = IDD_EDITPORTIE_DIALOG };

protected:
	virtual void      DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

  afx_msg void      OnEnChangeUnitamount();
  afx_msg void      OnEnChangeAmount();
  afx_msg void      OnCbnSelchangeOmschrijving();
  afx_msg void      OnBnClickedOk();

private:
  BOOL              OnInitDialog();

  void              UpdatePoints();

  weight::Model &       mModel;
  weight::VMDefinitie & mDefinitie;
  weight::Portie *      mPortie;
  bool              mMyPortion;

  std::vector<weight::PortieNaam>
                    mPortienames;

  CDoubleEdit       mPoints;
  CStringEdit       mVoedingsMiddel;
  CDoubleEdit       mUnitAmount;
  CStatic           mUnitStatic;
  PortieComboBox    mNaam;
};
