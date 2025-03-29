

#include "FoodDefinitionRepository.h"

#include "VoedingsmiddelDefinitie.h"

namespace weight {



bool FoodDefinitionRepository::Has(const std::wstring& name) const
{
    return Repository<VMDefinitie>::Has(name);
}

VMDefinitie* FoodDefinitionRepository::Find(const std::wstring& name) const
{
    return Repository<VMDefinitie>::Find(name);
}

bool FoodDefinitionRepository::Add(std::unique_ptr<VMDefinitie> definition)
{
    return Repository<VMDefinitie>::Add(std::move(definition));
}

bool FoodDefinitionRepository::Remove(const std::wstring& name)
{
    return Repository<VMDefinitie>::Remove(name);
}

void FoodDefinitionRepository::Clear()
{
    Repository::Clear();
}

std::vector<VMDefinitie*> FoodDefinitionRepository::GetAll() const
{
    return Repository<VMDefinitie>::GetAll();
}

} // namespace weight
