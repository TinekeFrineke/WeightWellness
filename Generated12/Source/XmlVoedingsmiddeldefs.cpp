#include "../Interface\Generated\stdafx.h"
#include "../Interface\Generated\XmlVoedingsmiddeldefs.h"

#include <assert.h>
#include <tchar.h>

#include "../Interface\Generated\XmlVoedingsmiddeldef.h"

namespace ww_1_2
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