#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children

namespace ww2019
{
// Forward declarations
class XmlGerecht;
class XmlHandmatigitem;
class XmlVoedingsmiddel;
class XmlRecept;
class XmlReceptdef : public XmlClass
{
public:
  XmlReceptdef();
  virtual ~XmlReceptdef();

  const std::vector<XmlGerecht *> & GetGerechtList() const;
  const std::vector<XmlHandmatigitem *> & GetHandmatigitemList() const;
  const std::vector<XmlVoedingsmiddel *> & GetVoedingsmiddelList() const;
  const std::vector<XmlRecept *> & GetReceptList() const;
  void Add(XmlGerecht * aGerecht);
  void Add(XmlHandmatigitem * aHandmatigitem);
  void Add(XmlVoedingsmiddel * aVoedingsmiddel);
  void Add(XmlRecept * aRecept);
  std::wstring Getnaam() const;
  std::wstring Getporties() const;
  void Setnaam(const std::wstring & anaam);
  void Setporties(const std::wstring & aporties);

private:
  // Prohibit copying and assignment
  XmlReceptdef(const XmlReceptdef & anOriginal);
  XmlReceptdef & operator=(const XmlReceptdef & anOriginal);
  std::vector<XmlGerecht *> mGerechtList;
  std::vector<XmlHandmatigitem *> mHandmatigitemList;
  std::vector<XmlVoedingsmiddel *> mVoedingsmiddelList;
  std::vector<XmlRecept *> mReceptList;
  std::wstring mnaam;
  std::wstring mporties;
};


}
