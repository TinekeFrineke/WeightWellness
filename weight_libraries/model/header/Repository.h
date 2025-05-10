
#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "IRepository.h"

namespace weight {

template <typename TYPE>
class Repository : public IRepository<TYPE>
{
public:
    virtual bool Has(const std::string& name) const override;
    virtual TYPE* Find(const std::string& name) const override;
    virtual bool Add(std::unique_ptr<TYPE> definition) override;
    virtual bool Remove(const std::string& name) override;
    virtual void Clear() override;
    virtual std::vector<TYPE*> GetAll() const override;

private:
    std::map<std::string, std::unique_ptr<TYPE>> m_elements;
};

template <typename TYPE>
bool Repository<TYPE>::Has(const std::string& name) const
{
    return m_elements.find(name) != m_elements.end();
}

template <typename TYPE>
TYPE* Repository<TYPE>::Find(const std::string& name) const
{
    auto iterator = m_elements.find(name);
    if (iterator == m_elements.end())
        return nullptr;

    return iterator->second.get();
}

template <typename TYPE>
bool Repository<TYPE>::Add(std::unique_ptr<TYPE> definition)
{
    if (definition == nullptr || m_elements.find(definition->GetName()) != m_elements.end())
        return false;

    m_elements[definition->GetName()] = std::move(definition);
    return true;
}

template <typename TYPE>
bool Repository<TYPE>::Remove(const std::string& name)
{
    auto iterator = m_elements.find(name);
    if (iterator == m_elements.end())
        return false;

    m_elements.erase(iterator);
    return true;
}

template <typename TYPE>
void Repository<TYPE>::Clear()
{
    m_elements.clear();
}

template <typename TYPE>
std::vector<TYPE*> Repository<TYPE>::GetAll() const
{
    std::vector<TYPE*> definitions;
    for (const auto& definition : m_elements)
        definitions.push_back(definition.second.get());
    return definitions;
}

} // namespace weight