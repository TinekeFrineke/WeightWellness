#include "stdafx.h"

#include "XmlPropoints.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "XmlBonuslistWriter.h"
#include "XmlBonuslist.h"
#include "XmlSterrelotsWriter.h"
#include "XmlSterrelots.h"
#include "XmlStrategybaseWriter.h"
#include "XmlStrategybase.h"
#include "XmlPropointsWriter.h"

namespace ww2015
{
XmlClass::eRESULT XmlPropointsWriter::Write(const std::wstring & aFilename, const XmlPropoints & aPropoints)
{
  ParseErrorHandler eh;
  XERCES_CPP_NAMESPACE::XercesDOMParser parser;
  parser.setDoValidation(false);
  parser.setErrorHandler(&eh);

  XERCES_CPP_NAMESPACE::DOMImplementation * impl =
    XERCES_CPP_NAMESPACE::DOMImplementationRegistry::getDOMImplementation(L"Core");

  XERCES_CPP_NAMESPACE::DOMDocument * doc =
    impl->createDocument(0,               // root element namespace URI.
                         L"propoints",  // root element name
                         0);              // document type object (Xml).
  XERCES_CPP_NAMESPACE::DOMElement * rootelement = doc->getDocumentElement();
  Fill(*doc, aPropoints, *rootelement);

  XERCES_CPP_NAMESPACE::DOMWriter * writer = ((XERCES_CPP_NAMESPACE::DOMImplementationLS*)impl)->createDOMWriter();
  XERCES_CPP_NAMESPACE::LocalFileFormatTarget formatter(aFilename.c_str());
  writer->writeNode(&formatter, *doc);
  writer->release();

  doc->release();

  return RESULT_Ok;
}


void XmlPropointsWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlPropoints & aPropoints, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

  XmlBonuslistWriter Bonuslistwriter;
  anElement.appendChild(Bonuslistwriter.Write(aDocument, aPropoints.GetBonuslist()));

  XmlSterrelotsWriter Sterrelotswriter;
  anElement.appendChild(Sterrelotswriter.Write(aDocument, aPropoints.GetSterrelots()));

  XmlStrategybaseWriter Strategybasewriter;
  anElement.appendChild(Strategybasewriter.Write(aDocument, aPropoints.GetStrategybase()));
}


}
