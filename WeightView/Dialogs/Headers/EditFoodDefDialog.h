#pragma once

#include "model/Model.h"
#include "afxwin.h"
#include "afxcmn.h"

#include "controls/DoubleEdit.h"
#include "controls/IntEdit.h"
#include "controls/StringEdit.h"

#include "PortieList.h"
#include "ComboBox.h"
#include "resource.h" 
#include "PortieComboBox.h"
#include "BrandComboBox.h"

// CEditFoodDefDialog dialog

namespace weight
{
class FixedVMDef;
class IRepository;
class VMDefinitie;
}

class CEditFoodDefDialog: public CDialog
{
    DECLARE_DYNAMIC(CEditFoodDefDialog)

public:
    CEditFoodDefDialog(std::shared_ptr<weight::IFoodDefinitionRepository> foodDefinitions,
                       std::shared_ptr<weight::IRepository> units,
                       std::shared_ptr<weight::IRepository> categories,
                       std::shared_ptr<weight::IRepository> brands,
                       weight::VMDefinitie& aDefinitie,
                       bool newDefinition,
                       std::shared_ptr<weight::PointsCalculator> calculator,
                       CWnd* pParent = NULL);   // standard constructor
    virtual ~CEditFoodDefDialog();

    // Dialog Data
    enum { IDD = IDD_EDITFOOD_DIALOG };

    BOOL                      OnInitDialog();

protected:
    virtual void              DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    DECLARE_MESSAGE_MAP()

    afx_msg void OnBnClickedAdd();
    afx_msg void OnBnClickedEdit();
    afx_msg void OnBnClickedDelete();
    afx_msg void OnBnClickedOk();
    afx_msg void OnEnChangeKcalper100();
    afx_msg void OnEnChangeVetper100();
    afx_msg void OnEnChangeEiwittenPer100();
    afx_msg void OnEnChangeKoolhydratenPer100();
    afx_msg void OnEnChangeVezelsPer100();
    afx_msg void OnBnClickedCancel();
    afx_msg void OnEnChangeEenheden();
    afx_msg void OnCbnSelchangeUnit();
    afx_msg void OnCbnEditchangeUnit();
    afx_msg void OnBnClickedCheckFavourite();
    afx_msg void OnNMDblclkPortie(NMHDR* pNMHDR, LRESULT* pResult);

private:
    void                      FillStatics();

    /// Processes the entered definition data into the definition(s)
    bool                      FinalizeData();
    bool                      FinalizeCalculatedData();
    bool                      CreateFood();
    bool                      CreateCommonFoodParts();

    CStatic                   mKCalPer100Static;
    CStatic                   mEiwitPer100Static;
    CStatic                   mKoolhydratenPer100Static;
    CStatic                   mVetPer100Static;
    CStatic                   mVezelsPer100Static;
    CStatic                   mEenhedenStatic;

    CStringEdit               mName;
    weight::ComboBox          mCategorie;
    weight::ComboBox          mUnitBox;

    CDoubleEdit               mKCalPer100;
    CDoubleEdit               mVetPer100;
    CDoubleEdit               mEiwitPer100;
    CDoubleEdit               mKoolhydratenPer100;
    CDoubleEdit               mVezelsPer100;
    // Contains and owns portions, initially a copy of the original portions.
    // It serves as the owner of the changed definitions portions.
    PortieList                mPortieListView;
    CIntEdit                  mEenheden;
    BrandComboBox             mMerk;

    weight::VMDefinitie& m_definition;
    // Bit of a hack... whether name should be read only
    bool m_newDefinition;
    std::shared_ptr<weight::IRepository> m_units;
    std::shared_ptr<weight::IRepository> m_categories;
    std::shared_ptr<weight::IRepository> m_brands;
    std::shared_ptr<weight::IFoodDefinitionRepository> m_foodDefinitions;

    std::shared_ptr<weight::PointsCalculator> m_calculator;
};
