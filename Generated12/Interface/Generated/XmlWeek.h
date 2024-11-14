#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children

namespace ww_1_2
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
    strategie_CarboHydrates
  };

  XmlWeek();
  virtual ~XmlWeek();

  const std::vector<XmlDag *> & GetDagList() const;
  void Add(XmlDag * aDag);
  std::wstring Getbegindatum() const;
  std::wstring Geteinddatum() const;
  std::wstring Getpunten() const;
  std::wstring Getweekpunten() const;
  std::wstring Getstartweight() const;
  strategie Getstrategie() const;
  void Setbegindatum(const std::wstring & abegindatum);
  void Seteinddatum(const std::wstring & aeinddatum);
  void Setpunten(const std::wstring & apunten);
  void Setweekpunten(const std::wstring & aweekpunten);
  void Setstartweight(const std::wstring & astartweight);
  void Setstrategie(strategie astrategie);

private:
  // Prohibit copying and assignment
  XmlWeek(const XmlWeek & anOriginal);
  XmlWeek & operator=(const XmlWeek & anOriginal);
  std::vector<XmlDag *> mDagList;
  std::wstring mbegindatum;
  std::wstring meinddatum;
  std::wstring mpunten;
  std::wstring mweekpunten;
  std::wstring mstartweight;
  strategie mstrategie;
};


}
