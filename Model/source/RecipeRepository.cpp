

#include "RecipeRepository.h"

#include "ReceptDefinitie.h"

namespace weight {



bool RecipeRepository::Has(const std::wstring& name) const
{
    return Repository<ReceptDefinitie>::Has(name);
}

ReceptDefinitie* RecipeRepository::Find(const std::wstring& name) const
{
    return Repository<ReceptDefinitie>::Find(name);
}

bool RecipeRepository::Add(std::unique_ptr<ReceptDefinitie> definition)
{
    return Repository<ReceptDefinitie>::Add(std::move(definition));
}

bool RecipeRepository::Remove(const std::wstring& name)
{
    return Repository<ReceptDefinitie>::Remove(name);
}

void RecipeRepository::Clear()
{
    Repository<ReceptDefinitie>::Clear();
}

std::vector<ReceptDefinitie*> RecipeRepository::GetAll() const
{
    return Repository<ReceptDefinitie>::GetAll();
}

} // namespace weight
