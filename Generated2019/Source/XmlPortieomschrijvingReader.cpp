//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlPortieomschrijvingReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlPortieomschrijving.h"


namespace ww2019
{
XmlPortieomschrijvingReader::XmlPortieomschrijvingReader()
{
}


std::unique_ptr<XmlPortieomschrijving> XmlPortieomschrijvingReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
    auto portieomschrijving = std::make_unique<XmlPortieomschrijving>();
    Fill(anElement, *portieomschrijving);
    return portieomschrijving;
}

XmlClass::Result XmlPortieomschrijvingReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlPortieomschrijving & aPortieomschrijving)
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
    const XERCES_CPP_NAMESPACE::DOMNode* omschrijvingnode = attributes->getNamedItem(_T("omschrijving"));
    if (omschrijvingnode != nullptr)
      aPortieomschrijving.Setomschrijving(omschrijvingnode->getNodeValue());
    }

    return XmlClass::Result::Ok;
}


}
