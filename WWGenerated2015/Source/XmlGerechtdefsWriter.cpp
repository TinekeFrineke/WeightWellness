#include "stdafx.h"

#include "XmlGerechtdefs.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "XmlGerechtdefWriter.h"
#include "XmlGerechtdef.h"
#include "XmlGerechtdefsWriter.h"

namespace ww2015
{
XmlClass::eRESULT XmlGerechtdefsWriter::Write(const std::wstring & aFilename, const XmlGerechtdefs & aGerechtdefs)
{
  ParseErrorHandler eh;
  XERCES_CPP_NAMESPACE::XercesDOMParser parser;
  parser.setDoValidation(false);
  parser.setErrorHandler(&eh);

  XERCES_CPP_NAMESPACE::DOMImplementation * impl =
    XERCES_CPP_NAMESPACE::DOMImplementationRegistry::getDOMImplementation(L"Core");

  XERCES_CPP_NAMESPACE::DOMDocument * doc =
    impl->createDocument(0,               // root element namespace URI.
                         L"gerechtdefs",  // root element name
                         0);              // document type object (Xml).
  XERCES_CPP_NAMESPACE::DOMElement * rootelement = doc->getDocumentElement();
  Fill(*doc, aGerechtdefs, *rootelement);

  XERCES_CPP_NAMESPACE::DOMWriter * writer = ((XERCES_CPP_NAMESPACE::DOMImplementationLS*)impl)->createDOMWriter();
  XERCES_CPP_NAMESPACE::LocalFileFormatTarget formatter(aFilename.c_str());
  writer->writeNode(&formatter, *doc);
  writer->release();

  doc->release();

  return RESULT_Ok;
}


void XmlGerechtdefsWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlGerechtdefs & aGerechtdefs, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

  XmlGerechtdefWriter Gerechtdefwriter;
  for (size_t i = 0; i < aGerechtdefs.GetGerechtdefList().size(); ++i)
  {
    XERCES_CPP_NAMESPACE::DOMNode * Gerechtdefnode = Gerechtdefwriter.Write(aDocument, *aGerechtdefs.GetGerechtdefList()[i]);
    anElement.appendChild(Gerechtdefnode);
  }
}


}
