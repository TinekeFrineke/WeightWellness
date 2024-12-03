#pragma once

#include <memory>
#include <string>
#include <vector>


namespace weight {

class VMDefinitie;

class IFoodDefinitionRepository {
public:
    virtual ~IFoodDefinitionRepository() = default;

    virtual bool Has(const std::wstring& name) const = 0;
    virtual VMDefinitie* Find(const std::wstring& name) const = 0;
    virtual bool Add(std::unique_ptr<VMDefinitie> definition) = 0;
    virtual bool Remove(const std::wstring& name) = 0;
    virtual std::vector <VMDefinitie*> GetAll() const = 0;
    virtual void Clear() = 0;

};

} // namespace weight
