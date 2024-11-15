#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
namespace ww2019
{
class XmlUnit : public XmlClass
{
public:
  XmlUnit();
  virtual ~XmlUnit();

  std::wstring Getnaam() const;
  void Setnaam(const std::wstring & anaam);

private:
  // Prohibit copying and assignment
  XmlUnit(const XmlUnit & anOriginal);
  XmlUnit & operator=(const XmlUnit & anOriginal);
  std::wstring mnaam;
};


}
