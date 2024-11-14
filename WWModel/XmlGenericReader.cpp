//#include "stdafx.h"
//
#include "XmlGenericReader.h"
//
//#include <fstream>
//#include <io.h>
//
//#include <xercesc/dom/dom.hpp>
//#include <xercesc/framework/membufinputsource.hpp>
//#include <xercesc/framework/localfileinputsource.hpp>
//#include <xercesc/parsers/XercesDOMParser.hpp>
//
//#include "ModelException.h"
//
//
////****************************************************************************
//// class WW::XmlGenericReader
////****************************************************************************
//
////---------------------------------------------------------------------------
//// Calls the Xerces parser to read the configuration
//XmlGenericReader::eRESULT XmlGenericReader::Read(const std::tstring & aFilename)
//{
//  ParseErrorHandler eh;
//  XERCES_CPP_NAMESPACE::XercesDOMParser parser;
//  parser.setDoValidation(false);
//  parser.setErrorHandler(&eh);
//
//  eRESULT result = ParseDocument(aFilename, parser);
//  if (result != RESULT_Ok)
//    if (result == RESULT_FileNotFound)
//      return RESULT_Ok;
//    else
//      return result;
//
//  if (parser.getDocument() == NULL)
//    return RESULT_ErrorInFile;
//
//  try
//  {
//    result = InterpretDocument(*parser.getDocument());
//  }
//  catch (const std::exception & anException)
//  {
//    throw ModelException("Error in file " + Str::ToString(aFilename) + ": " + anException.what());
//  }
//  catch (...)
//  {
//    throw ModelException("Unknown error in file " + Str::ToString(aFilename));
//  }
//
//  return result;
//}
//
//
////----------------------------------------------------------------------------
//XmlGenericReader::eRESULT XmlGenericReader::ParseDocument(const std::tstring &                   aFilename,
//                                                          XERCES_CPP_NAMESPACE::XercesDOMParser &aParser)
//{
//  //std::ifstream instr(Str::ToString(aFilename).c_str(), std::ios::in);
//  //if (!instr.is_open())
//  //  return RESULT_FileNotFound;
//
//  //std::string input;
//  //int c = instr.get();
//  //while (!instr.fail())
//  //{
//  //  input += static_cast<char>(c);
//  //  c = instr.get();
//  //}
//
//  XERCES_CPP_NAMESPACE::LocalFileInputSource source(NULL, aFilename.c_str());
////  XERCES_CPP_NAMESPACE::MemBufInputSource source((unsigned char *)input.c_str(),
////                                                 static_cast<unsigned int>(input.length()) * sizeof(input[0]),
////                                                 L"ID", false);
//
//  try
//  {
//    aParser.parse(source);
//  }
//  catch (const XERCES_CPP_NAMESPACE::XMLException& e)
//  {
//    char * message = XERCES_CPP_NAMESPACE::XMLString::transcode(e.getMessage());
//    ModelException exception(std::string("Exception occurred: ") + message + 
//                         "; File being parsed is " + Str::ToString(aFilename));
//    XERCES_CPP_NAMESPACE::XMLString::release(&message);
//    throw exception;
//  }
// 	catch (...)
// 	{
//    throw ModelException(std::string("Unexpected Exception occurred: ") + Str::ToString(aFilename));
//	}
//
//#ifdef _DEBUG
////  Print(aParser.getDocument(), 0);
//#endif
//
//  return RESULT_Ok;
//}
