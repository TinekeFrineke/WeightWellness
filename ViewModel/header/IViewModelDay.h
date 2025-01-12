
#pragma once

#include "IDay.h"
#include "ISettableDay.h"

namespace weight {
class Day;
}

namespace viewmodel {


class IViewModelDay
    : public ISettableDay
    , public IDay
{
public:
    IViewModelDay(QObject* parent) : IDay(parent) {}
    ~IViewModelDay() override = default;
};


} // namspace viewmodel