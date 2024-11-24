#pragma once


namespace WW {

enum class Result {
    Ok, FileNotFound, ErrorInFilename,
    FileOpenError,
    ErrorInFile, ParserError, InterpretError
};

} // namespace WW