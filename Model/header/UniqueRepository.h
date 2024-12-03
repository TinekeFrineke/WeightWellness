
#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>

namespace weight {

template <typename TYPE>
class UniqueRepository
{
public:
    // Inherited via IFoodDefinitionRepository
    virtual bool Has(const std::wstring& name) const;
    virtual TYPE* Find(const std::wstring& name) const;
    virtual bool Add(std::unique_ptr<TYPE> definition);
    virtual bool Remove(const std::wstring& name);
    virtual void Clear();
    virtual std::vector<TYPE*> GetAll() const;

private:
    std::map<std::wstring, std::unique_ptr<TYPE>> m_elements;
};

template <typename TYPE>
bool UniqueRepository<TYPE>::Has(const std::wstring& name) const
{
    return m_elements.find(name) != m_elements.end();
}

template <typename TYPE>
TYPE* UniqueRepository<TYPE>::Find(const std::wstring& name) const
{
    auto iterator = m_elements.find(name);
    if (iterator == m_elements.end())
        return nullptr;

    return iterator->second.get();
}

template <typename TYPE>
bool UniqueRepository<TYPE>::Add(std::unique_ptr<TYPE> definition)
{
    if (definition == nullptr || m_elements.find(definition->GetName()) != m_elements.end())
        return false;

    m_elements[definition->GetName()] = std::move(definition);
    return true;
}

template <typename TYPE>
bool UniqueRepository<TYPE>::Remove(const std::wstring& name)
{
    auto iterator = m_elements.find(name);
    if (iterator == m_elements.end())
        return false;

    m_elements.erase(iterator);
    return true;
}

template <typename TYPE>
void UniqueRepository<TYPE>::Clear()
{
    m_elements.clear();
}

template <typename TYPE>
std::vector<TYPE*> UniqueRepository<TYPE>::GetAll() const
{
    std::vector<TYPE*> definitions;
    for (const auto& definition : m_elements)
        definitions.push_back(definition.second.get());
    return definitions;
}

} // namespace weight