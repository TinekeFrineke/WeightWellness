#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlVoedingsmiddelheader_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlVoedingsmiddelheader_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
namespace ww_1_1
{
class XmlVoedingsmiddelheader : public Generator::XmlClass
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
#endif // Projects_VC10_WW_WWGenerated_XmlVoedingsmiddelheader_h__
