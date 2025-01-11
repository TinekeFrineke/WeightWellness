
#pragma once


namespace weight {
class Week;
}

namespace viewmodel {


class ISettableWeek
{
public:
    virtual ~ISettableWeek() = default;

    virtual void setWeek(weight::Week* week) = 0;
};


} // namspace viewmodel