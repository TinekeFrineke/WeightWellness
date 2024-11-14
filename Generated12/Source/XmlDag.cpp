#include "../Interface\Generated\stdafx.h"
#include "../Interface\Generated\XmlDag.h"

#include <assert.h>
#include <tchar.h>

#include "../Interface\Generated\XmlVoedingsmiddel.h"
#include "../Interface\Generated\XmlRecept.h"
#include "../Interface\Generated\XmlGerecht.h"
#include "../Interface\Generated\XmlHandmatigitem.h"
#include "../Interface\Generated\XmlBonuscell.h"

namespace ww_1_2
{
XmlDag::XmlDag()
{
}

XmlDag::~XmlDag()
{
  for (size_t i = 0; i < mVoedingsmiddelList.size(); ++i)
    delete mVoedingsmiddelList[i];
  for (size_t i = 0; i < mReceptList.size(); ++i)
    delete mReceptList[i];
  for (size_t i = 0; i < mGerechtList.size(); ++i)
    delete mGerechtList[i];
  for (size_t i = 0; i < mHandmatigitemList.size(); ++i)
    delete mHandmatigitemList[i];
  for (size_t i = 0; i < mBonuscellList.size(); ++i)
    delete mBonuscellList[i];
}



const std::vector<XmlVoedingsmiddel *> & XmlDag::GetVoedingsmiddelList() const
{
  return mVoedingsmiddelList;
}


const std::vector<XmlRecept *> & XmlDag::GetReceptList() const
{
  return mReceptList;
}


const std::vector<XmlGerecht *> & XmlDag::GetGerechtList() const
{
  return mGerechtList;
}


const std::vector<XmlHandmatigitem *> & XmlDag::GetHandmatigitemList() const
{
  return mHandmatigitemList;
}


const std::vector<XmlBonuscell *> & XmlDag::GetBonuscellList() const
{
  return mBonuscellList;
}


void XmlDag::Add(XmlVoedingsmiddel * aVoedingsmiddel)
{
  mVoedingsmiddelList.push_back(aVoedingsmiddel);
}


void XmlDag::Add(XmlRecept * aRecept)
{
  mReceptList.push_back(aRecept);
}


void XmlDag::Add(XmlGerecht * aGerecht)
{
  mGerechtList.push_back(aGerecht);
}


void XmlDag::Add(XmlHandmatigitem * aHandmatigitem)
{
  mHandmatigitemList.push_back(aHandmatigitem);
}


void XmlDag::Add(XmlBonuscell * aBonuscell)
{
  mBonuscellList.push_back(aBonuscell);
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