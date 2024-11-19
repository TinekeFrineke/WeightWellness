//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlBonuscellReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlBonuscell.h"


namespace ww2019
{
XmlBonuscellReader::XmlBonuscellReader()
{
}


std::unique_ptr<XmlBonuscell> XmlBonuscellReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
    auto bonuscell = std::make_unique<XmlBonuscell>();
    Fill(anElement, *bonuscell);
    return bonuscell;
}

XmlClass::Result XmlBonuscellReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlBonuscell & aBonuscell)
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
    const XERCES_CPP_NAMESPACE::DOMNode* gewichtnode = attributes->getNamedItem(_T("gewicht"));
    if (gewichtnode != nullptr) {
        aBonuscell.Setgewicht(_ttoi(gewichtnode->getNodeValue()));
    }
    const XERCES_CPP_NAMESPACE::DOMNode* intensiteitnode = attributes->getNamedItem(_T("intensiteit"));
    if (intensiteitnode != nullptr)
    {
      if (_tcscmp(intensiteitnode->getNodeValue(), _T("laag")) == 0)
        aBonuscell.Setintensiteit(XmlBonuscell::intensiteit::laag);
      else if (_tcscmp(intensiteitnode->getNodeValue(), _T("middel")) == 0)
        aBonuscell.Setintensiteit(XmlBonuscell::intensiteit::middel);
      else if (_tcscmp(intensiteitnode->getNodeValue(), _T("hoog")) == 0)
        aBonuscell.Setintensiteit(XmlBonuscell::intensiteit::hoog);
    }
    const XERCES_CPP_NAMESPACE::DOMNode* minutennode = attributes->getNamedItem(_T("minuten"));
    if (minutennode != nullptr) {
        aBonuscell.Setminuten(_ttoi(minutennode->getNodeValue()));
    }
    const XERCES_CPP_NAMESPACE::DOMNode* puntennode = attributes->getNamedItem(_T("punten"));
    if (puntennode != nullptr) {
        aBonuscell.Setpunten(_ttoi(puntennode->getNodeValue()));
    }
    }

    return XmlClass::Result::Ok;
}


}
