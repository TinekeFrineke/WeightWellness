//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlPortieReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlPortie.h"


namespace ww2024
{
XmlPortieReader::XmlPortieReader()
{
}


std::unique_ptr<XmlPortie> XmlPortieReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
    auto portie = std::make_unique<XmlPortie>();
    Fill(anElement, *portie);
    return portie;
}

XmlClass::Result XmlPortieReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlPortie & aPortie)
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
      aPortie.Setnaam(naamnode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* eenhedennode = attributes->getNamedItem(_T("eenheden"));
    if (eenhedennode != nullptr) {
        aPortie.Seteenheden(_wtof(eenhedennode->getNodeValue()));
    }
    }

    return XmlClass::Result::Ok;
}


}
