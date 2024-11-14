#include "stdafx.h"
#include "XmlGerecht.h"

#include <assert.h>
#include <tchar.h>


namespace ww2015
{
XmlGerecht::XmlGerecht()
{
}

XmlGerecht::~XmlGerecht()
{
}

std::wstring XmlGerecht::Getnaam() const
{
  return mnaam;
}

std::wstring XmlGerecht::Getpunten() const
{
  return mpunten;
}

std::wstring XmlGerecht::Gethoeveelheid() const
{
  return mhoeveelheid;
}

void XmlGerecht::Setnaam(const std::wstring & anaam)
{
   mnaam = anaam;
}

void XmlGerecht::Setpunten(const std::wstring & apunten)
{
   mpunten = apunten;
}

void XmlGerecht::Sethoeveelheid(const std::wstring & ahoeveelheid)
{
   mhoeveelheid = ahoeveelheid;
}

}