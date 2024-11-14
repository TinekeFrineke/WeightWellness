#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children

namespace ww2015
{
// Forward declarations
class XmlVoedingsmiddeldef;
class XmlVoedingsmiddeldefs : public XmlClass
{
public:
  XmlVoedingsmiddeldefs();
  virtual ~XmlVoedingsmiddeldefs();

  const std::vector<XmlVoedingsmiddeldef *> & GetVoedingsmiddeldefList() const;
  void Add(XmlVoedingsmiddeldef * aVoedingsmiddeldef);

private:
  // Prohibit copying and assignment
  XmlVoedingsmiddeldefs(const XmlVoedingsmiddeldefs & anOriginal);
  XmlVoedingsmiddeldefs & operator=(const XmlVoedingsmiddeldefs & anOriginal);
  std::vector<XmlVoedingsmiddeldef *> mVoedingsmiddeldefList;
};


}
