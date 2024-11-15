#include "../Interface/stdafx.h"
#include "../Interface/XmlUnitReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "../Interface/XmlUnit.h"


namespace ww2019
{
XmlUnitReader::XmlUnitReader()
{
}


XmlUnit * XmlUnitReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlUnit * Unit = new XmlUnit;
  Fill(anElement, *Unit);
  return Unit;
}

XmlClass::eRESULT XmlUnitReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlUnit & aUnit)
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
      aUnit.Setnaam(naamnode->getNodeValue());
  }

  return XmlClass::RESULT_Ok;
}


}
