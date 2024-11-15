#include "../Interface/stdafx.h"
#include "../Interface/XmlPortieomschrijving.h"

#include <assert.h>
#include <tchar.h>


namespace ww2019
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