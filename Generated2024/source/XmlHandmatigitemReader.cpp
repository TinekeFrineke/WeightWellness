//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlHandmatigitemReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlHandmatigitem.h"


namespace ww2024
{
XmlHandmatigitemReader::XmlHandmatigitemReader()
{
}


std::unique_ptr<XmlHandmatigitem> XmlHandmatigitemReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
    auto handmatigitem = std::make_unique<XmlHandmatigitem>();
    Fill(anElement, *handmatigitem);
    return handmatigitem;
}

XmlClass::Result XmlHandmatigitemReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlHandmatigitem & aHandmatigitem)
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
      aHandmatigitem.Setnaam(naamnode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* puntennode = attributes->getNamedItem(_T("punten"));
    if (puntennode != nullptr) {
        aHandmatigitem.Setpunten(_wtof(puntennode->getNodeValue()));
    }
    }

    return XmlClass::Result::Ok;
}


}
