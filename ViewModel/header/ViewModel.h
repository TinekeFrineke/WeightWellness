
#pragma once

#include <QObject>
#include <QQmlApplicationEngine>

#include <memory>

#include "Utilities/Date.h"

#include "IViewModel.h"


namespace weight {
class Model;
}

namespace viewmodel
{

class IPersonalData;
class IViewModelDay;
class IViewModelWeek;

class ViewModel
    : public IViewModel {
    Q_OBJECT
public:
    ViewModel(const Utils::Date& currentDate,
              std::shared_ptr<weight::Model> model,
              std::unique_ptr<IPersonalData> data,
              std::unique_ptr<IViewModelDay> day,
              std::unique_ptr<IViewModelWeek> week,
              QObject* parent = nullptr);
    ~ViewModel() override;

    // Inherited via IViewModelWeek
    QString endDate() const override;
    void setEndDate(const QString& date) override;
    double pointsLeft() const override;
    double weekPointsLeft() const override;

    QString startDate() const override;

private:
    // Inherited via IViewModel
    IPersonalData* GetPersonalData() override;
    IDay* GetDay() override;
    IWeek* GetWeek() override;

    QString currentDate() const override;
    void setCurrentDate(const QString& date) override;

    void DayMinusOne() override;
    void DayPlusOne() override;
    void endDatePlusOne() override;
    void endDateMinusOne() override;

    void UpdateDate(const Utils::Date& date);

    std::shared_ptr<weight::Model> m_model;
    Utils::Date m_currentDate;
    std::unique_ptr<IPersonalData> m_personalData;
    std::unique_ptr<IViewModelDay> m_day;
    std::unique_ptr<IViewModelWeek> m_week;

};

} // namespace viewmodel
