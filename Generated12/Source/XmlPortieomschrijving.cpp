#include "../Interface\Generated\stdafx.h"
#include "../Interface\Generated\XmlPortieomschrijving.h"

#include <assert.h>
#include <tchar.h>


namespace ww_1_2
{
XmlPortieomschrijving::XmlPortieomschrijving()
{
}

XmlPortieomschrijving::~XmlPortieomschrijving()
{
}

std::wstring XmlPortieomschrijving::Getomschrijving() const
{
  return momschrijving;
}

void XmlPortieomschrijving::Setomschrijving(const std::wstring & aomschrijving)
{
   momschrijving = aomschrijving;
}

}