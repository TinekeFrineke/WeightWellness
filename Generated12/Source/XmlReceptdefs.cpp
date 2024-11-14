#include "../Interface\Generated\stdafx.h"
#include "../Interface\Generated\XmlReceptdefs.h"

#include <assert.h>
#include <tchar.h>

#include "../Interface\Generated\XmlReceptdef.h"

namespace ww_1_2
{
XmlReceptdefs::XmlReceptdefs()
{
}

XmlReceptdefs::~XmlReceptdefs()
{
  for (size_t i = 0; i < mReceptdefList.size(); ++i)
    delete mReceptdefList[i];
}



const std::vector<XmlReceptdef *> & XmlReceptdefs::GetReceptdefList() const
{
  return mReceptdefList;
}


void XmlReceptdefs::Add(XmlReceptdef * aReceptdef)
{
  mReceptdefList.push_back(aReceptdef);
}
}