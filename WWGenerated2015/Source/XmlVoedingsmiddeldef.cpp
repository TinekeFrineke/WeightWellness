#include "stdafx.h"
#include "XmlVoedingsmiddeldef.h"

#include <assert.h>
#include <tchar.h>

#include "XmlVoedingswaarde.h"
#include "XmlPuntenper100.h"
#include "XmlVoedingsmiddelheader.h"
#include "XmlPortie.h"

namespace ww2015
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
  if (mPuntenper100 != NULL)
    delete mPuntenper100;
  for (size_t i = 0; i < mPortieList.size(); ++i)
    delete mPortieList[i];
}

const XmlVoedingswaarde * XmlVoedingsmiddeldef::GetVoedingswaarde() const
{
  return mVoedingswaarde;
}
const XmlPuntenper100 * XmlVoedingsmiddeldef::GetPuntenper100() const
{
  return mPuntenper100;
}
XmlVoedingsmiddelheader & XmlVoedingsmiddeldef::GetVoedingsmiddelheader()
{
  return mVoedingsmiddelheader;
}

const XmlVoedingsmiddelheader & XmlVoedingsmiddeldef::GetVoedingsmiddelheader() const
{
  return mVoedingsmiddelheader;
}


const std::vector<XmlPortie *> & XmlVoedingsmiddeldef::GetPortieList() const
{
  return mPortieList;
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


void XmlVoedingsmiddeldef::Add(XmlPortie * aPortie)
{
  mPortieList.push_back(aPortie);
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