//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#pragma once

#include <xercesc/util/xercesdefs.hpp>
#include <memory>
#include <vector>

#include "XmlClass.h"

namespace ww2024
{

// Forward declarations
class XmlVoedingsmiddeldef;


class XmlVoedingsmiddeldefs : public XmlClass
{
public:
    XmlVoedingsmiddeldefs();
    ~XmlVoedingsmiddeldefs() override;

    const std::vector<std::unique_ptr<XmlVoedingsmiddeldef>> & GetVoedingsmiddeldefList() const;
    void Add(std::unique_ptr<XmlVoedingsmiddeldef> aVoedingsmiddeldef);

private:
    XmlVoedingsmiddeldefs(const XmlVoedingsmiddeldefs& anOriginal) = delete;
    XmlVoedingsmiddeldefs& operator=(const XmlVoedingsmiddeldefs& anOriginal) = delete;

    std::vector<std::unique_ptr<XmlVoedingsmiddeldef>> mVoedingsmiddeldefList;
};


}
