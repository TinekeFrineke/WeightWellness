// EditFoodDialog.cpp : implementation file
//

#include "stdafx.h"

#include <assert.h>
#include "WeightWatchers.h"
#include ".\editfooddefdialog.h"
#include "EditPortieDialog.h"
#include "model/VoedingsmiddelDefinitie.h"


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
END_MESSAGE_MAP()


CEditFoodDefDialog::CEditFoodDefDialog(WW::Model& aModel,
                                       WW::VMDefinitie* aDefinitie,
                                       CWnd* pParent /*=nullptr*/)
    : CDialog(CEditFoodDefDialog::IDD, pParent),
    mModel(aModel),
    mDefinitieAbc(aDefinitie),
    mChangedDefinitieAbc(nullptr),
    mPortieListView(aModel, aDefinitie),
    mUnitBox(aModel, (aDefinitie ? aDefinitie->GetUnit().GetName() : _T("g"))),
    mCategorie(aModel, (aDefinitie ? aDefinitie->GetCategory().Get() : _T(""))),
    mMerk(aModel, false, (aDefinitie ? aDefinitie->GetMerk().Get() : _T("")))
{
    if (mDefinitieAbc != nullptr) {
        // Move the potions from the changed item to the portie list.
        std::vector<std::unique_ptr<WW::Portie>> porties;
        mDefinitieAbc->ReleasePorties(porties);

        // Copy the portions to the mOrigialPorties
        for (size_t i = 0; i < porties.size(); ++i)
            mOriginalPorties.push_back(std::make_unique<WW::Portie>(*porties[i]));

        mPortieListView.SetPorties(porties);

        mChangedDefinitieAbc = std::make_unique<WW::VMDefinitie>(*aDefinitie);
    }
}


CEditFoodDefDialog::~CEditFoodDefDialog() = default;


// CEditFoodDefDialog message handlers

BOOL CEditFoodDefDialog::OnInitDialog()
{
    if (CDialog::OnInitDialog() == FALSE)
        return FALSE;

    UpdateUiCalculated(mChangedDefinitieAbc == nullptr || mChangedDefinitieAbc->IsCalculated());

    mName.SetReadOnly(mChangedDefinitieAbc != nullptr);
    mEenheden.SetValue(100);

    std::tstring eenheden = mChangedDefinitieAbc == nullptr ? _T("eenheden") : mChangedDefinitieAbc->GetUnit().GetName().c_str();

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
            WW::CalculatedVMDef* cdef = mChangedDefinitieAbc->GetCalculatedVMDef();
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
            WW::FixedVMDef* fdef = mChangedDefinitieAbc->GetFixedVMDef();
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

    mPortieListView.Fill();
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
    CEditPortieDialog dialog(mModel, *mChangedDefinitieAbc, nullptr, mPortieListView.GetPorties(), this);
    INT_PTR nResponse = dialog.DoModal();
    if (nResponse == IDOK)
    {
        if (dialog.GetPortie() != nullptr) {
            mPortieListView.AddPortie(std::make_unique<WW::Portie>(*dialog.GetPortie()));
            mPortieListView.Fill();
        }
    }
}

void CEditFoodDefDialog::OnBnClickedEdit()
{
    if (!FinalizeData())
        return;

    // TODO: Add your control notification handler code here
    PortieListItem* item = mPortieListView.GetSelectedItem();
    if (item != nullptr)
    {
        CEditPortieDialog dialog(mModel, *mChangedDefinitieAbc, item->GetPortie(), mPortieListView.GetPorties(), this);
        INT_PTR nResponse = dialog.DoModal();
        if (nResponse == IDOK)
            mPortieListView.Update(item);
    }
}

void CEditFoodDefDialog::OnBnClickedDelete()
{
    if (!FinalizeData())
        return;

    // TODO: Add your control notification handler code here
    PortieListItem* item = mPortieListView.GetSelectedItem();
    if (item != nullptr)
    {
        mPortieListView.RemovePortie(item->GetPortie());
    }
}


bool CEditFoodDefDialog::CreateCommonFoodParts()
{
    assert(mChangedDefinitieAbc != nullptr);

    mChangedDefinitieAbc->SetUnit(WW::Unit(mModel, mUnitBox.GetString()));
    mChangedDefinitieAbc->SetCategory(WW::CategorieNaam(mModel, mCategorie.GetString()));
    mChangedDefinitieAbc->SetMerk(WW::MerkNaam(mModel, mMerk.GetString()));
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

    //if (mPortieListView.GetPorties().empty() && !mVrijePortieCheck.GetCheck() == BST_CHECKED)
    //{
    //  MessageBox(_T("Voeg portie toe!"), _T("ERROR"), MB_OK);
    //  return false;
    //}


    if (mEenheden.GetValue() == 0)
    {
        MessageBox(_T("Ongeldig aantal eenheden!"), _T("ERROR"), MB_OK);
        return false;
    }

    double amountFactor = 100.0f / static_cast<double>(mEenheden.GetValue());

    WW::FoodParameters parameters(mKCalPer100.GetValue() * amountFactor,
                                  mEiwitPer100.GetValue() * amountFactor,
                                  mVetPer100.GetValue() * amountFactor,
                                  mVezelsPer100.GetValue() * amountFactor,
                                  mKoolhydratenPer100.GetValue() * amountFactor);
    if (mChangedDefinitieAbc == nullptr)
    {
        auto vdef = std::make_unique<WW::CalculatedVMDef>(mModel.GetCalculator());
        vdef->SetParameters(parameters);
        mChangedDefinitieAbc = std::make_unique<WW::VMDefinitie>(mModel.GetCalculator(), name, WW::Unit(mModel, mUnitBox.GetString()), std::move(vdef));
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
        auto vdef = std::make_unique<WW::FixedVMDef>();
        vdef->SetPointsPer100Units(mPuntenPer100.GetValue() * amountFactor);
        mChangedDefinitieAbc = std::make_unique<WW::VMDefinitie>(mModel.GetCalculator(), name, WW::Unit(mModel, mUnitBox.GetString()), std::move(vdef));
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

    mPortieListView.SetDefinition(mChangedDefinitieAbc.get());

    return true;
}


bool CEditFoodDefDialog::FinalizeFixedData()
{
    if (!CreateFixedFood())
        return false;

    mPortieListView.SetDefinition(mChangedDefinitieAbc.get());

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

    std::vector<std::unique_ptr<WW::Portie>> porties;
    mPortieListView.ReleasePorties(porties);

    if (mChangedDefinitieAbc != nullptr)
    {
        if (mDefinitieAbc == nullptr)
        {
            mDefinitieAbc = std::make_unique<WW::VMDefinitie>(*mChangedDefinitieAbc);
            mModel.Add(std::move(mDefinitieAbc));
        }
        else
        {
            *mDefinitieAbc = *mChangedDefinitieAbc;
        }

        for (size_t i = 0; i < porties.size(); ++i)
            mDefinitieAbc->AddPortie(std::move(porties[i]));
    }

    OnOK();
}

void CEditFoodDefDialog::OnEnChangeKcalper100()
{
    if (mChangedDefinitieAbc != nullptr && mChangedDefinitieAbc->IsCalculated())
    {
        double amountFactor = 100.0f / static_cast<double>(mEenheden.GetValue());
        mChangedDefinitieAbc->GetCalculatedVMDef()->SetKCalPer100Units(mKCalPer100.GetValue() * amountFactor);
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
