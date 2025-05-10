#pragma once

#include <exception>
#include "Utilities/StrUtils.h"

class ModelException : public std::exception
{
public:
                        ModelException(const std::string & aString) : mWhat(aString) {}

  virtual const char *  what( ) const throw( );

private:
  std::string           mWhat;
};
