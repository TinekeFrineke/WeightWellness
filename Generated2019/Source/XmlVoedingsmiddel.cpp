//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlVoedingsmiddel.h"

#include <assert.h>
#include <tchar.h>

#include "XmlStandardlot.h"

namespace ww2019
{
XmlVoedingsmiddel::XmlVoedingsmiddel()
    : mStandardlot(nullptr)
{
}

XmlVoedingsmiddel::~XmlVoedingsmiddel()
{
}

const XmlStandardlot * XmlVoedingsmiddel::GetStandardlot() const
{
    return mStandardlot.get();
}


void XmlVoedingsmiddel::Add(std::unique_ptr<XmlStandardlot> aStandardlot)
{
    assert(mStandardlot == nullptr);
    mStandardlot = std::move(aStandardlot);
}
std::wstring XmlVoedingsmiddel::Getnaam() const
{
    return mnaam;
}

std::wstring XmlVoedingsmiddel::Getcategorie() const
{
    return mcategorie;
}

std::wstring XmlVoedingsmiddel::Getmerk() const
{
    return mmerk;
}

std::wstring XmlVoedingsmiddel::Getunit() const
{
    return munit;
}

void XmlVoedingsmiddel::Setnaam(const std::wstring & anaam)
{
    mnaam = anaam;
}

void XmlVoedingsmiddel::Setcategorie(const std::wstring & acategorie)
{
    mcategorie = acategorie;
}

void XmlVoedingsmiddel::Setmerk(const std::wstring & amerk)
{
    mmerk = amerk;
}

void XmlVoedingsmiddel::Setunit(const std::wstring & aunit)
{
    munit = aunit;
}

}