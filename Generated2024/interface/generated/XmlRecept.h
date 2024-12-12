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



class XmlRecept : public XmlClass
{
public:
    XmlRecept();
    ~XmlRecept() override;

    std::wstring Getnaam() const;
    double Getpunten() const;
    int Getaantalporties() const;
    void Setnaam(const std::wstring & anaam);
    void Setpunten(double apunten);
    void Setaantalporties(int aaantalporties);

private:
    XmlRecept(const XmlRecept& anOriginal) = delete;
    XmlRecept& operator=(const XmlRecept& anOriginal) = delete;

    std::wstring mnaam;
    double mpunten;
    int maantalporties;
};


}
