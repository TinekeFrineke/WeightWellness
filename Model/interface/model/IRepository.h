#pragma once


#include <string>
#include <vector>


namespace weight {

class IRepository
{
public:
    virtual ~IRepository() = default;

    virtual std::vector<std::wstring> Get() const = 0;
    virtual void Add(const std::wstring& element) = 0;
    // Is this necessary??
    virtual void Clear() = 0;
};


} // namespace weight