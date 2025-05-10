// ItemsPage.cpp : implementation file
//

#include "stdafx.h"
#include "afxmsg_.h"

#include "model/IFoodDefinitionRepository.h"
#include "model/IRepository.h"
#include "model/IStringRepository.h"
#include "model/VoedingsmiddelDefinitie.h"

#include "IPageFactory.h"
#include "ItemsPage.h"

#include "EditFoodDefDialog.h"
#include "FoodDefinitionEditor.h"

#include ".\itemspage.h"


// CItemsPage dialog

IMPLEMENT_DYNAMIC(CItemsPage, CDialog)


CItemsPage::CItemsPage(std::shared_ptr<weight::IFoodDefinitionRepository> foodDefinitions, const IPageFactory& factory, CWnd* pParent)
    : CDialog(CItemsPage::IDD, pParent)
    , m_pageFactory(factory)
    , mCategory(foodDefinitions->GetCategoryRepository()->Get())
    , mMerk(foodDefinitions->GetBrandRepository()->Get(), true)
    , mItemsList({})
    , mUpdatingFilter(false)
    , m_foodDefinitions(std::move(foodDefinitions))
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
    auto editor(m_pageFactory.CreateFoodDefinitionEditor(this));
    auto food = editor->Create();
    if (food != nullptr) {
        m_foodDefinitions->Add(std::move(food));
        mItemsList.SetDefinitions(m_foodDefinitions->GetAll());
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
        mItemsList.SetDefinitions(m_foodDefinitions->GetAll());
    CDialog::OnShowWindow(bShow, nStatus);
}

void CItemsPage::OnBnClickedDelete()
{
    auto definition = mItemsList.GetSelectedDefinition();
    if (definition == nullptr)
        return;

    if (m_foodDefinitions->Remove(definition->GetName())) {
        mItemsList.SetDefinitions(m_foodDefinitions->GetAll());
    }
}


void CItemsPage::EditItem()
{
    auto definition = mItemsList.GetSelectedDefinition();
    if (definition != nullptr) {
        auto editor(m_pageFactory.CreateFoodDefinitionEditor(this));
        if (editor->Edit(*definition))
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
