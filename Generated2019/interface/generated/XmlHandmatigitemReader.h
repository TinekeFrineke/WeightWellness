//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#pragma once

#include <xercesc/util/xercesdefs.hpp>

#include <memory>
#include <string>

#include "XmlClass.h"


XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2019
{

class XmlHandmatigitem;

class XmlHandmatigitemReader : public XmlClass
{
public:
    XmlHandmatigitemReader();

    std::unique_ptr<XmlHandmatigitem> Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

    XmlClass::Result Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlHandmatigitem & Handmatigitem);

private:
    XmlHandmatigitemReader(const XmlHandmatigitemReader& anOriginal) = delete;
    XmlHandmatigitemReader& operator=(const XmlHandmatigitemReader& anOriginal) = delete;

};


}
