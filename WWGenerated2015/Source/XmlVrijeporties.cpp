#include "stdafx.h"
#include "XmlVrijeporties.h"

#include <assert.h>
#include <tchar.h>

#include "XmlVrijeportie.h"

namespace ww2015
{
XmlVrijeporties::XmlVrijeporties()
: mVrijeportie(NULL)
{
}

XmlVrijeporties::~XmlVrijeporties()
{
  if (mVrijeportie != NULL)
    delete mVrijeportie;
}

const XmlVrijeportie * XmlVrijeporties::GetVrijeportie() const
{
  return mVrijeportie;
}


void XmlVrijeporties::Add(XmlVrijeportie * aVrijeportie)
{
  assert(mVrijeportie == NULL);
  mVrijeportie = aVrijeportie;
}
}