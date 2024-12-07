#include "Entity.h"

#ifdef FIND_LEAKS
#include <windows.h>
#endif


namespace weight
{

void EntityBase::Register(const std::tstring& aClassName,
                          const std::tstring& anInstanceName,
                          int                 aNumberOfInstances) noexcept
{
#ifdef FIND_LEAKS
    TCHAR smsg[1024];
    swprintf_s(smsg, _T("%s::%s %s 0x%08p: aNumberOfInstances == %d\n"),
              aClassName.c_str(), aClassName.c_str(), anInstanceName.c_str(),
              this, aNumberOfInstances);
    OutputDebugString(smsg);
#else
    (void)aClassName;
    (void)anInstanceName;
    (void)aNumberOfInstances;
#endif
}


void EntityBase::Unregister(const std::tstring& aClassName,
                            const std::tstring& anInstanceName,
                            int                 aNumberOfInstances) noexcept
{
#ifdef FIND_LEAKS
    TCHAR smsg[1024];
    swprintf_s(smsg, L"%s::~%s %s 0x%08x: aNumberOfInstances == %d\n",
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
