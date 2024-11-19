//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlPuntenper100Reader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlPuntenper100.h"


namespace ww2019
{
XmlPuntenper100Reader::XmlPuntenper100Reader()
{
}


std::unique_ptr<XmlPuntenper100> XmlPuntenper100Reader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
    auto puntenper100 = std::make_unique<XmlPuntenper100>();
    Fill(anElement, *puntenper100);
    return puntenper100;
}

XmlClass::Result XmlPuntenper100Reader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlPuntenper100 & aPuntenper100)
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
    const XERCES_CPP_NAMESPACE::DOMNode* puntennode = attributes->getNamedItem(_T("punten"));
    if (puntennode != nullptr)
      aPuntenper100.Setpunten(puntennode->getNodeValue());
    }

    return XmlClass::Result::Ok;
}


}
