#include "stdafx.h"
#include "XmlPropointscontainer.h"

#include <assert.h>
#include <tchar.h>

#include "XmlPropoints.h"

namespace ww2015
{
XmlPropointscontainer::XmlPropointscontainer()
{
}

XmlPropointscontainer::~XmlPropointscontainer()
{
  for (size_t i = 0; i < mPropointsList.size(); ++i)
    delete mPropointsList[i];
}



const std::vector<XmlPropoints *> & XmlPropointscontainer::GetPropointsList() const
{
  return mPropointsList;
}


void XmlPropointscontainer::Add(XmlPropoints * aPropoints)
{
  mPropointsList.push_back(aPropoints);
}
}