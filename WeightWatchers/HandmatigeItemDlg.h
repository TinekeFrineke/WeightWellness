#pragma once
#include "stringedit.h"
#include "doubleedit.h"


// HandmatigeItemDlg dialog

namespace WW { class ManualItem; } 

class HandmatigeItemDlg : public CDialog
{
	DECLARE_DYNAMIC(HandmatigeItemDlg)

public:
	HandmatigeItemDlg(WW::ManualItem * anItem = NULL, CWnd* pParent = NULL);   // standard constructor
	virtual ~HandmatigeItemDlg();

// Dialog Data
	enum { IDD = IDD_HANDMATIG_ITEM };

  WW::ManualItem *  GetItem() { return mItem; }

protected:
	virtual void      DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
  BOOL              OnInitDialog();

	DECLARE_MESSAGE_MAP()

  afx_msg void      OnBnClickedOk();

private:
  CStringEdit       mName;
  CDoubleEdit       mAmount;
  CDoubleEdit       mPoints;

  WW::ManualItem *  mItem;
};
