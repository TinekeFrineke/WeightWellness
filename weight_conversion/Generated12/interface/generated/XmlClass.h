// Copyright Tineke Franssen

#pragma once


#include <string>

#include <xercesc/sax/errorhandler.hpp>


namespace XERCES_CPP_NAMESPACE
{
class DOMDocument;
class DOMElement;
class DOMNode;
class XercesDOMParser;
}

namespace ww_1_2
{
class XmlClass
{
public:
    enum class Result
    {
        Ok,
        FileNotFound,
        ErrorInFilename,
        FileOpenError,
        ErrorInFile,
        ParserError,
        InterpretError,
        WriteError
    };

    virtual ~XmlClass() = default;

    class ParseErrorHandler: public XERCES_CPP_NAMESPACE::ErrorHandler
    {
    public:
        void warning(const XERCES_CPP_NAMESPACE::SAXParseException& e) override;
        void error(const XERCES_CPP_NAMESPACE::SAXParseException& e) override;
        void fatalError(const XERCES_CPP_NAMESPACE::SAXParseException& e) override;
        void resetErrors();
    };

    Result ParseDocument(const std::string& aFilename,
                         XERCES_CPP_NAMESPACE::XercesDOMParser& aParser);
};


} // ww_1_2

