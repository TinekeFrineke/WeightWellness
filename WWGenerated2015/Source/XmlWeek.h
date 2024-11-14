#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children

namespace ww2015
{
// Forward declarations
class XmlDag;
class XmlWeek : public XmlClass
{
public:
  enum strategie
  {
    strategie_FlexiPoints,
    strategie_ProPoints,
    strategie_KCal,
    strategie_Koolhydraten
  };

  XmlWeek();
  virtual ~XmlWeek();

  const std::vector<XmlDag *> & GetDagList() const;
  void Add(XmlDag * aDag);
  std::wstring Getbegindatum() const;
  std::wstring Geteinddatum() const;
  int Getpunten() const;
  int Getweekpunten() const;
  std::wstring Getstartweight() const;
  strategie Getstrategie() const;
  void Setbegindatum(const std::wstring & abegindatum);
  void Seteinddatum(const std::wstring & aeinddatum);
  void Setpunten(int apunten);
  void Setweekpunten(int aweekpunten);
  void Setstartweight(const std::wstring & astartweight);
  void Setstrategie(strategie astrategie);

private:
  // Prohibit copying and assignment
  XmlWeek(const XmlWeek & anOriginal);
  XmlWeek & operator=(const XmlWeek & anOriginal);
  std::vector<XmlDag *> mDagList;
  std::wstring mbegindatum;
  std::wstring meinddatum;
  int mpunten;
  int mweekpunten;
  std::wstring mstartweight;
  strategie mstrategie;
};


}
