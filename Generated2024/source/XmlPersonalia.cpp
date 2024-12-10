//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlPersonalia.h"

#include <assert.h>
#include <tchar.h>


namespace ww2024
{
XmlPersonalia::XmlPersonalia()
    : mkcpunten(0)
    , mkcweekpunten(0)
    , mchpunten(0)
    , mchweekpunten(0)
    , mgeslacht(geslacht::Mannelijk)
    , mwerk(werk::Zittend)
    , mlengte(0)
    , mgewicht(0)
    , mstreefgewicht(0)
    , mstartgewicht(0)
    , mhuidiggewicht(0)
    , mstrategie(strategie::KCal)

{
}

XmlPersonalia::~XmlPersonalia()
{
}

std::wstring XmlPersonalia::Getnaam() const
{
    return mnaam;
}

std::wstring XmlPersonalia::Getgebruikersnaam() const
{
    return mgebruikersnaam;
}

double XmlPersonalia::Getkcpunten() const
{
    return mkcpunten;
}

double XmlPersonalia::Getkcweekpunten() const
{
    return mkcweekpunten;
}

double XmlPersonalia::Getchpunten() const
{
    return mchpunten;
}

double XmlPersonalia::Getchweekpunten() const
{
    return mchweekpunten;
}

std::wstring XmlPersonalia::Getgeboren() const
{
    return mgeboren;
}

XmlPersonalia::geslacht XmlPersonalia::Getgeslacht() const
{
    return mgeslacht;
}

XmlPersonalia::werk XmlPersonalia::Getwerk() const
{
    return mwerk;
}

int XmlPersonalia::Getlengte() const
{
    return mlengte;
}

double XmlPersonalia::Getgewicht() const
{
    return mgewicht;
}

double XmlPersonalia::Getstreefgewicht() const
{
    return mstreefgewicht;
}

double XmlPersonalia::Getstartgewicht() const
{
    return mstartgewicht;
}

double XmlPersonalia::Gethuidiggewicht() const
{
    return mhuidiggewicht;
}

XmlPersonalia::strategie XmlPersonalia::Getstrategie() const
{
    return mstrategie;
}

void XmlPersonalia::Setnaam(const std::wstring & anaam)
{
    mnaam = anaam;
}

void XmlPersonalia::Setgebruikersnaam(const std::wstring & agebruikersnaam)
{
    mgebruikersnaam = agebruikersnaam;
}

void XmlPersonalia::Setkcpunten(double akcpunten)
{
    mkcpunten = akcpunten;
}

void XmlPersonalia::Setkcweekpunten(double akcweekpunten)
{
    mkcweekpunten = akcweekpunten;
}

void XmlPersonalia::Setchpunten(double achpunten)
{
    mchpunten = achpunten;
}

void XmlPersonalia::Setchweekpunten(double achweekpunten)
{
    mchweekpunten = achweekpunten;
}

void XmlPersonalia::Setgeboren(const std::wstring & ageboren)
{
    mgeboren = ageboren;
}

void XmlPersonalia::Setgeslacht(geslacht ageslacht)
{
    mgeslacht = ageslacht;
}

void XmlPersonalia::Setwerk(werk awerk)
{
    mwerk = awerk;
}

void XmlPersonalia::Setlengte(int alengte)
{
    mlengte = alengte;
}

void XmlPersonalia::Setgewicht(double agewicht)
{
    mgewicht = agewicht;
}

void XmlPersonalia::Setstreefgewicht(double astreefgewicht)
{
    mstreefgewicht = astreefgewicht;
}

void XmlPersonalia::Setstartgewicht(double astartgewicht)
{
    mstartgewicht = astartgewicht;
}

void XmlPersonalia::Sethuidiggewicht(double ahuidiggewicht)
{
    mhuidiggewicht = ahuidiggewicht;
}

void XmlPersonalia::Setstrategie(strategie astrategie)
{
    mstrategie = astrategie;
}

}