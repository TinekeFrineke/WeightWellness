// EditFoodDialog.cpp : implementation file
//

#include "stdafx.h"

#include <assert.h>
#include "WeightControl.h"
#include ".\editfooddefdialog.h"
#include "EditPortieDialog.h"
#include "model/IRepository.h"
#include "model/NutritionalValue.h"
#include "model/VoedingsmiddelDefinitie.h"
#include "PortieEditor.h"


// CEditFoodDefDialog dialog

IMPLEMENT_DYNAMIC(CEditFoodDefDialog, CDialog)


void CEditFoodDefDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_NAAM, mName);
    DDX_Control(pDX, IDC_CATEGORIE, mCategorie);
    DDX_Control(pDX, IDC_UNIT, mUnitBox);
    DDX_Control(pDX, IDC_KCALPER100, mKCalPer100);
    DDX_Control(pDX, IDC_VETPER100, mVetPer100);
    DDX_Control(pDX, IDC_PORTIE, mPortieListView);
    DDX_Control(pDX, IDC_EIWITTEN_PER_100, mEiwitPer100);
    DDX_Control(pDX, IDC_KOOLHYDRATEN_PER_100, mKoolhydratenPer100);
    DDX_Control(pDX, IDC_VEZELS_PER_100, mVezelsPer100);
    DDX_Control(pDX, IDC_COMBO1, mMerk);
    DDX_Control(pDX, IDS_EIWIT_PER_100, mEiwitPer100Static);
    DDX_Control(pDX, IDS_KOOLHYDRATEN_PER_100, mKoolhydratenPer100Static);
    DDX_Control(pDX, IDS_VET_PER_100, mVetPer100Static);
    DDX_Control(pDX, IDS_VEZELS_PER_100, mVezelsPer100Static);
    DDX_Control(pDX, IDS_PUNTEN_PER_100, mPuntenPer100Static);
    DDX_Control(pDX, IDC_PUNTEN_PER_100, mPuntenPer100);
    DDX_Control(pDX, IDS_KCAL_PER_100, mKCalPer100Static);
    DDX_Control(pDX, IDC_EENHEDEN, mEenheden);
    DDX_Control(pDX, IDC_EENHEDEN_STATIC, mEenhedenStatic);
}


BEGIN_MESSAGE_MAP(CEditFoodDefDialog, CDialog)
    ON_BN_CLICKED(IDC_ADD, OnBnClickedAdd)
    ON_BN_CLICKED(IDC_EDIT, OnBnClickedEdit)
    ON_BN_CLICKED(IDC_DELETE, OnBnClickedDelete)
    ON_BN_CLICKED(IDOK, OnBnClickedOk)
    ON_EN_CHANGE(IDC_KCALPER100, OnEnChangeKcalper100)
    ON_EN_CHANGE(IDC_VETPER100, OnEnChangeVetper100)
    ON_EN_CHANGE(IDC_EIWITTEN_PER_100, OnEnChangeEiwittenPer100)
    ON_EN_CHANGE(IDC_KOOLHYDRATEN_PER_100, OnEnChangeKoolhydratenPer100)
    ON_EN_CHANGE(IDC_VEZELS_PER_100, OnEnChangeVezelsPer100)
    ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
    ON_EN_CHANGE(IDC_EENHEDEN, OnEnChangeEenheden)
    ON_CBN_SELCHANGE(IDC_UNIT, OnCbnSelchangeUnit)
    ON_CBN_EDITCHANGE(IDC_UNIT, OnCbnEditchangeUnit)
    ON_BN_CLICKED(IDC_CHECK_FAVOURITE, OnBnClickedCheckFavourite)
    ON_NOTIFY(NM_DBLCLK, IDC_PORTIE, &CEditFoodDefDialog::OnNMDblclkPortie)
END_MESSAGE_MAP()


namespace {

std::vector<std::reference_wrapper<weight::Portie>>
CreateListViewPorties(const std::vector<std::unique_ptr<weight::Portie>>& porties)
{
    std::vector<std::reference_wrapper<weight::Portie>> newPorties;
    for (auto& portie : porties)
        newPorties.push_back(*portie);

    return newPorties;
}
}

CEditFoodDefDialog::CEditFoodDefDialog(weight::Model& aModel,
                                       std::shared_ptr<weight::IRepository> units,
                                       std::shared_ptr<weight::IRepository> categories,
                                       std::shared_ptr<weight::IRepository> brands,
                                       weight::VMDefinitie& aDefinitie,
                                       bool newDefinition,
                                       std::shared_ptr<weight::PointsCalculator> calculator,
                                       CWnd* pParent /*=nullptr*/)
    : CDialog(CEditFoodDefDialog::IDD, pParent)
    , mModel(aModel)
    , m_definition(aDefinitie)
    , m_newDefinition(newDefinition)
    , mUnitBox(units->Get(), aDefinitie.GetUnit())
    , mCategorie(categories->Get(), aDefinitie.GetCategory())
    , mMerk(brands->Get(), false, aDefinitie.GetMerk())
    , m_calculator(std::move(calculator))
{
}


CEditFoodDefDialog::~CEditFoodDefDialog() = default;


// CEditFoodDefDialog message handlers

BOOL CEditFoodDefDialog::OnInitDialog()
{
    if (CDialog::OnInitDialog() == FALSE)
        return FALSE;

    // ww2024 TODO
    //UpdateUiCalculated(true);

    mName.SetReadOnly(m_newDefinition);
    mEenheden.SetValue(100);

    std::tstring eenheden = m_definition.GetUnit().c_str();

    mName.SetValue(m_definition.GetName());

    mPuntenPer100.SetValue(m_definition.GetPointsPer100Units());

    // Definition is calculated
    mKCalPer100.SetValue(m_definition.GetNutritionalValue().GetKCalPer100Units());
    mVetPer100.SetValue(m_definition.GetNutritionalValue().GetFatPer100Units());
    mEiwitPer100.SetValue(m_definition.GetNutritionalValue().GetProteinPer100Units());
    mKoolhydratenPer100.SetValue(m_definition.GetNutritionalValue().GetCarbohydratesPer100Units());
    mVezelsPer100.SetValue(m_definition.GetNutritionalValue().GetFibersPer100Units());
    mPuntenPer100.SetValue(m_definition.GetNutritionalValue().GetPointsPer100Units());

    if (m_definition.IsFavourite())
        CheckDlgButton(IDC_CHECK_FAVOURITE, 1);

    // Initialize controls
    mPortieListView.Initialize();
    mUnitBox.Initialize();
    mCategorie.Initialize();
    mMerk.Initialize();

    // Fill controls
    mPortieListView.SetPointsPer100Units(m_definition.GetPointsPer100Units());
    mPortieListView.SetPorties(CreateListViewPorties(m_definition.GetPortieList()));
    mUnitBox.Fill();
    mCategorie.Fill();
    mMerk.Fill();

    FillStatics();
    return TRUE;
}


void CEditFoodDefDialog::FillStatics()
{
    std::tstring eehedenname(mUnitBox.GetString().empty() ? _T("eenheden") : mUnitBox.GetString());
    TCHAR labelstring[1024];
    _stprintf_s(labelstring, _T("kCal per %d %s"), mEenheden.GetValue(), eehedenname.c_str());
    mKCalPer100Static.SetWindowText(labelstring);
    _stprintf_s(labelstring, _T("Eiwitten per %d %s"), mEenheden.GetValue(), eehedenname.c_str());
    mEiwitPer100Static.SetWindowText(labelstring);
    _stprintf_s(labelstring, _T("Koolhydraten per %d %s"), mEenheden.GetValue(), eehedenname.c_str());
    mKoolhydratenPer100Static.SetWindowText(labelstring);
    _stprintf_s(labelstring, _T("Vet per %d %s"), mEenheden.GetValue(), eehedenname.c_str());
    mVetPer100Static.SetWindowText(labelstring);
    _stprintf_s(labelstring, _T("Vezels per %d %s"), mEenheden.GetValue(), eehedenname.c_str());
    mVezelsPer100Static.SetWindowText(labelstring);
    _stprintf_s(labelstring, _T("Punten per %d %s"), mEenheden.GetValue(), eehedenname.c_str());
    mPuntenPer100Static.SetWindowText(labelstring);
    mEenhedenStatic.SetWindowText(eehedenname.c_str());
}


void CEditFoodDefDialog::OnBnClickedAdd()
{
    if (!FinalizeData())
        return;

    // calculated state
    PortieEditor editor(m_definition, this);
    auto portie = editor.Create();
    if (portie != nullptr) {
        m_definition.AddPortie(std::move(portie));
        mPortieListView.SetPorties(CreateListViewPorties(m_definition.GetPortieList()));
    }
}

void CEditFoodDefDialog::OnBnClickedEdit()
{
    if (!FinalizeData())
        return;

    PortieListItem* item = mPortieListView.GetSelectedItem();
    if (item != nullptr)
    {
        PortieEditor editor(m_definition, this);
        if (editor.Edit(*item->GetPortie()))
            mPortieListView.Update(item);
    }
}

void CEditFoodDefDialog::OnBnClickedDelete()
{
    if (!FinalizeData())
        return;

    PortieListItem* item = mPortieListView.GetSelectedItem();
    if (item != nullptr)
    {
        m_definition.RemovePortie(item->GetPortie());
        mPortieListView.SetPorties(CreateListViewPorties(m_definition.GetPortieList()));
    }
}


bool CEditFoodDefDialog::CreateCommonFoodParts()
{
    m_definition.SetUnit(mUnitBox.GetString());
    m_definition.SetCategory(mCategorie.GetString());
    m_definition.SetMerk(mMerk.GetString());
    return true;
}


bool CEditFoodDefDialog::CreateFood()
{
// TF_TODO ww2924{
    //if (IsDlgButtonChecked(IDC_RADIO_BEREKEND))
        // calculated state
        return CreateCalculatedFood();
    //else
    //    // fixed state
    //    return CreateFixedFood();
}


bool CEditFoodDefDialog::CreateCalculatedFood()
{
    std::tstring name = mName.GetValue();
    if (name.empty())
        return false;

    if (mUnitBox.GetString().empty())
        return false;

    if (mEenheden.GetValue() == 0)
    {
        MessageBox(_T("Ongeldig aantal eenheden!"), _T("ERROR"), MB_OK);
        return false;
    }

    double amountFactor = 100.0f / static_cast<double>(mEenheden.GetValue());

    weight::FoodParameters parameters(mKCalPer100.GetValue() * amountFactor,
                                      mEiwitPer100.GetValue() * amountFactor,
                                      mVetPer100.GetValue() * amountFactor,
                                      mVezelsPer100.GetValue() * amountFactor,
                                      mKoolhydratenPer100.GetValue() * amountFactor);
    m_definition.SetNutritionalValues(parameters);

    CreateCommonFoodParts();

    return true;
}


bool CEditFoodDefDialog::OnCalculatedOk()
{
    std::tstring name = mName.GetValue();

    return FinalizeCalculatedData();
}


//bool CEditFoodDefDialog::OnFixedOk()
//{
//    std::tstring name = mName.GetValue();
//
//    return FinalizeFixedData();
//}


bool CEditFoodDefDialog::FinalizeCalculatedData()
{
    if (!CreateCalculatedFood())
        return false;

    mPortieListView.SetPointsPer100Units(m_definition.GetPointsPer100Units());

    return true;
}


bool CEditFoodDefDialog::FinalizeData()
{
    return FinalizeCalculatedData();
}


void CEditFoodDefDialog::OnBnClickedOk()
{
    std::tstring name = mName.GetValue();
    if (name.empty())
    {
        ::MessageBox(0, _T("Enter a unique name"), _T("Error"), MB_OK);
        return;
    }

    if (m_newDefinition && mModel.FindVoedingsmiddelDefinitie(name))
    {
        ::MessageBox(0, _T("Een voedingsmiddel met deze naam bestaat al!"), _T("Error"), MB_OK);
        return;
    }

    bool result = OnCalculatedOk();

    if (result)
        OnOK();
}

void CEditFoodDefDialog::OnEnChangeKcalper100()
{
    double amountFactor = 100.0f / static_cast<double>(mEenheden.GetValue());
    m_definition.SetKCalPer100Units(mKCalPer100.GetValue() * amountFactor);
    mPortieListView.SetPointsPer100Units(mKCalPer100.GetValue() * amountFactor);
}

void CEditFoodDefDialog::OnEnChangeVetper100()
{
    double amountFactor = 100.0f / static_cast<double>(mEenheden.GetValue());
    m_definition.SetVetPer100Units(mVetPer100.GetValue() * amountFactor);
}

void CEditFoodDefDialog::OnEnChangeEiwittenPer100()
{
    double amountFactor = 100.0f / static_cast<double>(mEenheden.GetValue());
    m_definition.SetEiwitPer100Units(mEiwitPer100.GetValue() * amountFactor);
}

void CEditFoodDefDialog::OnEnChangeKoolhydratenPer100()
{
    double amountFactor = 100.0f / static_cast<double>(mEenheden.GetValue());
    m_definition.SetKoolhydratenPer100Units(mKoolhydratenPer100.GetValue() * amountFactor);
}

void CEditFoodDefDialog::OnEnChangeVezelsPer100()
{
        double amountFactor = 100.0f / static_cast<double>(mEenheden.GetValue());
        m_definition.SetVezelsPer100Units(mVezelsPer100.GetValue() * amountFactor);
}


void CEditFoodDefDialog::UpdateUiCalculated(bool bCalculated)
{
    //mKCalPer100Static.EnableWindow(bCalculated);
    //mEiwitPer100Static.EnableWindow(bCalculated);
    //mKoolhydratenPer100Static.EnableWindow(bCalculated);
    //mVetPer100Static.EnableWindow(bCalculated);
    //mVezelsPer100Static.EnableWindow(bCalculated);
    //mPuntenPer100Static.EnableWindow(true);
    //mKCalPer100.EnableWindow(bCalculated);
    //mVetPer100.EnableWindow(bCalculated);
    //mEiwitPer100.EnableWindow(bCalculated);
    //mKoolhydratenPer100.EnableWindow(bCalculated);
    //mVezelsPer100.EnableWindow(bCalculated);
    //mPuntenPer100.SetReadOnly(bCalculated);
}


void CEditFoodDefDialog::OnBnClickedCancel()
{
    OnCancel();
}

void CEditFoodDefDialog::OnEnChangeEenheden()
{
    FinalizeData();
    FillStatics();
}

void CEditFoodDefDialog::OnCbnSelchangeUnit()
{
    FillStatics();
}

void CEditFoodDefDialog::OnCbnEditchangeUnit()
{
    FillStatics();
}

void CEditFoodDefDialog::OnBnClickedCheckFavourite()
{
    m_definition.SetFavourite(IsDlgButtonChecked(IDC_CHECK_FAVOURITE) != FALSE);
}


void CEditFoodDefDialog::OnNMDblclkPortie(NMHDR* pNMHDR, LRESULT* pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    // TODO: Add your control notification handler code here
    *pResult = 0;

    if (!FinalizeData())
        return;

    PortieListItem* item = mPortieListView.GetSelectedItem();
    if (item != nullptr)
    {
        PortieEditor editor(m_definition, this);
        if (editor.Edit(*item->GetPortie()))
            mPortieListView.Update(item);
    }
}
