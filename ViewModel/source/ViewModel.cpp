
#include "ViewModel.h"

#include "model/Day.h"
#include "model/Model.h"
#include "model/Week.h"
#include "Utilities/strutils.h"

#include "IPersonalData.h"
#include "IViewModelDay.h"
#include "IViewModelWeek.h"
#include "ViewModelUtilities.h"


namespace viewmodel
{

namespace {

}

ViewModel::ViewModel(const Utils::Date& currentDate,
                     std::shared_ptr<weight::Model> model,
                     std::unique_ptr<IPersonalData> data,
                     std::unique_ptr<IViewModelDay> day,
                     std::unique_ptr<IViewModelWeek> week,
                     QObject* parent)
    : IViewModel(parent)
    , m_model(std::move(model))
    , m_personalData(std::move(data))
    , m_day(std::move(day))
    , m_week(std::move(week))
    , m_currentDate(currentDate)
{
}

ViewModel::~ViewModel()
{
}

void ViewModel::DayMinusOne()
{
    auto newDate(m_currentDate);
    newDate.SubtractDays(1);

    UpdateDate(newDate);
}

void ViewModel::DayPlusOne()
{
    auto newDate(m_currentDate);
    newDate.AddDays(1);

    UpdateDate(newDate);
}

void ViewModel::endDatePlusOne()
{
    auto endDate = m_week->getWeek()->GetEndDate();
    endDate.AddDays(1);
    if (m_model->SetEndDate(*m_week->getWeek(), endDate))
        emit endDateChanged(Str::ToString(ToString(m_week->getWeek()->GetEndDate())).c_str());
}

void ViewModel::endDateMinusOne()
{
    auto endDate = m_week->getWeek()->GetEndDate();
    endDate.SubtractDays(1);
    if (m_model->SetEndDate(*m_week->getWeek(), endDate))
        emit endDateChanged(Str::ToString(ToString(m_week->getWeek()->GetEndDate())).c_str());
}

void ViewModel::UpdateDate(const Utils::Date& date)
{
    if (m_currentDate == date)
        return;

    if (date > Utils::Date::Today()) {
        emit dateChanged(Str::ToString(ToString(m_currentDate)).c_str());
        return;
    }

    std::cout << "ViewModel::UpdateDate to " << Str::ToString(ToString(date)) << '\n';

    m_currentDate = date;
    auto week = getOrCreateWeek(*m_model, date);
    auto day = getOrCreateDay(*m_model, *week, date);

    m_day->setDay(day);
    m_week->setWeek(week);

    emit dateChanged(Str::ToString(ToString(m_currentDate)).c_str());
}

QString ViewModel::currentDate() const
{
    return Str::ToString(ToString(m_currentDate)).c_str();
}

void ViewModel::setCurrentDate(const QString& date)
{
    auto modelDate = Utils::ToDate(date.toStdWString());
    UpdateDate(modelDate);
}

IPersonalData* ViewModel::GetPersonalData()
{
    return m_personalData.get();
}

IDay* ViewModel::GetDay()
{
    return m_day.get();
}

IWeek* ViewModel::GetWeek()
{
    return m_week.get();
}


QString ViewModel::startDate() const
{
    return Str::ToString(ToString(m_week->getWeek()->GetStartDate())).c_str();
}

QString ViewModel::endDate() const
{
    return Str::ToString(ToString(m_week->getWeek()->GetEndDate())).c_str();
}

void ViewModel::setEndDate(const QString& date)
{
    m_model->SetEndDate(*m_week->getWeek(), Utils::ToDate(date.toStdWString()));
}

double ViewModel::pointsLeft() const
{
    return m_week->getWeek()->GetPointsLeft(m_currentDate);
}

double ViewModel::weekPointsLeft() const
{
    return m_week->getWeek()->GetWeekPointsLeft(m_currentDate);
}

} // namespace viewmodel
