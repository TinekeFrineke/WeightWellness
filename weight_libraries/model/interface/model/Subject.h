#pragma once

#include <vector>

#ifndef NEW_TRIAL
#include "IObserver.h"
#endif
#include "ISubject.h"

namespace weight {

#ifdef NEW_TRIAL
class Subject: public ISubject
{
public:
    using RefObserver = std::reference_wrapper<IObserver>;

    virtual ~Subject() = default;

    void Attach(IObserver& observer) override;
    void Detach(const IObserver& observer) override;
    void NotifyObservers() override;

private:
    std::vector<RefObserver> m_observers;
};


class IntSubject : public Subject
{
public:
    void Set(int value) { m_value = value; NotifyObservers(); }
    int Get() const noexcept { return m_value; }

private:
    int m_value{};
};
#else
template <typename TYPE>
class Subject
    : public ISubject<TYPE>
{
public:
    using RefObserver = std::reference_wrapper<IObserver<TYPE>>;

    Subject() = default;
    virtual ~Subject() = default;
    Subject(const Subject&) = delete; // rule of three
    Subject& operator=(const Subject&) = delete;

    void Attach(IObserver<TYPE>& observer) override;
    void Detach(const IObserver<TYPE>& observer) override;
    void NotifyObservers() override;
    void Set(const TYPE&) override;
    const TYPE& Get() const override;

private:
    std::vector<RefObserver> m_observers;
    TYPE m_value{};
};

template <typename TYPE>
void Subject<TYPE>::Attach(IObserver<TYPE>& observer)
{
    m_observers.push_back(observer);
}


template <typename TYPE>
void Subject<TYPE>::Detach(const IObserver<TYPE>& observer)
{
    auto found = std::find_if(m_observers.begin(), m_observers.end(), [&observer] (const std::reference_wrapper<IObserver<TYPE>>& obs) {
        return &observer == &obs.get();
    });
    if (found != m_observers.end())
        m_observers.erase(found);
}


template <typename TYPE>
void Subject<TYPE>::NotifyObservers()
{
    for (auto observer : m_observers)
        observer.get().Update(m_value);
}

template <typename TYPE>
void Subject<TYPE>::Set(const TYPE& value)
{
    m_value = value;
    NotifyObservers();
}


template <typename TYPE>
const TYPE& Subject<TYPE>::Get() const
{
    return m_value;
}
#endif

} // namespace weight
