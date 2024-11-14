#include "stdafx.h"

#include "XmlVrijeportie.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "XmlVrijeportieWriter.h"

namespace ww2015
{
XERCES_CPP_NAMESPACE::DOMNode * XmlVrijeportieWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVrijeportie & aVrijeportie)
{
  XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("vrijeportie"));
  Fill(aDocument, aVrijeportie, *element);
  return element;
}

void XmlVrijeportieWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVrijeportie & aVrijeportie, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{
  (void)aDocument;
  (void)aVrijeportie;
  (void)anElement;
  anElement.setAttribute(_T("voedingsmiddel"), aVrijeportie.Getvoedingsmiddel().c_str());
  anElement.setAttribute(_T("punten"), aVrijeportie.Getpunten().c_str());
}


}
