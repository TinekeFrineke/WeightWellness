// FindVoedingsmiddel.cpp : implementation file
//

#include "stdafx.h"
#include ".\findrecept.h"

#include <assert.h>
#include "WeightControl.h"
#include "model/Day.h"
#include "model/Portie.h"
#include "model/Recept.h"
#include "model/ReceptDefinitie.h"

// CFindRecept dialog

IMPLEMENT_DYNAMIC(CFindRecept, CDialog)
CFindRecept::CFindRecept(WW::Model& aModel,
                         WW::ReceptDefinitie* aDefinitie,
                         CWnd* pParent /*=nullptr*/)
    : CDialog(CFindRecept::IDD, pParent),
    mItemList(aModel),
    mModel(aModel),
    mDefinitie(aDefinitie),
    mUpdating(false),
    mUpdatingFilter(false)
{
}

CFindRecept::~CFindRecept()
{
}

void CFindRecept::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_NAAM, mNaam);
    DDX_Control(pDX, IDC_ITEMLIST, mItemList);
    DDX_Control(pDX, IDC_PORTIES, mPorties);
    DDX_Control(pDX, IDC_POINTS, mPoints);
}


BEGIN_MESSAGE_MAP(CFindRecept, CDialog)
    ON_BN_CLICKED(IDOK, OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
    ON_EN_CHANGE(IDC_NAAM, OnEnChangeNaam)
    ON_NOTIFY(LVN_ITEMCHANGED, IDC_ITEMLIST, OnLvnItemchangedItemlist)
    ON_EN_CHANGE(IDC_PORTIES, OnEnChangePorties)
    ON_NOTIFY(NM_DBLCLK, IDC_ITEMLIST, OnNMDblclkItemlist)
END_MESSAGE_MAP()


void CFindRecept::UpdateItemFilter()
{
    mItemList.SetFilter(ReceptDefinitiesFilter(mNaam.GetValue()));
    mItemList.View(mModel.GetReceptDefs());
}


// CFindRecept message handlers

BOOL CFindRecept::OnInitDialog()
{
    if (CDialog::OnInitDialog() == FALSE)
        return FALSE;

    mItemList.Initialize();
    mItemList.View(mModel.GetReceptDefs());

    mPorties.SetValue(1);
    mPoints.SetValue(0);

    return TRUE;
}


void CFindRecept::OnBnClickedOk()
{
    ReceptDefinitiesListItem* item = mItemList.GetSelectedItem();
    if (item == nullptr || item->GetItem() == nullptr)
    {
        ::MessageBox(m_hWnd, _T("Pick a valid item"), _T("ERROR"), MB_OK);
        return;
    }

    if (mPorties.GetValue() <= 0)
    {
        ::MessageBox(m_hWnd, _T("Set a valid portion"), _T("ERROR"), MB_OK);
        return;
    }

    WW::ReceptDefinitie* definitie = item->GetItem();
    mRecept = std::make_unique<WW::Recept>(definitie->GetName());
    mRecept->SetNumberOfPortions(mPorties.GetValue());
    mRecept->SetPointsPerPortion(definitie->GetPointsPerPortion());

    OnOK();
}

void CFindRecept::OnBnClickedCancel()
{
    OnCancel();
}


void CFindRecept::OnEnChangeNaam()
{
    if (!mUpdatingFilter)
        UpdateItemFilter();
}


void CFindRecept::OnLvnItemchangedItemlist(NMHDR* pNMHDR, LRESULT* pResult)
{
    (void)pNMHDR;
    *pResult = 0;

    ReceptDefinitiesListItem* lvitem = mItemList.GetSelectedItem();
    if (lvitem == nullptr)
        return;

    mUpdatingFilter = true;

    mDefinitie = lvitem->GetItem();
    assert(mDefinitie != nullptr);
    mPoints.SetValue(mDefinitie->GetPointsPerPortion() * mPorties.GetValue());

    mUpdatingFilter = false;
}


void CFindRecept::OnEnChangePorties()
{
    if (mDefinitie == nullptr)
        return;

    if (!mUpdating)
    {
        mUpdating = true;
        mPoints.SetValue(mDefinitie->GetPointsPerPortion() * mPorties.GetValue());
        mUpdating = false;
    }
}


void CFindRecept::OnNMDblclkItemlist(NMHDR* pNMHDR, LRESULT* pResult)
{
    (void)pNMHDR;

    ReceptDefinitiesListItem* item = mItemList.GetSelectedItem();
    if (item == nullptr || item->GetItem() == nullptr)
    {
        ::MessageBox(m_hWnd, _T("Pick a valid item"), _T("ERROR"), MB_OK);
        return;
    }

    WW::ReceptDefinitie* definitie = item->GetItem();
    mRecept = std::make_unique<WW::Recept>(definitie->GetName());
    mRecept->SetNumberOfPortions(mPorties.GetValue());
    mRecept->SetPointsPerPortion(definitie->GetPointsPerPortion());

    OnOK();

    *pResult = 0;
}
