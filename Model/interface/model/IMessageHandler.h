
#pragma once


#include <string>


namespace weight {


class IMessageHandler
{
public:
    virtual ~IMessageHandler() = default;

    virtual void info(const std::wstring& message) = 0;
    virtual void warning(const std::wstring& message) = 0;
    virtual void error(const std::wstring& message) = 0;
};

} // namespace weight