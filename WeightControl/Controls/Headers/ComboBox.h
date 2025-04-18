#pragma once

#include "afxcmn.h"
#include "Utilities/StrUtils.h"

namespace weight
{


class ComboBox: public CComboBox
{
public:
    ComboBox(const std::vector<std::string>& availableTexts, const std::string& anInitialText = "");

    void Initialize();
    void Fill();

    virtual void AddLines();

    std::string GetString() const;
    std::string GetEditString() const;
    void SetText(const std::string& aString);

    //{{AFX_MSG(weight::ComboBox)
  //afx_msg int                 OnCreate(LPCREATESTRUCT lpCreateStruxct);
    //}}AFX_MSG

    DECLARE_MESSAGE_MAP()

private:
    std::vector<std::string> m_availableTexts;
    std::string mInitialText;
};

} // namespace weight
