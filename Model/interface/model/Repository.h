#pragma once


#include "IRepository.h"


namespace weight {

class Repository
    : public IRepository
{
public:
    std::vector<std::wstring> Get() const override;
    void Add(const std::wstring& unit) override;
    void Clear() override;

private:
    std::vector<std::wstring> m_units;

};


} // namespace weight