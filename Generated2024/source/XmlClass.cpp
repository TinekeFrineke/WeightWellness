
#include "XmlClass.h"

#include <sstream>

#include <tchar.h>
#include <windows.h>
#include <xercesc/framework/localfileinputsource.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/sax/saxparseexception.hpp>


namespace ww2024
{

void XmlClass::ParseErrorHandler::warning(const XERCES_CPP_NAMESPACE::SAXParseException& e)
{
    std::wstringstream ss;
    ss << L"Warning at file " << e.getSystemId() << L", line " << e.getLineNumber()
        << L", char " << e.getColumnNumber() << L", " << e.getMessage();

    ::MessageBox(0, ss.str().c_str(), _T("WARNING"), MB_OK);
}


void XmlClass::ParseErrorHandler::error(const XERCES_CPP_NAMESPACE::SAXParseException& e)
{
    std::wstringstream ss;
    ss << L"Error at file " << e.getSystemId() << L", line " << e.getLineNumber()
        << L", char " << e.getColumnNumber() << L", " << e.getMessage();

    ::MessageBox(0, ss.str().c_str(), _T("ERROR"), MB_OK);

    throw e;
}


void XmlClass::ParseErrorHandler::fatalError(const XERCES_CPP_NAMESPACE::SAXParseException& e)
{
    std::wstringstream ss;
    ss << L"Fatal error at file " << e.getSystemId() << L", line " << e.getLineNumber()
        << L", char " << e.getColumnNumber() << L", " << e.getMessage();

    ::MessageBox(0, ss.str().c_str(), _T("FATAL ERROR"), MB_OK);

    throw e;
}


void XmlClass::ParseErrorHandler::resetErrors()
{
}

XmlClass::Result XmlClass::ParseDocument(const std::wstring &                   aFilename,
                                          XERCES_CPP_NAMESPACE::XercesDOMParser &aParser)
{
    if (_taccess(aFilename.c_str(), 0) == -1)
    {
        switch (errno)
        {
            case ENOENT:
                return Result::FileNotFound;
            default:
                return Result::FileOpenError;
        }
    }

    XERCES_CPP_NAMESPACE::LocalFileInputSource source(NULL, aFilename.c_str());
    try
    {
        aParser.parse(source);
    }
    catch (const XERCES_CPP_NAMESPACE::XMLException& e)
    {
        ::MessageBox(0, (std::wstring(_T("Exception occurred: ")) + e.getMessage() + _T("; File being parsed is ") + aFilename).c_str(),
                     _T("ERROR"), MB_OK);
        return Result::ParserError;
    }
 	catch (...)
 	{
        ::MessageBox(0, (std::wstring(_T("Unexpected Exception occurred: ")) + aFilename).c_str(),
                     _T("ERROR"), MB_OK);
        return Result::ParserError;
	}

    return Result::Ok;
}
}

