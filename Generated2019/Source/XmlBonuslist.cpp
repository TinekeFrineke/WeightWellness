//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlBonuslist.h"

#include <assert.h>
#include <tchar.h>

#include "XmlBonuscell.h"

namespace ww2019
{
XmlBonuslist::XmlBonuslist()
{
}

XmlBonuslist::~XmlBonuslist()
{
}



const std::vector<std::unique_ptr<XmlBonuscell>> & XmlBonuslist::GetBonuscellList() const
{
    return mBonuscellList;
}


void XmlBonuslist::Add(std::unique_ptr<XmlBonuscell> aBonuscell)
{
    mBonuscellList.push_back(std::move(aBonuscell));
}
}