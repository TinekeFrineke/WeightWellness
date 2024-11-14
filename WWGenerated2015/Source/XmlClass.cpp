#include "XmlClass.h"

#include <tchar.h>
#include <windows.h>
#include <xercesc/framework/localfileinputsource.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/sax/saxparseexception.hpp>


namespace ww2015
{

void XmlClass::ParseErrorHandler::warning(const XERCES_CPP_NAMESPACE::SAXParseException& e)
{
  TCHAR smsg[1024];
  _stprintf_s(smsg, _T("Warning at file \"%s\", line %d, char %d: %s\n"),
            e.getSystemId(), e.getLineNumber(), e.getColumnNumber(), e.getMessage());

  ::MessageBox(0, smsg, _T("WARNING"), MB_OK);
}


void XmlClass::ParseErrorHandler::error(const XERCES_CPP_NAMESPACE::SAXParseException& e)
{
  TCHAR smsg[1024];
  _stprintf_s(smsg, _T("Error at file \"%s\", line %d, char %d: %s\n"),
            e.getSystemId(), e.getLineNumber(), e.getColumnNumber(), e.getMessage());

  ::MessageBox(0, smsg, _T("ERROR"), MB_OK);

  throw e;
}


void XmlClass::ParseErrorHandler::fatalError(const XERCES_CPP_NAMESPACE::SAXParseException& e)
{
  TCHAR smsg[1024];
  _stprintf_s(smsg, _T("Fatal Error at file \"%s\", line %d, char %d: %s\n"),
            e.getSystemId(), e.getLineNumber(), e.getColumnNumber(), e.getMessage());

  ::MessageBox(0, smsg, _T("FATAL ERROR"), MB_OK);

  throw e;
}


void XmlClass::ParseErrorHandler::resetErrors()
{
}

XmlClass::eRESULT XmlClass::ParseDocument(const std::wstring &                   aFilename,
                                          XERCES_CPP_NAMESPACE::XercesDOMParser &aParser)
{
  if (_taccess(aFilename.c_str(), 0) == -1)
  {
    switch (errno)
    {
      case ENOENT:
        return RESULT_FileNotFound;
      default:
        return RESULT_FileOpenError;
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
    return RESULT_ParserError;
  }
 	catch (...)
 	{
    ::MessageBox(0, (std::wstring(_T("Unexpected Exception occurred: ")) + aFilename).c_str(),
                 _T("ERROR"), MB_OK);
    return RESULT_ParserError;
	}

  return RESULT_Ok;
}
}

