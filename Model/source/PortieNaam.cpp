
#include "PortieNaam.h"

#include "Model.h"


namespace weight
{


PortieNaam::PortieNaam(Model& aModel, const std::tstring& aName)
    : Naam(aName)
{
    aModel.Add(*this);
}


} // namespace weight
