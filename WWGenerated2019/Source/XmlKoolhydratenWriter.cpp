#include "../Interface/stdafx.h"

#include "../Interface/XmlKoolhydraten.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "../Interface/XmlStrategybaseWriter.h"
#include "../Interface/XmlStrategybase.h"
#include "../Interface/XmlKoolhydratenWriter.h"

namespace ww2019
{
XmlClass::eRESULT XmlKoolhydratenWriter::Write(const std::wstring & aFilename, const XmlKoolhydraten & aKoolhydraten)
{
  ParseErrorHandler eh;
  XERCES_CPP_NAMESPACE::XercesDOMParser parser;
  parser.setDoValidation(false);
  parser.setErrorHandler(&eh);

  XERCES_CPP_NAMESPACE::DOMImplementation * impl =
    XERCES_CPP_NAMESPACE::DOMImplementationRegistry::getDOMImplementation(L"Core");

  XERCES_CPP_NAMESPACE::DOMDocument * doc =
    impl->createDocument(0,               // root element namespace URI.
                         L"koolhydraten",  // root element name
                         0);              // document type object (Xml).
  XERCES_CPP_NAMESPACE::DOMElement * rootelement = doc->getDocumentElement();
  Fill(*doc, aKoolhydraten, *rootelement);

  XERCES_CPP_NAMESPACE::DOMWriter * writer = ((XERCES_CPP_NAMESPACE::DOMImplementationLS*)impl)->createDOMWriter();
  XERCES_CPP_NAMESPACE::LocalFileFormatTarget formatter(aFilename.c_str());
  writer->writeNode(&formatter, *doc);
  writer->release();

  doc->release();

  return RESULT_Ok;
}


void XmlKoolhydratenWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlKoolhydraten & aKoolhydraten, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

  XmlStrategybaseWriter Strategybasewriter;
  anElement.appendChild(Strategybasewriter.Write(aDocument, aKoolhydraten.GetStrategybase()));
}


}
