#pragma once

#include "model/Item.h"

namespace weight
{
class IModel;
class ReceptDefinitie;

template<typename TYPE> class IRepository;
}

class CWnd;

class ItemEditVisitor: public weight::ItemVisitor
{
public:
    ItemEditVisitor(weight::IModel& aModel,
                    std::shared_ptr<weight::IRepository<weight::ReceptDefinitie>> recipes,
                    CWnd* aParent) : mModel(aModel), m_recipes(recipes), mParent(aParent) {}

    virtual void          Visit(weight::Recept& aRecept);
    virtual void          Visit(weight::Voedingsmiddel& aVoedingsmiddel);
    virtual void          Visit(weight::ManualItem& anItem);

private:
    weight::IModel& mModel;
    std::shared_ptr<weight::IRepository<weight::ReceptDefinitie>> m_recipes;
    CWnd* mParent;
};
