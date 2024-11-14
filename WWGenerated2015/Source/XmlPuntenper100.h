#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
namespace ww2015
{
class XmlPuntenper100 : public XmlClass
{
public:
  XmlPuntenper100();
  virtual ~XmlPuntenper100();

  std::wstring Getpunten() const;
  void Setpunten(const std::wstring & apunten);

private:
  // Prohibit copying and assignment
  XmlPuntenper100(const XmlPuntenper100 & anOriginal);
  XmlPuntenper100 & operator=(const XmlPuntenper100 & anOriginal);
  std::wstring mpunten;
};


}
