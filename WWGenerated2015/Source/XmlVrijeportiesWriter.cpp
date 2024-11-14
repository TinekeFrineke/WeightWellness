#include "stdafx.h"

#include "XmlVrijeporties.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "XmlVrijeportieWriter.h"
#include "XmlVrijeportie.h"
#include "XmlVrijeportiesWriter.h"

namespace ww2015
{
XERCES_CPP_NAMESPACE::DOMNode * XmlVrijeportiesWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVrijeporties & aVrijeporties)
{
  XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("vrijeporties"));
  Fill(aDocument, aVrijeporties, *element);
  return element;
}

void XmlVrijeportiesWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVrijeporties & aVrijeporties, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

  XmlVrijeportieWriter Vrijeportiewriter;
  if (aVrijeporties.GetVrijeportie() != NULL)
    anElement.appendChild(Vrijeportiewriter.Write(aDocument, *aVrijeporties.GetVrijeportie()));
}


}
