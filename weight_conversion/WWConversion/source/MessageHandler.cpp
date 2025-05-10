#include "MessageHandler.h"

#include <iostream>

void MessageHandler::info(const std::string& message)
{
    std::cout << "Info: " << message << std::endl;
}

void MessageHandler::warning(const std::string& message)
{
    std::cout << "Warning: " << message << std::endl;
}

void MessageHandler::error(const std::string& message)
{
    std::cout << "Error: " << message << std::endl;
}
