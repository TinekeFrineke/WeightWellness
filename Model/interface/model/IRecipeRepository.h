#pragma once

#include <memory>
#include <string>
#include <vector>


namespace weight {

class ReceptDefinitie;

class IRecipeRepository {
public:
    virtual ~IRecipeRepository() = default;

    virtual bool Has(const std::wstring& name) const = 0;
    virtual ReceptDefinitie* Find(const std::wstring& name) const = 0;
    virtual bool Add(std::unique_ptr<ReceptDefinitie> definition) = 0;
    virtual bool Remove(const std::wstring& name) = 0;
    virtual std::vector <ReceptDefinitie*> GetAll() const = 0;
    virtual void Clear() = 0;

};

} // namespace weight
