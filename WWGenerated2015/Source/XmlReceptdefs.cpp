#include "stdafx.h"
#include "XmlReceptdefs.h"

#include <assert.h>
#include <tchar.h>

#include "XmlReceptdef.h"

namespace ww2015
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