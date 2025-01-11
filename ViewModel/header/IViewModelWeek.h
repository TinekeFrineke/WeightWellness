
#pragma once


#include "ISettableWeek.h"
#include "IWeek.h"

namespace weight {
class Week;
}

namespace viewmodel {


class IViewModelWeek
    : public IWeek
    , public ISettableWeek
{
public:
    ~IViewModelWeek() override = default;
    IViewModelWeek(QObject* parent) : IWeek(parent) {}
};


} // namspace viewmodel