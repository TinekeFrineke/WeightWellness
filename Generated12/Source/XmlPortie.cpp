#include "../Interface\Generated\stdafx.h"
#include "../Interface\Generated\XmlPortie.h"

#include <assert.h>
#include <tchar.h>


namespace ww_1_2
{
XmlPortie::XmlPortie()
{
}

XmlPortie::~XmlPortie()
{
}

std::wstring XmlPortie::Getnaam() const
{
  return mnaam;
}

std::wstring XmlPortie::Geteenheden() const
{
  return meenheden;
}

void XmlPortie::Setnaam(const std::wstring & anaam)
{
   mnaam = anaam;
}

void XmlPortie::Seteenheden(const std::wstring & aeenheden)
{
   meenheden = aeenheden;
}

}