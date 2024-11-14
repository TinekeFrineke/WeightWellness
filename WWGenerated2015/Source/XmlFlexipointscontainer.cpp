#include "stdafx.h"
#include "XmlFlexipointscontainer.h"

#include <assert.h>
#include <tchar.h>

#include "XmlFlexipoints.h"

namespace ww2015
{
XmlFlexipointscontainer::XmlFlexipointscontainer()
{
}

XmlFlexipointscontainer::~XmlFlexipointscontainer()
{
  for (size_t i = 0; i < mFlexipointsList.size(); ++i)
    delete mFlexipointsList[i];
}



const std::vector<XmlFlexipoints *> & XmlFlexipointscontainer::GetFlexipointsList() const
{
  return mFlexipointsList;
}


void XmlFlexipointscontainer::Add(XmlFlexipoints * aFlexipoints)
{
  mFlexipointsList.push_back(aFlexipoints);
}
}