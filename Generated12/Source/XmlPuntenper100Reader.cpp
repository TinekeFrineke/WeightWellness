#include "../Interface\Generated\stdafx.h"
#include "../Interface\Generated\XmlPuntenper100Reader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "../Interface\Generated\XmlPuntenper100.h"


namespace ww_1_2
{
XmlPuntenper100Reader::XmlPuntenper100Reader()
{
}


XmlPuntenper100 * XmlPuntenper100Reader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlPuntenper100 * Puntenper100 = new XmlPuntenper100;
  Fill(anElement, *Puntenper100);
  return Puntenper100;
}

XmlClass::eRESULT XmlPuntenper100Reader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlPuntenper100 & aPuntenper100)
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
    XERCES_CPP_NAMESPACE::DOMNode * puntennode = attributes->getNamedItem(_T("punten"));
    if (puntennode != NULL)
      aPuntenper100.Setpunten(puntennode->getNodeValue());
  }

  return XmlClass::RESULT_Ok;
}


}
