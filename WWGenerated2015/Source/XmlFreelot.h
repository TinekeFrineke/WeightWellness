#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
namespace ww2015
{
class XmlFreelot : public XmlClass
{
public:
  XmlFreelot();
  virtual ~XmlFreelot();

  std::wstring Getpunten() const;
  void Setpunten(const std::wstring & apunten);

private:
  // Prohibit copying and assignment
  XmlFreelot(const XmlFreelot & anOriginal);
  XmlFreelot & operator=(const XmlFreelot & anOriginal);
  std::wstring mpunten;
};


}
