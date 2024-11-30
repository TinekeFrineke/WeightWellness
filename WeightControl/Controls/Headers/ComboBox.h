#pragma once

#include "afxcmn.h"
#include "Utilities/StrUtils.h"

namespace weight
{


class Model;


class ComboBox: public CComboBox
{
public:
    ComboBox(const std::vector<std::wstring>& availableTexts, const std::wstring& anInitialText = _T(""));

    void Initialize();
    void Fill();

    virtual void AddLines();

    std::wstring GetString() const;
    std::wstring GetEditString() const;
    void SetText(const std::wstring& aString);

    //{{AFX_MSG(weight::ComboBox)
  //afx_msg int                 OnCreate(LPCREATESTRUCT lpCreateStruxct);
    //}}AFX_MSG

    DECLARE_MESSAGE_MAP()

private:
    std::vector<std::wstring> m_availableTexts;
    std::tstring mInitialText;
};

} // namespace weight
