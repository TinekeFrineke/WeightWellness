#include "stdafx.h"

#include "XmlFlexipointscontainer.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "XmlFlexipointsWriter.h"
#include "XmlFlexipoints.h"
#include "XmlFlexipointscontainerWriter.h"

namespace ww2015
{
XmlClass::eRESULT XmlFlexipointscontainerWriter::Write(const std::wstring & aFilename, const XmlFlexipointscontainer & aFlexipointscontainer)
{
  ParseErrorHandler eh;
  XERCES_CPP_NAMESPACE::XercesDOMParser parser;
  parser.setDoValidation(false);
  parser.setErrorHandler(&eh);

  XERCES_CPP_NAMESPACE::DOMImplementation * impl =
    XERCES_CPP_NAMESPACE::DOMImplementationRegistry::getDOMImplementation(L"Core");

  XERCES_CPP_NAMESPACE::DOMDocument * doc =
    impl->createDocument(0,               // root element namespace URI.
                         L"flexipointscontainer",  // root element name
                         0);              // document type object (Xml).
  XERCES_CPP_NAMESPACE::DOMElement * rootelement = doc->getDocumentElement();
  Fill(*doc, aFlexipointscontainer, *rootelement);

  XERCES_CPP_NAMESPACE::DOMWriter * writer = ((XERCES_CPP_NAMESPACE::DOMImplementationLS*)impl)->createDOMWriter();
  XERCES_CPP_NAMESPACE::LocalFileFormatTarget formatter(aFilename.c_str());
  writer->writeNode(&formatter, *doc);
  writer->release();

  doc->release();

  return RESULT_Ok;
}


void XmlFlexipointscontainerWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlFlexipointscontainer & aFlexipointscontainer, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

  XmlFlexipointsWriter Flexipointswriter;
  for (size_t i = 0; i < aFlexipointscontainer.GetFlexipointsList().size(); ++i)
  {
    XERCES_CPP_NAMESPACE::DOMNode * Flexipointsnode = Flexipointswriter.Write(aDocument, *aFlexipointscontainer.GetFlexipointsList()[i]);
    anElement.appendChild(Flexipointsnode);
  }
}


}
