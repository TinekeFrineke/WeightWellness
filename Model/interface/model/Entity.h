#pragma once

#include "Utilities/StrUtils.h"

// Clas should be useful for detecting memory leaks

namespace weight
{

class EntityBase
{
protected:
    virtual                       ~EntityBase() {}
    void                          Register(const std::tstring& aClassName,
                                           const std::tstring& anInstanceName,
                                           int                  aNumberOfInstances);
    void                          Unregister(const std::tstring& aClassName,
                                             const std::tstring& anInstanceName,
                                             int                  aNumberOfInstances);
};

template <class CLASS>
class Entity : public EntityBase
{
public:
    void                          Register();
    void                          Unregister();

protected:
    virtual std::tstring          GetInstanceName() const = 0;

private:
    static int                    mNumberOfInstances;
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
