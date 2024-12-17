#pragma once

#include "afxwin.h"
#include <memory>

#include "controls/doubleedit.h"
#include "controls/StringEdit.h"

#include "resource.h"
#include "ComboBox.h"
#include "VMDefinitiesList.h"
#include "PortieComboBox.h"
#include "BrandComboBox.h"


namespace weight
{
class Day;
class ILotFactory;
class Voedingsmiddel;
}

// CFindVoedingsmiddel dialog

class CFindVoedingsmiddel: public CDialog
{
    DECLARE_DYNAMIC(CFindVoedingsmiddel)

public:
    CFindVoedingsmiddel(weight::Model& aModel,
                        std::unique_ptr<weight::ILotFactory> lotFactory,
                        CWnd* pParent = nullptr);   // standard constructor
    virtual ~CFindVoedingsmiddel();

    // Dialog Data
    enum { IDD = IDD_FIND_VOEDINGSMIDDEL };

    std::unique_ptr<weight::Voedingsmiddel> ExtractVoedingsMiddel();

protected:
    virtual void        DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    DECLARE_MESSAGE_MAP()

    BOOL OnInitDialog();

    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedCancel();
    afx_msg void OnEnChangeNaam();
    afx_msg void OnCbnSelchangeCombo1();
    afx_msg void OnLvnItemchangedItemlist(NMHDR* pNMHDR, LRESULT* pResult);
    afx_msg void OnCbnSelchangePortienaam();
    afx_msg void OnEnChangePorties();
    afx_msg void OnEnChangeUnits();
    afx_msg void OnNMDblclkItemlist(NMHDR* pNMHDR, LRESULT* pResult);
    afx_msg void OnCbnSelchangeBrand();
    afx_msg void OnBnClickedCheckFavourites();

private:
    friend class        VMState;

    void                UpdateItemFilter();

    weight::ComboBox mCategorieBox;
    BrandComboBox mMerkBox;
    CStringEdit mNaam;
    // Food items to pick from
    VMDefinitiesList    mItemList;
    // The number of porties
    CDoubleEdit         mPorties;
    // The number of units
    CDoubleEdit         mUnits;
    PortieComboBox      mPortieNaam;
    CStringEdit         mUnitNaam;
    CDoubleEdit         mPoints;

    std::unique_ptr<weight::Voedingsmiddel> mFood;
    weight::VMDefinitie* mDefinitie;

    bool                mUpdating;
    bool                mUpdatingFilter;

    std::unique_ptr<weight::ILotFactory> m_lotFactory;
};
