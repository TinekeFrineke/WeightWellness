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



class XmlBonuscell : public XmlClass
{
public:
    enum class intensiteit
    {
        laag,
        middel,
        hoog
    };

    XmlBonuscell();
    ~XmlBonuscell() override;

    int Getgewicht() const;
    intensiteit Getintensiteit() const;
    int Getminuten() const;
    int Getpunten() const;
    void Setgewicht(int agewicht);
    void Setintensiteit(intensiteit aintensiteit);
    void Setminuten(int aminuten);
    void Setpunten(int apunten);

private:
    XmlBonuscell(const XmlBonuscell& anOriginal) = delete;
    XmlBonuscell& operator=(const XmlBonuscell& anOriginal) = delete;

    int mgewicht;
    intensiteit mintensiteit;
    int mminuten;
    int mpunten;
};


}
