
#pragma once

#include <memory>
#include <vector>

namespace Utils {
class Date;
}

namespace weight {

class IWeek;

class IWeekRepository
{
public:
    virtual ~IWeekRepository() = default;

    virtual IWeek* Create(const Utils::Date& date) = 0;
    virtual bool Add(std::unique_ptr<IWeek> definition) = 0;
    virtual IWeek* FindWeekContaining(const Utils::Date& date) const = 0;
    virtual std::vector<IWeek*> GetAll() const = 0;
};

} // namespace weight
