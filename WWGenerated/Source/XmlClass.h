#ifndef GENERATOR_XMLCLASS_H__
#define GENERATOR_XMLCLASS_H__


#include "stdafx.h"

#include <string>

#include <xercesc/sax/errorhandler.hpp>

// Forward declaration
namespace XERCES_CPP_NAMESPACE
{
class DOMDocument;
class DOMElement;
class DOMNode;
class XercesDOMParser;
}

namespace Generator
{
class XmlClass
{
public:
  enum eRESULT
  {
    RESULT_Ok,
    RESULT_FileNotFound,
    RESULT_ErrorInFilename,
    RESULT_FileOpenError,
    RESULT_ErrorInFile,
    RESULT_ParserError,
    RESULT_InterpretError,
    RESULT_WriteError
  };

  virtual ~XmlClass() {}

  class ParseErrorHandler: public XERCES_CPP_NAMESPACE::ErrorHandler
  {
  public:
    void warning(const XERCES_CPP_NAMESPACE::SAXParseException & e);
    void error(const XERCES_CPP_NAMESPACE::SAXParseException & e);
    void fatalError(const XERCES_CPP_NAMESPACE::SAXParseException & e);
    void resetErrors();
  };

  eRESULT ParseDocument(const std::wstring &                    aFilename,
                        XERCES_CPP_NAMESPACE::XercesDOMParser & aParser);
};


}

#endif // GENERATOR_XMLCLASS_H__
