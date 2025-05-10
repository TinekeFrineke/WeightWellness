#pragma once

#include <memory>

#include "afxcmn.h"
#include "Utilities/StrUtils.h"

namespace weight
{
class Portie;
}

class PortieComboBox: public CComboBox
{
public:
    PortieComboBox(const std::string& aPortie);
    void Initialize();
    void Fill(const std::vector<std::string>& aNames, const std::string& aPortie = "");
    void Fill(const std::vector<std::unique_ptr<weight::Portie>>& aList, const std::string& aPortie = "");

    std::string GetString() const;
    void SetString(const std::string& aString);

    weight::Portie* GetSelectedPortie();

    //{{AFX_MSG(PortieComboBox)
  //afx_msg int                 OnCreate(LPCREATESTRUCT lpCreateStruxct);
    //}}AFX_MSG

    DECLARE_MESSAGE_MAP()

private:
    std::string mInitialPortie;
};
