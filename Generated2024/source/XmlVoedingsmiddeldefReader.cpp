//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlVoedingsmiddeldefReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlVoedingsmiddeldef.h"
#include "XmlVoedingswaardeReader.h"
#include "XmlVoedingswaarde.h"
#include "XmlPortieReader.h"
#include "XmlPortie.h"


namespace ww2024
{
XmlVoedingsmiddeldefReader::XmlVoedingsmiddeldefReader()
{
}


std::unique_ptr<XmlVoedingsmiddeldef> XmlVoedingsmiddeldefReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
    auto voedingsmiddeldef = std::make_unique<XmlVoedingsmiddeldef>();
    Fill(anElement, *voedingsmiddeldef);
    return voedingsmiddeldef;
}

XmlClass::Result XmlVoedingsmiddeldefReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingsmiddeldef & aVoedingsmiddeldef)
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
     if (_tcscmp(node->getNodeName(), _T("voedingswaarde")) == 0)
     {
         XmlVoedingswaardeReader VoedingswaardeReader;
         XmlVoedingswaarde & Voedingswaarde = aVoedingsmiddeldef.GetVoedingswaarde();
         VoedingswaardeReader.Fill(*node, Voedingswaarde);
     }
     else if (_tcscmp(node->getNodeName(), _T("portie")) == 0)
     {
         XmlPortieReader portieReader;
         auto portie = portieReader.Generate(*node);
         if (portie != nullptr)
             aVoedingsmiddeldef.Add(std::move(portie));
     }
   }
  }
    const XERCES_CPP_NAMESPACE::DOMNamedNodeMap * attributes = anElement.getAttributes();
    if (attributes != nullptr)
    {
    const XERCES_CPP_NAMESPACE::DOMNode* naamnode = attributes->getNamedItem(_T("naam"));
    if (naamnode != nullptr)
      aVoedingsmiddeldef.Setnaam(naamnode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* categorienode = attributes->getNamedItem(_T("categorie"));
    if (categorienode != nullptr)
      aVoedingsmiddeldef.Setcategorie(categorienode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* merknode = attributes->getNamedItem(_T("merk"));
    if (merknode != nullptr)
      aVoedingsmiddeldef.Setmerk(merknode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* unitnode = attributes->getNamedItem(_T("unit"));
    if (unitnode != nullptr)
      aVoedingsmiddeldef.Setunit(unitnode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* favorietnode = attributes->getNamedItem(_T("favoriet"));
    if (favorietnode != nullptr)
    {
      if (_tcscmp(favorietnode->getNodeValue(), _T("yes")) == 0)
        aVoedingsmiddeldef.Setfavoriet(XmlVoedingsmiddeldef::favoriet::yes);
      else if (_tcscmp(favorietnode->getNodeValue(), _T("no")) == 0)
        aVoedingsmiddeldef.Setfavoriet(XmlVoedingsmiddeldef::favoriet::no);
    }
    }

    return XmlClass::Result::Ok;
}


}
