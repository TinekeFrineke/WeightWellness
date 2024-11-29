#pragma once

#include <memory>

#include "resource.h"
#include "categorycombobox.h"
#include "stringedit.h"
#include "vmdefinitieslist.h"
#include "doubleedit.h"
#include "portiecombobox.h"
#include "afxwin.h"
#include "brandcombobox.h"


class VMState;

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
                        weight::VMDefinitie* aDefinitie,
                        std::unique_ptr<weight::ILotFactory> lotFactory,
                        CWnd* pParent = nullptr);   // standard constructor
    virtual ~CFindVoedingsmiddel();

    // Dialog Data
    enum { IDD = IDD_FIND_VOEDINGSMIDDEL };

    std::unique_ptr<weight::Voedingsmiddel> ExtractVoedingsMiddel();

protected:
    virtual void        DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    DECLARE_MESSAGE_MAP()

    BOOL                OnInitDialog();

    afx_msg void        OnBnClickedOk();
    afx_msg void        OnBnClickedCancel();
    afx_msg void        OnEnChangeNaam();
    afx_msg void        OnCbnSelchangeCombo1();
    afx_msg void        OnLvnItemchangedItemlist(NMHDR* pNMHDR, LRESULT* pResult);
    afx_msg void        OnCbnSelchangePortienaam();
    afx_msg void        OnEnChangePorties();
    afx_msg void        OnEnChangeUnits();
    afx_msg void        OnNMDblclkItemlist(NMHDR* pNMHDR, LRESULT* pResult);
    afx_msg void        OnCbnSelchangeBrand();
    afx_msg void        OnBnClickedCheckFavourites();

    std::unique_ptr<VMState> CreateState(weight::VMDefinitie& aDefinitie);
    void SetState(std::unique_ptr<VMState> aState);

private:
    friend class        VMState;

    void                UpdateItemFilter();

    CategoryComboBox    mCategorieBox;
    BrandComboBox       mMerkBox;
    CStringEdit         mNaam;
    // Food items to pick from
    VMDefinitiesList    mItemList;
    // The number of porties
    CDoubleEdit         mPorties;
    // The number of units
    CDoubleEdit         mUnits;
    PortieComboBox      mPortieNaam;
    CStringEdit         mUnitNaam;
    CDoubleEdit         mPoints;

    weight::Model& mModel;
    std::unique_ptr<weight::Voedingsmiddel> mFood;
    weight::VMDefinitie* mDefinitie;

    bool                mUpdating;
    bool                mUpdatingFilter;

    std::unique_ptr<VMState> mState;
    std::unique_ptr<weight::ILotFactory> m_lotFactory;
};


class VMState
{
public:
    VMState(CFindVoedingsmiddel& aDialog,
            weight::VMDefinitie& aDefinitie,
            weight::Model& aModel)
        : mDialog(aDialog),
        mDefinitie(aDefinitie),
        mModel(aModel)
    {}

    virtual void              Initialize() = 0;

    void                      UpdatePortionValues(const weight::Portie& aPortie);

protected:
    CFindVoedingsmiddel& GetDialog() { return mDialog; }
    // The number of porties
    CDoubleEdit& GetPorties() { return mDialog.mPorties; }
    // The number of units
    CDoubleEdit& GetUnits() { return mDialog.mUnits; }
    CStringEdit& GetUnitNaam() { return mDialog.mUnitNaam; }

    PortieComboBox& GetPortieBox() { return mDialog.mPortieNaam; }
    CDoubleEdit& GetPoints() { return mDialog.mPoints; }

    weight::VMDefinitie& GetDefinitie() { return mDefinitie; }
    const weight::Model& GetModel() const { return mModel; }

private:
    CFindVoedingsmiddel& mDialog;
    weight::VMDefinitie& mDefinitie;
    weight::Model& mModel;
};


class VMNoPortionsState: public VMState
{
public:
    VMNoPortionsState(CFindVoedingsmiddel& aDialog,
                      weight::VMDefinitie& aDefinitie,
                      weight::Model& aModel)
        : VMState(aDialog, aDefinitie, aModel) {}

    virtual void              Initialize() override;
};


class VMStandardPortionsState: public VMState
{
public:
    VMStandardPortionsState(CFindVoedingsmiddel& aDialog,
                            weight::VMDefinitie& aDefinitie,
                            weight::Model& aModel)
        : VMState(aDialog, aDefinitie, aModel) {}

    void Initialize() override;
};