#include "stdafx.h"
#include "XmlKoolhydraten.h"

#include <assert.h>
#include <tchar.h>

#include "XmlStrategybase.h"

namespace ww2015
{
XmlKoolhydraten::XmlKoolhydraten()
{
}

XmlKoolhydraten::~XmlKoolhydraten()
{
}

XmlStrategybase & XmlKoolhydraten::GetStrategybase()
{
  return mStrategybase;
}

const XmlStrategybase & XmlKoolhydraten::GetStrategybase() const
{
  return mStrategybase;
}
}