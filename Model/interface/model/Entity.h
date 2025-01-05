#pragma once

#include <string>

// Class should be useful for detecting memory leaks

namespace weight
{

class EntityBase
{
protected:
    virtual ~EntityBase() = default;

    void Register(const std::wstring& aClassName,
                  const std::wstring& anInstanceName,
                  int                  aNumberOfInstances) noexcept;
    void Unregister(const std::wstring& aClassName,
                    const std::wstring& anInstanceName,
                    int                  aNumberOfInstances) noexcept;
};

template <class CLASS>
class Entity : public EntityBase
{
public:
    virtual ~Entity() = default;

    void Register() noexcept;
    void Unregister() noexcept;

protected:
    virtual std::wstring GetInstanceName() const noexcept = 0;

private:
    static int mNumberOfInstances;
};


template<class CLASS>
void Entity<CLASS>::Register() noexcept
{
    EntityBase::Register(CLASS::GetClassName(), GetInstanceName(), ++mNumberOfInstances);
}


template<class CLASS>
void Entity<CLASS>::Unregister() noexcept
{
    EntityBase::Unregister(CLASS::GetClassName(), GetInstanceName(), --mNumberOfInstances);
}

} // namespace weight
