//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlGerechtReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlGerecht.h"


namespace ww2019
{
XmlGerechtReader::XmlGerechtReader()
{
}


std::unique_ptr<XmlGerecht> XmlGerechtReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
    auto gerecht = std::make_unique<XmlGerecht>();
    Fill(anElement, *gerecht);
    return gerecht;
}

XmlClass::Result XmlGerechtReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlGerecht & aGerecht)
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
      aGerecht.Setnaam(naamnode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* puntennode = attributes->getNamedItem(_T("punten"));
    if (puntennode != nullptr)
      aGerecht.Setpunten(puntennode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* hoeveelheidnode = attributes->getNamedItem(_T("hoeveelheid"));
    if (hoeveelheidnode != nullptr)
      aGerecht.Sethoeveelheid(hoeveelheidnode->getNodeValue());
    }

    return XmlClass::Result::Ok;
}


}
