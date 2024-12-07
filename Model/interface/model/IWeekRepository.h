#pragma once

#include <memory>
#include <string>
#include <vector>


namespace weight {

class Week;

class IWeekRepository {
public:
    virtual ~IWeekRepository() = default;

    virtual bool Has(const std::wstring& name) const = 0;
    virtual Week* Find(const std::wstring& name) const = 0;
    virtual bool Add(std::unique_ptr<Week> definition) = 0;
    virtual bool Remove(const std::wstring& name) = 0;
    virtual std::vector <Week*> GetAll() const = 0;
    virtual void Clear() = 0;

};

} // namespace weight
