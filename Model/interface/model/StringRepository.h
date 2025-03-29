#pragma once


#include "IStringRepository.h"


namespace weight {

class StringRepository
    : public IStringRepository
{
public:
    std::vector<std::wstring> Get() const override;
    void Add(const std::wstring& element) override;
    void Clear() noexcept override;

private:
    std::vector<std::wstring> m_elements;

};


} // namespace weight