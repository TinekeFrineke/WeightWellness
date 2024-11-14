#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlPuntenper100_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlPuntenper100_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
namespace ww_1_1
{
class XmlPuntenper100 : public Generator::XmlClass
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
#endif // Projects_VC10_WW_WWGenerated_XmlPuntenper100_h__
