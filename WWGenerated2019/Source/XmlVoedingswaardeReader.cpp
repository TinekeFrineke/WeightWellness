#include "../Interface/stdafx.h"
#include "../Interface/XmlVoedingswaardeReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "../Interface/XmlVoedingswaarde.h"


namespace ww2019
{
XmlVoedingswaardeReader::XmlVoedingswaardeReader()
{
}


XmlVoedingswaarde * XmlVoedingswaardeReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlVoedingswaarde * Voedingswaarde = new XmlVoedingswaarde;
  Fill(anElement, *Voedingswaarde);
  return Voedingswaarde;
}

XmlClass::eRESULT XmlVoedingswaardeReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingswaarde & aVoedingswaarde)
{
  XERCES_CPP_NAMESPACE::DOMNodeList * list = anElement.getChildNodes();

  if (list == NULL)
    return XmlClass::RESULT_Ok;

  for (XMLSize_t i = 0; i < list->getLength(); i++)
  {
    if (list->item(i) == NULL)
      continue;

  }
  XERCES_CPP_NAMESPACE::DOMNamedNodeMap * attributes = anElement.getAttributes();
  if (attributes != NULL)
  {
    XERCES_CPP_NAMESPACE::DOMNode * kcalper100node = attributes->getNamedItem(_T("kcalper100"));
    if (kcalper100node != NULL)
      aVoedingswaarde.Setkcalper100(kcalper100node->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * vetper100node = attributes->getNamedItem(_T("vetper100"));
    if (vetper100node != NULL)
      aVoedingswaarde.Setvetper100(vetper100node->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * koolhydratenper100node = attributes->getNamedItem(_T("koolhydratenper100"));
    if (koolhydratenper100node != NULL)
      aVoedingswaarde.Setkoolhydratenper100(koolhydratenper100node->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * eiwitper100node = attributes->getNamedItem(_T("eiwitper100"));
    if (eiwitper100node != NULL)
      aVoedingswaarde.Seteiwitper100(eiwitper100node->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * vezelsper100node = attributes->getNamedItem(_T("vezelsper100"));
    if (vezelsper100node != NULL)
      aVoedingswaarde.Setvezelsper100(vezelsper100node->getNodeValue());
  }

  return XmlClass::RESULT_Ok;
}


}
