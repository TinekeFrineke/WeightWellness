#include "../Interface\Generated\stdafx.h"

#include "../Interface\Generated\XmlBonuslist.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "../Interface\Generated\XmlBonuscellWriter.h"
#include "../Interface\Generated\XmlBonuscell.h"
#include "../Interface\Generated\XmlBonuslistWriter.h"

namespace ww_1_2
{
XmlClass::eRESULT XmlBonuslistWriter::Write(const std::wstring & aFilename, const XmlBonuslist & aBonuslist)
{
  ParseErrorHandler eh;
  XERCES_CPP_NAMESPACE::XercesDOMParser parser;
  parser.setDoValidation(false);
  parser.setErrorHandler(&eh);

  XERCES_CPP_NAMESPACE::DOMImplementation * impl =
    XERCES_CPP_NAMESPACE::DOMImplementationRegistry::getDOMImplementation(L"Core");

  XERCES_CPP_NAMESPACE::DOMDocument * doc =
    impl->createDocument(0,               // root element namespace URI.
                         L"bonuslist",  // root element name
                         0);              // document type object (Xml).
  XERCES_CPP_NAMESPACE::DOMElement * rootelement = doc->getDocumentElement();
  Fill(*doc, aBonuslist, *rootelement);

  XERCES_CPP_NAMESPACE::DOMWriter * writer = ((XERCES_CPP_NAMESPACE::DOMImplementationLS*)impl)->createDOMWriter();
  XERCES_CPP_NAMESPACE::LocalFileFormatTarget formatter(aFilename.c_str());
  writer->writeNode(&formatter, *doc);
  writer->release();

  doc->release();

  return RESULT_Ok;
}


void XmlBonuslistWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlBonuslist & aBonuslist, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

  XmlBonuscellWriter Bonuscellwriter;
  for (size_t i = 0; i < aBonuslist.GetBonuscellList().size(); ++i)
  {
    XERCES_CPP_NAMESPACE::DOMNode * Bonuscellnode = Bonuscellwriter.Write(aDocument, *aBonuslist.GetBonuscellList()[i]);
    anElement.appendChild(Bonuscellnode);
  }
}


}
