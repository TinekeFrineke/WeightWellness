// EditReceptDefDialog.cpp : implementation file
//

#include "stdafx.h"

#include "editreceptdefdialog.h"

#include "model/LotFactory.h"
#include "model/ReceptDefinitie.h"

#include "FindVoedingsmiddel.h"
#include "ItemEditVisitor.h"

// EditReceptDefDialog dialog

IMPLEMENT_DYNAMIC(EditReceptDefDialog, CDialog)

BEGIN_MESSAGE_MAP(EditReceptDefDialog, CDialog)
    ON_BN_CLICKED(IDC_ADD, OnBnClickedAdd)
    ON_BN_CLICKED(IDOK, OnBnClickedOk)
    ON_BN_CLICKED(IDC_EDIT, OnBnClickedEdit)
    ON_NOTIFY(LVN_ITEMCHANGED, IDC_ITEMS_LIST, OnLvnItemchangedItemsList)
    ON_NOTIFY(NM_DBLCLK, IDC_ITEMS_LIST, OnNMDblclkItemsList)
    ON_EN_CHANGE(IDC_PORTIES, OnEnChangePorties)
    ON_BN_CLICKED(IDC_DELETE, OnBnClickedDelete)
END_MESSAGE_MAP()


EditReceptDefDialog::EditReceptDefDialog(std::shared_ptr<weight::IRepository<weight::ReceptDefinitie>> recipes,
                                         std::shared_ptr<weight::IRepository<weight::VMDefinitie>> foodDefinitions,
                                         std::shared_ptr<weight::PointsCalculator> calculator,
                                         std::shared_ptr<weight::IStringRepository> categories,
                                         std::shared_ptr<weight::IStringRepository> brands,
                                         weight::ReceptDefinitie& aRecept,
                                         CWnd* pParent)
    : CDialog(EditReceptDefDialog::IDD, pParent)
    , m_foodDefinitions(std::move(foodDefinitions))
    , m_recipes(std::move(recipes))
    , m_calculator(std::move(calculator))
    , m_categories(std::move(categories))
    , m_brands(std::move(brands))
    , mRecept(aRecept)
{
}

EditReceptDefDialog::~EditReceptDefDialog()
{
}

void EditReceptDefDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_ITEMS_LIST, mItemList);
    DDX_Control(pDX, IDC_EDIT1, mName);
    DDX_Control(pDX, IDC_PUNTEN, mPointsPerPortion);
    DDX_Control(pDX, IDC_PORTIES, mPorties);
}


BOOL EditReceptDefDialog::OnInitDialog()
{
    if (CDialog::OnInitDialog() == FALSE)
        return FALSE;

    mItemList.Initialize();
    mName.SetValue(mRecept.GetName());
    mItemList.View(mRecept.GetItems());
    mPointsPerPortion.SetValue(mRecept.GetPointsPerPortion());
    mPorties.SetValue(mRecept.GetPortions());

    return TRUE;

}


void EditReceptDefDialog::EditSelectedItem()
{
    ItemListItem* item = mItemList.GetSelectedItem();
    if (item == nullptr)
        return;

    ItemEditVisitor visitor(m_recipes, m_foodDefinitions, m_calculator, this);
    item->GetItem()->Accept(visitor);

    mItemList.View(mRecept.GetItems());
    mPointsPerPortion.SetValue(mRecept.GetPointsPerPortion());
    mPorties.SetValue(mRecept.GetPortions());
}


// EditReceptDefDialog message handlers

void EditReceptDefDialog::OnBnClickedAdd()
{
    CFindVoedingsmiddel dialog(*m_foodDefinitions, *m_categories, *m_brands,
                               std::make_unique<weight::LotFactory>(m_calculator), this);
    INT_PTR nResponse = dialog.DoModal();
    if (nResponse == IDOK)
    {
        auto voedingsMiddel = dialog.ExtractVoedingsMiddel();
        if (voedingsMiddel != nullptr) {
            mRecept.Add(std::move(voedingsMiddel));
        }
    }

    mPointsPerPortion.SetValue(mRecept.GetPointsPerPortion());
    mItemList.View(mRecept.GetItems());
}

void EditReceptDefDialog::OnBnClickedOk()
{
    if (mName.GetValue().empty()) {
        MessageBox(L"Empty name not allowed!", L"ERROR");
        return;
    }

    mRecept.SetName(mName.GetValue());
    mRecept.SetPortions(mPorties.GetValue());

    OnOK();
}


void EditReceptDefDialog::OnBnClickedEdit()
{
    EditSelectedItem();
}


void EditReceptDefDialog::OnLvnItemchangedItemsList(NMHDR* pNMHDR, LRESULT* pResult)
{
    LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
    (void)pNMLV;
    *pResult = 0;
}

void EditReceptDefDialog::OnNMDblclkItemsList(NMHDR* pNMHDR, LRESULT* pResult)
{
    (void)pNMHDR;

    EditSelectedItem();

    *pResult = 0;
}

void EditReceptDefDialog::OnEnChangePorties()
{
    mRecept.SetPortions(mPorties.GetValue());
    mPointsPerPortion.SetValue(mRecept.GetPointsPerPortion());
}

void EditReceptDefDialog::OnBnClickedDelete()
{
    ItemListItem* item = mItemList.GetSelectedItem();
    if (item == nullptr)
        return;

    mRecept.Remove(item->GetItem());

    mItemList.View(mRecept.GetItems());
    mPointsPerPortion.SetValue(mRecept.GetPointsPerPortion());
    mPorties.SetValue(mRecept.GetPortions());
}
