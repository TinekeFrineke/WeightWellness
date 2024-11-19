//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlReceptdefs.h"

#include <assert.h>
#include <tchar.h>

#include "XmlReceptdef.h"

namespace ww2019
{
XmlReceptdefs::XmlReceptdefs()
{
}

XmlReceptdefs::~XmlReceptdefs()
{
}



const std::vector<std::unique_ptr<XmlReceptdef>> & XmlReceptdefs::GetReceptdefList() const
{
    return mReceptdefList;
}


void XmlReceptdefs::Add(std::unique_ptr<XmlReceptdef> aReceptdef)
{
    mReceptdefList.push_back(std::move(aReceptdef));
}
}