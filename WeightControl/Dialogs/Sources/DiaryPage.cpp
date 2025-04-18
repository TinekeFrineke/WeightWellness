// DiaryPage.cpp : implementation file
//

#include "stdafx.h"

#include "DiaryPage.h"

#include "model/IDay.h"
#include "model/IFoodDefinitionRepository.h"
#include "model/IModel.h"
#include "model/IWeek.h"
#include "model/IWeekRepository.h"
#include "model/LotFactory.h"
#include "model/ManualItem.h"
#include "model/ModelFactory.h"
#include "model/Personalia.h"
#include "model/Recept.h"
#include "model/Voedingsmiddel.h"

#include "BewegingDialog.h"
#include "EditBonuses.h"
#include "FindRecept.h"
#include "FindVoedingsmiddel.h"
#include "HandmatigeItemDlg.h"
#include "ItemEditVisitor.h"
#include "WeightControl.h"


// CDiaryPage dialog

IMPLEMENT_DYNAMIC(CDiaryPage, CDialog)
void CDiaryPage::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_ITEMLIST, mItemList);
    DDX_Control(pDX, IDC_PUNTEN, mPunten);
    DDX_Control(pDX, IDC_WEEK_EINDE, mEndOfWeek);
    DDX_Control(pDX, IDC_WEEK_BEGIN, mStartOfWeek);
    DDX_Control(pDX, IDC_BONUSPUNTEN, mBonusPoints);
    DDX_Control(pDX, IDC_PUNTEN_OVER, mPointsLeft);
    DDX_Control(pDX, IDC_DATE, mDate);
    DDX_Control(pDX, IDC_WEIGHT, mWeight);
    DDX_Control(pDX, IDC_TOTAAL, mTotaal);
    DDX_Control(pDX, IDC_STRATEGIE, mStrategie);
    DDX_Control(pDX, IDC_WEEKPUNTEN, mWeekPunten);
    DDX_Control(pDX, IDC_WEEKPUNTENSTATIC, mWeekpuntenStatic);
    DDX_Control(pDX, IDC_CALCULATEDBONUS, mCalculatedBonusPoints);
}


BEGIN_MESSAGE_MAP(CDiaryPage, CDialog)
    ON_BN_CLICKED(IDC_ADD_FOOD, OnBnClickedAddFood)
    ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_WEEK_EINDE, OnDeltaposSpinWeekEinde)
    ON_EN_CHANGE(IDC_BONUSPUNTEN, OnEnChangeBonuspunten)
    ON_BN_CLICKED(IDC_DAY_MINUS, OnBnClickedDayMinus)
    ON_BN_CLICKED(IDC_DAY_PLUS, OnBnClickedDayPlus)
    ON_BN_CLICKED(IDC_ADD_RECEPT, OnBnClickedAddRecept)
    ON_BN_CLICKED(IDC_EDIT, OnBnClickedEdit)
    ON_BN_CLICKED(IDC_DELETE, OnBnClickedDelete)
    ON_EN_CHANGE(IDC_WEIGHT, OnEnChangeWeight)
    ON_BN_CLICKED(IDC_ADD_HANDMATIG, OnBnClickedAddHandmatig)
    ON_NOTIFY(NM_DBLCLK, IDC_ITEMLIST, OnNMDblclkItemlist)
    ON_WM_SHOWWINDOW()
    ON_EN_CHANGE(IDC_WEEK_EINDE, OnEnChangeWeekEinde)
    ON_BN_CLICKED(IDC_ADDBONUS, &CDiaryPage::OnBnClickedAddbonus)
END_MESSAGE_MAP()


CDiaryPage::CDiaryPage(weight::IModel& aModel, std::shared_ptr<weight::IMessageHandler> messageHandler, CWnd* pParent)
    : CDialog(CDiaryPage::IDD, pParent)
    , mModel(aModel)
    , m_messageHandler(messageHandler)
{
}

CDiaryPage::~CDiaryPage()
{
}

BOOL CDiaryPage::OnInitDialog()
{
    if (CDialog::OnInitDialog() == FALSE)
        return FALSE;

    mItemList.Initialize();
    mItemList.SetSelectionMark(0);
    mItemList.ShowWindow(SW_SHOW);

    ProcessDate(Utils::Today());
    UpdatePointsLeft();

    return TRUE;
}


void CDiaryPage::OnCancel()
{
}


bool CDiaryPage::ProcessDate(const Utils::Date& aDate)
{
    mWeek = mModel.GetWeekRepository()->FindWeekContaining(aDate);
    if (mWeek == nullptr)
        mWeek = mModel.CreateWeek(aDate);
    if (mWeek == nullptr)
        return false;

    switch (mWeek->GetStrategy())
    {
        case weight::STRATEGY_TYPE::KCal:
            mStrategie.SetValue(_T("KCal"));
            break;
        case weight::STRATEGY_TYPE::CarboHydrates:
            mStrategie.SetValue(_T("CarboHydrates"));
            break;
        default:
            assert(false);
    }

    mPunten.SetValue(mWeek->GetPoints());
    mDate.SetValue(Utils::ToString(aDate));
    mStartOfWeek.SetValue(Utils::ToString(mWeek->GetStartDate()));
    mEndOfWeek.SetValue(Utils::ToString(mWeek->GetEndDate()));

    mDay = mWeek->GetDay(aDate);
    if (mDay == nullptr)
    {
        auto day = weight::ModelFactory(m_messageHandler).CreateDay(aDate);
        mDay = day.get();
        mDay->SetWeight(mModel.GetPersonalia()->GetHuidigGewicht());
        mWeek->Add(std::move(day));
    }

    mItemList.View(mDay);
    mBonusPoints.SetValue(mDay->GetFreeBonusPoints());
    mCalculatedBonusPoints.SetValue(mDay->GetCalculatedBonusPoints());
    mWeight.SetValue(mDay->GetWeight());

    return true;
}


void CDiaryPage::OnBnClickedAddFood()
{
    CFindVoedingsmiddel dialog(*mModel.GetFoodDefinitionRepository(),
                               *mModel.GetFoodDefinitionRepository()->GetCategoryRepository(),
                               *mModel.GetFoodDefinitionRepository()->GetBrandRepository(),
                               std::make_unique<weight::LotFactory>(mModel.GetCalculator()), this);
    INT_PTR nResponse = dialog.DoModal();
    if (nResponse == IDOK)
    {
        auto food = dialog.ExtractVoedingsMiddel();
        if (food != nullptr)
        {
            mDay->Add(std::move(food));
            mItemList.View(mDay);
            UpdatePointsLeft();
        }
    }
}

void CDiaryPage::OnDeltaposSpinWeekEinde(NMHDR* pNMHDR, LRESULT* pResult)
{
    LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);

    Utils::Date date(Utils::ToDate(mEndOfWeek.GetValue()));
    if (pNMUpDown->iDelta < 0) {
        if (date > mWeek->GetStartDate()) {
            int diff = date.DaysDifference(mWeek->GetStartDate());
            if (diff < 14)
                date.AddDays(1);
        }

        mEndOfWeek.SetValue(Utils::ToString(date));
    }
    else {
        if (date > mWeek->GetStartDate() &&
            date > Utils::Today()) {
            int diff(date.DaysDifference(mWeek->GetStartDate()));
            if (diff > 3)
                date.SubtractDays(1);
        }

        mEndOfWeek.SetValue(Utils::ToString(date));
    }

    *pResult = 0;
}


void CDiaryPage::UpdatePointsLeft()
{
    if (mWeek == nullptr || mDay == nullptr)
        return;

    mPointsLeft.SetValue(mWeek->GetPointsLeft(mDay->GetDate()));
    mWeekPunten.SetValue(mWeek->GetWeekPointsLeft(mDay->GetDate()));
    mTotaal.SetValue(mDay->GetPoints());
}

void CDiaryPage::OnEnChangeBonuspunten()
{
    mDay->SetFreeBonusPoints(mBonusPoints.GetValue());
    UpdatePointsLeft();
}

void CDiaryPage::OnBnClickedDayMinus()
{
    Utils::Date date(Utils::ToDate(mDate.GetValue()));
    date.SubtractDays(1);
    ProcessDate(date);
}

void CDiaryPage::OnBnClickedDayPlus()
{
    Utils::Date date(Utils::ToDate(mDate.GetValue()));
    date.AddDays(1);
    if (date <= Utils::Today())
        ProcessDate(date);
}

void CDiaryPage::OnBnClickedAddRecept()
{
    CFindRecept dialog(mModel.GetRecipeDefinitionRepository(), nullptr, this);
    INT_PTR nResponse = dialog.DoModal();
    if (nResponse == IDOK)
    {
        auto recept = dialog.ExtractRecept();
        if (recept != nullptr)
        {
            mDay->Add(std::move(recept));
            mItemList.View(mDay);
            UpdatePointsLeft();
        }
    }
}

void CDiaryPage::EditItem(weight::Item& item)
{
    ItemEditVisitor visitor(mModel.GetRecipeDefinitionRepository(), mModel.GetFoodDefinitionRepository(),
                            mModel.GetCalculator(), this);
    item.Accept(visitor);

    mItemList.View(mDay);
    UpdatePointsLeft();
}


void CDiaryPage::OnBnClickedEdit()
{
    ItemListItem* item = mItemList.GetSelectedItem();
    if (item == nullptr || item->GetItem() == nullptr)
        return;

    EditItem(*item->GetItem());
}

void CDiaryPage::OnBnClickedDelete()
{
    ItemListItem* item = mItemList.GetSelectedItem();
    if (item == nullptr)
        return;

    mDay->Remove(item->GetItem());

    mItemList.View(mDay);
    UpdatePointsLeft();
}


void CDiaryPage::OnEnChangeWeight()
{
    mDay->SetWeight(mWeight.GetValue());
    mModel.GetPersonalia()->SetHuidigGewicht(mDay->GetWeight());
}


void CDiaryPage::OnBnClickedAddHandmatig()
{
    HandmatigeItemDlg dialog(nullptr, this);
    INT_PTR nResponse = dialog.DoModal();
    if (nResponse == IDOK)
    {
        //  dismissed with OK
        auto item = dialog.GetItem();
        if (item != nullptr)
        {
            mDay->Add(std::move(item));
            mItemList.View(mDay);
            UpdatePointsLeft();
        }
    }
}

void CDiaryPage::OnNMDblclkItemlist(NMHDR* pNMHDR, LRESULT* pResult)
{
    LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

    *pResult = 0;

    ItemListItem* item = mItemList.GetItemAt(pNMLV->iItem);
    if (item == nullptr || item->GetItem() == 0)
        return;

    EditItem(*item->GetItem());
}

void CDiaryPage::OnShowWindow(BOOL bShow, UINT nStatus)
{
    CDialog::OnShowWindow(bShow, nStatus);

    if (mDay == nullptr) {
        MessageBox("Day == nulptr!!!", "FATAL ERROR", MB_OK);
        return;
    }

    mPunten.SetValue(mWeek->GetPoints());

    mDay->SetWeight(mModel.GetPersonalia()->GetHuidigGewicht());
    mBonusPoints.SetValue(mDay->GetFreeBonusPoints());
    mCalculatedBonusPoints.SetValue(mDay->GetCalculatedBonusPoints());
    mWeight.SetValue(mDay->GetWeight());

    mItemList.View(mDay);
}

void CDiaryPage::OnEnChangeWeekEinde()
{
    if (!mWeek->SetEndDate(Utils::ToDate(mEndOfWeek.GetValue())))
    {
        ::MessageBox(m_hWnd, ("Could not set end date " + mEndOfWeek.GetValue()).c_str(), "Error", MB_OK);
        return;
    }

    UpdatePointsLeft();
}

void CDiaryPage::OnBnClickedAddbonus()
{
    BewegingDialog dialog(mDay->GetCalculatedBonusPoints(), this);
    INT_PTR nResponse = dialog.DoModal();
    if (nResponse == IDOK) {
        weight::Bonus bonus{ weight::Bonus::INTENSITY::Medium, 1, static_cast<int>(dialog.GetBewegingsPunten()) };
        mDay->SetBonuses(std::list<weight::Bonus>({ bonus }));
        mCalculatedBonusPoints.SetValue(mDay->GetCalculatedBonusPoints());
    }
}
