#include "stdafx.h"
#include "XmlVoedingsmiddel.h"

#include <assert.h>
#include <tchar.h>

#include "XmlStandardlot.h"
#include "XmlFreelot.h"

namespace ww_1_1
{
XmlVoedingsmiddel::XmlVoedingsmiddel()
: mStandardlot(NULL),
  mFreelot(NULL)
{
}

XmlVoedingsmiddel::~XmlVoedingsmiddel()
{
  if (mStandardlot != NULL)
    delete mStandardlot;
  if (mFreelot != NULL)
    delete mFreelot;
}

const XmlStandardlot * XmlVoedingsmiddel::GetStandardlot() const
{
  return mStandardlot;
}
const XmlFreelot * XmlVoedingsmiddel::GetFreelot() const
{
  return mFreelot;
}


void XmlVoedingsmiddel::Add(XmlStandardlot * aStandardlot)
{
  assert(mStandardlot == NULL);
  mStandardlot = aStandardlot;
}


void XmlVoedingsmiddel::Add(XmlFreelot * aFreelot)
{
  assert(mFreelot == NULL);
  mFreelot = aFreelot;
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