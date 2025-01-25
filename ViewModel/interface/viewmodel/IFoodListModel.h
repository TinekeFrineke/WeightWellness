
#pragma once

#include <QObject>
#include <QAbstractListModel>
#include <QList>


namespace viewmodel {

class FoodModel;

class IFoodListModel: public QAbstractListModel {
    Q_OBJECT

public:
    //enum FoodRoles {
    //    NameRole = Qt::UserRole + 1,
    //    PointsRole
    //};

    explicit IFoodListModel(QObject* parent = nullptr) : QAbstractListModel(parent) {}

    virtual void addFood(const FoodModel& model) = 0;
    Q_INVOKABLE virtual  QVariantList getFoodsForQML() const = 0;
    Q_INVOKABLE virtual void remove(int index, int count = 1) = 0;
    Q_INVOKABLE virtual void push(const QString& name, double points) = 0;
};

} // namespace viewmodel