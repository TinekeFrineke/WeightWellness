#include "stdafx.h"
#include "XmlPropoints.h"

#include <assert.h>
#include <tchar.h>

#include "XmlBonuslist.h"
#include "XmlSterrelots.h"
#include "XmlStrategybase.h"

namespace ww2015
{
XmlPropoints::XmlPropoints()
{
}

XmlPropoints::~XmlPropoints()
{
}

XmlBonuslist & XmlPropoints::GetBonuslist()
{
  return mBonuslist;
}

const XmlBonuslist & XmlPropoints::GetBonuslist() const
{
  return mBonuslist;
}
XmlSterrelots & XmlPropoints::GetSterrelots()
{
  return mSterrelots;
}

const XmlSterrelots & XmlPropoints::GetSterrelots() const
{
  return mSterrelots;
}
XmlStrategybase & XmlPropoints::GetStrategybase()
{
  return mStrategybase;
}

const XmlStrategybase & XmlPropoints::GetStrategybase() const
{
  return mStrategybase;
}
}