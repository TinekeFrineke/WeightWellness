#include "stdafx.h"
#include "XmlVrijeportie.h"

#include <assert.h>
#include <tchar.h>


namespace ww2015
{
XmlVrijeportie::XmlVrijeportie()
{
}

XmlVrijeportie::~XmlVrijeportie()
{
}

std::wstring XmlVrijeportie::Getvoedingsmiddel() const
{
  return mvoedingsmiddel;
}

std::wstring XmlVrijeportie::Getpunten() const
{
  return mpunten;
}

void XmlVrijeportie::Setvoedingsmiddel(const std::wstring & avoedingsmiddel)
{
   mvoedingsmiddel = avoedingsmiddel;
}

void XmlVrijeportie::Setpunten(const std::wstring & apunten)
{
   mpunten = apunten;
}

}