
#include "ViewModel.h"

#include "IPersonalData.h"
#include "IViewModelDay.h"
#include "IViewModelWeek.h"


namespace viewmodel
{

ViewModel::ViewModel(std::shared_ptr<weight::Model> model,
                     std::unique_ptr<IPersonalData> data,
                     std::unique_ptr<IViewModelDay> day,
                     std::unique_ptr<IViewModelWeek> week,
                     QObject* parent)
    : IViewModel(parent)
    , m_model(std::move(model))
    , m_personalData(std::move(data))
    , m_day(std::move(day))
    , m_week(std::move(week))
{
}

ViewModel::~ViewModel()
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
