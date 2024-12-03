#pragma once

#include <map>

#include "IFoodDefinitionRepository.h"
#include "UniqueRepository.h"


namespace weight {

class VMDefinitie;

class FoodDefinitionRepository
    : public IFoodDefinitionRepository
    , private UniqueRepository<VMDefinitie>
{
public:
    // Inherited via IFoodDefinitionRepository
    bool Has(const std::wstring& name) const override;
    VMDefinitie* Find(const std::wstring& name) const override;
    bool Add(std::unique_ptr<VMDefinitie> definition) override;
    bool Remove(const std::wstring& name) override;
    void Clear() override;
    std::vector<VMDefinitie*> GetAll() const override;
};

} // namespace weight
