#include "stdafx.h"
#include "XmlSterrelot.h"

#include <assert.h>
#include <tchar.h>


namespace ww2015
{
XmlSterrelot::XmlSterrelot()
{
}

XmlSterrelot::~XmlSterrelot()
{
}

std::wstring XmlSterrelot::Getvoedingsmiddel() const
{
  return mvoedingsmiddel;
}

std::wstring XmlSterrelot::Getportie() const
{
  return mportie;
}

std::wstring XmlSterrelot::Gethoeveelheid() const
{
  return mhoeveelheid;
}

void XmlSterrelot::Setvoedingsmiddel(const std::wstring & avoedingsmiddel)
{
   mvoedingsmiddel = avoedingsmiddel;
}

void XmlSterrelot::Setportie(const std::wstring & aportie)
{
   mportie = aportie;
}

void XmlSterrelot::Sethoeveelheid(const std::wstring & ahoeveelheid)
{
   mhoeveelheid = ahoeveelheid;
}

}