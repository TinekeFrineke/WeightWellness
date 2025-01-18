
#pragma once


namespace Utils {
class Date;
}

namespace weight {
class Week;
}

namespace viewmodel {


class ISettableWeek
{
public:
    virtual ~ISettableWeek() = default;

    virtual void setWeek(weight::Week* week) = 0;
    virtual weight::Week* getWeek() const = 0;
};


} // namspace viewmodel