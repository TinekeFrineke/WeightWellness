#pragma once


#include <Callback.h>


namespace viewmodel {

template <typename T>
class Value
{
public:
    int SubscribeCallback(const std::function<void(const T&)>& callback)
    {
        return m_callback.SubscribeValueChanged(callback);
    }

    void UnsubscribeCallback(int handle)
    {
        return m_callback.UnsubscribeValueChanged(handle);
    }

    void SetValue(const T& value)
    {
        if (m_value == value)
            return;

        m_value = value;
        m_callback.Notify(value);
    }

private:
    T m_value{};
    Callback<T> m_callback;
};

} // namespace viewmodel