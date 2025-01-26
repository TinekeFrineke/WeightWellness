
#include "Day.h"

#include "model/Item.h"

#include "FoodListModel.h"
#include "FoodModel.h"

namespace viewmodel {


Day::Day(std::shared_ptr<weight::Model> model, QObject* parent)
    : IViewModelDay(parent)
    , m_model(std::move(model))
    , m_foodListmodel(std::make_unique<FoodListModel>(nullptr))
{
}

void Day::setDay(weight::Day* day)
{
    if (day == m_day)
        return;

    m_day = day;
    emit weightChanged(m_day->GetWeight());

    if (m_foodListmodel->rowCount() > 0)
        m_foodListmodel->remove(0, m_foodListmodel->rowCount());

    for (const auto& item : m_day->GetItems())
        m_foodListmodel->addFood(FoodModel(QString(item->GetName().c_str()), item->GetPoints()));
}

const weight::Day* Day::getDay() const
{
    return m_day;
}

double Day::weight() const
{
    return m_day->GetWeight();
}

void Day::setWeight(double weight)
{
    m_day->SetWeight(weight);
}

double Day::freeBonus() const
{
    return m_day->GetFreeBonusPoints();
}

void Day::setFreeBonus(double bonus)
{
    m_day->SetFreeBonusPoints(bonus);
}

double Day::totalPointsSpent() const
{
    return m_day->GetPoints();
}

void Day::handleItemDoubleClicked(int index)
{
    auto item = m_foodListmodel->getAtIndex(index);
    if (item)
        qDebug() << "Day::handleItemDoubleClicked(" << index << ") item == " << item->getName() << " / " << item->getPoints();
    else
        qDebug() << "Day::handleItemDoubleClicked(" << index << ") no item";
}

void Day::handleEditFood(int index)
{
    auto item = m_foodListmodel->getAtIndex(index);
    if (item)
        qDebug() << "Day::handleEditFoodItem(" << index << ") item == " << item->getName() << " / " << item->getPoints();
    else
        qDebug() << "Day::handleEditFoodItem(" << index << ") no item";
}


} // namespace viewmodel