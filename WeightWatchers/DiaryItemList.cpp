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


#include "WW/WWModel/Day.h"
#include "WW/WWModel/Item.h"

/////////////////////////////////////////////////////////////////////////////
// CDiaryItemList

CDiaryItemList::CDiaryItemList(WW::Model & aModel)
: ItemList(aModel),
  mDate   (Utils::Date::Today()),
  mDay    (NULL)
{
}

CDiaryItemList::~CDiaryItemList()
{
  ClearItems();
}


void CDiaryItemList::View(WW::Day * aDay)
{
  if (aDay == NULL)
  {
    DeleteAllItems();
    ClearItems();
  }
  else
  {
    ItemList::View(aDay->GetItems());
  }
}


void CDiaryItemList::Update(Subject * aSubject)
{
  (void)aSubject;
}


void CDiaryItemList::Destroyed(Subject * aSubject)
{
  (void)aSubject;
}


BEGIN_MESSAGE_MAP(CDiaryItemList, CListCtrl)
	//{{AFX_MSG_MAP(CDiaryItemList)
	//ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
//// CDiaryItemList message handlers
//
//void CDiaryItemList::OnLButtonDown(UINT nFlags, CPoint point) 
//{
//  (void)nFlags;
//  (void)point;
//}
