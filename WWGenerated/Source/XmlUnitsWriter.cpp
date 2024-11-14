#include "stdafx.h"

#include "XmlUnits.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "XmlUnitWriter.h"
#include "XmlUnit.h"
#include "XmlUnitsWriter.h"

namespace ww_1_1
{
Generator::XmlClass::eRESULT XmlUnitsWriter::Write(const std::wstring & aFilename, const XmlUnits & aUnits)
{
  ParseErrorHandler eh;
  XERCES_CPP_NAMESPACE::XercesDOMParser parser;
  parser.setDoValidation(false);
  parser.setErrorHandler(&eh);

  XERCES_CPP_NAMESPACE::DOMImplementation * impl =
    XERCES_CPP_NAMESPACE::DOMImplementationRegistry::getDOMImplementation(L"Core");

  XERCES_CPP_NAMESPACE::DOMDocument * doc =
    impl->createDocument(0,               // root element namespace URI.
                         L"units",  // root element name
                         0);              // document type object (Xml).
  XERCES_CPP_NAMESPACE::DOMElement * rootelement = doc->getDocumentElement();
  Fill(*doc, aUnits, *rootelement);

  XERCES_CPP_NAMESPACE::DOMWriter * writer = ((XERCES_CPP_NAMESPACE::DOMImplementationLS*)impl)->createDOMWriter();
  XERCES_CPP_NAMESPACE::LocalFileFormatTarget formatter(aFilename.c_str());
  writer->writeNode(&formatter, *doc);
  writer->release();

  doc->release();

  return RESULT_Ok;
}


void XmlUnitsWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlUnits & aUnits, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

  XmlUnitWriter Unitwriter;
  for (size_t i = 0; i < aUnits.GetUnitList().size(); ++i)
  {
    XERCES_CPP_NAMESPACE::DOMNode * Unitnode = Unitwriter.Write(aDocument, *aUnits.GetUnitList()[i]);
    anElement.appendChild(Unitnode);
  }
}


}
