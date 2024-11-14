#include "../Interface\Generated\stdafx.h"

#include "../Interface\Generated\XmlHandmatigitem.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "../Interface\Generated\XmlHandmatigitemWriter.h"

namespace ww_1_2
{
XERCES_CPP_NAMESPACE::DOMNode * XmlHandmatigitemWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlHandmatigitem & aHandmatigitem)
{
  XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("handmatigitem"));
  Fill(aDocument, aHandmatigitem, *element);
  return element;
}

void XmlHandmatigitemWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlHandmatigitem & aHandmatigitem, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{
  (void)aDocument;
  (void)aHandmatigitem;
  (void)anElement;
  anElement.setAttribute(_T("naam"), aHandmatigitem.Getnaam().c_str());
  anElement.setAttribute(_T("punten"), aHandmatigitem.Getpunten().c_str());
  anElement.setAttribute(_T("hoeveelheid"), aHandmatigitem.Gethoeveelheid().c_str());
}


}
