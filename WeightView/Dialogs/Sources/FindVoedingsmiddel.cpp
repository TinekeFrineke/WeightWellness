// FindVoedingsmiddel.cpp : implementation file
//

#include "stdafx.h"
#include ".\findvoedingsmiddel.h"

#include <assert.h>

#include "model/Day.h"
#include "model/IFoodDefinitionRepository.h"
#include "model/IRepository.h"
#include "model/Model.h"
#include "model/NutritionalValue.h"
#include "model/Portie.h"
#include "model/Voedingsmiddel.h"
#include "model/VoedingsmiddelDefinitie.h"
#include "model/ILotFactory.h"

// CFindVoedingsmiddel dialog

IMPLEMENT_DYNAMIC(CFindVoedingsmiddel, CDialog)

BEGIN_MESSAGE_MAP(CFindVoedingsmiddel, CDialog)
    ON_BN_CLICKED(IDOK, OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
    ON_EN_CHANGE(IDC_NAAM, OnEnChangeNaam)
    ON_CBN_SELCHANGE(IDC_COMBO1, OnCbnSelchangeCombo1)
    ON_NOTIFY(LVN_ITEMCHANGED, IDC_ITEMLIST, OnLvnItemchangedItemlist)
    ON_CBN_SELCHANGE(IDC_PORTIENAAM, OnCbnSelchangePortienaam)
    ON_EN_CHANGE(IDC_PORTIES, OnEnChangePorties)
    ON_EN_CHANGE(IDC_UNITS, OnEnChangeUnits)
    ON_NOTIFY(NM_DBLCLK, IDC_ITEMLIST, OnNMDblclkItemlist)
    ON_CBN_SELCHANGE(IDC_BRAND, OnCbnSelchangeBrand)
    ON_BN_CLICKED(IDC_CHECK_FAVOURITES, OnBnClickedCheckFavourites)
END_MESSAGE_MAP()


CFindVoedingsmiddel::CFindVoedingsmiddel(weight::Model& aModel,
                                         std::unique_ptr<weight::ILotFactory> lotFactory,
                                         CWnd* pParent /*=nullptr*/)
    : CDialog(CFindVoedingsmiddel::IDD, pParent)
    , mItemList(aModel.GetFoodDefinitionRepository()->GetAll())
    , mCategorieBox(aModel.GetCategoryRepository()->Get())
    , mMerkBox(aModel.GetBrandRepository()->Get(), true)
    , mFood(nullptr)
    , m_lotFactory(std::move(lotFactory))
    , mDefinitie(nullptr)
    , mPortieNaam(_T(""))
    , mUpdating(false)
    , mUpdatingFilter(false)
{
}

CFindVoedingsmiddel::~CFindVoedingsmiddel() = default;


std::unique_ptr<weight::Voedingsmiddel> CFindVoedingsmiddel::ExtractVoedingsMiddel()
{
    return std::move(mFood);
}

void CFindVoedingsmiddel::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO1, mCategorieBox);
    DDX_Control(pDX, IDC_NAAM, mNaam);
    DDX_Control(pDX, IDC_ITEMLIST, mItemList);
    DDX_Control(pDX, IDC_PORTIES, mPorties);
    DDX_Control(pDX, IDC_UNITS, mUnits);
    DDX_Control(pDX, IDC_PORTIENAAM, mPortieNaam);
    DDX_Control(pDX, IDC_UNIT, mUnitNaam);
    DDX_Control(pDX, IDC_POINTS, mPoints);
    DDX_Control(pDX, IDC_BRAND, mMerkBox);
}


void CFindVoedingsmiddel::UpdateItemFilter()
{
    mItemList.SetFilter(VMDefinitiesFilter(mNaam.GetValue(),
                                           mCategorieBox.GetString(),
                                           mMerkBox.GetString()));
    mItemList.Fill();
}


// CFindVoedingsmiddel message handlers

BOOL CFindVoedingsmiddel::OnInitDialog()
{
    if (CDialog::OnInitDialog() == FALSE)
        return FALSE;

    mItemList.Initialize();
    mItemList.Fill();

    mPortieNaam.Initialize();
    mPortieNaam.EnableWindow(true);

    mCategorieBox.Initialize();
    mCategorieBox.Fill();
    mCategorieBox.SetText(_T(""));

    mMerkBox.Initialize();
    mMerkBox.Fill();
    mMerkBox.SetText(_T(""));

    return TRUE;
}


void CFindVoedingsmiddel::OnBnClickedOk()
{
    weight::Portie* portie = mPortieNaam.GetSelectedPortie();
    if (portie == nullptr)
    {
        ::MessageBox(m_hWnd, _T("Pick a valid portion"), _T("ERROR"), MB_OK);
        return;
    }

    auto definitie = mItemList.GetSelectedDefinition();
    if (definitie == nullptr)
        return;

    auto lot = m_lotFactory->Create(definitie->GetNutritionalValue().GetParameters(), *portie);
    assert(lot != nullptr);
    lot->SetNumberOfPortions(mPorties.GetValue());
    mFood = std::make_unique<weight::Voedingsmiddel>(std::move(lot), *definitie);

    OnOK();
}

void CFindVoedingsmiddel::OnBnClickedCancel()
{
    OnCancel();
}

void CFindVoedingsmiddel::OnEnChangeNaam()
{
    if (!mUpdatingFilter)
        UpdateItemFilter();
}

void CFindVoedingsmiddel::OnCbnSelchangeCombo1()
{
    if (!mUpdatingFilter)
        UpdateItemFilter();
}

void CFindVoedingsmiddel::OnLvnItemchangedItemlist(NMHDR* pNMHDR, LRESULT* pResult)
{
    (void)pNMHDR;
    *pResult = 0;

    auto definitie = mItemList.GetSelectedDefinition();
    if (definitie == nullptr)
        return;

    mDefinitie = definitie;

    mUpdatingFilter = true;

    mUnitNaam.SetValue(definitie->GetUnit());

    mPortieNaam.Fill(mDefinitie->GetPortieList());
    mPorties.SetValue(1);

    auto portie = mPortieNaam.GetSelectedPortie();
    if (portie != nullptr) {
        mUnits.SetValue(portie->GetUnits());
        mPortieNaam.SetString(portie->GetName());
    }

    mUpdatingFilter = false;
}

void CFindVoedingsmiddel::OnCbnSelchangePortienaam()
{
    weight::Portie* portie = mPortieNaam.GetSelectedPortie();
    if (portie != nullptr)
    {
        mUnits.SetValue(portie->GetUnits());
        mPorties.SetValue(1);

        if (mDefinitie != nullptr)
            mPoints.SetValue((mUnits.GetValue() * mDefinitie->GetPointsPer100Units()) / 100);
    }
}

void CFindVoedingsmiddel::OnEnChangePorties()
{
    if (!mUpdating)
    {
        mUpdating = true;

        weight::Portie* portie = mPortieNaam.GetSelectedPortie();
        if (portie != nullptr)
        {
            mUnits.SetValue(mPorties.GetValue() * portie->GetUnits());

            if (mDefinitie != nullptr)
                mPoints.SetValue((mUnits.GetValue() * mDefinitie->GetPointsPer100Units()) / 100);
        }

        mUpdating = false;
    }
}

void CFindVoedingsmiddel::OnEnChangeUnits()
{
    if (!mUpdating)
    {
        mUpdating = true;
        weight::Portie* portie = mPortieNaam.GetSelectedPortie();
        if (portie != nullptr)
        {
            mPorties.SetValue(mUnits.GetValue() / portie->GetUnits());

            if (mDefinitie != nullptr)
                mPoints.SetValue((mUnits.GetValue() * mDefinitie->GetPointsPer100Units()) / 100);
        }

        mUpdating = false;
    }
}


void CFindVoedingsmiddel::OnNMDblclkItemlist(NMHDR* pNMHDR, LRESULT* pResult)
{
    (void)pNMHDR;

    auto item = mItemList.GetSelectedDefinition();
    if (item == nullptr)
        return;

    mDefinitie = item;
    weight::Portie* portie = mPortieNaam.GetSelectedPortie();
    if (portie == nullptr)
    {
        ::MessageBox(m_hWnd, _T("Pick a valid portion"), _T("ERROR"), MB_OK);
        return;
    }

    auto lot = m_lotFactory->Create(mDefinitie->GetNutritionalValue().GetParameters(), *portie);
    lot->SetNumberOfPortions(mPorties.GetValue());
    mFood = std::make_unique<weight::Voedingsmiddel>(std::move(lot), *mDefinitie);

    OnOK();

    *pResult = 0;
}


void CFindVoedingsmiddel::OnCbnSelchangeBrand()
{
    if (!mUpdatingFilter)
        UpdateItemFilter();
}

void CFindVoedingsmiddel::OnBnClickedCheckFavourites()
{
    mItemList.SetFavouritesOnly(IsDlgButtonChecked(IDC_CHECK_FAVOURITES) != FALSE);
    mItemList.Fill();
}
