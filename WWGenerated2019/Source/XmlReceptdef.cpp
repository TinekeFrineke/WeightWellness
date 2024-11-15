#include "../Interface/stdafx.h"
#include "../Interface/XmlReceptdef.h"

#include <assert.h>
#include <tchar.h>

#include "../Interface/XmlGerecht.h"
#include "../Interface/XmlHandmatigitem.h"
#include "../Interface/XmlVoedingsmiddel.h"
#include "../Interface/XmlRecept.h"

namespace ww2019
{
XmlReceptdef::XmlReceptdef()
{
}

XmlReceptdef::~XmlReceptdef()
{
  for (size_t i = 0; i < mGerechtList.size(); ++i)
    delete mGerechtList[i];
  for (size_t i = 0; i < mHandmatigitemList.size(); ++i)
    delete mHandmatigitemList[i];
  for (size_t i = 0; i < mVoedingsmiddelList.size(); ++i)
    delete mVoedingsmiddelList[i];
  for (size_t i = 0; i < mReceptList.size(); ++i)
    delete mReceptList[i];
}



const std::vector<XmlGerecht *> & XmlReceptdef::GetGerechtList() const
{
  return mGerechtList;
}


const std::vector<XmlHandmatigitem *> & XmlReceptdef::GetHandmatigitemList() const
{
  return mHandmatigitemList;
}


const std::vector<XmlVoedingsmiddel *> & XmlReceptdef::GetVoedingsmiddelList() const
{
  return mVoedingsmiddelList;
}


const std::vector<XmlRecept *> & XmlReceptdef::GetReceptList() const
{
  return mReceptList;
}


void XmlReceptdef::Add(XmlGerecht * aGerecht)
{
  mGerechtList.push_back(aGerecht);
}


void XmlReceptdef::Add(XmlHandmatigitem * aHandmatigitem)
{
  mHandmatigitemList.push_back(aHandmatigitem);
}


void XmlReceptdef::Add(XmlVoedingsmiddel * aVoedingsmiddel)
{
  mVoedingsmiddelList.push_back(aVoedingsmiddel);
}


void XmlReceptdef::Add(XmlRecept * aRecept)
{
  mReceptList.push_back(aRecept);
}
std::wstring XmlReceptdef::Getnaam() const
{
  return mnaam;
}

std::wstring XmlReceptdef::Getporties() const
{
  return mporties;
}

void XmlReceptdef::Setnaam(const std::wstring & anaam)
{
   mnaam = anaam;
}

void XmlReceptdef::Setporties(const std::wstring & aporties)
{
   mporties = aporties;
}

}