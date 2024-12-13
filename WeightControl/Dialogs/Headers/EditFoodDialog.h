#pragma once

#include "controls/doubleedit.h"
#include "controls/stringedit.h"
#include "model/PointsCalculator.h"

#include "portiecombobox.h"
#include "resource.h"

#include "afxwin.h"


namespace weight
{
class Lot;
class Model;
class PointsCalculator;
class Portie;
class Voedingsmiddel;

}

// EditFoodDialog dialog
class EditFoodDialog: public CDialog
{
    DECLARE_DYNAMIC(EditFoodDialog)

public:
    EditFoodDialog(weight::Voedingsmiddel& aVoedingsmiddel,
                   weight::FoodParameters& parameters,
                   std::shared_ptr<weight::PointsCalculator> calculator,
                   double pointsPer100Units,
                   const std::vector<std::unique_ptr<weight::Portie>>& porties,
                   CWnd* pParent = NULL);

    virtual ~EditFoodDialog() override;

    // Dialog Data
    enum { IDD = IDD_EDIT_VOEDINGSMIDDEL };

protected:
    virtual void                  DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    DECLARE_MESSAGE_MAP()

    BOOL                          OnInitDialog();

    afx_msg void                  OnCbnSelchangePortienaam();
    afx_msg void                  OnEnChangeAantalPorties();
    afx_msg void                  OnEnChangeAantalUnits();
    afx_msg void                  OnBnClickedOk();

private:
    weight::Voedingsmiddel& mVoedingsmiddel;
    weight::FoodParameters m_parameters;
    std::shared_ptr<weight::PointsCalculator> m_calculator;
    double m_pointsPer100Units;
    const std::vector<std::unique_ptr<weight::Portie>>& m_porties;

    CStringEdit                   mNaam;
    CDoubleEdit                   mAantalPorties;
    CDoubleEdit                   mAantalEenheden;
    CDoubleEdit                   mPunten;
    PortieComboBox                mPortie;

    bool                          mUpdating;
};
