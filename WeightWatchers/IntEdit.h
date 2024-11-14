#pragma once

#include "afxcmn.h"


class CIntEdit : public CEdit
{
public:
  int                 GetValue() const;
  void                SetValue(int aValue);

protected:
	//{{AFX_MSG(CIntEdit)
  afx_msg void OnKillFocus( CWnd* );
  afx_msg void OnChar( UINT, UINT, UINT );
//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

private:
  bool CheckContents();
};
