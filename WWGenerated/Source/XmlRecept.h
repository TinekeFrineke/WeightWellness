#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlRecept_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlRecept_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
namespace ww_1_1
{
class XmlRecept : public Generator::XmlClass
{
public:
  XmlRecept();
  virtual ~XmlRecept();

  std::wstring Getnaam() const;
  std::wstring Getpunten() const;
  std::wstring Gethoeveelheid() const;
  void Setnaam(const std::wstring & anaam);
  void Setpunten(const std::wstring & apunten);
  void Sethoeveelheid(const std::wstring & ahoeveelheid);

private:
  // Prohibit copying and assignment
  XmlRecept(const XmlRecept & anOriginal);
  XmlRecept & operator=(const XmlRecept & anOriginal);
  std::wstring mnaam;
  std::wstring mpunten;
  std::wstring mhoeveelheid;
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlRecept_h__
