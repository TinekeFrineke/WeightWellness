#include "../Interface\Generated\stdafx.h"
#include "../Interface\Generated\XmlHandmatigitem.h"

#include <assert.h>
#include <tchar.h>


namespace ww_1_2
{
XmlHandmatigitem::XmlHandmatigitem()
{
}

XmlHandmatigitem::~XmlHandmatigitem()
{
}

std::wstring XmlHandmatigitem::Getnaam() const
{
  return mnaam;
}

std::wstring XmlHandmatigitem::Getpunten() const
{
  return mpunten;
}

std::wstring XmlHandmatigitem::Gethoeveelheid() const
{
  return mhoeveelheid;
}

void XmlHandmatigitem::Setnaam(const std::wstring & anaam)
{
   mnaam = anaam;
}

void XmlHandmatigitem::Setpunten(const std::wstring & apunten)
{
   mpunten = apunten;
}

void XmlHandmatigitem::Sethoeveelheid(const std::wstring & ahoeveelheid)
{
   mhoeveelheid = ahoeveelheid;
}

}