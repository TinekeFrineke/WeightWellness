#pragma once

#include <xercesc/dom/dom.hpp>

#include <iostream>
#include <xercesc/sax/errorhandler.hpp>


class XmlBase
{
public:
  enum class Result { Ok, FileNotFound, ErrorInFilename,
                       FileOpenError,
                       ErrorInFile, ParserError, InterpretError };
};
