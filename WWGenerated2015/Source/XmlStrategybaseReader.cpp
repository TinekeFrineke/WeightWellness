#include "stdafx.h"
#include "XmlStrategybaseReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlStrategybase.h"


namespace ww2015
{
XmlStrategybaseReader::XmlStrategybaseReader()
{
}


XmlStrategybase * XmlStrategybaseReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlStrategybase * Strategybase = new XmlStrategybase;
  Fill(anElement, *Strategybase);
  return Strategybase;
}

XmlClass::eRESULT XmlStrategybaseReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlStrategybase & aStrategybase)
{
  XERCES_CPP_NAMESPACE::DOMNodeList * list = anElement.getChildNodes();

  if (list == NULL)
    return XmlClass::RESULT_Ok;

  for (XMLSize_t i = 0; i < list->getLength(); i++)
  {
    if (list->item(i) == NULL)
      continue;

  }
  return XmlClass::RESULT_Ok;
}


}
