//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlUnitReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlUnit.h"


namespace ww2019
{
XmlUnitReader::XmlUnitReader()
{
}


std::unique_ptr<XmlUnit> XmlUnitReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
    auto unit = std::make_unique<XmlUnit>();
    Fill(anElement, *unit);
    return unit;
}

XmlClass::Result XmlUnitReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlUnit & aUnit)
{
    const XERCES_CPP_NAMESPACE::DOMNodeList * list = anElement.getChildNodes();

    if (list == nullptr)
        return XmlClass::Result::Ok;

    for (XMLSize_t i = 0; i < list->getLength(); i++) {
        if (list->item(i) == nullptr)
            continue;

  }
    const XERCES_CPP_NAMESPACE::DOMNamedNodeMap * attributes = anElement.getAttributes();
    if (attributes != nullptr)
    {
    const XERCES_CPP_NAMESPACE::DOMNode* naamnode = attributes->getNamedItem(_T("naam"));
    if (naamnode != nullptr)
      aUnit.Setnaam(naamnode->getNodeValue());
    }

    return XmlClass::Result::Ok;
}


}
