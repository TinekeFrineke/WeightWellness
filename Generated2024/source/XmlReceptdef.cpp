//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlReceptdef.h"

#include <assert.h>
#include <tchar.h>

#include "XmlVoedingsmiddel.h"
#include "XmlRecept.h"
#include "XmlHandmatigitem.h"

namespace ww2024
{
XmlReceptdef::XmlReceptdef()
    : mporties(0)

{
}

XmlReceptdef::~XmlReceptdef()
{
}



const std::vector<std::unique_ptr<XmlVoedingsmiddel>> & XmlReceptdef::GetVoedingsmiddelList() const
{
    return mVoedingsmiddelList;
}


const std::vector<std::unique_ptr<XmlRecept>> & XmlReceptdef::GetReceptList() const
{
    return mReceptList;
}


const std::vector<std::unique_ptr<XmlHandmatigitem>> & XmlReceptdef::GetHandmatigitemList() const
{
    return mHandmatigitemList;
}


void XmlReceptdef::Add(std::unique_ptr<XmlVoedingsmiddel> aVoedingsmiddel)
{
    mVoedingsmiddelList.push_back(std::move(aVoedingsmiddel));
}


void XmlReceptdef::Add(std::unique_ptr<XmlRecept> aRecept)
{
    mReceptList.push_back(std::move(aRecept));
}


void XmlReceptdef::Add(std::unique_ptr<XmlHandmatigitem> aHandmatigitem)
{
    mHandmatigitemList.push_back(std::move(aHandmatigitem));
}
std::wstring XmlReceptdef::Getnaam() const
{
    return mnaam;
}

double XmlReceptdef::Getporties() const
{
    return mporties;
}

void XmlReceptdef::Setnaam(const std::wstring & anaam)
{
    mnaam = anaam;
}

void XmlReceptdef::Setporties(double aporties)
{
    mporties = aporties;
}

}