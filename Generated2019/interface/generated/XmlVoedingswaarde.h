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



class XmlVoedingswaarde : public XmlClass
{
public:
    XmlVoedingswaarde();
    ~XmlVoedingswaarde() override;

    std::wstring Getkcalper100() const;
    std::wstring Getvetper100() const;
    std::wstring Getkoolhydratenper100() const;
    std::wstring Geteiwitper100() const;
    std::wstring Getvezelsper100() const;
    void Setkcalper100(const std::wstring & akcalper100);
    void Setvetper100(const std::wstring & avetper100);
    void Setkoolhydratenper100(const std::wstring & akoolhydratenper100);
    void Seteiwitper100(const std::wstring & aeiwitper100);
    void Setvezelsper100(const std::wstring & avezelsper100);

private:
    XmlVoedingswaarde(const XmlVoedingswaarde& anOriginal) = delete;
    XmlVoedingswaarde& operator=(const XmlVoedingswaarde& anOriginal) = delete;

    std::wstring mkcalper100;
    std::wstring mvetper100;
    std::wstring mkoolhydratenper100;
    std::wstring meiwitper100;
    std::wstring mvezelsper100;
};


}
