#pragma once


#include <Callback.h>


namespace ViewModel {

template <typename T>
class Value
{
public:
    void SetValue(const T& value)
    {
        m_value = value;
        m_callback.Notify(value);
    }

private:
    T m_value{};
    Callback<T> m_callback;
};

} // namespace ViewModel