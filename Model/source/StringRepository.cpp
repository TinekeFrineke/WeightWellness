
#include "StringRepository.h"

namespace weight {

std::vector<std::string> StringRepository::Get() const
{
    return m_elements;
}

void StringRepository::Add(const std::string& element)
{
    if (element.empty() || std::find(m_elements.begin(), m_elements.end(), element) != m_elements.end())
        return;

    m_elements.push_back(element);
}

void StringRepository::Clear() noexcept
{
    m_elements.clear();
}

} // namespace weight
