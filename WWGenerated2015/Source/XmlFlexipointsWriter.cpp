#include "stdafx.h"

#include "XmlFlexipoints.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "XmlBonuslistWriter.h"
#include "XmlBonuslist.h"
#include "XmlVrijeportiesWriter.h"
#include "XmlVrijeporties.h"
#include "XmlStrategybaseWriter.h"
#include "XmlStrategybase.h"
#include "XmlFlexipointsWriter.h"

namespace ww2015
{
XmlClass::eRESULT XmlFlexipointsWriter::Write(const std::wstring & aFilename, const XmlFlexipoints & aFlexipoints)
{
  ParseErrorHandler eh;
  XERCES_CPP_NAMESPACE::XercesDOMParser parser;
  parser.setDoValidation(false);
  parser.setErrorHandler(&eh);

  XERCES_CPP_NAMESPACE::DOMImplementation * impl =
    XERCES_CPP_NAMESPACE::DOMImplementationRegistry::getDOMImplementation(L"Core");

  XERCES_CPP_NAMESPACE::DOMDocument * doc =
    impl->createDocument(0,               // root element namespace URI.
                         L"flexipoints",  // root element name
                         0);              // document type object (Xml).
  XERCES_CPP_NAMESPACE::DOMElement * rootelement = doc->getDocumentElement();
  Fill(*doc, aFlexipoints, *rootelement);

  XERCES_CPP_NAMESPACE::DOMWriter * writer = ((XERCES_CPP_NAMESPACE::DOMImplementationLS*)impl)->createDOMWriter();
  XERCES_CPP_NAMESPACE::LocalFileFormatTarget formatter(aFilename.c_str());
  writer->writeNode(&formatter, *doc);
  writer->release();

  doc->release();

  return RESULT_Ok;
}


void XmlFlexipointsWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlFlexipoints & aFlexipoints, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

  XmlBonuslistWriter Bonuslistwriter;
  anElement.appendChild(Bonuslistwriter.Write(aDocument, aFlexipoints.GetBonuslist()));

  XmlVrijeportiesWriter Vrijeportieswriter;
  anElement.appendChild(Vrijeportieswriter.Write(aDocument, aFlexipoints.GetVrijeporties()));

  XmlStrategybaseWriter Strategybasewriter;
  anElement.appendChild(Strategybasewriter.Write(aDocument, aFlexipoints.GetStrategybase()));
}


}
