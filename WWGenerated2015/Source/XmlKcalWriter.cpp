#include "stdafx.h"

#include "XmlKcal.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "XmlStrategybaseWriter.h"
#include "XmlStrategybase.h"
#include "XmlKcalWriter.h"

namespace ww2015
{
XmlClass::eRESULT XmlKcalWriter::Write(const std::wstring & aFilename, const XmlKcal & aKcal)
{
  ParseErrorHandler eh;
  XERCES_CPP_NAMESPACE::XercesDOMParser parser;
  parser.setDoValidation(false);
  parser.setErrorHandler(&eh);

  XERCES_CPP_NAMESPACE::DOMImplementation * impl =
    XERCES_CPP_NAMESPACE::DOMImplementationRegistry::getDOMImplementation(L"Core");

  XERCES_CPP_NAMESPACE::DOMDocument * doc =
    impl->createDocument(0,               // root element namespace URI.
                         L"kcal",  // root element name
                         0);              // document type object (Xml).
  XERCES_CPP_NAMESPACE::DOMElement * rootelement = doc->getDocumentElement();
  Fill(*doc, aKcal, *rootelement);

  XERCES_CPP_NAMESPACE::DOMWriter * writer = ((XERCES_CPP_NAMESPACE::DOMImplementationLS*)impl)->createDOMWriter();
  XERCES_CPP_NAMESPACE::LocalFileFormatTarget formatter(aFilename.c_str());
  writer->writeNode(&formatter, *doc);
  writer->release();

  doc->release();

  return RESULT_Ok;
}


void XmlKcalWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlKcal & aKcal, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

  XmlStrategybaseWriter Strategybasewriter;
  anElement.appendChild(Strategybasewriter.Write(aDocument, aKcal.GetStrategybase()));
}


}
