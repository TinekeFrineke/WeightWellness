#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
namespace ww2019
{
class XmlVoedingsmiddelheader : public XmlClass
{
public:
  XmlVoedingsmiddelheader();
  virtual ~XmlVoedingsmiddelheader();

  std::wstring Getnaam() const;
  std::wstring Getcategorie() const;
  std::wstring Getmerk() const;
  std::wstring Getunit() const;
  void Setnaam(const std::wstring & anaam);
  void Setcategorie(const std::wstring & acategorie);
  void Setmerk(const std::wstring & amerk);
  void Setunit(const std::wstring & aunit);

private:
  // Prohibit copying and assignment
  XmlVoedingsmiddelheader(const XmlVoedingsmiddelheader & anOriginal);
  XmlVoedingsmiddelheader & operator=(const XmlVoedingsmiddelheader & anOriginal);
  std::wstring mnaam;
  std::wstring mcategorie;
  std::wstring mmerk;
  std::wstring munit;
};


}
