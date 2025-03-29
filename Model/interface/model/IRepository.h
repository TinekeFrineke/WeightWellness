
#pragma once

#include <memory>
#include <string>
#include <vector>

namespace weight {

template<typename TYPE>
class IRepository
{
public:
    virtual bool Has(const std::wstring& name) const = 0;
    virtual TYPE* Find(const std::wstring& name) const = 0;
    virtual bool Add(std::unique_ptr<TYPE> definition) = 0;
    virtual bool Remove(const std::wstring& name) = 0;
    virtual void Clear() = 0;
    virtual std::vector<TYPE*> GetAll() const = 0;
};

} // namepsace weight