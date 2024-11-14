#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
namespace ww2015
{
class XmlVrijeportie : public XmlClass
{
public:
  XmlVrijeportie();
  virtual ~XmlVrijeportie();

  std::wstring Getvoedingsmiddel() const;
  std::wstring Getpunten() const;
  void Setvoedingsmiddel(const std::wstring & avoedingsmiddel);
  void Setpunten(const std::wstring & apunten);

private:
  // Prohibit copying and assignment
  XmlVrijeportie(const XmlVrijeportie & anOriginal);
  XmlVrijeportie & operator=(const XmlVrijeportie & anOriginal);
  std::wstring mvoedingsmiddel;
  std::wstring mpunten;
};


}
