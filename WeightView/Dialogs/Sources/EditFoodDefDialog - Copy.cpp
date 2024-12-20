// EditFoodDialog.cpp : implementation file
//

#include "stdafx.h"

#include <assert.h>
#include "WeightControl.h"
#include ".\editfooddefdialog.h"
#include "EditPortieDialog.h"
#include "model/IRepository.h"
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
    ON_BN_CLICKED(IDC_RADIO_BEREKEND, OnBnClickedRadioBerekend)
    ON_BN_CLICKED(IDC_RADIO_VAST, OnBnClickedRadioVast)
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
                                       weight::VMDefinitie* aDefinitie,
                                       std::shared_ptr<weight::PointsCalculator> calculator,
                                       CWnd* pParent /*=nullptr*/)
    : CDialog(CEditFoodDefDialog::IDD, pParent)
    , mModel(aModel)
    , mDefinitieAbc(aDefinitie)
    , mChangedDefinitieAbc(nullptr)
    , mUnitBox(units->Get(), (aDefinitie ? aDefinitie->GetUnit() : _T("g")))
    , mCategorie(categories->Get(), (aDefinitie ? aDefinitie->GetCategory() : _T("")))
    , mMerk(brands->Get(), false, (aDefinitie ? aDefinitie->GetMerk() : _T("")))
    , m_calculator(std::move(calculator))
{
    if (mDefinitieAbc != nullptr) {
        mChangedDefinitieAbc = std::make_unique<weight::VMDefinitie>(*mDefinitieAbc);
    }
}


CEditFoodDefDialog::~CEditFoodDefDialog() = default;


// CEditFoodDefDialog message handlers

BOOL CEditFoodDefDialog::OnInitDialog()
{
    if (CDialog::OnInitDialog() == FALSE)
        return FALSE;

    mPortieListView.SetPorties(CreateListViewPorties(mChangedDefinitieAbc->GetPortieList()));
    mPortieListView.SetPointsPer100Units(mDefinitieAbc->GetPointsPer100Units());

    UpdateUiCalculated(mChangedDefinitieAbc == nullptr || mChangedDefinitieAbc->IsCalculated());

    mName.SetReadOnly(mChangedDefinitieAbc != nullptr);
    mEenheden.SetValue(100);

    std::tstring eenheden = mChangedDefinitieAbc == nullptr ? _T("eenheden") : mChangedDefinitieAbc->GetUnit().c_str();

    if (mChangedDefinitieAbc == nullptr)
    {
        // No definition available yet
        mKCalPer100.SetValue(0);
        mVetPer100.SetValue(0);
        mEiwitPer100.SetValue(0);
        mKoolhydratenPer100.SetValue(0);
        mVezelsPer100.SetValue(0);
        mPuntenPer100.SetValue(0);
    }
    else
    {
        // Definition available
        mName.SetValue(mChangedDefinitieAbc->GetName());

        mPuntenPer100.SetValue(mChangedDefinitieAbc->GetPointsPer100Units());

        if (mChangedDefinitieAbc->IsCalculated())
        {
            // Definition is calculated
            weight::CalculatedVMDef* cdef = mChangedDefinitieAbc->GetCalculatedVMDef();
            assert(cdef != nullptr);
            mKCalPer100.SetValue(cdef->GetKCalPer100Units());
            mVetPer100.SetValue(cdef->GetVetPer100Units());
            mEiwitPer100.SetValue(cdef->GetEiwitPer100Units());
            mKoolhydratenPer100.SetValue(cdef->GetKoolhydratenPer100Units());
            mVezelsPer100.SetValue(cdef->GetVezelsPer100Units());
            mPuntenPer100.SetValue(cdef->GetPointsPer100Units());
        }
        else if (mChangedDefinitieAbc->IsFixed())
        {
            // Definition is fixed
            weight::FixedVMDef* fdef = mChangedDefinitieAbc->GetFixedVMDef();
            mKCalPer100.SetValue(0);
            mVetPer100.SetValue(0);
            mEiwitPer100.SetValue(0);
            mKoolhydratenPer100.SetValue(0);
            mVezelsPer100.SetValue(0);
            mPuntenPer100.SetValue(fdef->GetPointsPer100Units());
        }
        else
        {
            assert(false);
        }
    }

    if (mChangedDefinitieAbc != nullptr && mChangedDefinitieAbc->IsFavourite())
        CheckDlgButton(IDC_CHECK_FAVOURITE, 1);

    mPortieListView.Initialize();
    mUnitBox.Initialize();
    mCategorie.Initialize();
    mMerk.Initialize();

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
    PortieEditor editor(*mChangedDefinitieAbc, this);
    auto portie = editor.Create();
    if (portie != nullptr) {
        mChangedDefinitieAbc->AddPortie(std::move(portie));
        //mPortieListView.AddPortie(std::make_unique<weight::Portie>(*dialog.GetPortie()));
        mPortieListView.SetPorties(CreateListViewPorties(mChangedDefinitieAbc->GetPortieList()));
    }
}

void CEditFoodDefDialog::OnBnClickedEdit()
{
    if (!FinalizeData())
        return;

    PortieListItem* item = mPortieListView.GetSelectedItem();
    if (item != nullptr)
    {
        PortieEditor editor(*mChangedDefinitieAbc, this);
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
        mChangedDefinitieAbc->RemovePortie(item->GetPortie());
        mPortieListView.SetPorties(CreateListViewPorties(mChangedDefinitieAbc->GetPortieList()));
    }
}


bool CEditFoodDefDialog::CreateCommonFoodParts()
{
    assert(mChangedDefinitieAbc != nullptr);

    mChangedDefinitieAbc->SetUnit(mUnitBox.GetString());
    mChangedDefinitieAbc->SetCategory(mCategorie.GetString());
    mChangedDefinitieAbc->SetMerk(mMerk.GetString());
    return true;
}


bool CEditFoodDefDialog::CreateFood()
{
    if (IsDlgButtonChecked(IDC_RADIO_BEREKEND))
        // calculated state
        return CreateCalculatedFood();
    else
        // fixed state
        return CreateFixedFood();
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
    if (mChangedDefinitieAbc == nullptr)
    {
        auto vdef = std::make_unique<weight::CalculatedVMDef>(m_calculator);
        vdef->SetParameters(parameters);
        mChangedDefinitieAbc = std::make_unique<weight::VMDefinitie>(m_calculator, name, mUnitBox.GetString(), std::move(vdef));
    }
    else if (!mChangedDefinitieAbc->IsCalculated())
    {
        mChangedDefinitieAbc->SetCalculated(parameters);
    }
    else
    {
        assert(mChangedDefinitieAbc->GetCalculatedVMDef() != nullptr);
        mChangedDefinitieAbc->GetCalculatedVMDef()->SetParameters(parameters);
    }

    CreateCommonFoodParts();

    return true;
}


bool CEditFoodDefDialog::CreateFixedFood()
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

    if (mChangedDefinitieAbc == nullptr)
    {
        auto vdef = std::make_unique<weight::FixedVMDef>();
        vdef->SetPointsPer100Units(mPuntenPer100.GetValue() * amountFactor);
        mChangedDefinitieAbc = std::make_unique<weight::VMDefinitie>(m_calculator, name, mUnitBox.GetString(), std::move(vdef));
    }
    else if (mChangedDefinitieAbc->IsFixed())
    {
        mChangedDefinitieAbc->GetFixedVMDef()->SetPointsPer100Units(mPuntenPer100.GetValue() * amountFactor);
    }
    else
    {
        mChangedDefinitieAbc->SetFixed();
    }

    CreateCommonFoodParts();

    return true;
}


bool CEditFoodDefDialog::OnCalculatedOk()
{
    std::tstring name = mName.GetValue();

    return FinalizeCalculatedData();
}


bool CEditFoodDefDialog::OnFixedOk()
{
    std::tstring name = mName.GetValue();

    return FinalizeFixedData();
}


bool CEditFoodDefDialog::FinalizeCalculatedData()
{
    if (!CreateCalculatedFood())
        return false;

    mPortieListView.SetPointsPer100Units(mChangedDefinitieAbc->GetPointsPer100Units());

    return true;
}


bool CEditFoodDefDialog::FinalizeFixedData()
{
    if (!CreateFixedFood())
        return false;

    mPortieListView.SetPointsPer100Units(mChangedDefinitieAbc->GetPointsPer100Units());

    return true;
}


bool CEditFoodDefDialog::FinalizeData()
{
    if (IsDlgButtonChecked(IDC_RADIO_BEREKEND))
        return FinalizeCalculatedData();
    else
        return FinalizeFixedData();
}


void CEditFoodDefDialog::OnBnClickedOk()
{
    std::tstring name = mName.GetValue();
    if (mDefinitieAbc == nullptr && mModel.FindVoedingsmiddelDefinitie(name))
    {
        ::MessageBox(0, _T("Een voedingsmiddel met deze naam bestaat al!"), _T("Error"), MB_OK);
        return;
    }

    bool result = false;
    if (IsDlgButtonChecked(IDC_RADIO_BEREKEND))
        // calculated state
        result = OnCalculatedOk();
    else
        // fixed state
        result = OnFixedOk();

    if (!result)
        return;

    //std::vector<std::unique_ptr<weight::Portie>> porties;
    //mPortieListView.ReleasePorties(porties);

    if (mChangedDefinitieAbc != nullptr)
    {
        if (mDefinitieAbc == nullptr)
        {
            mDefinitieAbc = std::make_unique<weight::VMDefinitie>(*mChangedDefinitieAbc);
            *mDefinitieAbc = *mChangedDefinitieAbc;
            mModel.Add(std::move(mDefinitieAbc));
        }
        else
        {
            *mDefinitieAbc = *mChangedDefinitieAbc;
        }
    }

    OnOK();
}

void CEditFoodDefDialog::OnEnChangeKcalper100()
{
    if (mChangedDefinitieAbc != nullptr && mChangedDefinitieAbc->IsCalculated())
    {
        double amountFactor = 100.0f / static_cast<double>(mEenheden.GetValue());
        mChangedDefinitieAbc->GetCalculatedVMDef()->SetKCalPer100Units(mKCalPer100.GetValue() * amountFactor);
        mPortieListView.SetPointsPer100Units(mKCalPer100.GetValue() * amountFactor);
    }
}

void CEditFoodDefDialog::OnEnChangeVetper100()
{
    if (mChangedDefinitieAbc != nullptr && mChangedDefinitieAbc->IsCalculated())
    {
        double amountFactor = 100.0f / static_cast<double>(mEenheden.GetValue());
        mChangedDefinitieAbc->GetCalculatedVMDef()->SetVetPer100Units(mVetPer100.GetValue() * amountFactor);
    }
}

void CEditFoodDefDialog::OnEnChangeEiwittenPer100()
{
    if (mChangedDefinitieAbc != nullptr && mChangedDefinitieAbc->IsCalculated())
    {
        double amountFactor = 100.0f / static_cast<double>(mEenheden.GetValue());
        mChangedDefinitieAbc->GetCalculatedVMDef()->SetEiwitPer100Units(mEiwitPer100.GetValue() * amountFactor);
    }
}

void CEditFoodDefDialog::OnEnChangeKoolhydratenPer100()
{
    if (mChangedDefinitieAbc != nullptr && mChangedDefinitieAbc->IsCalculated())
    {
        double amountFactor = 100.0f / static_cast<double>(mEenheden.GetValue());
        mChangedDefinitieAbc->GetCalculatedVMDef()->SetKoolhydratenPer100Units(mKoolhydratenPer100.GetValue() * amountFactor);
    }
}

void CEditFoodDefDialog::OnEnChangeVezelsPer100()
{
    if (mChangedDefinitieAbc != nullptr && mChangedDefinitieAbc->IsCalculated())
    {
        double amountFactor = 100.0f / static_cast<double>(mEenheden.GetValue());
        mChangedDefinitieAbc->GetCalculatedVMDef()->SetVezelsPer100Units(mVezelsPer100.GetValue() * amountFactor);
    }
}


void CEditFoodDefDialog::UpdateUiCalculated(bool bCalculated)
{
    if (bCalculated)
        CheckDlgButton(IDC_RADIO_BEREKEND, 1);
    else
        CheckDlgButton(IDC_RADIO_VAST, 1);

    mKCalPer100Static.EnableWindow(bCalculated);
    mEiwitPer100Static.EnableWindow(bCalculated);
    mKoolhydratenPer100Static.EnableWindow(bCalculated);
    mVetPer100Static.EnableWindow(bCalculated);
    mVezelsPer100Static.EnableWindow(bCalculated);
    mPuntenPer100Static.EnableWindow(true);
    mKCalPer100.EnableWindow(bCalculated);
    mVetPer100.EnableWindow(bCalculated);
    mEiwitPer100.EnableWindow(bCalculated);
    mKoolhydratenPer100.EnableWindow(bCalculated);
    mVezelsPer100.EnableWindow(bCalculated);
    mPuntenPer100.SetReadOnly(bCalculated);
}


void CEditFoodDefDialog::OnBnClickedRadioBerekend()
{
    UpdateUiCalculated(true);
}

void CEditFoodDefDialog::OnBnClickedRadioVast()
{
    UpdateUiCalculated(false);
}

void CEditFoodDefDialog::OnBnClickedCancel()
{
    if (mDefinitieAbc == nullptr)
        mChangedDefinitieAbc.reset();

    // Re-attach the original portions to the food
    for (size_t i = 0; i < mOriginalPorties.size(); ++i)
        mDefinitieAbc->AddPortie(std::move(mOriginalPorties[i]));

    mOriginalPorties.clear();

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
    mChangedDefinitieAbc->SetFavourite(IsDlgButtonChecked(IDC_CHECK_FAVOURITE) != FALSE);
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
        PortieEditor editor(*mChangedDefinitieAbc, this);
        if (editor.Edit(*item->GetPortie()))
            mPortieListView.Update(item);
    }
}
