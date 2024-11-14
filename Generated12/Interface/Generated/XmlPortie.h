#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
namespace ww_1_2
{
class XmlPortie : public XmlClass
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
