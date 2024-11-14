#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlFreelot_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlFreelot_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
namespace ww_1_1
{
class XmlFreelot : public Generator::XmlClass
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
#endif // Projects_VC10_WW_WWGenerated_XmlFreelot_h__
