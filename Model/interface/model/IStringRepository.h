#pragma once


#include <string>
#include <vector>


namespace weight {

class IStringRepository
{
public:
    virtual ~IStringRepository() = default;

    virtual std::vector<std::wstring> Get() const = 0;
    virtual void Add(const std::wstring& element) = 0;
    virtual void Clear() = 0;
};


} // namespace weight