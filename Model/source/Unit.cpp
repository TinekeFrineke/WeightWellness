
#include "Unit.h"

#include "Model.h"

namespace weight
{


Unit::Unit(Model& aModel, const std::tstring& aName)
    : mName(aName)
{
    aModel.AddUnit(aName);
}

Unit::Unit(const std::tstring& aName)
    : mName(aName)
{
}


} // namespace weight
