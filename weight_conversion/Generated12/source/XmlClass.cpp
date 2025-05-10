#include "generated/XmlClass.h"

#include <io.h>
#include <sstream>
#include <windows.h>
#include <xercesc/framework/localfileinputsource.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/sax/saxparseexception.hpp>

#include <Utilities/strutils.h>

namespace ww_1_2

{

void XmlClass::ParseErrorHandler::warning(const XERCES_CPP_NAMESPACE::SAXParseException& e)
{
    std::cerr << "Warning at file \"" << Str::ToString(e.getSystemId())
        << " line " << e.getLineNumber() << " char " << e.getColumnNumber()
        << ": " << Str::ToString(e.getMessage()) << std::endl;
}


void XmlClass::ParseErrorHandler::error(const XERCES_CPP_NAMESPACE::SAXParseException& e)
{
    std::cerr << "Error at file \"" << Str::ToString(e.getSystemId())
        << " line " << e.getLineNumber() << " char " << e.getColumnNumber()
        << ": " << Str::ToString(e.getMessage()) << std::endl;
    throw e;
}


void XmlClass::ParseErrorHandler::fatalError(const XERCES_CPP_NAMESPACE::SAXParseException& e)
{
    std::cerr << "Fatal error at file \"" << Str::ToString(e.getSystemId())
        << " line " << e.getLineNumber() << " char " <<e.getColumnNumber()
        << ": " << Str::ToString(e.getMessage()) << std::endl;
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
        std::cerr << "Exception occurred: " << Str::ToString(e.getMessage()) << "; File being parsed is " + aFilename<< std::endl;
    }
 	catch (...)
 	{
        std::cerr << "Unexpected Exception occurred: " << aFilename << std::endl;
        return Result::ParserError;
	}

    return Result::Ok;
}
}

