//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlVoedingsmiddelReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlVoedingsmiddel.h"
#include "XmlStandardlotReader.h"
#include "XmlStandardlot.h"


namespace ww2019
{
XmlVoedingsmiddelReader::XmlVoedingsmiddelReader()
{
}


std::unique_ptr<XmlVoedingsmiddel> XmlVoedingsmiddelReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
    auto voedingsmiddel = std::make_unique<XmlVoedingsmiddel>();
    Fill(anElement, *voedingsmiddel);
    return voedingsmiddel;
}

XmlClass::Result XmlVoedingsmiddelReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingsmiddel & aVoedingsmiddel)
{
    const XERCES_CPP_NAMESPACE::DOMNodeList * list = anElement.getChildNodes();

    if (list == nullptr)
        return XmlClass::Result::Ok;

    for (XMLSize_t i = 0; i < list->getLength(); i++) {
        if (list->item(i) == nullptr)
            continue;

        short type = list->item(i)->getNodeType();
        XERCES_CPP_NAMESPACE::DOMNode * node = list->item(i);

        if (type == XERCES_CPP_NAMESPACE::DOMNode::ELEMENT_NODE) {
     if (_tcscmp(node->getNodeName(), _T("standardlot")) == 0)
     {
         XmlStandardlotReader standardlotReader;
         auto standardlot = standardlotReader.Generate(*node);
         if (standardlot != nullptr)
             aVoedingsmiddel.Add(std::move(standardlot));
     }
   }
  }
    const XERCES_CPP_NAMESPACE::DOMNamedNodeMap * attributes = anElement.getAttributes();
    if (attributes != nullptr)
    {
    const XERCES_CPP_NAMESPACE::DOMNode* naamnode = attributes->getNamedItem(_T("naam"));
    if (naamnode != nullptr)
      aVoedingsmiddel.Setnaam(naamnode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* categorienode = attributes->getNamedItem(_T("categorie"));
    if (categorienode != nullptr)
      aVoedingsmiddel.Setcategorie(categorienode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* merknode = attributes->getNamedItem(_T("merk"));
    if (merknode != nullptr)
      aVoedingsmiddel.Setmerk(merknode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* unitnode = attributes->getNamedItem(_T("unit"));
    if (unitnode != nullptr)
      aVoedingsmiddel.Setunit(unitnode->getNodeValue());
    }

    return XmlClass::Result::Ok;
}


}
