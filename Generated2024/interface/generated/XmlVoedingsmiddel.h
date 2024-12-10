//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#pragma once

#include <xercesc/util/xercesdefs.hpp>
#include <memory>
#include <vector>

#include "XmlClass.h"

namespace ww2024
{

// Forward declarations
class XmlPortie;
class XmlVoedingswaarde;


class XmlVoedingsmiddel : public XmlClass
{
public:
    XmlVoedingsmiddel();
    ~XmlVoedingsmiddel() override;

    const XmlPortie & GetPortie() const;
    XmlPortie & GetPortie();
    const XmlVoedingswaarde & GetVoedingswaarde() const;
    XmlVoedingswaarde & GetVoedingswaarde();
    void SetXmlPortie(std::unique_ptr<XmlPortie> aPortie);
    void SetXmlVoedingswaarde(std::unique_ptr<XmlVoedingswaarde> aVoedingswaarde);
    std::wstring Getnaam() const;
    std::wstring Getcategorie() const;
    std::wstring Getunit() const;
    double Getaantalporties() const;
    void Setnaam(const std::wstring & anaam);
    void Setcategorie(const std::wstring & acategorie);
    void Setunit(const std::wstring & aunit);
    void Setaantalporties(double aaantalporties);

private:
    XmlVoedingsmiddel(const XmlVoedingsmiddel& anOriginal) = delete;
    XmlVoedingsmiddel& operator=(const XmlVoedingsmiddel& anOriginal) = delete;

    std::unique_ptr<XmlPortie> mPortie;
    std::unique_ptr<XmlVoedingswaarde> mVoedingswaarde;
    std::wstring mnaam;
    std::wstring mcategorie;
    std::wstring munit;
    double maantalporties;
};


}
