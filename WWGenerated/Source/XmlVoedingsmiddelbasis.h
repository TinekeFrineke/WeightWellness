#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlVoedingsmiddelbasis_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlVoedingsmiddelbasis_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
#include "XmlVoedingsmiddelheader.h"

namespace ww_1_1
{
// Forward declarations
class XmlVoedingsmiddelbasis : public Generator::XmlClass
{
public:
  enum vrijeportie
  {
    vrijeportie_true,
    vrijeportie_false
  };

  enum vrijeppportie
  {
    vrijeppportie_true,
    vrijeppportie_false
  };

  XmlVoedingsmiddelbasis();
  virtual ~XmlVoedingsmiddelbasis();

  const XmlVoedingsmiddelheader & GetVoedingsmiddelheader() const;
  XmlVoedingsmiddelheader & GetVoedingsmiddelheader();
  std::wstring Getsterreportie() const;
  vrijeportie Getvrijeportie() const;
  std::wstring Getvrijepunten() const;
  vrijeppportie Getvrijeppportie() const;
  std::wstring Getvrijepppunten() const;
  void Setsterreportie(const std::wstring & asterreportie);
  void Setvrijeportie(vrijeportie avrijeportie);
  void Setvrijepunten(const std::wstring & avrijepunten);
  void Setvrijeppportie(vrijeppportie avrijeppportie);
  void Setvrijepppunten(const std::wstring & avrijepppunten);

private:
  // Prohibit copying and assignment
  XmlVoedingsmiddelbasis(const XmlVoedingsmiddelbasis & anOriginal);
  XmlVoedingsmiddelbasis & operator=(const XmlVoedingsmiddelbasis & anOriginal);
  XmlVoedingsmiddelheader mVoedingsmiddelheader;
  std::wstring msterreportie;
  vrijeportie mvrijeportie;
  std::wstring mvrijepunten;
  vrijeppportie mvrijeppportie;
  std::wstring mvrijepppunten;
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlVoedingsmiddelbasis_h__
