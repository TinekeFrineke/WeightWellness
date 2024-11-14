#include "stdafx.h"
#include "XmlReceptdef.h"

#include <assert.h>
#include <tchar.h>

#include "XmlVoedingsmiddel.h"
#include "XmlRecept.h"
#include "XmlGerecht.h"
#include "XmlHandmatigitem.h"

namespace ww_1_1
{
XmlReceptdef::XmlReceptdef()
{
}

XmlReceptdef::~XmlReceptdef()
{
  for (size_t i = 0; i < mVoedingsmiddelList.size(); ++i)
    delete mVoedingsmiddelList[i];
  for (size_t i = 0; i < mReceptList.size(); ++i)
    delete mReceptList[i];
  for (size_t i = 0; i < mGerechtList.size(); ++i)
    delete mGerechtList[i];
  for (size_t i = 0; i < mHandmatigitemList.size(); ++i)
    delete mHandmatigitemList[i];
}



const std::vector<XmlVoedingsmiddel *> & XmlReceptdef::GetVoedingsmiddelList() const
{
  return mVoedingsmiddelList;
}


const std::vector<XmlRecept *> & XmlReceptdef::GetReceptList() const
{
  return mReceptList;
}


const std::vector<XmlGerecht *> & XmlReceptdef::GetGerechtList() const
{
  return mGerechtList;
}


const std::vector<XmlHandmatigitem *> & XmlReceptdef::GetHandmatigitemList() const
{
  return mHandmatigitemList;
}


void XmlReceptdef::Add(XmlVoedingsmiddel * aVoedingsmiddel)
{
  mVoedingsmiddelList.push_back(aVoedingsmiddel);
}


void XmlReceptdef::Add(XmlRecept * aRecept)
{
  mReceptList.push_back(aRecept);
}


void XmlReceptdef::Add(XmlGerecht * aGerecht)
{
  mGerechtList.push_back(aGerecht);
}


void XmlReceptdef::Add(XmlHandmatigitem * aHandmatigitem)
{
  mHandmatigitemList.push_back(aHandmatigitem);
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