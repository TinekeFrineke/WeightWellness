// EditReceptDefDialog.cpp : implementation file
//

#include "stdafx.h"
#include "WeightControl.h"
#include ".\editreceptdefdialog.h"

#include "FindVoedingsmiddel.h"
#include "ItemEditVisitor.h"

#include "model/LotFactory.h"
#include "model/ReceptDefinitie.h"

// EditReceptDefDialog dialog

IMPLEMENT_DYNAMIC(EditReceptDefDialog, CDialog)
EditReceptDefDialog::EditReceptDefDialog(WW::Model& aModel, WW::ReceptDefinitie* aRecept, CWnd* pParent /*=nullptr*/)
    : CDialog(EditReceptDefDialog::IDD, pParent),
    mModel(aModel),
    mItemList(aModel),
    mRecept(aRecept)
{
}

EditReceptDefDialog::~EditReceptDefDialog()
{
}

std::unique_ptr<WW::ReceptDefinitie> EditReceptDefDialog::ExtractRecept()
{
    return std::move(mRecept);
}

void EditReceptDefDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_ITEMS_LIST, mItemList);
    DDX_Control(pDX, IDC_EDIT1, mName);
    DDX_Control(pDX, IDC_PUNTEN, mPointsPerPortion);
    DDX_Control(pDX, IDC_PORTIES, mPorties);
}


BEGIN_MESSAGE_MAP(EditReceptDefDialog, CDialog)
    ON_BN_CLICKED(IDC_ADD, OnBnClickedAdd)
    ON_BN_CLICKED(IDOK, OnBnClickedOk)
    ON_BN_CLICKED(IDC_EDIT, OnBnClickedEdit)
    ON_NOTIFY(LVN_ITEMCHANGED, IDC_ITEMS_LIST, OnLvnItemchangedItemsList)
    ON_NOTIFY(NM_DBLCLK, IDC_ITEMS_LIST, OnNMDblclkItemsList)
    ON_EN_CHANGE(IDC_PORTIES, OnEnChangePorties)
    ON_BN_CLICKED(IDC_DELETE, OnBnClickedDelete)
END_MESSAGE_MAP()


BOOL EditReceptDefDialog::OnInitDialog()
{
    if (CDialog::OnInitDialog() == FALSE)
        return FALSE;

    mItemList.Initialize();
    if (mRecept == 0)
    {
        mPointsPerPortion.SetValue(0);
        mPorties.SetValue(4);
    }
    else
    {
        mName.SetValue(mRecept->GetName());
        mItemList.View(mRecept->GetItems());
        mPointsPerPortion.SetValue(mRecept->GetPointsPerPortion());
        mPorties.SetValue(mRecept->GetPortions());
    }

    return TRUE;

}


void EditReceptDefDialog::EditSelectedItem()
{
    ItemListItem* item = mItemList.GetSelectedItem();
    if (item == nullptr || mRecept == nullptr)
        return;

    ItemEditVisitor visitor(mModel, this);
    item->GetItem()->Accept(visitor);

    mItemList.View(mRecept->GetItems());
    mPointsPerPortion.SetValue(mRecept->GetPointsPerPortion());
    mPorties.SetValue(mRecept->GetPortions());
}


// EditReceptDefDialog message handlers

void EditReceptDefDialog::OnBnClickedAdd()
{
    if (mRecept == nullptr) {
        if (mName.GetValue().empty()) {
            ::MessageBox(0, _T("Type name"), _T("ERROR"), MB_OK);
            return;
        }

        if (mModel.FindReceptDefinitie(mName.GetValue()) != nullptr)
        {
            ::MessageBox(0, _T("Duplicate recept name"), _T("ERROR"), MB_OK);
            return;
        }

        mRecept = std::make_unique<WW::ReceptDefinitie>(mName.GetValue());
    }

    CFindVoedingsmiddel dialog(mModel, nullptr, std::make_unique<WW::LotFactory>(mModel.GetCalculator()), this);
    INT_PTR nResponse = dialog.DoModal();
    if (nResponse == IDOK)
    {
        auto voedingsMiddel = dialog.ExtractVoedingsMiddel();
        if (voedingsMiddel != nullptr) {
            mRecept->Add(std::move(voedingsMiddel));
        }
    }

    mPointsPerPortion.SetValue(mRecept->GetPointsPerPortion());
    mItemList.View(mRecept->GetItems());
}

void EditReceptDefDialog::OnBnClickedOk()
{
    if (mRecept == nullptr)
        return;

    mRecept->SetPortions(mPorties.GetValue());

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
    if (mRecept == nullptr)
        return;

    mRecept->SetPortions(mPorties.GetValue());
    mPointsPerPortion.SetValue(mRecept->GetPointsPerPortion());
}

void EditReceptDefDialog::OnBnClickedDelete()
{
    ItemListItem* item = mItemList.GetSelectedItem();
    if (item == nullptr || mRecept == nullptr)
        return;

    mRecept->Remove(item->GetItem());

    mItemList.View(mRecept->GetItems());
    mPointsPerPortion.SetValue(mRecept->GetPointsPerPortion());
    mPorties.SetValue(mRecept->GetPortions());
}
