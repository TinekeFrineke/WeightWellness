
#include "FoodListModel.h"


#include "FoodModel.h"

namespace viewmodel {


FoodListModel::FoodListModel(QObject* parent)
    : IFoodListModel(parent)
{
}

void FoodListModel::addFood(const FoodModel& model)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_foods << std::move(model);  // Move the object into the list
    endInsertRows();
}

Q_INVOKABLE QVariantList FoodListModel::getFoodsForQML() const
{
    QVariantList animalsList;
    for (const FoodModel& food : m_foods) {
        QVariantMap animalMap;
        animalMap["name"] = food.getName();
        animalMap["points"] = food.getPoints();
        animalsList.append(animalMap);
    }
    return animalsList;
}

Q_INVOKABLE void FoodListModel::remove(int index, int count)
{
    beginRemoveRows(QModelIndex(), index, index + count - 1);
    for (int row = 0; row < count; ++row) {
        m_foods.removeAt(index);
    }
    endRemoveRows();
}

Q_INVOKABLE void FoodListModel::push(const QString& name, double points)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_foods << FoodModel(name, points);
    endInsertRows();
}

//Q_INVOKABLE void FoodListModel::print()
//{
//    qDebug() << "\nPrinting from FoodListModel::print()";
//    for (const FoodModel& model : m_foods) {
//        qDebug() << model.getName() << model.getPoints();
//    }
//}

int FoodListModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return m_foods.count();
}

QVariant FoodListModel::data(const QModelIndex& index, int role) const
{
    if (index.row() < 0 || index.row() >= m_foods.count())
        return {};

    const FoodModel& foodModel = m_foods[index.row()];
    switch (role) {
        case NameRole:
            return foodModel.getName();
        case PointsRole:
            return foodModel.getPoints();
        default:
            return {};
    }
}

QVariant FoodListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    qDebug() << section << orientation << role;
    if (role != Qt::DisplayRole || orientation != Qt::Orientation::Horizontal)
        return QVariant();

    if (section == 0)
        return "Name";
    return "Points";
}

QHash<int, QByteArray> FoodListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name"; // string
    roles[PointsRole] = "points"; // double
    return roles;
}


} // namespace viewmodel