#pragma once

#include "model/Item.h"

namespace weight
{
class Model;
}

class CWnd;

class ItemEditVisitor : public weight::ItemVisitor
{
public:
                        ItemEditVisitor(weight::Model & aModel, CWnd * aParent) : mModel(aModel), mParent(aParent) {}

  virtual void          Visit(weight::Recept & aRecept);
  virtual void          Visit(weight::Voedingsmiddel & aVoedingsmiddel);
  virtual void          Visit(weight::ManualItem & anItem);

private:
  weight::Model& mModel;
  CWnd* mParent;
};
