
#pragma once


namespace weight {
class Day;
}

namespace viewmodel {


class ISettableDay
{
public:
    virtual ~ISettableDay() = default;

    virtual void setDay(weight::Day* day) = 0;
};


} // namspace viewmodel