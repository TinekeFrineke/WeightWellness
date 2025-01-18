
#pragma once


#include <QObject>

namespace viewmodel
{

class IDay;
class IPersonalData;
class IWeek;

class IViewModel
    : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString currentDate READ currentDate WRITE setCurrentDate NOTIFY dateChanged)
    Q_PROPERTY(QString startDate READ startDate NOTIFY startDateChanged)
    Q_PROPERTY(QString endDate READ endDate WRITE setEndDate NOTIFY endDateChanged)
    Q_PROPERTY(double pointsLeft READ pointsLeft NOTIFY pointsLeftChanged)
    Q_PROPERTY(double weekPointsLeft READ weekPointsLeft NOTIFY weekPointsLeftChanged)

    virtual QString currentDate() const = 0;
    virtual void setCurrentDate(const QString& date) = 0;
    virtual QString startDate() const = 0;
    virtual QString endDate() const = 0;
    virtual void setEndDate(const QString& date) = 0;

    virtual double pointsLeft() const = 0;
    virtual double weekPointsLeft() const = 0;

public:
    virtual ~IViewModel() = default;
    IViewModel(QObject* parent) : QObject(parent) {}

    virtual IPersonalData* GetPersonalData() = 0;
    virtual IDay* GetDay() = 0;
    virtual IWeek* GetWeek() = 0;


signals:
    void dateChanged(const QString& newDate);
    void strategyChanged(QString newStrategy);
    void startDateChanged(const QString& newDate);
    void endDateChanged(const QString& newDate);
    void pointsLeftChanged(double points);
    void weekPointsLeftChanged(double points);

public slots:
    virtual void DayPlusOne() = 0;
    virtual void DayMinusOne() = 0;
    virtual void endDatePlusOne() = 0;
    virtual void endDateMinusOne() = 0;
};


} // namespace viewmodel