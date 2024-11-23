
#include "Unit.h"

#include "WWModel.h"

namespace WW
{


Unit::Unit(WW::Model& aModel, const std::tstring& aName)
    : mName(aName)
{
    aModel.Add(*this);
}


} // namespace WW
