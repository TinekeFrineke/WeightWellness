//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlReceptReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlRecept.h"


namespace ww2024
{
XmlReceptReader::XmlReceptReader()
{
}


std::unique_ptr<XmlRecept> XmlReceptReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
    auto recept = std::make_unique<XmlRecept>();
    Fill(anElement, *recept);
    return recept;
}

XmlClass::Result XmlReceptReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlRecept & aRecept)
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
      aRecept.Setnaam(naamnode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* puntennode = attributes->getNamedItem(_T("punten"));
    if (puntennode != nullptr) {
        aRecept.Setpunten(_wtof(puntennode->getNodeValue()));
    }
    const XERCES_CPP_NAMESPACE::DOMNode* aantalportiesnode = attributes->getNamedItem(_T("aantalporties"));
    if (aantalportiesnode != nullptr) {
        aRecept.Setaantalporties(_ttoi(aantalportiesnode->getNodeValue()));
    }
    }

    return XmlClass::Result::Ok;
}


}
