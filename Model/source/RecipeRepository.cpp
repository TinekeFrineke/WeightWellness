

#include "RecipeRepository.h"

#include "ReceptDefinitie.h"

namespace weight {



bool RecipeRepository::Has(const std::wstring& name) const
{
    return UniqueRepository<ReceptDefinitie>::Has(name);
}

ReceptDefinitie* RecipeRepository::Find(const std::wstring& name) const
{
    return UniqueRepository<ReceptDefinitie>::Find(name);
}

bool RecipeRepository::Add(std::unique_ptr<ReceptDefinitie> definition)
{
    return UniqueRepository<ReceptDefinitie>::Add(std::move(definition));
}

bool RecipeRepository::Remove(const std::wstring& name)
{
    return UniqueRepository<ReceptDefinitie>::Remove(name);
}

void RecipeRepository::Clear()
{
    UniqueRepository<ReceptDefinitie>::Clear();
}

std::vector<ReceptDefinitie*> RecipeRepository::GetAll() const
{
    return UniqueRepository<ReceptDefinitie>::GetAll();
}

} // namespace weight
