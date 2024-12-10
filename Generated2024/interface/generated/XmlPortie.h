//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#pragma once

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

namespace ww2024
{



class XmlPortie : public XmlClass
{
public:
    XmlPortie();
    ~XmlPortie() override;

    std::wstring Getnaam() const;
    double Geteenheden() const;
    void Setnaam(const std::wstring & anaam);
    void Seteenheden(double aeenheden);

private:
    XmlPortie(const XmlPortie& anOriginal) = delete;
    XmlPortie& operator=(const XmlPortie& anOriginal) = delete;

    std::wstring mnaam;
    double meenheden;
};


}
