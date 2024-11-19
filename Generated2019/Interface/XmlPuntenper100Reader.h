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

class XmlPuntenper100;

class XmlPuntenper100Reader : public XmlClass
{
public:
    XmlPuntenper100Reader();

    std::unique_ptr<XmlPuntenper100> Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

    XmlClass::Result Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlPuntenper100 & Puntenper100);

private:
    XmlPuntenper100Reader(const XmlPuntenper100Reader& anOriginal) = delete;
    XmlPuntenper100Reader& operator=(const XmlPuntenper100Reader& anOriginal) = delete;

};


}
