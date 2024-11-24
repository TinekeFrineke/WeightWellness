//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#pragma once

#include <xercesc/util/xercesdefs.hpp>
#include <memory>
#include <vector>

#include "XmlClass.h"

// Includes for children

namespace ww2019
{


class XmlStandardlot;


class XmlVoedingsmiddel : public XmlClass
{
public:
    XmlVoedingsmiddel();
    ~XmlVoedingsmiddel() override;

    const XmlStandardlot * GetStandardlot() const;
    void Add(std::unique_ptr<XmlStandardlot> aStandardlot);
    std::wstring Getnaam() const;
    std::wstring Getcategorie() const;
    std::wstring Getmerk() const;
    std::wstring Getunit() const;
    void Setnaam(const std::wstring & anaam);
    void Setcategorie(const std::wstring & acategorie);
    void Setmerk(const std::wstring & amerk);
    void Setunit(const std::wstring & aunit);

private:
    XmlVoedingsmiddel(const XmlVoedingsmiddel& anOriginal) = delete;
    XmlVoedingsmiddel& operator=(const XmlVoedingsmiddel& anOriginal) = delete;

    std::unique_ptr<XmlStandardlot> mStandardlot;
    std::wstring mnaam;
    std::wstring mcategorie;
    std::wstring mmerk;
    std::wstring munit;
};


}
