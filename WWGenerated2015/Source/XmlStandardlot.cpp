#include "stdafx.h"
#include "XmlStandardlot.h"

#include <assert.h>
#include <tchar.h>

#include "XmlVoedingswaarde.h"
#include "XmlPuntenper100.h"
#include "XmlPortie.h"

namespace ww2015
{
XmlStandardlot::XmlStandardlot()
: mVoedingswaarde(NULL),
  mPuntenper100(NULL)
{
}

XmlStandardlot::~XmlStandardlot()
{
  if (mVoedingswaarde != NULL)
    delete mVoedingswaarde;
  if (mPuntenper100 != NULL)
    delete mPuntenper100;
}

const XmlVoedingswaarde * XmlStandardlot::GetVoedingswaarde() const
{
  return mVoedingswaarde;
}
const XmlPuntenper100 * XmlStandardlot::GetPuntenper100() const
{
  return mPuntenper100;
}
XmlPortie & XmlStandardlot::GetPortie()
{
  return mPortie;
}

const XmlPortie & XmlStandardlot::GetPortie() const
{
  return mPortie;
}


void XmlStandardlot::Add(XmlVoedingswaarde * aVoedingswaarde)
{
  assert(mVoedingswaarde == NULL);
  mVoedingswaarde = aVoedingswaarde;
}


void XmlStandardlot::Add(XmlPuntenper100 * aPuntenper100)
{
  assert(mPuntenper100 == NULL);
  mPuntenper100 = aPuntenper100;
}
std::wstring XmlStandardlot::Gethoeveelheid() const
{
  return mhoeveelheid;
}

void XmlStandardlot::Sethoeveelheid(const std::wstring & ahoeveelheid)
{
   mhoeveelheid = ahoeveelheid;
}

}