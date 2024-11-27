#pragma once

#include <memory>

#include "afxcmn.h"
#include "Utilities/StrUtils.h"

namespace WW
{
  class Model;
  class Portie;
  class PortieNaam;
}

class PortieComboBox : public CComboBox
{
public:
                              PortieComboBox(const WW::Model &    aModel,
                                             const std::tstring & aPortie);
  void                        Initialize();
  void                        Fill(const std::vector<WW::PortieNaam> & aNames, const std::tstring & aPortie = _T(""));
  void                        Fill(const std::vector<std::unique_ptr<WW::Portie>> & aList, const std::tstring & aPortie = _T(""));

  std::tstring                GetString() const;
  void                        SetString(const std::tstring & aString);

  WW::Portie *                GetSelectedPortie();

	//{{AFX_MSG(PortieComboBox)
  //afx_msg int                 OnCreate(LPCREATESTRUCT lpCreateStruxct);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

private:
  const WW::Model &           mModel;
  std::tstring                mInitialPortie;
};
