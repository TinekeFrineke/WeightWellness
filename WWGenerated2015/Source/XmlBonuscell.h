#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
namespace ww2015
{
class XmlBonuscell : public XmlClass
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
