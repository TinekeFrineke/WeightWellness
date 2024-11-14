#include "../Interface\Generated\stdafx.h"
#include "../Interface\Generated\XmlFreelot.h"

#include <assert.h>
#include <tchar.h>


namespace ww_1_2
{
XmlFreelot::XmlFreelot()
{
}

XmlFreelot::~XmlFreelot()
{
}

std::wstring XmlFreelot::Getpunten() const
{
  return mpunten;
}

void XmlFreelot::Setpunten(const std::wstring & apunten)
{
   mpunten = apunten;
}

}