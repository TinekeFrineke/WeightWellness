#include "../Interface/stdafx.h"
#include "../Interface/XmlKcal.h"

#include <assert.h>
#include <tchar.h>

#include "../Interface/XmlStrategybase.h"

namespace ww2019
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