#pragma once

#include "Utilities/StrUtils.h"

// Clas should be useful for detecting memory leaks

namespace weight
{

class EntityBase
{
protected:
    virtual ~EntityBase() = default;

    void Register(const std::string& aClassName,
                  const std::string& anInstanceName,
                  int                  aNumberOfInstances) noexcept;
    void Unregister(const std::string& aClassName,
                    const std::string& anInstanceName,
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
    virtual std::string GetInstanceName() const = 0;

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
