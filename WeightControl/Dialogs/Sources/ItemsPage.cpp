// ItemsPage.cpp : implementation file
//

#include "stdafx.h"
#include "afxmsg_.h"

#include "model/IFoodDefinitionRepository.h"
#include "model/IRepository.h"
#include "model/VoedingsmiddelDefinitie.h"

#include "ItemsPage.h"

#include "EditFoodDefDialog.h"
#include "FoodDefinitionEditor.h"

#include ".\itemspage.h"


// CItemsPage dialog

IMPLEMENT_DYNAMIC(CItemsPage, CDialog)
CItemsPage::CItemsPage(weight::Model& aModel, CWnd* pParent /*=nullptr*/)
    : CDialog(CItemsPage::IDD, pParent)
    , mModel(aModel)
    , mCategory(aModel.GetCategoryRepository()->Get())
    , mMerk(aModel.GetBrandRepository()->Get(), true)
    , mItemsList({}/*aModel.GetFoodDefinitionRepository()->GetAll()*/)
    , mUpdatingFilter(false)
{
}

CItemsPage::~CItemsPage()
{
}

void CItemsPage::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_ITEMLIST, mItemsList);
    DDX_Control(pDX, IDC_NAAM, mNaam);
    DDX_Control(pDX, IDC_COMBO1, mCategory);
    DDX_Control(pDX, IDC_BRAND, mMerk);
}


BEGIN_MESSAGE_MAP(CItemsPage, CDialog)
    ON_WM_SHOWWINDOW()
    ON_BN_CLICKED(IDC_ADD, OnBnClickedAdd)
    ON_BN_CLICKED(IDC_EDIT, OnBnClickedEdit)
    ON_BN_CLICKED(IDC_DELETE, OnBnClickedDelete)
    ON_NOTIFY(NM_DBLCLK, IDC_ITEMLIST, OnNMDblclkItemlist)
    ON_EN_CHANGE(IDC_NAAM, OnEnChangeNaam)
    ON_CBN_SELCHANGE(IDC_COMBO1, OnCbnSelchangeCombo1)
    ON_CBN_SELCHANGE(IDC_BRAND, OnCbnSelchangeBrand)
    ON_CBN_EDITCHANGE(IDC_COMBO1, OnCbnEditchangeCombo1)
    ON_BN_CLICKED(IDC_CHECK_FAVOURITES, OnBnClickedCheckFavourites)
END_MESSAGE_MAP()


// CItemsPage message handlers


BOOL CItemsPage::OnInitDialog()
{
    if (CDialog::OnInitDialog() == FALSE)
        return FALSE;

    mItemsList.Initialize();

    mCategory.Initialize();
    mCategory.Fill();

    mMerk.Initialize();
    mMerk.Fill();

    return TRUE;
}

void CItemsPage::OnBnClickedAdd()
{
    FoodDefinitionEditor editor(mModel, this);
    auto food = editor.Create();
    if (food != nullptr) {
        mModel.Add(std::move(food));
        mItemsList.SetDefinitions(mModel.GetFoodDefinitionRepository()->GetAll());
        mItemsList.Fill();
    }
}

void CItemsPage::OnBnClickedEdit()
{
    EditItem();
}

void CItemsPage::OnCancel()
{
}

void CItemsPage::OnShowWindow(BOOL bShow, UINT nStatus)
{
    if (bShow == TRUE)
        mItemsList.SetDefinitions(mModel.GetFoodDefinitionRepository()->GetAll());
    CDialog::OnShowWindow(bShow, nStatus);
}

void CItemsPage::OnBnClickedDelete()
{
    auto definition = mItemsList.GetSelectedDefinition();
    if (definition == nullptr)
        return;

    if (mModel.Remove(definition)) {
        mItemsList.SetDefinitions(mModel.GetFoodDefinitionRepository()->GetAll());
    }
}


void CItemsPage::EditItem()
{
    auto definition = mItemsList.GetSelectedDefinition();
    if (definition != nullptr) {
        FoodDefinitionEditor editor(mModel, this);
        if (editor.Edit(*definition))
        {
            mItemsList.SelectItem(*definition);
            // TODO ww2024: Place code here to handle when the dialog is
            // dismissed with OK
        }
    }
}


void CItemsPage::UpdateItemFilter()
{
    mItemsList.SetFilter(VMDefinitiesFilter(mNaam.GetValue(),
                                            mCategory.GetString(),
                                            mMerk.GetString()));
    mItemsList.Fill();
}


void CItemsPage::OnNMDblclkItemlist(NMHDR* pNMHDR, LRESULT* pResult)
{
    (void)pNMHDR;
    EditItem();
    *pResult = 0;
}

void CItemsPage::OnEnChangeNaam()
{
    if (!mUpdatingFilter)
        UpdateItemFilter();
}

void CItemsPage::OnCbnSelchangeCombo1()
{
    if (!mUpdatingFilter)
        UpdateItemFilter();
}

void CItemsPage::OnCbnSelchangeBrand()
{
    if (!mUpdatingFilter)
        UpdateItemFilter();
}

void CItemsPage::OnCbnEditchangeCombo1()
{
    if (mCategory.GetEditString().empty())
        mCategory.SetCurSel(-1);

    if (!mUpdatingFilter)
        UpdateItemFilter();
}

void CItemsPage::OnBnClickedCheckFavourites()
{
    mItemsList.SetFavouritesOnly(IsDlgButtonChecked(IDC_CHECK_FAVOURITES) != FALSE);
    mItemsList.Fill();
}
