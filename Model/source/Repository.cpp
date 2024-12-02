
#include "Repository.h"

namespace weight {

std::vector<std::wstring> Repository::Get() const
{
    return m_units;
}

void Repository::Add(const std::wstring& unit)
{
    if (std::find(m_units.begin(), m_units.end(), unit) != m_units.end())
        return;

    m_units.push_back(unit);
}

void Repository::Clear()
{
    m_units.clear();
}

} // namespace weight
