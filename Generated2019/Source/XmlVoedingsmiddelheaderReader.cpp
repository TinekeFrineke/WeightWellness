//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlVoedingsmiddelheaderReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlVoedingsmiddelheader.h"


namespace ww2019
{
XmlVoedingsmiddelheaderReader::XmlVoedingsmiddelheaderReader()
{
}


std::unique_ptr<XmlVoedingsmiddelheader> XmlVoedingsmiddelheaderReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
    auto voedingsmiddelheader = std::make_unique<XmlVoedingsmiddelheader>();
    Fill(anElement, *voedingsmiddelheader);
    return voedingsmiddelheader;
}

XmlClass::Result XmlVoedingsmiddelheaderReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingsmiddelheader & aVoedingsmiddelheader)
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
      aVoedingsmiddelheader.Setnaam(naamnode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* categorienode = attributes->getNamedItem(_T("categorie"));
    if (categorienode != nullptr)
      aVoedingsmiddelheader.Setcategorie(categorienode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* merknode = attributes->getNamedItem(_T("merk"));
    if (merknode != nullptr)
      aVoedingsmiddelheader.Setmerk(merknode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* unitnode = attributes->getNamedItem(_T("unit"));
    if (unitnode != nullptr)
      aVoedingsmiddelheader.Setunit(unitnode->getNodeValue());
    }

    return XmlClass::Result::Ok;
}


}
