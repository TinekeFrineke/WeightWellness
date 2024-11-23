#pragma once

#include "model/Item.h"

namespace WW
{
class Model;
}

class CWnd;

class ItemEditVisitor : public WW::ItemVisitor
{
public:
                        ItemEditVisitor(WW::Model & aModel, CWnd * aParent) : mModel(aModel), mParent(aParent) {}

  virtual void          Visit(WW::Recept & aRecept);
  virtual void          Visit(WW::Gerecht & aGerecht);
  virtual void          Visit(WW::Voedingsmiddel & aVoedingsmiddel);
  virtual void          Visit(WW::ManualItem & anItem);

private:
  WW::Model &           mModel;
  CWnd *                mParent;
};
