#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlUnit_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlUnit_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
namespace ww_1_1
{
class XmlUnit : public Generator::XmlClass
{
public:
  XmlUnit();
  virtual ~XmlUnit();

  std::wstring Getnaam() const;
  void Setnaam(const std::wstring & anaam);

private:
  // Prohibit copying and assignment
  XmlUnit(const XmlUnit & anOriginal);
  XmlUnit & operator=(const XmlUnit & anOriginal);
  std::wstring mnaam;
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlUnit_h__
