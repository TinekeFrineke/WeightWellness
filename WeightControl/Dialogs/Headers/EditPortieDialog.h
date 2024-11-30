#pragma once


#include "afxwin.h"

#include "model/Model.h"
#include "model/Portie.h"

#include "controls/DoubleEdit.h"
#include "controls/IntEdit.h"
#include "controls/StringEdit.h"

#include "PortieComboBox.h"
#include "resource.h"

// CEditPortieDialog dialog

class CEditPortieDialog: public CDialog
{
    DECLARE_DYNAMIC(CEditPortieDialog)

public:
    CEditPortieDialog(weight::VMDefinitie& aDefinitie,
                      weight::Portie* aPortie,
                      const std::vector<std::unique_ptr<weight::Portie>>& aPorties,
                      CWnd* pParent = nullptr);   // standard constructor
    ~CEditPortieDialog() override;

    weight::Portie* GetPortie() { return mPortie; }

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

    weight::VMDefinitie& mDefinitie;
    weight::Portie* mPortie;
    bool              mMyPortion;

    std::vector<std::wstring> mPortienames;

    CDoubleEdit       mPoints;
    CStringEdit       mVoedingsMiddel;
    CDoubleEdit       mUnitAmount;
    CStatic           mUnitStatic;
    PortieComboBox    mNaam;
};
