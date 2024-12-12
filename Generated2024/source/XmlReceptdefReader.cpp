//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlReceptdefReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlReceptdef.h"
#include "XmlVoedingsmiddelReader.h"
#include "XmlVoedingsmiddel.h"
#include "XmlReceptReader.h"
#include "XmlRecept.h"
#include "XmlHandmatigitemReader.h"
#include "XmlHandmatigitem.h"


namespace ww2024
{
XmlReceptdefReader::XmlReceptdefReader()
{
}


std::unique_ptr<XmlReceptdef> XmlReceptdefReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
    auto receptdef = std::make_unique<XmlReceptdef>();
    Fill(anElement, *receptdef);
    return receptdef;
}

XmlClass::Result XmlReceptdefReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlReceptdef & aReceptdef)
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
     if (_tcscmp(node->getNodeName(), _T("voedingsmiddel")) == 0)
     {
         XmlVoedingsmiddelReader voedingsmiddelReader;
         auto voedingsmiddel = voedingsmiddelReader.Generate(*node);
         if (voedingsmiddel != nullptr)
             aReceptdef.Add(std::move(voedingsmiddel));
     }
     else if (_tcscmp(node->getNodeName(), _T("recept")) == 0)
     {
         XmlReceptReader receptReader;
         auto recept = receptReader.Generate(*node);
         if (recept != nullptr)
             aReceptdef.Add(std::move(recept));
     }
     else if (_tcscmp(node->getNodeName(), _T("handmatigitem")) == 0)
     {
         XmlHandmatigitemReader handmatigitemReader;
         auto handmatigitem = handmatigitemReader.Generate(*node);
         if (handmatigitem != nullptr)
             aReceptdef.Add(std::move(handmatigitem));
     }
   }
  }
    const XERCES_CPP_NAMESPACE::DOMNamedNodeMap * attributes = anElement.getAttributes();
    if (attributes != nullptr)
    {
    const XERCES_CPP_NAMESPACE::DOMNode* naamnode = attributes->getNamedItem(_T("naam"));
    if (naamnode != nullptr)
      aReceptdef.Setnaam(naamnode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* portiesnode = attributes->getNamedItem(_T("porties"));
    if (portiesnode != nullptr) {
        aReceptdef.Setporties(_ttoi(portiesnode->getNodeValue()));
    }
    }

    return XmlClass::Result::Ok;
}


}
