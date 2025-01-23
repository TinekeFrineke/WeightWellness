
#pragma once

#include <QObject>
#include <QAbstractListModel>
#include <QList>

#include "IFoodListModel.h"

namespace viewmodel {

class FoodModel;

class FoodListModel
    : public IFoodListModel {
    Q_OBJECT

public:
    enum FoodRoles {
        NameRole = Qt::UserRole + 1,
        PointsRole
    };

    explicit FoodListModel(QObject* parent = nullptr);

    void addFood(const FoodModel& model);

    Q_INVOKABLE QVariantList getFoodsForQML() const;

    Q_INVOKABLE void remove(int index, int count = 1);

    Q_INVOKABLE void push(const QString& name, double points);

    //Q_INVOKABLE void print();

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation,
                                            int role = Qt::DisplayRole) const override;
protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<FoodModel> m_foods;
};

} // namespace viewmodel