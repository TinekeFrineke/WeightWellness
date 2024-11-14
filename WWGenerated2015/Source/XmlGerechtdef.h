#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
namespace ww2015
{
class XmlGerechtdef : public XmlClass
{
public:
  XmlGerechtdef();
  virtual ~XmlGerechtdef();

  std::wstring Getnaam() const;
  std::wstring Getpunten() const;
  void Setnaam(const std::wstring & anaam);
  void Setpunten(const std::wstring & apunten);

private:
  // Prohibit copying and assignment
  XmlGerechtdef(const XmlGerechtdef & anOriginal);
  XmlGerechtdef & operator=(const XmlGerechtdef & anOriginal);
  std::wstring mnaam;
  std::wstring mpunten;
};


}
