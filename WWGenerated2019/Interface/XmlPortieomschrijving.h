#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
namespace ww2019
{
class XmlPortieomschrijving : public XmlClass
{
public:
  XmlPortieomschrijving();
  virtual ~XmlPortieomschrijving();

  std::wstring Getomschrijving() const;
  void Setomschrijving(const std::wstring & aomschrijving);

private:
  // Prohibit copying and assignment
  XmlPortieomschrijving(const XmlPortieomschrijving & anOriginal);
  XmlPortieomschrijving & operator=(const XmlPortieomschrijving & anOriginal);
  std::wstring momschrijving;
};


}
