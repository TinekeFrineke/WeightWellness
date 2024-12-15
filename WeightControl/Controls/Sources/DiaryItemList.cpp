#include "stdafx.h"

#include "DiaryItemList.h"

/////////////////////////////////////////////////////
// This class is provided as is and Ben Hill takes no
// responsibility for any loss of any kind in connection
// to this code.
/////////////////////////////////////////////////////
// Is is meant purely as a educational tool and may
// contain bugs.
/////////////////////////////////////////////////////
// ben@shido.fsnet.co.uk
// http://www.shido.fsnet.co.uk
/////////////////////////////////////////////////////
// Thanks to a mystery poster in the C++ forum on 
// www.codeguru.com I can't find your name to say thanks
// for your Control drawing code. If you are that person 
// thank you very much. I have been able to use some of 
// you ideas to produce this sample application.
/////////////////////////////////////////////////////


#include "model/Day.h"
#include "model/Item.h"

/////////////////////////////////////////////////////////////////////////////
// CDiaryItemList

CDiaryItemList::CDiaryItemList(weight::Model& aModel)
    : ItemList(aModel)
    , mDate(Utils::Date::Today())
    , mDay(nullptr)
{
}

CDiaryItemList::~CDiaryItemList()
{
    ClearItems();
}


void CDiaryItemList::View(weight::Day* aDay)
{
    if (aDay == nullptr)
    {
        DeleteAllItems();
        ClearItems();
    }
    else
    {
        ItemList::View(aDay->GetItems());
    }
}


BEGIN_MESSAGE_MAP(CDiaryItemList, CListCtrl)
    //{{AFX_MSG_MAP(CDiaryItemList)
    //ON_WM_LBUTTONDOWN()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()
