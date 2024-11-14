#include "stdafx.h"

#include "xmlbase.h"
//
//#include <windows.h>
////#include <fstream>
////#include <ostream>
//#include <strstream>
//#include <iostream>
//#include <tchar.h>
//
//#include <xercesc/dom/dom.hpp>
//#include <xercesc/sax/saxparseexception.hpp>
//#include <xercesc/util/xmlstring.hpp>
//
//#include "Utilities/StrUtils.h"
//#include "ModelException.h"
//
//
//void XmlBase::ParseErrorHandler::warning(const XERCES_CPP_NAMESPACE::SAXParseException& e)
//{
//  char * systemId  = XERCES_CPP_NAMESPACE::XMLString::transcode(e.getSystemId());
//  char * message   = XERCES_CPP_NAMESPACE::XMLString::transcode(e.getMessage());
//
//  TCHAR smsg[1024];
//  _stprintf(smsg, _T("Warning at file \"%S\", line %d, char %d: %S\n"),
//            systemId, e.getLineNumber(), e.getColumnNumber(), message);
//  //std::cout << "Warning at file \""
//  //          << e.getSystemId() << "\", line "
//  //          << e.getLineNumber() << ", char " << e.getColumnNumber()
//  //          << ":  " << e.getMessage() << std::endl;
//
//  XERCES_CPP_NAMESPACE::XMLString::release(&systemId);
//  XERCES_CPP_NAMESPACE::XMLString::release(&message);
//
//  ::MessageBox(0, smsg, _T("WARNING"), MB_OK);
//}
//
//
//void XmlBase::ParseErrorHandler::error(const XERCES_CPP_NAMESPACE::SAXParseException& e)
//{
//  char * systemId  = XERCES_CPP_NAMESPACE::XMLString::transcode(e.getSystemId());
//  char * message   = XERCES_CPP_NAMESPACE::XMLString::transcode(e.getMessage());
//
//  TCHAR smsg[1024];
//  _stprintf(smsg, _T("Error at file \"%S\", line %d, char %d: %S\n"),
//            systemId, e.getLineNumber(), e.getColumnNumber(), message);
//  //std::cout << "Error at file \"" << systemId << "\", line "
//  //          << e.getLineNumber() << ", char " << e.getColumnNumber()
//  //          << ":  " << message << std::endl;
//  XERCES_CPP_NAMESPACE::XMLString::release(&systemId);
//  XERCES_CPP_NAMESPACE::XMLString::release(&message);
//
//  ::MessageBox(0, smsg, _T("ERROR"), MB_OK);
//
//  throw e;
//}
//
//
//void XmlBase::ParseErrorHandler::fatalError(const XERCES_CPP_NAMESPACE::SAXParseException& e)
//{
//  char * systemId  = XERCES_CPP_NAMESPACE::XMLString::transcode(e.getSystemId());
//  char * message   = XERCES_CPP_NAMESPACE::XMLString::transcode(e.getMessage());
//
//  TCHAR smsg[1024];
//  _stprintf(smsg, _T("Fatal Error at file \"%S\", line %d, char %d: %S\n"),
//            systemId, e.getLineNumber(), e.getColumnNumber(), message);
//  //std::cout << "Fatal Error at file \"" << systemId << "\", line "
//  //          << e.getLineNumber() << ", char " << e.getColumnNumber()
//  //          << ":  " << message << std::endl;
//  XERCES_CPP_NAMESPACE::XMLString::release(&systemId);
//  XERCES_CPP_NAMESPACE::XMLString::release(&message);
//
//  ::MessageBox(0, smsg, _T("FATAL ERROR"), MB_OK);
//
//  throw e;
//}
//
//
//void XmlBase::ParseErrorHandler::resetErrors()
//{
//}
//
//
//bool XmlBase::mParserInitialized = false;
//
//
////---------------------------------------------------------------------------
//bool XmlBase::InitializeXmlParser()
//{
//  if (mParserInitialized)
//  {
//    std::cout << "WARNING : Trying to initialize already initialized parser";
//    return true;
//  }
//
//	try
//  {
//    XERCES_CPP_NAMESPACE::XMLPlatformUtils::Initialize();
//  }
//  catch (const XERCES_CPP_NAMESPACE::XMLException& toCatch)
//  {
//    char * message = XERCES_CPP_NAMESPACE::XMLString::transcode(toCatch.getMessage());
//    ModelException exception (std::string("Error during initialization of xerces-c: ") + message);
//    XERCES_CPP_NAMESPACE::XMLString::release(&message);
//    throw exception;
//  }
//
//  mParserInitialized = true;
//  return true;
//}
//
//
////---------------------------------------------------------------------------
//bool XmlBase::TerminateXmlParser()
//{
//  if (!mParserInitialized)
//  {
//    std::cout << L"WARNING : Trying to terminate uninitialized parser";
//    return true;
//  }
//
//  XERCES_CPP_NAMESPACE::XMLPlatformUtils::Terminate();
//  mParserInitialized = false;
//  return true;
//}
//
//
//#ifdef _DEBUG
////---------------------------------------------------------------------------
//void XmlBase::Print(const XERCES_CPP_NAMESPACE::DOMNode & aNode,
//                     unsigned int                 aLevel)
//{
//  std::wstring type;
//  switch (aNode.getNodeType())
//  {
//    case XERCES_CPP_NAMESPACE::DOMNode::ELEMENT_NODE:
//      type = L"ELEMENT_NODE               ";
//    break;
//    case XERCES_CPP_NAMESPACE::DOMNode::ATTRIBUTE_NODE:
//      type = L"ATTRIBUTE_NODE             ";
//    break;
//    case XERCES_CPP_NAMESPACE::DOMNode::TEXT_NODE:
//      // Ignore text nodes
//    return;
//    case XERCES_CPP_NAMESPACE::DOMNode::CDATA_SECTION_NODE:
//      type = L"CDATA_SECTION_NODE         ";
//    break;
//    case XERCES_CPP_NAMESPACE::DOMNode::ENTITY_REFERENCE_NODE:
//      type = L"ENTITY_REFERENCE_NODE      ";
//    break;
//    case XERCES_CPP_NAMESPACE::DOMNode::ENTITY_NODE:
//      type = L"ENTITY_NODE                ";
//    break;
//    case XERCES_CPP_NAMESPACE::DOMNode::PROCESSING_INSTRUCTION_NODE:
//      type = L"PROCESSING_INSTRUCTION_NODE";
//    break;
//    case XERCES_CPP_NAMESPACE::DOMNode::COMMENT_NODE:
//      type = L"COMMENT_NODE               ";
//    break;
//    case XERCES_CPP_NAMESPACE::DOMNode::DOCUMENT_NODE:
//      type = L"DOCUMENT_NODE              ";
//    break;
//    case XERCES_CPP_NAMESPACE::DOMNode::DOCUMENT_TYPE_NODE:
//      type = L"DOCUMENT_TYPE_NODE         ";
//    break;
//    case XERCES_CPP_NAMESPACE::DOMNode::DOCUMENT_FRAGMENT_NODE:
//      type = L"DOCUMENT_FRAGMENT_NODE     ";
//    break;
//    case XERCES_CPP_NAMESPACE::DOMNode::NOTATION_NODE:
//      type = L"NOTATION_NODE              ";
//    break;
//    default:
//      type = L"Unknown                    ";
//  }
//
//  //std::string name (AsString(aNode.getNodeName()));
//  //std::string value(AsString(aNode.getNodeValue()));
//
//  std::wstring level;
//  for (unsigned int i = 0; i < aLevel; i++)
//    level += L' ';
//
////  std::cout << level << L"Type = " << type << L" name = " << name
////            << L" value = " << value;
//
//  XERCES_CPP_NAMESPACE::DOMNodeList * list = aNode.getChildNodes();
//  if (list != NULL)
//  {
//    for (XMLSize_t i = 0; i < list->getLength(); i++)
//      Print(*list->item(i), aLevel + 1);
//  }
//
//  XERCES_CPP_NAMESPACE::DOMNamedNodeMap * attributes = aNode.getAttributes();
//  if (attributes == NULL)
//    return;
//
//  for (XMLSize_t i = 0; i < attributes->getLength(); i++)
//    if (attributes->item(i) != NULL)
//      Print(*attributes->item(i), aLevel + 1);
//}
//#endif
