#pragma once


#include <string>
#include <vector>


namespace weight {

class IStringRepository
{
public:
    virtual ~IStringRepository() = default;

    virtual std::vector<std::string> Get() const = 0;
    virtual void Add(const std::string& element) = 0;
    virtual void Clear() = 0;
};


} // namespace weight