//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlWeek.h"

#include <assert.h>
#include <tchar.h>

#include "XmlDag.h"

namespace ww2019
{
XmlWeek::XmlWeek()
    : mpunten(0)
    , mweekpunten(0)
    , mstrategie(strategie::KCal)

{
}

XmlWeek::~XmlWeek()
{
}



const std::vector<std::unique_ptr<XmlDag>> & XmlWeek::GetDagList() const
{
    return mDagList;
}


void XmlWeek::Add(std::unique_ptr<XmlDag> aDag)
{
    mDagList.push_back(std::move(aDag));
}
std::wstring XmlWeek::Getbegindatum() const
{
    return mbegindatum;
}

std::wstring XmlWeek::Geteinddatum() const
{
    return meinddatum;
}

int XmlWeek::Getpunten() const
{
    return mpunten;
}

int XmlWeek::Getweekpunten() const
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

void XmlWeek::Setpunten(int apunten)
{
    mpunten = apunten;
}

void XmlWeek::Setweekpunten(int aweekpunten)
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