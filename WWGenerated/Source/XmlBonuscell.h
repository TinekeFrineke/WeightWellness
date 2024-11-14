#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlBonuscell_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlBonuscell_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
namespace ww_1_1
{
class XmlBonuscell : public Generator::XmlClass
{
public:
  enum intensiteit
  {
    intensiteit_laag,
    intensiteit_middel,
    intensiteit_hoog
  };

  XmlBonuscell();
  virtual ~XmlBonuscell();

  int Getgewicht() const;
  intensiteit Getintensiteit() const;
  int Getminuten() const;
  int Getpunten() const;
  void Setgewicht(int agewicht);
  void Setintensiteit(intensiteit aintensiteit);
  void Setminuten(int aminuten);
  void Setpunten(int apunten);

private:
  // Prohibit copying and assignment
  XmlBonuscell(const XmlBonuscell & anOriginal);
  XmlBonuscell & operator=(const XmlBonuscell & anOriginal);
  int mgewicht;
  intensiteit mintensiteit;
  int mminuten;
  int mpunten;
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlBonuscell_h__
