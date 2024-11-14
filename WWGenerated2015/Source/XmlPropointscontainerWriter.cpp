#include "stdafx.h"

#include "XmlPropointscontainer.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "XmlPropointsWriter.h"
#include "XmlPropoints.h"
#include "XmlPropointscontainerWriter.h"

namespace ww2015
{
XmlClass::eRESULT XmlPropointscontainerWriter::Write(const std::wstring & aFilename, const XmlPropointscontainer & aPropointscontainer)
{
  ParseErrorHandler eh;
  XERCES_CPP_NAMESPACE::XercesDOMParser parser;
  parser.setDoValidation(false);
  parser.setErrorHandler(&eh);

  XERCES_CPP_NAMESPACE::DOMImplementation * impl =
    XERCES_CPP_NAMESPACE::DOMImplementationRegistry::getDOMImplementation(L"Core");

  XERCES_CPP_NAMESPACE::DOMDocument * doc =
    impl->createDocument(0,               // root element namespace URI.
                         L"propointscontainer",  // root element name
                         0);              // document type object (Xml).
  XERCES_CPP_NAMESPACE::DOMElement * rootelement = doc->getDocumentElement();
  Fill(*doc, aPropointscontainer, *rootelement);

  XERCES_CPP_NAMESPACE::DOMWriter * writer = ((XERCES_CPP_NAMESPACE::DOMImplementationLS*)impl)->createDOMWriter();
  XERCES_CPP_NAMESPACE::LocalFileFormatTarget formatter(aFilename.c_str());
  writer->writeNode(&formatter, *doc);
  writer->release();

  doc->release();

  return RESULT_Ok;
}


void XmlPropointscontainerWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlPropointscontainer & aPropointscontainer, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

  XmlPropointsWriter Propointswriter;
  for (size_t i = 0; i < aPropointscontainer.GetPropointsList().size(); ++i)
  {
    XERCES_CPP_NAMESPACE::DOMNode * Propointsnode = Propointswriter.Write(aDocument, *aPropointscontainer.GetPropointsList()[i]);
    anElement.appendChild(Propointsnode);
  }
}


}
