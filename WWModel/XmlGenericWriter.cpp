//#include "stdafx.h"
//
#include "XmlGenericWriter.h"
//
//#include <xercesc/dom/dom.hpp>
//#include <xercesc/dom/domdocumenttype.hpp>
//#include <xercesc/framework/localfileformattarget.hpp>
////#include <xercesc/framework/membufinputsource.hpp>
//#include <xercesc/parsers/XercesDOMParser.hpp>
//
//XmlGenericWriter::~XmlGenericWriter()
//{
//  //CloseDocument();
//}
//
//
//void XmlGenericWriter::OpenDocument(const std::tstring & aRootElementName)
//{
//  CloseDocument();
//
//  XERCES_CPP_NAMESPACE::XercesDOMParser parser;
//  parser.setDoValidation(false);
//  parser.setErrorHandler(&mErrorHandler);
//
//  XERCES_CPP_NAMESPACE::DOMImplementation * impl =
//      XERCES_CPP_NAMESPACE::DOMImplementationRegistry::getDOMImplementation(L"Core");
//
//  mDocument = impl->createDocument(0,        // root element namespace URI.
//                                   aRootElementName.c_str(), // root element name
//                                   0);       // document type object (DTD).
//}
//
//
//void XmlGenericWriter::SaveDocument(const std::tstring & aFilename)
//{
//  if (mDocument == NULL)
//    return;
//
//  XERCES_CPP_NAMESPACE::DOMImplementation * impl =
//      XERCES_CPP_NAMESPACE::DOMImplementationRegistry::getDOMImplementation(L"Core");
//
//  XERCES_CPP_NAMESPACE::DOMWriter * writer = ((XERCES_CPP_NAMESPACE::DOMImplementationLS*)impl)->createDOMWriter();
//  XERCES_CPP_NAMESPACE::LocalFileFormatTarget formatter(aFilename.c_str());
//
//  writer->writeNode(&formatter, *mDocument);
//  writer->release();
//}
//
//
//void XmlGenericWriter::CloseDocument()
//{
//  if (mDocument != NULL)
//  {
//    mDocument->release();
//    mDocument = NULL;
//  }
//}
