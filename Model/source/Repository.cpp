
#include "Repository.h"

namespace weight {

std::vector<std::wstring> Repository::Get() const
{
    return m_elements;
}

void Repository::Add(const std::wstring& element)
{
    if (element.empty() || std::find(m_elements.begin(), m_elements.end(), element) != m_elements.end())
        return;

    m_elements.push_back(element);
}

void Repository::Clear() noexcept
{
    m_elements.clear();
}

} // namespace weight
