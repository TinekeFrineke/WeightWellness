#include "stdafx.h"

#include "XmlSterrelots.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "XmlSterrelotWriter.h"
#include "XmlSterrelot.h"
#include "XmlSterrelotsWriter.h"

namespace ww2015
{
XERCES_CPP_NAMESPACE::DOMNode * XmlSterrelotsWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlSterrelots & aSterrelots)
{
  XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("sterrelots"));
  Fill(aDocument, aSterrelots, *element);
  return element;
}

void XmlSterrelotsWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlSterrelots & aSterrelots, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

  XmlSterrelotWriter Sterrelotwriter;
  if (aSterrelots.GetSterrelot() != NULL)
    anElement.appendChild(Sterrelotwriter.Write(aDocument, *aSterrelots.GetSterrelot()));
}


}
