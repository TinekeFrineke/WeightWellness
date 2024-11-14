#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlVoedingsmiddeldefs_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlVoedingsmiddeldefs_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children

namespace ww_1_1
{
// Forward declarations
class XmlVoedingsmiddeldef;
class XmlVoedingsmiddeldefs : public Generator::XmlClass
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
#endif // Projects_VC10_WW_WWGenerated_XmlVoedingsmiddeldefs_h__
