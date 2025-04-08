
#include "MessageHandler.h"

#include <Windows.h>

void MessageHandler::info(const std::wstring& message)
{
    issueMessage(message, L"INFO", MB_ICONINFORMATION);
}

void MessageHandler::warning(const std::wstring& message)
{
    issueMessage(message, L"WARNING", MB_ICONWARNING);
}

void MessageHandler::error(const std::wstring& message)
{
    issueMessage(message, L"ERROR", MB_ICONERROR);
}

void MessageHandler::issueMessage(const std::wstring& message, const std::wstring& caption, unsigned int severity)
{
    ::MessageBox(0, message.c_str(), caption.c_str(), MB_OK | severity);
}
