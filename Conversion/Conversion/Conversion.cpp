// Conversion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "ww\wwmodel\xml01\xml01reader.h"
#include "ww\wwmodel\xmlwriter.h"

#include <xercesc/util/PlatformUtils.hpp>

int _tmain(int argc, _TCHAR* argv[])
{
  if (argc < 3)
    return -1;

  WW::Model model;

  XERCES_CPP_NAMESPACE::XMLPlatformUtils::Initialize();

  WW_0_1::XmlReader reader(model);
  reader.Read(argv[1]);

  WW_1_0::XmlWriter writer(model);
  writer.Write(argv[2]);

  XERCES_CPP_NAMESPACE::XMLPlatformUtils::Terminate();

	return 0;
}

