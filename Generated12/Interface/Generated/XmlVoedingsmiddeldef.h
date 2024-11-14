#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
#include "XmlVoedingsmiddelbasis.h"

namespace ww_1_2
{
// Forward declarations
class XmlVoedingswaarde;
class XmlPortie;
class XmlPuntenper100;
class XmlVoedingsmiddeldef : public XmlClass
{
public:
  enum favoriet
  {
    favoriet_true,
    favoriet_false
  };

  XmlVoedingsmiddeldef();
  virtual ~XmlVoedingsmiddeldef();

  const XmlVoedingswaarde * GetVoedingswaarde() const;
  const std::vector<XmlPortie *> & GetPortieList() const;
  const XmlPuntenper100 * GetPuntenper100() const;
  const XmlVoedingsmiddelbasis & GetVoedingsmiddelbasis() const;
  XmlVoedingsmiddelbasis & GetVoedingsmiddelbasis();
  void Add(XmlVoedingswaarde * aVoedingswaarde);
  void Add(XmlPortie * aPortie);
  void Add(XmlPuntenper100 * aPuntenper100);
  favoriet Getfavoriet() const;
  void Setfavoriet(favoriet afavoriet);

private:
  // Prohibit copying and assignment
  XmlVoedingsmiddeldef(const XmlVoedingsmiddeldef & anOriginal);
  XmlVoedingsmiddeldef & operator=(const XmlVoedingsmiddeldef & anOriginal);
  XmlVoedingswaarde * mVoedingswaarde;
  std::vector<XmlPortie *> mPortieList;
  XmlPuntenper100 * mPuntenper100;
  XmlVoedingsmiddelbasis mVoedingsmiddelbasis;
  favoriet mfavoriet;
};


}
