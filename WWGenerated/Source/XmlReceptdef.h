#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlReceptdef_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlReceptdef_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children

namespace ww_1_1
{
// Forward declarations
class XmlVoedingsmiddel;
class XmlRecept;
class XmlGerecht;
class XmlHandmatigitem;
class XmlReceptdef : public Generator::XmlClass
{
public:
  XmlReceptdef();
  virtual ~XmlReceptdef();

  const std::vector<XmlVoedingsmiddel *> & GetVoedingsmiddelList() const;
  const std::vector<XmlRecept *> & GetReceptList() const;
  const std::vector<XmlGerecht *> & GetGerechtList() const;
  const std::vector<XmlHandmatigitem *> & GetHandmatigitemList() const;
  void Add(XmlVoedingsmiddel * aVoedingsmiddel);
  void Add(XmlRecept * aRecept);
  void Add(XmlGerecht * aGerecht);
  void Add(XmlHandmatigitem * aHandmatigitem);
  std::wstring Getnaam() const;
  std::wstring Getporties() const;
  void Setnaam(const std::wstring & anaam);
  void Setporties(const std::wstring & aporties);

private:
  // Prohibit copying and assignment
  XmlReceptdef(const XmlReceptdef & anOriginal);
  XmlReceptdef & operator=(const XmlReceptdef & anOriginal);
  std::vector<XmlVoedingsmiddel *> mVoedingsmiddelList;
  std::vector<XmlRecept *> mReceptList;
  std::vector<XmlGerecht *> mGerechtList;
  std::vector<XmlHandmatigitem *> mHandmatigitemList;
  std::wstring mnaam;
  std::wstring mporties;
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlReceptdef_h__
