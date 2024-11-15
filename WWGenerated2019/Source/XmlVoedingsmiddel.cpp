#include "../Interface/stdafx.h"
#include "../Interface/XmlVoedingsmiddel.h"

#include <assert.h>
#include <tchar.h>

#include "../Interface/XmlStandardlot.h"

namespace ww2019
{
XmlVoedingsmiddel::XmlVoedingsmiddel()
: mStandardlot(NULL)
{
}

XmlVoedingsmiddel::~XmlVoedingsmiddel()
{
  if (mStandardlot != NULL)
    delete mStandardlot;
}

const XmlStandardlot * XmlVoedingsmiddel::GetStandardlot() const
{
  return mStandardlot;
}


void XmlVoedingsmiddel::Add(XmlStandardlot * aStandardlot)
{
  assert(mStandardlot == NULL);
  mStandardlot = aStandardlot;
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