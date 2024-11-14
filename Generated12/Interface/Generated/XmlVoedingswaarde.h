#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
namespace ww_1_2
{
class XmlVoedingswaarde : public XmlClass
{
public:
  XmlVoedingswaarde();
  virtual ~XmlVoedingswaarde();

  std::wstring Getkcalper100() const;
  std::wstring Getvetper100() const;
  std::wstring Getkoolhydratenper100() const;
  std::wstring Geteiwitper100() const;
  std::wstring Getvezelsper100() const;
  void Setkcalper100(const std::wstring & akcalper100);
  void Setvetper100(const std::wstring & avetper100);
  void Setkoolhydratenper100(const std::wstring & akoolhydratenper100);
  void Seteiwitper100(const std::wstring & aeiwitper100);
  void Setvezelsper100(const std::wstring & avezelsper100);

private:
  // Prohibit copying and assignment
  XmlVoedingswaarde(const XmlVoedingswaarde & anOriginal);
  XmlVoedingswaarde & operator=(const XmlVoedingswaarde & anOriginal);
  std::wstring mkcalper100;
  std::wstring mvetper100;
  std::wstring mkoolhydratenper100;
  std::wstring meiwitper100;
  std::wstring mvezelsper100;
};


}
