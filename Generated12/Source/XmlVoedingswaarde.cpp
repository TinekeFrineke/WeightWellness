#include "../Interface\Generated\stdafx.h"
#include "../Interface\Generated\XmlVoedingswaarde.h"

#include <assert.h>
#include <tchar.h>


namespace ww_1_2
{
XmlVoedingswaarde::XmlVoedingswaarde()
: mkcalper100(_T("-1"))
, mvetper100(_T("-1"))
, mkoolhydratenper100(_T("-1"))
, meiwitper100(_T("-1"))
, mvezelsper100(_T("-1"))

{
}

XmlVoedingswaarde::~XmlVoedingswaarde()
{
}

std::wstring XmlVoedingswaarde::Getkcalper100() const
{
  return mkcalper100;
}

std::wstring XmlVoedingswaarde::Getvetper100() const
{
  return mvetper100;
}

std::wstring XmlVoedingswaarde::Getkoolhydratenper100() const
{
  return mkoolhydratenper100;
}

std::wstring XmlVoedingswaarde::Geteiwitper100() const
{
  return meiwitper100;
}

std::wstring XmlVoedingswaarde::Getvezelsper100() const
{
  return mvezelsper100;
}

void XmlVoedingswaarde::Setkcalper100(const std::wstring & akcalper100)
{
   mkcalper100 = akcalper100;
}

void XmlVoedingswaarde::Setvetper100(const std::wstring & avetper100)
{
   mvetper100 = avetper100;
}

void XmlVoedingswaarde::Setkoolhydratenper100(const std::wstring & akoolhydratenper100)
{
   mkoolhydratenper100 = akoolhydratenper100;
}

void XmlVoedingswaarde::Seteiwitper100(const std::wstring & aeiwitper100)
{
   meiwitper100 = aeiwitper100;
}

void XmlVoedingswaarde::Setvezelsper100(const std::wstring & avezelsper100)
{
   mvezelsper100 = avezelsper100;
}

}