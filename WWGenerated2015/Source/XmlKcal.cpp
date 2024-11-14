#include "stdafx.h"
#include "XmlKcal.h"

#include <assert.h>
#include <tchar.h>

#include "XmlStrategybase.h"

namespace ww2015
{
XmlKcal::XmlKcal()
{
}

XmlKcal::~XmlKcal()
{
}

XmlStrategybase & XmlKcal::GetStrategybase()
{
  return mStrategybase;
}

const XmlStrategybase & XmlKcal::GetStrategybase() const
{
  return mStrategybase;
}
}