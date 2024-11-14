#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlStandardlot_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlStandardlot_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
#include "XmlPortie.h"

namespace ww_1_1
{
// Forward declarations
class XmlVoedingswaarde;
class XmlPuntenper100;
class XmlStandardlot : public Generator::XmlClass
{
public:
  enum sterrelot
  {
    sterrelot_true,
    sterrelot_false
  };

  XmlStandardlot();
  virtual ~XmlStandardlot();

  const XmlPortie & GetPortie() const;
  XmlPortie & GetPortie();
  const XmlVoedingswaarde * GetVoedingswaarde() const;
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
  XmlPortie mPortie;
  XmlVoedingswaarde * mVoedingswaarde;
  XmlPuntenper100 * mPuntenper100;
  sterrelot msterrelot;
  std::wstring mhoeveelheid;
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlStandardlot_h__
