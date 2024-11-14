#include "stdafx.h"

#include "ModelException.h"

const char * ModelException::what( ) const throw( )
{
  return mWhat.c_str();
}
