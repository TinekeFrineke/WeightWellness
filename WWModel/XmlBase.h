#pragma once

#include <xercesc/dom/dom.hpp>

#include <iostream>
#include <xercesc/sax/errorhandler.hpp>


class XmlBase
{
public:
  enum class Result { RESULT_Ok, RESULT_FileNotFound, RESULT_ErrorInFilename,
                       RESULT_FileOpenError,
                       RESULT_ErrorInFile, RESULT_ParserError, RESULT_InterpretError };
};
