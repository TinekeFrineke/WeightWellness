#pragma once

#include "model/Item.h"

namespace weight
{
class IModel;
class ReceptDefinitie;
class VMDefinitie;

template<typename TYPE> class IRepository;
}

class CWnd;

class ItemEditVisitor: public weight::ItemVisitor
{
public:
    ItemEditVisitor(std::shared_ptr<weight::IRepository<weight::ReceptDefinitie>> recipes,
                    std::shared_ptr<weight::IRepository<weight::VMDefinitie>> foodDefinitions,
                    std::shared_ptr<weight::PointsCalculator> calculator,
                    CWnd* aParent);

    virtual void          Visit(weight::Recept& aRecept);
    virtual void          Visit(weight::Voedingsmiddel& aVoedingsmiddel);
    virtual void          Visit(weight::ManualItem& anItem);

private:
    std::shared_ptr<weight::IRepository<weight::ReceptDefinitie>> m_recipes;
    std::shared_ptr<weight::IRepository<weight::VMDefinitie>> m_foodDefinitions;
    std::shared_ptr<weight::PointsCalculator> m_calculator;
    CWnd* mParent;
};
