//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlBonuscell.h"

#include <assert.h>
#include <tchar.h>


namespace ww2024
{
XmlBonuscell::XmlBonuscell()
    : mgewicht(0)
    , mintensiteit(intensiteit::laag)
    , mminuten(0)
    , mpunten(0)

{
}

XmlBonuscell::~XmlBonuscell()
{
}

int XmlBonuscell::Getgewicht() const
{
    return mgewicht;
}

XmlBonuscell::intensiteit XmlBonuscell::Getintensiteit() const
{
    return mintensiteit;
}

int XmlBonuscell::Getminuten() const
{
    return mminuten;
}

int XmlBonuscell::Getpunten() const
{
    return mpunten;
}

void XmlBonuscell::Setgewicht(int agewicht)
{
    mgewicht = agewicht;
}

void XmlBonuscell::Setintensiteit(intensiteit aintensiteit)
{
    mintensiteit = aintensiteit;
}

void XmlBonuscell::Setminuten(int aminuten)
{
    mminuten = aminuten;
}

void XmlBonuscell::Setpunten(int apunten)
{
    mpunten = apunten;
}

}