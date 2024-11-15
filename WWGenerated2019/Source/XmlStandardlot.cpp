#include "../Interface/stdafx.h"
#include "../Interface/XmlStandardlot.h"

#include <assert.h>
#include <tchar.h>

#include "../Interface/XmlPortie.h"
#include "../Interface/XmlPuntenper100.h"
#include "../Interface/XmlVoedingswaarde.h"

namespace ww2019
{
XmlStandardlot::XmlStandardlot()
: mPuntenper100(NULL),
  mVoedingswaarde(NULL)
{
}

XmlStandardlot::~XmlStandardlot()
{
  if (mPuntenper100 != NULL)
    delete mPuntenper100;
  if (mVoedingswaarde != NULL)
    delete mVoedingswaarde;
}

XmlPortie & XmlStandardlot::GetPortie()
{
  return mPortie;
}

const XmlPortie & XmlStandardlot::GetPortie() const
{
  return mPortie;
}
const XmlPuntenper100 * XmlStandardlot::GetPuntenper100() const
{
  return mPuntenper100;
}
const XmlVoedingswaarde * XmlStandardlot::GetVoedingswaarde() const
{
  return mVoedingswaarde;
}


void XmlStandardlot::Add(XmlPuntenper100 * aPuntenper100)
{
  assert(mPuntenper100 == NULL);
  mPuntenper100 = aPuntenper100;
}


void XmlStandardlot::Add(XmlVoedingswaarde * aVoedingswaarde)
{
  assert(mVoedingswaarde == NULL);
  mVoedingswaarde = aVoedingswaarde;
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