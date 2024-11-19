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



class XmlVoedingsmiddelheader : public XmlClass
{
public:
    XmlVoedingsmiddelheader();
    ~XmlVoedingsmiddelheader() override;

    std::wstring Getnaam() const;
    std::wstring Getcategorie() const;
    std::wstring Getmerk() const;
    std::wstring Getunit() const;
    void Setnaam(const std::wstring & anaam);
    void Setcategorie(const std::wstring & acategorie);
    void Setmerk(const std::wstring & amerk);
    void Setunit(const std::wstring & aunit);

private:
    XmlVoedingsmiddelheader(const XmlVoedingsmiddelheader& anOriginal) = delete;
    XmlVoedingsmiddelheader& operator=(const XmlVoedingsmiddelheader& anOriginal) = delete;

    std::wstring mnaam;
    std::wstring mcategorie;
    std::wstring mmerk;
    std::wstring munit;
};


}
