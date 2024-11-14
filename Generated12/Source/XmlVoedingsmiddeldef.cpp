#include "../Interface\Generated\stdafx.h"
#include "../Interface\Generated\XmlVoedingsmiddeldef.h"

#include <assert.h>
#include <tchar.h>

#include "../Interface\Generated\XmlVoedingswaarde.h"
#include "../Interface\Generated\XmlPortie.h"
#include "../Interface\Generated\XmlPuntenper100.h"
#include "../Interface\Generated\XmlVoedingsmiddelbasis.h"

namespace ww_1_2
{
XmlVoedingsmiddeldef::XmlVoedingsmiddeldef()
: mVoedingswaarde(NULL),
  mPuntenper100(NULL), mfavoriet(favoriet_false)

{
}

XmlVoedingsmiddeldef::~XmlVoedingsmiddeldef()
{
  if (mVoedingswaarde != NULL)
    delete mVoedingswaarde;
  for (size_t i = 0; i < mPortieList.size(); ++i)
    delete mPortieList[i];
  if (mPuntenper100 != NULL)
    delete mPuntenper100;
}

const XmlVoedingswaarde * XmlVoedingsmiddeldef::GetVoedingswaarde() const
{
  return mVoedingswaarde;
}


const std::vector<XmlPortie *> & XmlVoedingsmiddeldef::GetPortieList() const
{
  return mPortieList;
}
const XmlPuntenper100 * XmlVoedingsmiddeldef::GetPuntenper100() const
{
  return mPuntenper100;
}
XmlVoedingsmiddelbasis & XmlVoedingsmiddeldef::GetVoedingsmiddelbasis()
{
  return mVoedingsmiddelbasis;
}

const XmlVoedingsmiddelbasis & XmlVoedingsmiddeldef::GetVoedingsmiddelbasis() const
{
  return mVoedingsmiddelbasis;
}


void XmlVoedingsmiddeldef::Add(XmlVoedingswaarde * aVoedingswaarde)
{
  assert(mVoedingswaarde == NULL);
  mVoedingswaarde = aVoedingswaarde;
}


void XmlVoedingsmiddeldef::Add(XmlPortie * aPortie)
{
  mPortieList.push_back(aPortie);
}


void XmlVoedingsmiddeldef::Add(XmlPuntenper100 * aPuntenper100)
{
  assert(mPuntenper100 == NULL);
  mPuntenper100 = aPuntenper100;
}
XmlVoedingsmiddeldef::favoriet XmlVoedingsmiddeldef::Getfavoriet() const
{
  return mfavoriet;
}

void XmlVoedingsmiddeldef::Setfavoriet(favoriet afavoriet)
{
   mfavoriet = afavoriet;
}

}