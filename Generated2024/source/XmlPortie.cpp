//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlPortie.h"

#include <assert.h>
#include <tchar.h>


namespace ww2024
{
XmlPortie::XmlPortie()
    : meenheden(0)

{
}

XmlPortie::~XmlPortie()
{
}

std::wstring XmlPortie::Getnaam() const
{
    return mnaam;
}

double XmlPortie::Geteenheden() const
{
    return meenheden;
}

void XmlPortie::Setnaam(const std::wstring & anaam)
{
    mnaam = anaam;
}

void XmlPortie::Seteenheden(double aeenheden)
{
    meenheden = aeenheden;
}

}