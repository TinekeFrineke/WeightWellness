//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlVoedingsmiddelReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlVoedingsmiddel.h"
#include "XmlPortieReader.h"
#include "XmlPortie.h"
#include "XmlVoedingswaardeReader.h"
#include "XmlVoedingswaarde.h"


namespace ww2024
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
     if (_tcscmp(node->getNodeName(), _T("portie")) == 0)
     {
         XmlPortieReader PortieReader;
         XmlPortie & Portie = aVoedingsmiddel.GetPortie();
         PortieReader.Fill(*node, Portie);
     }
     else if (_tcscmp(node->getNodeName(), _T("voedingswaarde")) == 0)
     {
         XmlVoedingswaardeReader VoedingswaardeReader;
         XmlVoedingswaarde & Voedingswaarde = aVoedingsmiddel.GetVoedingswaarde();
         VoedingswaardeReader.Fill(*node, Voedingswaarde);
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
    const XERCES_CPP_NAMESPACE::DOMNode* unitnode = attributes->getNamedItem(_T("unit"));
    if (unitnode != nullptr)
      aVoedingsmiddel.Setunit(unitnode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* aantalportiesnode = attributes->getNamedItem(_T("aantalporties"));
    if (aantalportiesnode != nullptr) {
        aVoedingsmiddel.Setaantalporties(_wtof(aantalportiesnode->getNodeValue()));
    }
    }

    return XmlClass::Result::Ok;
}


}
