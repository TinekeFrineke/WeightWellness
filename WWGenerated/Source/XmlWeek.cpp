#include "stdafx.h"
#include "XmlWeek.h"

#include <assert.h>
#include <tchar.h>

#include "XmlDag.h"

namespace ww_1_1
{
XmlWeek::XmlWeek()
: mstrategie(strategie_FlexiPoints)

{
}

XmlWeek::~XmlWeek()
{
  for (size_t i = 0; i < mDagList.size(); ++i)
    delete mDagList[i];
}



const std::vector<XmlDag *> & XmlWeek::GetDagList() const
{
  return mDagList;
}


void XmlWeek::Add(XmlDag * aDag)
{
  mDagList.push_back(aDag);
}
std::wstring XmlWeek::Getbegindatum() const
{
  return mbegindatum;
}

std::wstring XmlWeek::Geteinddatum() const
{
  return meinddatum;
}

std::wstring XmlWeek::Getpunten() const
{
  return mpunten;
}

std::wstring XmlWeek::Getweekpunten() const
{
  return mweekpunten;
}

std::wstring XmlWeek::Getstartweight() const
{
  return mstartweight;
}

XmlWeek::strategie XmlWeek::Getstrategie() const
{
  return mstrategie;
}

void XmlWeek::Setbegindatum(const std::wstring & abegindatum)
{
   mbegindatum = abegindatum;
}

void XmlWeek::Seteinddatum(const std::wstring & aeinddatum)
{
   meinddatum = aeinddatum;
}

void XmlWeek::Setpunten(const std::wstring & apunten)
{
   mpunten = apunten;
}

void XmlWeek::Setweekpunten(const std::wstring & aweekpunten)
{
   mweekpunten = aweekpunten;
}

void XmlWeek::Setstartweight(const std::wstring & astartweight)
{
   mstartweight = astartweight;
}

void XmlWeek::Setstrategie(strategie astrategie)
{
   mstrategie = astrategie;
}

}