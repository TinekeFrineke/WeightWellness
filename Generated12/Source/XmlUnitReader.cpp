#include "../Interface\Generated\stdafx.h"
#include "../Interface\Generated\XmlUnitReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "../Interface\Generated\XmlUnit.h"


namespace ww_1_2
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
