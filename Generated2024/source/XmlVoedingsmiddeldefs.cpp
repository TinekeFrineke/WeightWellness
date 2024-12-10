//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlVoedingsmiddeldefs.h"

#include <assert.h>
#include <tchar.h>

#include "XmlVoedingsmiddeldef.h"

namespace ww2024
{
XmlVoedingsmiddeldefs::XmlVoedingsmiddeldefs()
{
}

XmlVoedingsmiddeldefs::~XmlVoedingsmiddeldefs()
{
}



const std::vector<std::unique_ptr<XmlVoedingsmiddeldef>> & XmlVoedingsmiddeldefs::GetVoedingsmiddeldefList() const
{
    return mVoedingsmiddeldefList;
}


void XmlVoedingsmiddeldefs::Add(std::unique_ptr<XmlVoedingsmiddeldef> aVoedingsmiddeldef)
{
    mVoedingsmiddeldefList.push_back(std::move(aVoedingsmiddeldef));
}
}