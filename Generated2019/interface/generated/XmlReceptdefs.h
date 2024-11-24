//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#pragma once

#include <xercesc/util/xercesdefs.hpp>
#include <memory>
#include <vector>

#include "XmlClass.h"

// Includes for children

namespace ww2019
{


class XmlReceptdef;


class XmlReceptdefs : public XmlClass
{
public:
    XmlReceptdefs();
    ~XmlReceptdefs() override;

    const std::vector<std::unique_ptr<XmlReceptdef>> & GetReceptdefList() const;
    void Add(std::unique_ptr<XmlReceptdef> aReceptdef);

private:
    XmlReceptdefs(const XmlReceptdefs& anOriginal) = delete;
    XmlReceptdefs& operator=(const XmlReceptdefs& anOriginal) = delete;

    std::vector<std::unique_ptr<XmlReceptdef>> mReceptdefList;
};


}
