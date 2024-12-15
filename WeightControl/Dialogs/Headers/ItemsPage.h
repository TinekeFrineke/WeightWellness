#pragma once

#include "model/Model.h"
#include "afxcmn.h"

#include "controls/StringEdit.h"
#include "controls/TabPage.h"

#include "VMDefinitiesList.h"
#include "ComboBox.h"
#include "BrandComboBox.h"
#include "resource.h"

// CItemsPage dialog

class CItemsPage: public CDialog, public TabPage
{
    DECLARE_DYNAMIC(CItemsPage)

public:
    CItemsPage(weight::Model& aModel, CWnd* pParent = NULL);   // standard constructor
    virtual ~CItemsPage();

    // Dialog Data
    enum { IDD = IDD_ITEMS_PAGE };

    virtual CDialog* GetDialog() { return this; }

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    virtual BOOL OnInitDialog() override;
    virtual void OnCancel() override;
    virtual void OnOK() override {}
    virtual void OnShowWindow(BOOL bShow, UINT nStatus);

    DECLARE_MESSAGE_MAP()

private:
    void                EditItem();
    void                UpdateItemFilter();

    afx_msg void        OnBnClickedAdd();
    afx_msg void        OnBnClickedEdit();
    afx_msg void        OnBnClickedDelete();
    afx_msg void        OnNMDblclkItemlist(NMHDR* pNMHDR, LRESULT* pResult);
    afx_msg void        OnEnChangeNaam();
    afx_msg void        OnCbnSelchangeCombo1();
    afx_msg void        OnCbnSelchangeBrand();

    CStringEdit         mNaam;
    weight::ComboBox    mCategory;
    BrandComboBox       mMerk;

    weight::Model& mModel;
    VMDefinitiesList    mItemsList;

    bool                mUpdatingFilter;
public:
    afx_msg void OnCbnEditchangeCombo1();
    afx_msg void OnBnClickedCheckFavourites();
};
