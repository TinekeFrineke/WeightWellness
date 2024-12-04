#pragma once

#include "Utilities/StrUtils.h"

// Clas should be useful for detecting memory leaks

namespace weight
{

class EntityBase
{
protected:
    virtual ~EntityBase() = default;

    void Register(const std::wstring& aClassName,
                  const std::wstring& anInstanceName,
                  int                  aNumberOfInstances);
    void Unregister(const std::wstring& aClassName,
                    const std::wstring& anInstanceName,
                    int                  aNumberOfInstances);
};

template <class CLASS>
class Entity : public EntityBase
{
public:
    virtual ~Entity() = default;

    void Register();
    void Unregister();

protected:
    virtual std::wstring GetInstanceName() const = 0;

private:
    static int mNumberOfInstances;
};


template<class CLASS>
void Entity<CLASS>::Register()
{
    EntityBase::Register(CLASS::GetClassName(), GetInstanceName(), ++mNumberOfInstances);
}


template<class CLASS>
void Entity<CLASS>::Unregister()
{
    EntityBase::Unregister(CLASS::GetClassName(), GetInstanceName(), --mNumberOfInstances);
}

} // namespace weight
