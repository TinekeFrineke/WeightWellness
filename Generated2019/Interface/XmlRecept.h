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



class XmlRecept : public XmlClass
{
public:
    XmlRecept();
    ~XmlRecept() override;

    std::wstring Getnaam() const;
    std::wstring Getpunten() const;
    std::wstring Gethoeveelheid() const;
    void Setnaam(const std::wstring & anaam);
    void Setpunten(const std::wstring & apunten);
    void Sethoeveelheid(const std::wstring & ahoeveelheid);

private:
    XmlRecept(const XmlRecept& anOriginal) = delete;
    XmlRecept& operator=(const XmlRecept& anOriginal) = delete;

    std::wstring mnaam;
    std::wstring mpunten;
    std::wstring mhoeveelheid;
};


}
