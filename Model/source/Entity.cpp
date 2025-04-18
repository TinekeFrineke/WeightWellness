#include "Entity.h"

#ifdef FIND_LEAKS
#include <windows.h>
#endif


namespace weight
{

void EntityBase::Register(const std::string& aClassName,
                          const std::string& anInstanceName,
                          int aNumberOfInstances) noexcept
{
#ifdef FIND_LEAKS
    char smsg[1024];
    sprintf_s(smsg, "%s::%s %s 0x%08p: aNumberOfInstances == %d\n",
              aClassName.c_str(), aClassName.c_str(), anInstanceName.c_str(),
              this, aNumberOfInstances);
    OutputDebugString(smsg);
#else
    (void)aClassName;
    (void)anInstanceName;
    (void)aNumberOfInstances;
#endif
}


void EntityBase::Unregister(const std::string& aClassName,
                            const std::string& anInstanceName,
                            int aNumberOfInstances) noexcept
{
#ifdef FIND_LEAKS
    char smsg[1024];
    sprintf_s(smsg, "%s::~%s %s 0x%08x: aNumberOfInstances == %d\n",
               aClassName.c_str(), aClassName.c_str(), anInstanceName.c_str(),
               (int)this, aNumberOfInstances);
    OutputDebugString(smsg);
#else
    std::ignore = aClassName;
    std::ignore = anInstanceName;
    std::ignore = aNumberOfInstances;
#endif
}


} // namespace weight
