//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlHandmatigitem.h"

#include <assert.h>
#include <tchar.h>


namespace ww2024
{
XmlHandmatigitem::XmlHandmatigitem()
    : mpunten(0)
    , mhoeveelheid(0)

{
}

XmlHandmatigitem::~XmlHandmatigitem()
{
}

std::wstring XmlHandmatigitem::Getnaam() const
{
    return mnaam;
}

double XmlHandmatigitem::Getpunten() const
{
    return mpunten;
}

double XmlHandmatigitem::Gethoeveelheid() const
{
    return mhoeveelheid;
}

void XmlHandmatigitem::Setnaam(const std::wstring & anaam)
{
    mnaam = anaam;
}

void XmlHandmatigitem::Setpunten(double apunten)
{
    mpunten = apunten;
}

void XmlHandmatigitem::Sethoeveelheid(double ahoeveelheid)
{
    mhoeveelheid = ahoeveelheid;
}

}