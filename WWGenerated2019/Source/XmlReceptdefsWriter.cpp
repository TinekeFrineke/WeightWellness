#include "../Interface/stdafx.h"

#include "../Interface/XmlReceptdefs.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "../Interface/XmlReceptdefWriter.h"
#include "../Interface/XmlReceptdef.h"
#include "../Interface/XmlReceptdefsWriter.h"

namespace ww2019
{
XmlClass::eRESULT XmlReceptdefsWriter::Write(const std::wstring & aFilename, const XmlReceptdefs & aReceptdefs)
{
  ParseErrorHandler eh;
  XERCES_CPP_NAMESPACE::XercesDOMParser parser;
  parser.setDoValidation(false);
  parser.setErrorHandler(&eh);

  XERCES_CPP_NAMESPACE::DOMImplementation * impl =
    XERCES_CPP_NAMESPACE::DOMImplementationRegistry::getDOMImplementation(L"Core");

  XERCES_CPP_NAMESPACE::DOMDocument * doc =
    impl->createDocument(0,               // root element namespace URI.
                         L"receptdefs",  // root element name
                         0);              // document type object (Xml).
  XERCES_CPP_NAMESPACE::DOMElement * rootelement = doc->getDocumentElement();
  Fill(*doc, aReceptdefs, *rootelement);

  XERCES_CPP_NAMESPACE::DOMWriter * writer = ((XERCES_CPP_NAMESPACE::DOMImplementationLS*)impl)->createDOMWriter();
  XERCES_CPP_NAMESPACE::LocalFileFormatTarget formatter(aFilename.c_str());
  writer->writeNode(&formatter, *doc);
  writer->release();

  doc->release();

  return RESULT_Ok;
}


void XmlReceptdefsWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlReceptdefs & aReceptdefs, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

  XmlReceptdefWriter Receptdefwriter;
  for (size_t i = 0; i < aReceptdefs.GetReceptdefList().size(); ++i)
  {
    XERCES_CPP_NAMESPACE::DOMNode * Receptdefnode = Receptdefwriter.Write(aDocument, *aReceptdefs.GetReceptdefList()[i]);
    anElement.appendChild(Receptdefnode);
  }
}


}
