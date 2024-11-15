#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
#include "XmlVoedingsmiddelheader.h"

namespace ww2019
{
// Forward declarations
class XmlPortie;
class XmlPuntenper100;
class XmlVoedingswaarde;
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

  const std::vector<XmlPortie *> & GetPortieList() const;
  const XmlPuntenper100 * GetPuntenper100() const;
  const XmlVoedingsmiddelheader & GetVoedingsmiddelheader() const;
  XmlVoedingsmiddelheader & GetVoedingsmiddelheader();
  const XmlVoedingswaarde * GetVoedingswaarde() const;
  void Add(XmlPortie * aPortie);
  void Add(XmlPuntenper100 * aPuntenper100);
  void Add(XmlVoedingswaarde * aVoedingswaarde);
  favoriet Getfavoriet() const;
  void Setfavoriet(favoriet afavoriet);

private:
  // Prohibit copying and assignment
  XmlVoedingsmiddeldef(const XmlVoedingsmiddeldef & anOriginal);
  XmlVoedingsmiddeldef & operator=(const XmlVoedingsmiddeldef & anOriginal);
  std::vector<XmlPortie *> mPortieList;
  XmlPuntenper100 * mPuntenper100;
  XmlVoedingsmiddelheader mVoedingsmiddelheader;
  XmlVoedingswaarde * mVoedingswaarde;
  favoriet mfavoriet;
};


}
