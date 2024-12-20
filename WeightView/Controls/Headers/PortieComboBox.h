#pragma once

#include <memory>

#include "afxcmn.h"
#include "Utilities/StrUtils.h"

namespace weight
{
class Model;
class Portie;
}

class PortieComboBox: public CComboBox
{
public:
    PortieComboBox(const std::wstring& aPortie);
    void Initialize();
    void Fill(const std::vector<std::wstring>& aNames, const std::tstring& aPortie = _T(""));
    void Fill(const std::vector<std::unique_ptr<weight::Portie>>& aList, const std::tstring& aPortie = _T(""));

    std::wstring GetString() const;
    void SetString(const std::wstring& aString);

    weight::Portie* GetSelectedPortie();

    //{{AFX_MSG(PortieComboBox)
  //afx_msg int                 OnCreate(LPCREATESTRUCT lpCreateStruxct);
    //}}AFX_MSG

    DECLARE_MESSAGE_MAP()

private:
    std::wstring mInitialPortie;
};
