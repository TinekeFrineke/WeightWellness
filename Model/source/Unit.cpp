
#include "Unit.h"

#include "Model.h"

namespace weight
{


Unit::Unit(Model& aModel, const std::tstring& aName)
    : mName(aName)
{
    aModel.Add(*this);
}


} // namespace weight
