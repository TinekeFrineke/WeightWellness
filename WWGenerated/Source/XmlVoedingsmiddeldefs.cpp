#include "stdafx.h"
#include "XmlVoedingsmiddeldefs.h"

#include <assert.h>
#include <tchar.h>

#include "XmlVoedingsmiddeldef.h"

namespace ww_1_1
{
XmlVoedingsmiddeldefs::XmlVoedingsmiddeldefs()
{
}

XmlVoedingsmiddeldefs::~XmlVoedingsmiddeldefs()
{
  for (size_t i = 0; i < mVoedingsmiddeldefList.size(); ++i)
    delete mVoedingsmiddeldefList[i];
}



const std::vector<XmlVoedingsmiddeldef *> & XmlVoedingsmiddeldefs::GetVoedingsmiddeldefList() const
{
  return mVoedingsmiddeldefList;
}


void XmlVoedingsmiddeldefs::Add(XmlVoedingsmiddeldef * aVoedingsmiddeldef)
{
  mVoedingsmiddeldefList.push_back(aVoedingsmiddeldef);
}
}