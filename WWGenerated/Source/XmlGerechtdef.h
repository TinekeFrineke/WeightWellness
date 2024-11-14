#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlGerechtdef_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlGerechtdef_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
namespace ww_1_1
{
class XmlGerechtdef : public Generator::XmlClass
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
#endif // Projects_VC10_WW_WWGenerated_XmlGerechtdef_h__
