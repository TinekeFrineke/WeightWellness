//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#pragma once

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
namespace ww2019
{



class XmlPortie : public XmlClass
{
public:
    XmlPortie();
    ~XmlPortie() override;

    std::wstring Getnaam() const;
    std::wstring Geteenheden() const;
    void Setnaam(const std::wstring & anaam);
    void Seteenheden(const std::wstring & aeenheden);

private:
    XmlPortie(const XmlPortie& anOriginal) = delete;
    XmlPortie& operator=(const XmlPortie& anOriginal) = delete;

    std::wstring mnaam;
    std::wstring meenheden;
};


}
