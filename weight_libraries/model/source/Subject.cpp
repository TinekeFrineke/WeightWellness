
#include "Subject.h"

#include "Observer.h"


namespace weight {



//void Subject::Attach(IObserver& observer)
//{
//    m_observers.push_back(observer);
//}
//
//void Subject::Detach(const IObserver& observer)
//{
//    auto found = std::find_if(m_observers.begin(), m_observers.end(), [&observer] (const std::reference_wrapper<IObserver>& obs) {
//        return &(obs.get()) == &observer;
//    });
//    if (found != m_observers.end())
//        m_observers.erase(found);
//}
//
//void Subject::NotifyObservers()
//{
//    for (const auto& observer : m_observers)
//        observer.get().Update(*this);
//}

} // namespace weight