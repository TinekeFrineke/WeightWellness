#include "../Interface\Generated\stdafx.h"
#include "../Interface\Generated\XmlGerechtdefReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "../Interface\Generated\XmlGerechtdef.h"


namespace ww_1_2
{
XmlGerechtdefReader::XmlGerechtdefReader()
{
}


XmlGerechtdef * XmlGerechtdefReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlGerechtdef * Gerechtdef = new XmlGerechtdef;
  Fill(anElement, *Gerechtdef);
  return Gerechtdef;
}

XmlClass::eRESULT XmlGerechtdefReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlGerechtdef & aGerechtdef)
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
    XERCES_CPP_NAMESPACE::DOMNode * naamnode = attributes->getNamedItem(_T("naam"));
    if (naamnode != NULL)
      aGerechtdef.Setnaam(naamnode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * puntennode = attributes->getNamedItem(_T("punten"));
    if (puntennode != NULL)
      aGerechtdef.Setpunten(puntennode->getNodeValue());
  }

  return XmlClass::RESULT_Ok;
}


}
