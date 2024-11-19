//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlGerechtdefReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlGerechtdef.h"


namespace ww2019
{
XmlGerechtdefReader::XmlGerechtdefReader()
{
}


std::unique_ptr<XmlGerechtdef> XmlGerechtdefReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
    auto gerechtdef = std::make_unique<XmlGerechtdef>();
    Fill(anElement, *gerechtdef);
    return gerechtdef;
}

XmlClass::Result XmlGerechtdefReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlGerechtdef & aGerechtdef)
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
      aGerechtdef.Setnaam(naamnode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* puntennode = attributes->getNamedItem(_T("punten"));
    if (puntennode != nullptr)
      aGerechtdef.Setpunten(puntennode->getNodeValue());
    }

    return XmlClass::Result::Ok;
}


}
