#pragma once


namespace weight {

#ifdef NEW_TRIAL
class IObserver;

class ISubject
{
public:
    virtual ~ISubject() = default;
    virtual void Attach(IObserver& observer) = 0;
    virtual void Detach(const IObserver& observer) = 0;
    virtual void NotifyObservers() = 0;
};
#else
template <typename TYPE>class IObserver;

template <typename TYPE>
class ISubject
{
public:
    virtual void Attach(IObserver<TYPE>& observer) = 0;
    virtual void Detach(const IObserver<TYPE>& observer) = 0;
    virtual void NotifyObservers() = 0;
    virtual void Set(const TYPE& value) = 0;
    virtual const TYPE& Get() const = 0;
};
#endif
} // namespace weight