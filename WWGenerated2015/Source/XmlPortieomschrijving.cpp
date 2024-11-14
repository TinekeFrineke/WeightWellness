#include "stdafx.h"
#include "XmlPortieomschrijving.h"

#include <assert.h>
#include <tchar.h>


namespace ww2015
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