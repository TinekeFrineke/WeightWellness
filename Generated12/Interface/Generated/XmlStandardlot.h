#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
#include "XmlPortie.h"

namespace ww_1_2
{
// Forward declarations
class XmlVoedingswaarde;
class XmlPuntenper100;
class XmlStandardlot : public XmlClass
{
public:
  enum sterrelot
  {
    sterrelot_true,
    sterrelot_false
  };

  XmlStandardlot();
  virtual ~XmlStandardlot();

  const XmlVoedingswaarde * GetVoedingswaarde() const;
  const XmlPortie & GetPortie() const;
  XmlPortie & GetPortie();
  const XmlPuntenper100 * GetPuntenper100() const;
  void Add(XmlVoedingswaarde * aVoedingswaarde);
  void Add(XmlPuntenper100 * aPuntenper100);
  sterrelot Getsterrelot() const;
  std::wstring Gethoeveelheid() const;
  void Setsterrelot(sterrelot asterrelot);
  void Sethoeveelheid(const std::wstring & ahoeveelheid);

private:
  // Prohibit copying and assignment
  XmlStandardlot(const XmlStandardlot & anOriginal);
  XmlStandardlot & operator=(const XmlStandardlot & anOriginal);
  XmlVoedingswaarde * mVoedingswaarde;
  XmlPortie mPortie;
  XmlPuntenper100 * mPuntenper100;
  sterrelot msterrelot;
  std::wstring mhoeveelheid;
};


}
