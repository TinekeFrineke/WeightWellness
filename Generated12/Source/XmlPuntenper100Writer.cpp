#include "../Interface\Generated\stdafx.h"

#include "../Interface\Generated\XmlPuntenper100.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "../Interface\Generated\XmlPuntenper100Writer.h"

namespace ww_1_2
{
XERCES_CPP_NAMESPACE::DOMNode * XmlPuntenper100Writer::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlPuntenper100 & aPuntenper100)
{
  XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("puntenper100"));
  Fill(aDocument, aPuntenper100, *element);
  return element;
}

void XmlPuntenper100Writer::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlPuntenper100 & aPuntenper100, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{
  (void)aDocument;
  (void)aPuntenper100;
  (void)anElement;
  anElement.setAttribute(_T("punten"), aPuntenper100.Getpunten().c_str());
}


}
