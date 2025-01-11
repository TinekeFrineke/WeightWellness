
#pragma once

#include <QObject>
#include <QQmlApplicationEngine>

#include <memory>

#include "IViewModel.h"


namespace weight {
class Model;
}

namespace viewmodel
{

class IDay;
class IPersonalData;
class IWeek;

class ViewModel
    : public IViewModel {
    Q_OBJECT
public:
    ViewModel(std::shared_ptr<weight::Model> model,
              std::unique_ptr<IPersonalData> data,
              std::unique_ptr<IDay> day,
              std::unique_ptr<IWeek> week,
              QObject* parent = nullptr);
    ~ViewModel() override;

public slots:
    void onItemClicked(int index);
    void onItemDoubleClicked(int index);

private:
    std::shared_ptr<weight::Model> m_model;
    std::unique_ptr<IPersonalData> m_personalData;
    std::unique_ptr<IDay> m_day;
    std::unique_ptr<IWeek> m_week;
};

} // namespace viewmodel
