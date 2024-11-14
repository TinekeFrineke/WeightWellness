#include "stdafx.h"

#include "XmlSterrelot.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "XmlSterrelotWriter.h"

namespace ww2015
{
XERCES_CPP_NAMESPACE::DOMNode * XmlSterrelotWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlSterrelot & aSterrelot)
{
  XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("sterrelot"));
  Fill(aDocument, aSterrelot, *element);
  return element;
}

void XmlSterrelotWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlSterrelot & aSterrelot, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{
  (void)aDocument;
  (void)aSterrelot;
  (void)anElement;
  anElement.setAttribute(_T("voedingsmiddel"), aSterrelot.Getvoedingsmiddel().c_str());
  anElement.setAttribute(_T("portie"), aSterrelot.Getportie().c_str());
  anElement.setAttribute(_T("hoeveelheid"), aSterrelot.Gethoeveelheid().c_str());
}


}
