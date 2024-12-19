#pragma once

#include <functional>
#include <map>


namespace viewmodel {


template <typename T>
class Callback
{
public:
    int SubscribeValueChanged(const std::function<void(const T&)>& callback);
    void UnsubscribeValueChanged(int handle);

    void Notify(const T& newValue)
    {
        for (auto callback : m_callbacks)
            callback.second(newValue);
    }

private:
    int m_lastValue{};
    std::map<int, std::function<void(const T&)>> m_callbacks;
};

template<typename T>
inline int Callback<T>::SubscribeValueChanged(const std::function<void(const T&)>& callback)
{
    return 0;
}

template<typename T>
void Callback<T>::UnsubscribeValueChanged(int handle)
{
    m_callbacks.erase(m_callbacks.find(handle));
}

} // namespace viewmodel