#include "../Interface/stdafx.h"
#include "../Interface/XmlVoedingsmiddelheader.h"

#include <assert.h>
#include <tchar.h>


namespace ww2019
{
XmlVoedingsmiddelheader::XmlVoedingsmiddelheader()
{
}

XmlVoedingsmiddelheader::~XmlVoedingsmiddelheader()
{
}

std::wstring XmlVoedingsmiddelheader::Getnaam() const
{
  return mnaam;
}

std::wstring XmlVoedingsmiddelheader::Getcategorie() const
{
  return mcategorie;
}

std::wstring XmlVoedingsmiddelheader::Getmerk() const
{
  return mmerk;
}

std::wstring XmlVoedingsmiddelheader::Getunit() const
{
  return munit;
}

void XmlVoedingsmiddelheader::Setnaam(const std::wstring & anaam)
{
   mnaam = anaam;
}

void XmlVoedingsmiddelheader::Setcategorie(const std::wstring & acategorie)
{
   mcategorie = acategorie;
}

void XmlVoedingsmiddelheader::Setmerk(const std::wstring & amerk)
{
   mmerk = amerk;
}

void XmlVoedingsmiddelheader::Setunit(const std::wstring & aunit)
{
   munit = aunit;
}

}