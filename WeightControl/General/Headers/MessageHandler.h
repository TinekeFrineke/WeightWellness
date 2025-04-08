#pragma once


#include "model/IMessageHandler.h"

class MessageHandler
    : public weight::IMessageHandler
{
public:
    void info(const std::wstring& message) override;
    void warning(const std::wstring& message) override;
    void error(const std::wstring& message) override;

private:
    void issueMessage(const std::wstring& message, const std::wstring& caption, unsigned int severity);
};

