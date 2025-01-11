
#include "ViewModel.h"


namespace viewmodel
{

ViewModel::ViewModel(std::shared_ptr<weight::Model> model,
                     std::shared_ptr<IPersonalData> data,
                     std::shared_ptr<IDay> day,
                     std::shared_ptr<IWeek> week,
                     QObject* parent)
    : IViewModel(parent)
    , m_model(std::move(model))
    , m_personalData(std::move(data))
    , m_day(std::move(day))
    , m_week(std::move(week))
{
}

void ViewModel::onItemClicked(int index) {
    qDebug() << "Item clicked at index:" << index;
    // Add your logic here
}

void ViewModel::onItemDoubleClicked(int index) {
    qDebug() << "Item double-clicked at index:" << index;
    // Add your logic here
}

} // namespace viewmodel
