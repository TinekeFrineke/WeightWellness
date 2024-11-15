#include "../Interface/stdafx.h"
#include "../Interface/XmlGerechtdefs.h"

#include <assert.h>
#include <tchar.h>

#include "../Interface/XmlGerechtdef.h"

namespace ww2019
{
XmlGerechtdefs::XmlGerechtdefs()
{
}

XmlGerechtdefs::~XmlGerechtdefs()
{
  for (size_t i = 0; i < mGerechtdefList.size(); ++i)
    delete mGerechtdefList[i];
}



const std::vector<XmlGerechtdef *> & XmlGerechtdefs::GetGerechtdefList() const
{
  return mGerechtdefList;
}


void XmlGerechtdefs::Add(XmlGerechtdef * aGerechtdef)
{
  mGerechtdefList.push_back(aGerechtdef);
}
}