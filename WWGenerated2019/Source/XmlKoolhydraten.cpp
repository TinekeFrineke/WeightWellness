#include "../Interface/stdafx.h"
#include "../Interface/XmlKoolhydraten.h"

#include <assert.h>
#include <tchar.h>

#include "../Interface/XmlStrategybase.h"

namespace ww2019
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