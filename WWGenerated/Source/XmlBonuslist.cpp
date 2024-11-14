#include "stdafx.h"
#include "XmlBonuslist.h"

#include <assert.h>
#include <tchar.h>

#include "XmlBonuscell.h"

namespace ww_1_1
{
XmlBonuslist::XmlBonuslist()
{
}

XmlBonuslist::~XmlBonuslist()
{
  for (size_t i = 0; i < mBonuscellList.size(); ++i)
    delete mBonuscellList[i];
}



const std::vector<XmlBonuscell *> & XmlBonuslist::GetBonuscellList() const
{
  return mBonuscellList;
}


void XmlBonuslist::Add(XmlBonuscell * aBonuscell)
{
  mBonuscellList.push_back(aBonuscell);
}
}