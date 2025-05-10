#pragma once

namespace weight {

#ifdef NEW_TRIAL

class ISubject;

class IObserver
{
    public:
        virtual ~IObserver() = default;
        IObserver(const IObserver&) = delete; // rule of three
        IObserver& operator=(const IObserver&) = delete;
    
        virtual void Update(const ISubject& subject) noexcept = 0;
};
#else
template <typename TYPE>
class IObserver
{
public:
    virtual ~IObserver() = default;
    IObserver(const IObserver&) = delete; // rule of three
    IObserver& operator=(const IObserver&) = delete;

    virtual void Update(const TYPE& value) noexcept = 0;
};
#endif
} // namespace weight
