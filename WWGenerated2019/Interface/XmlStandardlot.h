#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
#include "XmlPortie.h"

namespace ww2019
{
// Forward declarations
class XmlPuntenper100;
class XmlVoedingswaarde;
class XmlStandardlot : public XmlClass
{
public:
  XmlStandardlot();
  virtual ~XmlStandardlot();

  const XmlPortie & GetPortie() const;
  XmlPortie & GetPortie();
  const XmlPuntenper100 * GetPuntenper100() const;
  const XmlVoedingswaarde * GetVoedingswaarde() const;
  void Add(XmlPuntenper100 * aPuntenper100);
  void Add(XmlVoedingswaarde * aVoedingswaarde);
  std::wstring Gethoeveelheid() const;
  void Sethoeveelheid(const std::wstring & ahoeveelheid);

private:
  // Prohibit copying and assignment
  XmlStandardlot(const XmlStandardlot & anOriginal);
  XmlStandardlot & operator=(const XmlStandardlot & anOriginal);
  XmlPortie mPortie;
  XmlPuntenper100 * mPuntenper100;
  XmlVoedingswaarde * mVoedingswaarde;
  std::wstring mhoeveelheid;
};


}
