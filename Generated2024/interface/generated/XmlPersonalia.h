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



class XmlPersonalia : public XmlClass
{
public:
    enum class geslacht
    {
        Mannelijk,
        Vrouwelijk
    };

    enum class werk
    {
        Zittend,
        Staand,
        Lopend,
        Zwaar
    };

    enum class strategie
    {
        KCal,
        CarboHydrates
    };

    XmlPersonalia();
    ~XmlPersonalia() override;

    std::wstring Getnaam() const;
    std::wstring Getgebruikersnaam() const;
    int Getkcpunten() const;
    int Getkcweekpunten() const;
    int Getchpunten() const;
    int Getchweekpunten() const;
    std::wstring Getgeboren() const;
    geslacht Getgeslacht() const;
    werk Getwerk() const;
    int Getlengte() const;
    double Getgewicht() const;
    double Getstreefgewicht() const;
    double Getstartgewicht() const;
    double Gethuidiggewicht() const;
    strategie Getstrategie() const;
    void Setnaam(const std::wstring & anaam);
    void Setgebruikersnaam(const std::wstring & agebruikersnaam);
    void Setkcpunten(int akcpunten);
    void Setkcweekpunten(int akcweekpunten);
    void Setchpunten(int achpunten);
    void Setchweekpunten(int achweekpunten);
    void Setgeboren(const std::wstring & ageboren);
    void Setgeslacht(geslacht ageslacht);
    void Setwerk(werk awerk);
    void Setlengte(int alengte);
    void Setgewicht(double agewicht);
    void Setstreefgewicht(double astreefgewicht);
    void Setstartgewicht(double astartgewicht);
    void Sethuidiggewicht(double ahuidiggewicht);
    void Setstrategie(strategie astrategie);

private:
    XmlPersonalia(const XmlPersonalia& anOriginal) = delete;
    XmlPersonalia& operator=(const XmlPersonalia& anOriginal) = delete;

    std::wstring mnaam;
    std::wstring mgebruikersnaam;
    int mkcpunten;
    int mkcweekpunten;
    int mchpunten;
    int mchweekpunten;
    std::wstring mgeboren;
    geslacht mgeslacht;
    werk mwerk;
    int mlengte;
    double mgewicht;
    double mstreefgewicht;
    double mstartgewicht;
    double mhuidiggewicht;
    strategie mstrategie;
};


}
