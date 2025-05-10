#pragma once

#include "model/IMessageHandler.h"

class MessageHandler
    : public weight::IMessageHandler
{
    // Inherited via IMessageHandler
    virtual void info(const std::string& message) override;
    virtual void warning(const std::string& message) override;
    virtual void error(const std::string& message) override;
};

