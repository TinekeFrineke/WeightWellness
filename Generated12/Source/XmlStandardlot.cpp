#include "../Interface\Generated\stdafx.h"
#include "../Interface\Generated\XmlStandardlot.h"

#include <assert.h>
#include <tchar.h>

#include "../Interface\Generated\XmlVoedingswaarde.h"
#include "../Interface\Generated\XmlPortie.h"
#include "../Interface\Generated\XmlPuntenper100.h"

namespace ww_1_2
{
XmlStandardlot::XmlStandardlot()
: mVoedingswaarde(NULL),
  mPuntenper100(NULL), msterrelot(sterrelot_true)

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
XmlStandardlot::sterrelot XmlStandardlot::Getsterrelot() const
{
  return msterrelot;
}

std::wstring XmlStandardlot::Gethoeveelheid() const
{
  return mhoeveelheid;
}

void XmlStandardlot::Setsterrelot(sterrelot asterrelot)
{
   msterrelot = asterrelot;
}

void XmlStandardlot::Sethoeveelheid(const std::wstring & ahoeveelheid)
{
   mhoeveelheid = ahoeveelheid;
}

}