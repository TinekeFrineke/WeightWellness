#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlPersonalia_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlPersonalia_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
namespace ww_1_1
{
class XmlPersonalia : public Generator::XmlClass
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

  enum streven
  {
    streven_Afvallen,
    streven_OpGewichtBlijven,
    streven_Lopend,
    streven_Zwaar
  };

  enum strategie
  {
    strategie_FlexiPoints,
    strategie_ProPoints,
    strategie_KCal,
    strategie_CarboHydrates
  };

  XmlPersonalia();
  virtual ~XmlPersonalia();

  std::wstring Getnaam() const;
  std::wstring Getgebruikersnaam() const;
  std::wstring Getpunten() const;
  std::wstring Getpppunten() const;
  std::wstring Getppweekpunten() const;
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
  streven Getstreven() const;
  strategie Getstrategie() const;
  void Setnaam(const std::wstring & anaam);
  void Setgebruikersnaam(const std::wstring & agebruikersnaam);
  void Setpunten(const std::wstring & apunten);
  void Setpppunten(const std::wstring & apppunten);
  void Setppweekpunten(const std::wstring & appweekpunten);
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
  void Setstreven(streven astreven);
  void Setstrategie(strategie astrategie);

private:
  // Prohibit copying and assignment
  XmlPersonalia(const XmlPersonalia & anOriginal);
  XmlPersonalia & operator=(const XmlPersonalia & anOriginal);
  std::wstring mnaam;
  std::wstring mgebruikersnaam;
  std::wstring mpunten;
  std::wstring mpppunten;
  std::wstring mppweekpunten;
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
  streven mstreven;
  strategie mstrategie;
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlPersonalia_h__
