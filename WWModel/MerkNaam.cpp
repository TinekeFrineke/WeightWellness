#include "stdafx.h"

#include "MerkNaam.h"

#include "WWModel.h"


namespace WW
{


MerkNaam::MerkNaam(WW::Model & aModel, const std::tstring & aName)
: Naam(aName)
{
  if (!aName.empty())
    aModel.Add(*this);
}


} // namespace WW