#include "stdafx.h"
#include "XmlFlexipoints.h"

#include <assert.h>
#include <tchar.h>

#include "XmlBonuslist.h"
#include "XmlVrijeporties.h"
#include "XmlStrategybase.h"

namespace ww2015
{
XmlFlexipoints::XmlFlexipoints()
{
}

XmlFlexipoints::~XmlFlexipoints()
{
}

XmlBonuslist & XmlFlexipoints::GetBonuslist()
{
  return mBonuslist;
}

const XmlBonuslist & XmlFlexipoints::GetBonuslist() const
{
  return mBonuslist;
}
XmlVrijeporties & XmlFlexipoints::GetVrijeporties()
{
  return mVrijeporties;
}

const XmlVrijeporties & XmlFlexipoints::GetVrijeporties() const
{
  return mVrijeporties;
}
XmlStrategybase & XmlFlexipoints::GetStrategybase()
{
  return mStrategybase;
}

const XmlStrategybase & XmlFlexipoints::GetStrategybase() const
{
  return mStrategybase;
}
}