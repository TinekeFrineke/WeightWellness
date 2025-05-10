#pragma once


#include "IStringRepository.h"


namespace weight {

class StringRepository
    : public IStringRepository
{
public:
    std::vector<std::string> Get() const override;
    void Add(const std::string& element) override;
    void Clear() noexcept override;

private:
    std::vector<std::string> m_elements;

};


} // namespace weight