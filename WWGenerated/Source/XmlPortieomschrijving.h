#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlPortieomschrijving_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlPortieomschrijving_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
namespace ww_1_1
{
class XmlPortieomschrijving : public Generator::XmlClass
{
public:
  XmlPortieomschrijving();
  virtual ~XmlPortieomschrijving();

  std::wstring Getomschrijving() const;
  void Setomschrijving(const std::wstring & aomschrijving);

private:
  // Prohibit copying and assignment
  XmlPortieomschrijving(const XmlPortieomschrijving & anOriginal);
  XmlPortieomschrijving & operator=(const XmlPortieomschrijving & anOriginal);
  std::wstring momschrijving;
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlPortieomschrijving_h__
