#pragma once


#include "model/IMessageHandler.h"

class MessageHandler
    : public weight::IMessageHandler
{
public:
    void info(const std::string& message) override;
    void warning(const std::string& message) override;
    void error(const std::string& message) override;

private:
    void issueMessage(const std::string& message, const std::string& caption, unsigned int severity);
};

