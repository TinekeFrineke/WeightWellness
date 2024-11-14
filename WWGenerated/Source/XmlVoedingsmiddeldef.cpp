#include "stdafx.h"
#include "XmlVoedingsmiddeldef.h"

#include <assert.h>
#include <tchar.h>

#include "XmlVoedingsmiddelbasis.h"
#include "XmlPortie.h"
#include "XmlVoedingswaarde.h"
#include "XmlPuntenper100.h"

namespace ww_1_1
{
XmlVoedingsmiddeldef::XmlVoedingsmiddeldef()
: mVoedingswaarde(NULL),
  mPuntenper100(NULL), mfavoriet(favoriet_false)

{
}

XmlVoedingsmiddeldef::~XmlVoedingsmiddeldef()
{
  for (size_t i = 0; i < mPortieList.size(); ++i)
    delete mPortieList[i];
  if (mVoedingswaarde != NULL)
    delete mVoedingswaarde;
  if (mPuntenper100 != NULL)
    delete mPuntenper100;
}

XmlVoedingsmiddelbasis & XmlVoedingsmiddeldef::GetVoedingsmiddelbasis()
{
  return mVoedingsmiddelbasis;
}

const XmlVoedingsmiddelbasis & XmlVoedingsmiddeldef::GetVoedingsmiddelbasis() const
{
  return mVoedingsmiddelbasis;
}


const std::vector<XmlPortie *> & XmlVoedingsmiddeldef::GetPortieList() const
{
  return mPortieList;
}
const XmlVoedingswaarde * XmlVoedingsmiddeldef::GetVoedingswaarde() const
{
  return mVoedingswaarde;
}
const XmlPuntenper100 * XmlVoedingsmiddeldef::GetPuntenper100() const
{
  return mPuntenper100;
}


void XmlVoedingsmiddeldef::Add(XmlPortie * aPortie)
{
  mPortieList.push_back(aPortie);
}


void XmlVoedingsmiddeldef::Add(XmlVoedingswaarde * aVoedingswaarde)
{
  assert(mVoedingswaarde == NULL);
  mVoedingswaarde = aVoedingswaarde;
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