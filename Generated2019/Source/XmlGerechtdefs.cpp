//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlGerechtdefs.h"

#include <assert.h>
#include <tchar.h>

#include "XmlGerechtdef.h"

namespace ww2019
{
XmlGerechtdefs::XmlGerechtdefs()
{
}

XmlGerechtdefs::~XmlGerechtdefs()
{
}



const std::vector<std::unique_ptr<XmlGerechtdef>> & XmlGerechtdefs::GetGerechtdefList() const
{
    return mGerechtdefList;
}


void XmlGerechtdefs::Add(std::unique_ptr<XmlGerechtdef> aGerechtdef)
{
    mGerechtdefList.push_back(std::move(aGerechtdef));
}
}