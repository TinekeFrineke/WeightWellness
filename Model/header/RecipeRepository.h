#pragma once

#include <map>

#include "IRecipeRepository.h"
#include "UniqueRepository.h"


namespace weight {

class ReceptDefinitie;

class RecipeRepository
    : public IRecipeRepository
    , private UniqueRepository<ReceptDefinitie>
{
public:
    // Inherited via IFoodDefinitionRepository
    bool Has(const std::wstring& name) const override;
    ReceptDefinitie* Find(const std::wstring& name) const override;
    bool Add(std::unique_ptr<ReceptDefinitie> definition) override;
    bool Remove(const std::wstring& name) override;
    void Clear() override;
    std::vector<ReceptDefinitie*> GetAll() const override;
};

} // namespace weight
