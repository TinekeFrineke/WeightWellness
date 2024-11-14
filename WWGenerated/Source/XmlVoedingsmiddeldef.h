#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlVoedingsmiddeldef_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlVoedingsmiddeldef_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
#include "XmlVoedingsmiddelbasis.h"

namespace ww_1_1
{
// Forward declarations
class XmlPortie;
class XmlVoedingswaarde;
class XmlPuntenper100;
class XmlVoedingsmiddeldef : public Generator::XmlClass
{
public:
  enum favoriet
  {
    favoriet_true,
    favoriet_false
  };

  XmlVoedingsmiddeldef();
  virtual ~XmlVoedingsmiddeldef();

  const XmlVoedingsmiddelbasis & GetVoedingsmiddelbasis() const;
  XmlVoedingsmiddelbasis & GetVoedingsmiddelbasis();
  const std::vector<XmlPortie *> & GetPortieList() const;
  const XmlVoedingswaarde * GetVoedingswaarde() const;
  const XmlPuntenper100 * GetPuntenper100() const;
  void Add(XmlPortie * aPortie);
  void Add(XmlVoedingswaarde * aVoedingswaarde);
  void Add(XmlPuntenper100 * aPuntenper100);
  favoriet Getfavoriet() const;
  void Setfavoriet(favoriet afavoriet);

private:
  // Prohibit copying and assignment
  XmlVoedingsmiddeldef(const XmlVoedingsmiddeldef & anOriginal);
  XmlVoedingsmiddeldef & operator=(const XmlVoedingsmiddeldef & anOriginal);
  XmlVoedingsmiddelbasis mVoedingsmiddelbasis;
  std::vector<XmlPortie *> mPortieList;
  XmlVoedingswaarde * mVoedingswaarde;
  XmlPuntenper100 * mPuntenper100;
  favoriet mfavoriet;
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlVoedingsmiddeldef_h__
