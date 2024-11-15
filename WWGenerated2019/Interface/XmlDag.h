#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children

namespace ww2019
{
// Forward declarations
class XmlBonuscell;
class XmlGerecht;
class XmlHandmatigitem;
class XmlVoedingsmiddel;
class XmlRecept;
class XmlDag : public XmlClass
{
public:
  XmlDag();
  virtual ~XmlDag();

  const std::vector<XmlBonuscell *> & GetBonuscellList() const;
  const std::vector<XmlGerecht *> & GetGerechtList() const;
  const std::vector<XmlHandmatigitem *> & GetHandmatigitemList() const;
  const std::vector<XmlVoedingsmiddel *> & GetVoedingsmiddelList() const;
  const std::vector<XmlRecept *> & GetReceptList() const;
  void Add(XmlBonuscell * aBonuscell);
  void Add(XmlGerecht * aGerecht);
  void Add(XmlHandmatigitem * aHandmatigitem);
  void Add(XmlVoedingsmiddel * aVoedingsmiddel);
  void Add(XmlRecept * aRecept);
  std::wstring Getbonuspunten() const;
  std::wstring Getdatum() const;
  std::wstring Getgewicht() const;
  void Setbonuspunten(const std::wstring & abonuspunten);
  void Setdatum(const std::wstring & adatum);
  void Setgewicht(const std::wstring & agewicht);

private:
  // Prohibit copying and assignment
  XmlDag(const XmlDag & anOriginal);
  XmlDag & operator=(const XmlDag & anOriginal);
  std::vector<XmlBonuscell *> mBonuscellList;
  std::vector<XmlGerecht *> mGerechtList;
  std::vector<XmlHandmatigitem *> mHandmatigitemList;
  std::vector<XmlVoedingsmiddel *> mVoedingsmiddelList;
  std::vector<XmlRecept *> mReceptList;
  std::wstring mbonuspunten;
  std::wstring mdatum;
  std::wstring mgewicht;
};


}
