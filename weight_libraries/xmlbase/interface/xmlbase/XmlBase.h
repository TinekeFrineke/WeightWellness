#pragma once


namespace weight {

enum class Result {
    Ok, FileNotFound, ErrorInFilename,
    FileOpenError,
    ErrorInFile, ParserError, InterpretError
};

} // namespace weight
