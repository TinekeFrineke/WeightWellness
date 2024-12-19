
#pragma once


namespace Utils {
class Date;
}

namespace weight {
class Day;
}

namespace Private
{

class IDay
{
public:
    virtual ~IDay() = default;

    virtual void SetDay(const Utils::Date& date, weight::Day* day) = 0;
};


} // namespace Private