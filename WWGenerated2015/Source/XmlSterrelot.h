#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
namespace ww2015
{
class XmlSterrelot : public XmlClass
{
public:
  XmlSterrelot();
  virtual ~XmlSterrelot();

  std::wstring Getvoedingsmiddel() const;
  std::wstring Getportie() const;
  std::wstring Gethoeveelheid() const;
  void Setvoedingsmiddel(const std::wstring & avoedingsmiddel);
  void Setportie(const std::wstring & aportie);
  void Sethoeveelheid(const std::wstring & ahoeveelheid);

private:
  // Prohibit copying and assignment
  XmlSterrelot(const XmlSterrelot & anOriginal);
  XmlSterrelot & operator=(const XmlSterrelot & anOriginal);
  std::wstring mvoedingsmiddel;
  std::wstring mportie;
  std::wstring mhoeveelheid;
};


}
