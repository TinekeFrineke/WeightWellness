#include "stdafx.h"
#include "XmlSterrelots.h"

#include <assert.h>
#include <tchar.h>

#include "XmlSterrelot.h"

namespace ww2015
{
XmlSterrelots::XmlSterrelots()
: mSterrelot(NULL)
{
}

XmlSterrelots::~XmlSterrelots()
{
  if (mSterrelot != NULL)
    delete mSterrelot;
}

const XmlSterrelot * XmlSterrelots::GetSterrelot() const
{
  return mSterrelot;
}


void XmlSterrelots::Add(XmlSterrelot * aSterrelot)
{
  assert(mSterrelot == NULL);
  mSterrelot = aSterrelot;
}
}