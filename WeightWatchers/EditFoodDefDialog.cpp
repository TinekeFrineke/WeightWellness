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
    mDefinitie(aDefinitie),
    mChangedDefinitie(nullptr),
    mPortieListView(aModel, aDefinitie),
    mUnitBox(aModel, (aDefinitie ? aDefinitie->GetUnit().GetName() : _T(""))),
    mCategorie(aModel, (aDefinitie ? aDefinitie->GetCategory().Get() : _T(""))),
    mMerk(aModel, false, (aDefinitie ? aDefinitie->GetMerk().Get() : _T("")))
{
    if (mDefinitie != nullptr) {
        // Move the potions from the changed item to the portie list.
        std::vector<std::unique_ptr<WW::Portie>> porties;
        mDefinitie->ReleasePorties(porties);

        // Copy the portions to the mOrigialPorties
        for (size_t i = 0; i < porties.size(); ++i)
            mOriginalPorties.push_back(new WW::Portie(*porties[i]));

        mPortieListView.SetPorties(porties);

        mChangedDefinitie = new WW::VMDefinitie(*aDefinitie);
    }
}


CEditFoodDefDialog::~CEditFoodDefDialog()
{
    for (size_t i = 0; i < mOriginalPorties.size(); ++i)
        delete mOriginalPorties[i];

    delete mChangedDefinitie;
}


// CEditFoodDefDialog message handlers

BOOL CEditFoodDefDialog::OnInitDialog()
{
    if (CDialog::OnInitDialog() == FALSE)
        return FALSE;

    SetCalculated(mChangedDefinitie == nullptr || mChangedDefinitie->IsCalculated());

    mName.SetReadOnly(mChangedDefinitie != nullptr);
    mEenheden.SetValue(100);

    std::tstring eenheden = mChangedDefinitie == nullptr ? _T("eenheden") : mChangedDefinitie->GetUnit().GetName().c_str();

    if (mChangedDefinitie == nullptr)
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
        mName.SetValue(mChangedDefinitie->GetName());

        mPuntenPer100.SetValue(mChangedDefinitie->GetPointsPer100Units());

        if (mChangedDefinitie->IsCalculated())
        {
            // Definition is calculated
            WW::CalculatedVMDef* cdef = mChangedDefinitie->GetCalculatedVMDef();
            assert(cdef != nullptr);
            mKCalPer100.SetValue(cdef->GetKCalPer100Units());
            mVetPer100.SetValue(cdef->GetVetPer100Units());
            mEiwitPer100.SetValue(cdef->GetEiwitPer100Units());
            mKoolhydratenPer100.SetValue(cdef->GetKoolhydratenPer100Units());
            mVezelsPer100.SetValue(cdef->GetVezelsPer100Units());
            mPuntenPer100.SetValue(cdef->GetPointsPer100Units());
        }
        else if (mChangedDefinitie->IsFixed())
        {
            // Definition is fixed
            WW::FixedVMDef* fdef = mChangedDefinitie->GetFixedVMDef();
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

    if (mChangedDefinitie != nullptr && mChangedDefinitie->IsFavourite())
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
    CEditPortieDialog dialog(mModel, *mChangedDefinitie, nullptr, mPortieListView.GetPorties(), this);
    INT_PTR nResponse = dialog.DoModal();
    if (nResponse == IDOK)
    {
        if (dialog.GetPortie() != nullptr) {
            mPortieListView.AddPortie(new WW::Portie(*dialog.GetPortie()));
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
        CEditPortieDialog dialog(mModel, *mChangedDefinitie, item->GetPortie(), mPortieListView.GetPorties(), this);
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
    assert(mChangedDefinitie != nullptr);

    mChangedDefinitie->SetUnit(WW::Unit(mModel, mUnitBox.GetString()));
    mChangedDefinitie->SetCategory(WW::CategorieNaam(mModel, mCategorie.GetString()));
    mChangedDefinitie->SetMerk(WW::MerkNaam(mModel, mMerk.GetString()));
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
    if (mChangedDefinitie == nullptr)
    {
        WW::CalculatedVMDef* vdef = new WW::CalculatedVMDef(mModel.GetCalculator());
        vdef->SetParameters(parameters);
        mChangedDefinitie = new WW::VMDefinitie(mModel.GetCalculator(), name, WW::Unit(mModel, mUnitBox.GetString()), vdef);
    }
    else if (!mChangedDefinitie->IsCalculated())
    {
        mChangedDefinitie->SetCalculated(parameters);
    }
    else
    {
        assert(mChangedDefinitie->GetCalculatedVMDef() != nullptr);
        mChangedDefinitie->GetCalculatedVMDef()->SetParameters(parameters);
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

    if (mChangedDefinitie == nullptr)
    {
        WW::FixedVMDef* vdef = new WW::FixedVMDef;
        vdef->SetPointsPer100Units(mPuntenPer100.GetValue() * amountFactor);
        mChangedDefinitie = new WW::VMDefinitie(mModel.GetCalculator(), name, WW::Unit(mModel, mUnitBox.GetString()), vdef);
    }
    else if (mChangedDefinitie->IsFixed())
    {
        mChangedDefinitie->GetFixedVMDef()->SetPointsPer100Units(mPuntenPer100.GetValue() * amountFactor);
    }
    else
    {
        mChangedDefinitie->SetFixed();
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

    mPortieListView.SetDefinition(mChangedDefinitie);

    return true;
}


bool CEditFoodDefDialog::FinalizeFixedData()
{
    if (!CreateFixedFood())
        return false;

    mPortieListView.SetDefinition(mChangedDefinitie);

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
    if (mDefinitie == nullptr && mModel.FindVoedingsmiddelDefinitie(name))
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

    if (mChangedDefinitie != nullptr)
    {
        if (mDefinitie == nullptr)
        {
            mDefinitie = std::make_unique<WW::VMDefinitie>(*mChangedDefinitie);
            mModel.Add(mDefinitie);
        }
        else
        {
            *mDefinitie = *mChangedDefinitie;
        }

        for (size_t i = 0; i < porties.size(); ++i)
            mDefinitie->AddPortie(porties[i]);
    }

    OnOK();
}

void CEditFoodDefDialog::OnEnChangeKcalper100()
{
    if (mChangedDefinitie != nullptr && mChangedDefinitie->IsCalculated())
    {
        double amountFactor = 100.0f / static_cast<double>(mEenheden.GetValue());
        mChangedDefinitie->GetCalculatedVMDef()->SetKCalPer100Units(mKCalPer100.GetValue() * amountFactor);
    }
}

void CEditFoodDefDialog::OnEnChangeVetper100()
{
    if (mChangedDefinitie != nullptr && mChangedDefinitie->IsCalculated())
    {
        double amountFactor = 100.0f / static_cast<double>(mEenheden.GetValue());
        mChangedDefinitie->GetCalculatedVMDef()->SetVetPer100Units(mVetPer100.GetValue() * amountFactor);
    }
}

void CEditFoodDefDialog::OnEnChangeEiwittenPer100()
{
    if (mChangedDefinitie != nullptr && mChangedDefinitie->IsCalculated())
    {
        double amountFactor = 100.0f / static_cast<double>(mEenheden.GetValue());
        mChangedDefinitie->GetCalculatedVMDef()->SetEiwitPer100Units(mEiwitPer100.GetValue() * amountFactor);
    }
}

void CEditFoodDefDialog::OnEnChangeKoolhydratenPer100()
{
    if (mChangedDefinitie != nullptr && mChangedDefinitie->IsCalculated())
    {
        double amountFactor = 100.0f / static_cast<double>(mEenheden.GetValue());
        mChangedDefinitie->GetCalculatedVMDef()->SetKoolhydratenPer100Units(mKoolhydratenPer100.GetValue() * amountFactor);
    }
}

void CEditFoodDefDialog::OnEnChangeVezelsPer100()
{
    if (mChangedDefinitie != nullptr && mChangedDefinitie->IsCalculated())
    {
        double amountFactor = 100.0f / static_cast<double>(mEenheden.GetValue());
        mChangedDefinitie->GetCalculatedVMDef()->SetVezelsPer100Units(mVezelsPer100.GetValue() * amountFactor);
    }
}


void CEditFoodDefDialog::SetCalculated(bool bCalculated)
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
    SetCalculated(true);
}

void CEditFoodDefDialog::OnBnClickedRadioVast()
{
    SetCalculated(false);
}

void CEditFoodDefDialog::OnBnClickedCancel()
{
    if (mDefinitie == nullptr)
        delete mChangedDefinitie;

    // Re-attach the original portions to the food
    for (size_t i = 0; i < mOriginalPorties.size(); ++i)
        mDefinitie->AddPortie(mOriginalPorties[i]);

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
    mChangedDefinitie->SetFavourite(IsDlgButtonChecked(IDC_CHECK_FAVOURITE) != FALSE);
}
