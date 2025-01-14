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

namespace ww2024
{

class XmlDag;

class XmlDagReader : public XmlClass
{
public:
    XmlDagReader();

    std::unique_ptr<XmlDag> Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

    XmlClass::Result Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlDag & Dag);

private:
    XmlDagReader(const XmlDagReader& anOriginal) = delete;
    XmlDagReader& operator=(const XmlDagReader& anOriginal) = delete;

};


}
