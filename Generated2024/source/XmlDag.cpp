//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlDag.h"

#include <assert.h>
#include <tchar.h>

#include "XmlVoedingsmiddel.h"
#include "XmlRecept.h"
#include "XmlHandmatigitem.h"
#include "XmlBonuscell.h"

namespace ww2024
{
XmlDag::XmlDag()
{
}

XmlDag::~XmlDag()
{
}



const std::vector<std::unique_ptr<XmlVoedingsmiddel>> & XmlDag::GetVoedingsmiddelList() const
{
    return mVoedingsmiddelList;
}


const std::vector<std::unique_ptr<XmlRecept>> & XmlDag::GetReceptList() const
{
    return mReceptList;
}


const std::vector<std::unique_ptr<XmlHandmatigitem>> & XmlDag::GetHandmatigitemList() const
{
    return mHandmatigitemList;
}


const std::vector<std::unique_ptr<XmlBonuscell>> & XmlDag::GetBonuscellList() const
{
    return mBonuscellList;
}


void XmlDag::Add(std::unique_ptr<XmlVoedingsmiddel> aVoedingsmiddel)
{
    mVoedingsmiddelList.push_back(std::move(aVoedingsmiddel));
}


void XmlDag::Add(std::unique_ptr<XmlRecept> aRecept)
{
    mReceptList.push_back(std::move(aRecept));
}


void XmlDag::Add(std::unique_ptr<XmlHandmatigitem> aHandmatigitem)
{
    mHandmatigitemList.push_back(std::move(aHandmatigitem));
}


void XmlDag::Add(std::unique_ptr<XmlBonuscell> aBonuscell)
{
    mBonuscellList.push_back(std::move(aBonuscell));
}
std::wstring XmlDag::Getbonuspunten() const
{
    return mbonuspunten;
}

std::wstring XmlDag::Getdatum() const
{
    return mdatum;
}

std::wstring XmlDag::Getgewicht() const
{
    return mgewicht;
}

void XmlDag::Setbonuspunten(const std::wstring & abonuspunten)
{
    mbonuspunten = abonuspunten;
}

void XmlDag::Setdatum(const std::wstring & adatum)
{
    mdatum = adatum;
}

void XmlDag::Setgewicht(const std::wstring & agewicht)
{
    mgewicht = agewicht;
}

}