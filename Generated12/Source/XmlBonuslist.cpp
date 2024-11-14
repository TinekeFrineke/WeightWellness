#include "../Interface\Generated\stdafx.h"
#include "../Interface\Generated\XmlBonuslist.h"

#include <assert.h>
#include <tchar.h>

#include "../Interface\Generated\XmlBonuscell.h"

namespace ww_1_2
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