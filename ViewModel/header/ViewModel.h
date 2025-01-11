
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
    explicit ViewModel(std::shared_ptr<weight::Model> model,
                       std::shared_ptr<IPersonalData> data,
                       std::shared_ptr<IDay> day,
                       std::shared_ptr<IWeek> week,
                       QObject* parent = nullptr);

public slots:
    void onItemClicked(int index);
    void onItemDoubleClicked(int index);

private:
    std::shared_ptr<weight::Model> m_model;
    std::shared_ptr<IDay> m_personalData;
    std::shared_ptr<IDay> m_day;
    std::shared_ptr<IDay> m_week;
};

} // namespace viewmodel
