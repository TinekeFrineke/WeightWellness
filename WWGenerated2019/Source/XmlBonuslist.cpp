#include "../Interface/stdafx.h"
#include "../Interface/XmlBonuslist.h"

#include <assert.h>
#include <tchar.h>

#include "../Interface/XmlBonuscell.h"

namespace ww2019
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