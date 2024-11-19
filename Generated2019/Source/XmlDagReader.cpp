//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlDagReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlDag.h"
#include "XmlVoedingsmiddelReader.h"
#include "XmlVoedingsmiddel.h"
#include "XmlReceptReader.h"
#include "XmlRecept.h"
#include "XmlGerechtReader.h"
#include "XmlGerecht.h"
#include "XmlHandmatigitemReader.h"
#include "XmlHandmatigitem.h"
#include "XmlBonuscellReader.h"
#include "XmlBonuscell.h"


namespace ww2019
{
XmlDagReader::XmlDagReader()
{
}


std::unique_ptr<XmlDag> XmlDagReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
    auto dag = std::make_unique<XmlDag>();
    Fill(anElement, *dag);
    return dag;
}

XmlClass::Result XmlDagReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlDag & aDag)
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
             aDag.Add(std::move(voedingsmiddel));
     }
     else if (_tcscmp(node->getNodeName(), _T("recept")) == 0)
     {
         XmlReceptReader receptReader;
         auto recept = receptReader.Generate(*node);
         if (recept != nullptr)
             aDag.Add(std::move(recept));
     }
     else if (_tcscmp(node->getNodeName(), _T("gerecht")) == 0)
     {
         XmlGerechtReader gerechtReader;
         auto gerecht = gerechtReader.Generate(*node);
         if (gerecht != nullptr)
             aDag.Add(std::move(gerecht));
     }
     else if (_tcscmp(node->getNodeName(), _T("handmatigitem")) == 0)
     {
         XmlHandmatigitemReader handmatigitemReader;
         auto handmatigitem = handmatigitemReader.Generate(*node);
         if (handmatigitem != nullptr)
             aDag.Add(std::move(handmatigitem));
     }
     else if (_tcscmp(node->getNodeName(), _T("bonuscell")) == 0)
     {
         XmlBonuscellReader bonuscellReader;
         auto bonuscell = bonuscellReader.Generate(*node);
         if (bonuscell != nullptr)
             aDag.Add(std::move(bonuscell));
     }
   }
  }
    const XERCES_CPP_NAMESPACE::DOMNamedNodeMap * attributes = anElement.getAttributes();
    if (attributes != nullptr)
    {
    const XERCES_CPP_NAMESPACE::DOMNode* bonuspuntennode = attributes->getNamedItem(_T("bonuspunten"));
    if (bonuspuntennode != nullptr)
      aDag.Setbonuspunten(bonuspuntennode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* datumnode = attributes->getNamedItem(_T("datum"));
    if (datumnode != nullptr)
      aDag.Setdatum(datumnode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* gewichtnode = attributes->getNamedItem(_T("gewicht"));
    if (gewichtnode != nullptr)
      aDag.Setgewicht(gewichtnode->getNodeValue());
    }

    return XmlClass::Result::Ok;
}


}
