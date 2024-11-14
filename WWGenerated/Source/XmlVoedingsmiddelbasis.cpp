#include "stdafx.h"
#include "XmlVoedingsmiddelbasis.h"

#include <assert.h>
#include <tchar.h>

#include "XmlVoedingsmiddelheader.h"

namespace ww_1_1
{
XmlVoedingsmiddelbasis::XmlVoedingsmiddelbasis()
: mvrijeportie(vrijeportie_false)
, mvrijeppportie(vrijeppportie_false)

{
}

XmlVoedingsmiddelbasis::~XmlVoedingsmiddelbasis()
{
}

XmlVoedingsmiddelheader & XmlVoedingsmiddelbasis::GetVoedingsmiddelheader()
{
  return mVoedingsmiddelheader;
}

const XmlVoedingsmiddelheader & XmlVoedingsmiddelbasis::GetVoedingsmiddelheader() const
{
  return mVoedingsmiddelheader;
}
std::wstring XmlVoedingsmiddelbasis::Getsterreportie() const
{
  return msterreportie;
}

XmlVoedingsmiddelbasis::vrijeportie XmlVoedingsmiddelbasis::Getvrijeportie() const
{
  return mvrijeportie;
}

std::wstring XmlVoedingsmiddelbasis::Getvrijepunten() const
{
  return mvrijepunten;
}

XmlVoedingsmiddelbasis::vrijeppportie XmlVoedingsmiddelbasis::Getvrijeppportie() const
{
  return mvrijeppportie;
}

std::wstring XmlVoedingsmiddelbasis::Getvrijepppunten() const
{
  return mvrijepppunten;
}

void XmlVoedingsmiddelbasis::Setsterreportie(const std::wstring & asterreportie)
{
   msterreportie = asterreportie;
}

void XmlVoedingsmiddelbasis::Setvrijeportie(vrijeportie avrijeportie)
{
   mvrijeportie = avrijeportie;
}

void XmlVoedingsmiddelbasis::Setvrijepunten(const std::wstring & avrijepunten)
{
   mvrijepunten = avrijepunten;
}

void XmlVoedingsmiddelbasis::Setvrijeppportie(vrijeppportie avrijeppportie)
{
   mvrijeppportie = avrijeppportie;
}

void XmlVoedingsmiddelbasis::Setvrijepppunten(const std::wstring & avrijepppunten)
{
   mvrijepppunten = avrijepppunten;
}

}