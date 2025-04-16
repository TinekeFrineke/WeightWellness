
#include "MessageHandler.h"

#include <Windows.h>

void MessageHandler::info(const std::string& message)
{
    issueMessage(message, "INFO", MB_ICONINFORMATION);
}

void MessageHandler::warning(const std::string& message)
{
    issueMessage(message, "WARNING", MB_ICONWARNING);
}

void MessageHandler::error(const std::string& message)
{
    issueMessage(message, "ERROR", MB_ICONERROR);
}

void MessageHandler::issueMessage(const std::string& message, const std::string& caption, unsigned int severity)
{
    ::MessageBox(0, message.c_str(), caption.c_str(), MB_OK | severity);
}
