#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlPortie_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlPortie_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
namespace ww_1_1
{
class XmlPortie : public Generator::XmlClass
{
public:
  XmlPortie();
  virtual ~XmlPortie();

  std::wstring Getnaam() const;
  std::wstring Geteenheden() const;
  void Setnaam(const std::wstring & anaam);
  void Seteenheden(const std::wstring & aeenheden);

private:
  // Prohibit copying and assignment
  XmlPortie(const XmlPortie & anOriginal);
  XmlPortie & operator=(const XmlPortie & anOriginal);
  std::wstring mnaam;
  std::wstring meenheden;
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlPortie_h__
