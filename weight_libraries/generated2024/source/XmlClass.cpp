#include "XmlClass.h"

#include <io.h>
#include <sstream>
#include <windows.h>
#include <xercesc/framework/localfileinputsource.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/sax/saxparseexception.hpp>

#include <Utilities/strutils.h>

namespace ww2024

{

void XmlClass::ParseErrorHandler::warning(const XERCES_CPP_NAMESPACE::SAXParseException& e)
{
    std::stringstream message;
    message << "Warning at file \"" << Str::ToString(e.getSystemId())
        << " line " << e.getLineNumber() << " char " << e.getColumnNumber()
        << ": " << Str::ToString(e.getMessage());
    ::MessageBox(0, message.str().c_str(), "WARNING", MB_OK);
}


void XmlClass::ParseErrorHandler::error(const XERCES_CPP_NAMESPACE::SAXParseException& e)
{
    std::stringstream message;
    message << "Error at file \"" << Str::ToString(e.getSystemId())
        << " line " << e.getLineNumber() << " char " << e.getColumnNumber()
        << ": " << Str::ToString(e.getMessage());
    ::MessageBox(0, message.str().c_str(), "ERROR", MB_OK);

    throw e;
}


void XmlClass::ParseErrorHandler::fatalError(const XERCES_CPP_NAMESPACE::SAXParseException& e)
{
    std::stringstream message;
    message << "Fatal error at file \"" << Str::ToString(e.getSystemId())
        << " line " << e.getLineNumber() << " char " <<e.getColumnNumber()
        << ": " << Str::ToString(e.getMessage());
    ::MessageBox(0, message.str().c_str(), "FATAL ERROR", MB_OK);

    throw e;
}


void XmlClass::ParseErrorHandler::resetErrors()
{
}

XmlClass::Result XmlClass::ParseDocument(const std::string& aFilename,
                                          XERCES_CPP_NAMESPACE::XercesDOMParser& aParser)
{
    if (_access(aFilename.c_str(), 0) == -1)
    {
        switch (errno)
        {
            case ENOENT:
                return Result::FileNotFound;
            default:
                return Result::FileOpenError;
        }
    }

    XERCES_CPP_NAMESPACE::LocalFileInputSource source(nullptr, Str::ToWString(aFilename).c_str());
    try
    {
        aParser.parse(source);
    }
    catch (const XERCES_CPP_NAMESPACE::XMLException& e)
    {
        ::MessageBox(0, ("Exception occurred: " + Str::ToString(e.getMessage()) + "; File being parsed is " + aFilename).c_str(),
                     "ERROR", MB_OK);
        return Result::ParserError;
    }
 	catch (...)
 	{
        ::MessageBox(0, ("Unexpected Exception occurred: " + aFilename).c_str(),
                     "ERROR", MB_OK);
        return Result::ParserError;
	}

    return Result::Ok;
}
}

