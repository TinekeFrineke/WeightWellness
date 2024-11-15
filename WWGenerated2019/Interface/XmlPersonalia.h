#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
namespace ww2019
{
class XmlPersonalia : public XmlClass
{
public:
  enum geslacht
  {
    geslacht_Mannelijk,
    geslacht_Vrouwelijk
  };

  enum werk
  {
    werk_Zittend,
    werk_Staand,
    werk_Lopend,
    werk_Zwaar
  };

  enum strategie
  {
    strategie_KCal,
    strategie_CarboHydrates
  };

  XmlPersonalia();
  virtual ~XmlPersonalia();

  std::wstring Getnaam() const;
  std::wstring Getgebruikersnaam() const;
  std::wstring Getpunten() const;
  std::wstring Getkcpunten() const;
  std::wstring Getkcweekpunten() const;
  std::wstring Getgeboren() const;
  geslacht Getgeslacht() const;
  werk Getwerk() const;
  std::wstring Getlengte() const;
  std::wstring Getgewicht() const;
  std::wstring Getstreefgewicht() const;
  std::wstring Getstartgewicht() const;
  std::wstring Gethuidiggewicht() const;
  strategie Getstrategie() const;
  void Setnaam(const std::wstring & anaam);
  void Setgebruikersnaam(const std::wstring & agebruikersnaam);
  void Setpunten(const std::wstring & apunten);
  void Setkcpunten(const std::wstring & akcpunten);
  void Setkcweekpunten(const std::wstring & akcweekpunten);
  void Setgeboren(const std::wstring & ageboren);
  void Setgeslacht(geslacht ageslacht);
  void Setwerk(werk awerk);
  void Setlengte(const std::wstring & alengte);
  void Setgewicht(const std::wstring & agewicht);
  void Setstreefgewicht(const std::wstring & astreefgewicht);
  void Setstartgewicht(const std::wstring & astartgewicht);
  void Sethuidiggewicht(const std::wstring & ahuidiggewicht);
  void Setstrategie(strategie astrategie);

private:
  // Prohibit copying and assignment
  XmlPersonalia(const XmlPersonalia & anOriginal);
  XmlPersonalia & operator=(const XmlPersonalia & anOriginal);
  std::wstring mnaam;
  std::wstring mgebruikersnaam;
  std::wstring mpunten;
  std::wstring mkcpunten;
  std::wstring mkcweekpunten;
  std::wstring mgeboren;
  geslacht mgeslacht;
  werk mwerk;
  std::wstring mlengte;
  std::wstring mgewicht;
  std::wstring mstreefgewicht;
  std::wstring mstartgewicht;
  std::wstring mhuidiggewicht;
  strategie mstrategie;
};


}
