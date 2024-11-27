#pragma once

namespace WW
{
  class Voedingsmiddel : public Item
  {
  public:
    Voedingsmiddel(const std::wstring & aName) : Item(aName) {}
    virtual       ~Voedingsmiddel() {}

    virtual int   GetPoints() const;
  };
}
