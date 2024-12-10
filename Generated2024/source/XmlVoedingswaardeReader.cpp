//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlVoedingswaardeReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlVoedingswaarde.h"


namespace ww2024
{
XmlVoedingswaardeReader::XmlVoedingswaardeReader()
{
}


std::unique_ptr<XmlVoedingswaarde> XmlVoedingswaardeReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
    auto voedingswaarde = std::make_unique<XmlVoedingswaarde>();
    Fill(anElement, *voedingswaarde);
    return voedingswaarde;
}

XmlClass::Result XmlVoedingswaardeReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingswaarde & aVoedingswaarde)
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
    const XERCES_CPP_NAMESPACE::DOMNode* kcalper100node = attributes->getNamedItem(_T("kcalper100"));
    if (kcalper100node != nullptr) {
        aVoedingswaarde.Setkcalper100(_wtof(kcalper100node->getNodeValue()));
    }
    const XERCES_CPP_NAMESPACE::DOMNode* vetper100node = attributes->getNamedItem(_T("vetper100"));
    if (vetper100node != nullptr) {
        aVoedingswaarde.Setvetper100(_wtof(vetper100node->getNodeValue()));
    }
    const XERCES_CPP_NAMESPACE::DOMNode* koolhydratenper100node = attributes->getNamedItem(_T("koolhydratenper100"));
    if (koolhydratenper100node != nullptr) {
        aVoedingswaarde.Setkoolhydratenper100(_wtof(koolhydratenper100node->getNodeValue()));
    }
    const XERCES_CPP_NAMESPACE::DOMNode* eiwitper100node = attributes->getNamedItem(_T("eiwitper100"));
    if (eiwitper100node != nullptr) {
        aVoedingswaarde.Seteiwitper100(_wtof(eiwitper100node->getNodeValue()));
    }
    const XERCES_CPP_NAMESPACE::DOMNode* vezelsper100node = attributes->getNamedItem(_T("vezelsper100"));
    if (vezelsper100node != nullptr) {
        aVoedingswaarde.Setvezelsper100(_wtof(vezelsper100node->getNodeValue()));
    }
    }

    return XmlClass::Result::Ok;
}


}
