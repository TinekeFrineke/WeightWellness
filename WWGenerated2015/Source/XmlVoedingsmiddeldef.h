#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
#include "XmlVoedingsmiddelheader.h"

namespace ww2015
{
// Forward declarations
class XmlVoedingswaarde;
class XmlPuntenper100;
class XmlPortie;
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
  const XmlPuntenper100 * GetPuntenper100() const;
  const XmlVoedingsmiddelheader & GetVoedingsmiddelheader() const;
  XmlVoedingsmiddelheader & GetVoedingsmiddelheader();
  const std::vector<XmlPortie *> & GetPortieList() const;
  void Add(XmlVoedingswaarde * aVoedingswaarde);
  void Add(XmlPuntenper100 * aPuntenper100);
  void Add(XmlPortie * aPortie);
  favoriet Getfavoriet() const;
  void Setfavoriet(favoriet afavoriet);

private:
  // Prohibit copying and assignment
  XmlVoedingsmiddeldef(const XmlVoedingsmiddeldef & anOriginal);
  XmlVoedingsmiddeldef & operator=(const XmlVoedingsmiddeldef & anOriginal);
  XmlVoedingswaarde * mVoedingswaarde;
  XmlPuntenper100 * mPuntenper100;
  XmlVoedingsmiddelheader mVoedingsmiddelheader;
  std::vector<XmlPortie *> mPortieList;
  favoriet mfavoriet;
};


}
