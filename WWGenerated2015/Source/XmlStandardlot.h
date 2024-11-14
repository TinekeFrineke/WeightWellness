#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
#include "XmlPortie.h"

namespace ww2015
{
// Forward declarations
class XmlVoedingswaarde;
class XmlPuntenper100;
class XmlStandardlot : public XmlClass
{
public:
  XmlStandardlot();
  virtual ~XmlStandardlot();

  const XmlVoedingswaarde * GetVoedingswaarde() const;
  const XmlPuntenper100 * GetPuntenper100() const;
  const XmlPortie & GetPortie() const;
  XmlPortie & GetPortie();
  void Add(XmlVoedingswaarde * aVoedingswaarde);
  void Add(XmlPuntenper100 * aPuntenper100);
  std::wstring Gethoeveelheid() const;
  void Sethoeveelheid(const std::wstring & ahoeveelheid);

private:
  // Prohibit copying and assignment
  XmlStandardlot(const XmlStandardlot & anOriginal);
  XmlStandardlot & operator=(const XmlStandardlot & anOriginal);
  XmlVoedingswaarde * mVoedingswaarde;
  XmlPuntenper100 * mPuntenper100;
  XmlPortie mPortie;
  std::wstring mhoeveelheid;
};


}
