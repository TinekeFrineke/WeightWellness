#pragma once

#include "afxcmn.h"
#include "Utilities/StrUtils.h"

namespace WW
{


class Model;


class ComboBox : public CComboBox
{
public:
                              ComboBox(const WW::Model &    aModel,
                                       const std::tstring & anInitialText = _T(""));

  void                        Initialize();
  void                        Fill();

  virtual void                AddLines() = 0;

  std::tstring                GetString() const;
  std::tstring                GetEditString() const;
  void                        SetString(const std::tstring & aString);

	//{{AFX_MSG(WW::ComboBox)
  //afx_msg int                 OnCreate(LPCREATESTRUCT lpCreateStruxct);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

protected:
  const WW::Model &           GetModel() const { return mModel; }

private:
  const WW::Model &           mModel;
  std::tstring                mInitialText;
};

} // namespace WW
