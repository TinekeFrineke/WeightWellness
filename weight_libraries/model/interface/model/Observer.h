#pragma once

#include "IObserver.h"

namespace weight {

#ifdef NEW_TRIAL
template <typename TYPE>
class Observer
    : public IObserver
{
public:
    virtual ~Observer() = default;
    Observer(const Observer&) = delete;
    Observer& operator=(const Observer&) = delete;
};
#else
template <typename TYPE>
class Observer
{
public:
    virtual ~Observer() = default;
    Observer(const Observer&) = delete; // rule of three
    Observer& operator=(const Observer&) = delete;

    virtual void Update(const TYPE& value) noexcept = 0;
};
#endif
} // namespace weight
