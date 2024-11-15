#include "../Interface/stdafx.h"
#include "../Interface/XmlVoedingsmiddeldef.h"

#include <assert.h>
#include <tchar.h>

#include "../Interface/XmlPortie.h"
#include "../Interface/XmlPuntenper100.h"
#include "../Interface/XmlVoedingsmiddelheader.h"
#include "../Interface/XmlVoedingswaarde.h"

namespace ww2019
{
XmlVoedingsmiddeldef::XmlVoedingsmiddeldef()
: mPuntenper100(NULL),
  mVoedingswaarde(NULL), mfavoriet(favoriet_false)

{
}

XmlVoedingsmiddeldef::~XmlVoedingsmiddeldef()
{
  for (size_t i = 0; i < mPortieList.size(); ++i)
    delete mPortieList[i];
  if (mPuntenper100 != NULL)
    delete mPuntenper100;
  if (mVoedingswaarde != NULL)
    delete mVoedingswaarde;
}



const std::vector<XmlPortie *> & XmlVoedingsmiddeldef::GetPortieList() const
{
  return mPortieList;
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
const XmlVoedingswaarde * XmlVoedingsmiddeldef::GetVoedingswaarde() const
{
  return mVoedingswaarde;
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


void XmlVoedingsmiddeldef::Add(XmlVoedingswaarde * aVoedingswaarde)
{
  assert(mVoedingswaarde == NULL);
  mVoedingswaarde = aVoedingswaarde;
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