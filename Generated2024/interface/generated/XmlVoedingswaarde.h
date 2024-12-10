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



class XmlVoedingswaarde : public XmlClass
{
public:
    XmlVoedingswaarde();
    ~XmlVoedingswaarde() override;

    double Getkcalper100() const;
    double Getvetper100() const;
    double Getkoolhydratenper100() const;
    double Geteiwitper100() const;
    double Getvezelsper100() const;
    void Setkcalper100(double akcalper100);
    void Setvetper100(double avetper100);
    void Setkoolhydratenper100(double akoolhydratenper100);
    void Seteiwitper100(double aeiwitper100);
    void Setvezelsper100(double avezelsper100);

private:
    XmlVoedingswaarde(const XmlVoedingswaarde& anOriginal) = delete;
    XmlVoedingswaarde& operator=(const XmlVoedingswaarde& anOriginal) = delete;

    double mkcalper100;
    double mvetper100;
    double mkoolhydratenper100;
    double meiwitper100;
    double mvezelsper100;
};


}
