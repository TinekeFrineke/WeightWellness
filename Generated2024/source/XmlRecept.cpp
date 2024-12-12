//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlRecept.h"

#include <assert.h>
#include <tchar.h>


namespace ww2024
{
XmlRecept::XmlRecept()
    : mpunten(0)
    , maantalporties(0)

{
}

XmlRecept::~XmlRecept()
{
}

std::wstring XmlRecept::Getnaam() const
{
    return mnaam;
}

double XmlRecept::Getpunten() const
{
    return mpunten;
}

int XmlRecept::Getaantalporties() const
{
    return maantalporties;
}

void XmlRecept::Setnaam(const std::wstring & anaam)
{
    mnaam = anaam;
}

void XmlRecept::Setpunten(double apunten)
{
    mpunten = apunten;
}

void XmlRecept::Setaantalporties(int aaantalporties)
{
    maantalporties = aaantalporties;
}

}