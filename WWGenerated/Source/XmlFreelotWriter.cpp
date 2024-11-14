#include "stdafx.h"

#include "XmlFreelot.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "XmlFreelotWriter.h"

namespace ww_1_1
{
XERCES_CPP_NAMESPACE::DOMNode * XmlFreelotWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlFreelot & aFreelot)
{
  XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("freelot"));
  Fill(aDocument, aFreelot, *element);
  return element;
}

void XmlFreelotWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlFreelot & aFreelot, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{
  (void)aDocument;
  (void)aFreelot;
  (void)anElement;
  anElement.setAttribute(_T("punten"), aFreelot.Getpunten().c_str());
}


}
