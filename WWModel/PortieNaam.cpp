#include "stdafx.h"

#include "PortieNaam.h"

#include "WWModel.h"


namespace WW
{


PortieNaam::PortieNaam(WW::Model & aModel, const std::tstring & aName)
: Naam(aName)
{
  aModel.Add(*this);
}


} // namespace WW