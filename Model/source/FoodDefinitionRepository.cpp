

#include "FoodDefinitionRepository.h"

#include "VoedingsmiddelDefinitie.h"

namespace weight {



bool FoodDefinitionRepository::Has(const std::wstring& name) const
{
    return UniqueRepository<VMDefinitie>::Has(name);
}

VMDefinitie* FoodDefinitionRepository::Find(const std::wstring& name) const
{
    return UniqueRepository<VMDefinitie>::Find(name);
}

bool FoodDefinitionRepository::Add(std::unique_ptr<VMDefinitie> definition)
{
    return UniqueRepository<VMDefinitie>::Add(std::move(definition));
}

bool FoodDefinitionRepository::Remove(const std::wstring& name)
{
    return UniqueRepository<VMDefinitie>::Remove(name);
}

void FoodDefinitionRepository::Clear()
{
    UniqueRepository::Clear();
}

std::vector<VMDefinitie*> FoodDefinitionRepository::GetAll() const
{
    return UniqueRepository<VMDefinitie>::GetAll();
}

} // namespace weight
