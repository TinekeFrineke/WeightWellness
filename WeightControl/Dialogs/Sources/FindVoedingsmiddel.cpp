// FindVoedingsmiddel.cpp : implementation file
//

#include "stdafx.h"
#include ".\findvoedingsmiddel.h"

#include <assert.h>
#include "WeightControl.h"
#include "model/Day.h"
#include "model/Portie.h"
#include "model/Voedingsmiddel.h"
#include "model/VoedingsmiddelDefinitie.h"
#include "model/ILotFactory.h"

// CFindVoedingsmiddel dialog

namespace {
std::vector<weight::VMDefinitie*> Definitions(const weight::Model& model)
{
    std::vector<weight::VMDefinitie*> definitions;
    for (auto& definition : model.GetVoedingsmiddelDefinities())
        definitions.push_back(definition.get());
    return definitions;
}
}

IMPLEMENT_DYNAMIC(CFindVoedingsmiddel, CDialog)
CFindVoedingsmiddel::CFindVoedingsmiddel(weight::Model& aModel,
                                         weight::VMDefinitie* aDefinitie,
                                         std::unique_ptr<weight::ILotFactory> lotFactory,
                                         CWnd* pParent /*=nullptr*/)
    : CDialog(CFindVoedingsmiddel::IDD, pParent)
    , mItemList(Definitions(aModel))
    , mCategorieBox(aModel.GetCategories())
    , mMerkBox(aModel.GetBrands(), true)
    , mFood(nullptr)
    , mState(nullptr)
    , m_lotFactory(std::move(lotFactory))
    , mDefinitie(aDefinitie)
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

    auto lot = m_lotFactory->Create(*mDefinitie, *portie);
    assert(lot != nullptr);
    lot->SetNumberOfPortions(mPorties.GetValue());
    mFood = std::make_unique<weight::Voedingsmiddel>(std::move(lot), *mDefinitie);

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

    VMDefinitiesListItem* lvitem = mItemList.GetSelectedItem();
    if (lvitem == nullptr)
        return;

    mUpdatingFilter = true;

    mDefinitie = lvitem->GetItem();
    assert(mDefinitie != nullptr);
    mUnitNaam.SetValue(mDefinitie->GetUnit().GetName());

    SetState(CreateState(*mDefinitie));

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

    weight::Portie* portie = mPortieNaam.GetSelectedPortie();
    if (portie == nullptr)
    {
        ::MessageBox(m_hWnd, _T("Pick a valid portion"), _T("ERROR"), MB_OK);
        return;
    }

    auto lot = m_lotFactory->Create(*mDefinitie, *portie);
    lot->SetNumberOfPortions(mPorties.GetValue());
    mFood = std::make_unique<weight::Voedingsmiddel>(std::move(lot), *mDefinitie);

    OnOK();

    *pResult = 0;
}


std::unique_ptr<VMState> CFindVoedingsmiddel::CreateState(weight::VMDefinitie& aDefinitie)
{
    if (aDefinitie.GetPortieList().empty())
        return std::make_unique<VMNoPortionsState>(*this, aDefinitie);
    else
        return std::make_unique<VMStandardPortionsState>(*this, aDefinitie);
}


void CFindVoedingsmiddel::SetState(std::unique_ptr<VMState> aState)
{
    mState = std::move(aState);
    if (mState != nullptr)
        mState->Initialize();
}


void VMState::UpdatePortionValues(const weight::Portie& aPortie)
{
    GetUnits().SetValue(aPortie.GetUnits());
    GetPorties().SetValue(1);
    GetPortieBox().SetString(aPortie.GetName());
}


void VMNoPortionsState::Initialize()
{
    GetUnits().SetReadOnly(true);
    GetPorties().SetReadOnly(true);
    GetPortieBox().EnableWindow(false);
}


void VMStandardPortionsState::Initialize()
{
    GetUnits().SetReadOnly(false);
    GetPorties().SetReadOnly(false);
    GetPortieBox().EnableWindow(true);
    GetPortieBox().Fill(GetDefinitie().GetPortieList());

    UpdatePortionValues(*GetPortieBox().GetSelectedPortie());
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
