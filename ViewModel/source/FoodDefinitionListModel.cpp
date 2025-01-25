
#include "FoodDefinitionListModel.h"


#include "FoodDefinitionModel.h"

namespace viewmodel {

namespace {
enum DefinitionRoles {
    NameRole = Qt::UserRole + 1,
    CategoryRole,
    UnitRole,
    PointsRole
};

}

FoodDefinitionListModel::FoodDefinitionListModel(QObject* parent)
    : IFoodDefinitionListModel(parent)
{
}

void FoodDefinitionListModel::addDefinition(const FoodDefinitionModel& model)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_definition << std::move(model);  // Move the object into the list
    endInsertRows();
}

Q_INVOKABLE QVariantList FoodDefinitionListModel::getFoodDefinitionsForQML() const
{
    QVariantList foodDefinitionList;
    for (const FoodDefinitionModel& definition : m_definition) {
        QVariantMap definitionMap;
        definitionMap["name"] = definition.getName();
        definitionMap["category"] = definition.getCategory();
        definitionMap["unit"] = definition.getUnit();
        definitionMap["points"] = definition.getPoints();
        foodDefinitionList.append(definitionMap);
    }
    return foodDefinitionList;
}

Q_INVOKABLE void FoodDefinitionListModel::remove(int index, int count)
{
    beginRemoveRows(QModelIndex(), index, index + count - 1);
    for (int row = 0; row < count; ++row) {
        m_definition.removeAt(index);
    }
    endRemoveRows();
}

Q_INVOKABLE void FoodDefinitionListModel::push(const QString& name, const QString& category, const QString& unit, double points)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_definition << FoodDefinitionModel(name, category, unit, points);
    endInsertRows();
}

int FoodDefinitionListModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return m_definition.count();
}

QVariant FoodDefinitionListModel::data(const QModelIndex& index, int role) const
{
    if (index.row() < 0 || index.row() >= m_definition.count())
        return {};

    const FoodDefinitionModel& definitionModel = m_definition[index.row()];
    switch (role) {
        case NameRole:
            return definitionModel.getName();
        case CategoryRole:
            return definitionModel.getCategory();
        case UnitRole:
            return definitionModel.getUnit();
        case PointsRole:
            return definitionModel.getPoints();
        default:
            return {};
    }
}

QVariant FoodDefinitionListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    qDebug() << section << orientation << role;
    if (role != Qt::DisplayRole || orientation != Qt::Orientation::Horizontal)
        return QVariant();

    if (section == 0)
        return "Name";
    return "Points";
}

QHash<int, QByteArray> FoodDefinitionListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name"; // string
    roles[CategoryRole] = "category"; // double
    roles[UnitRole] = "unit"; // double
    roles[PointsRole] = "points"; // double
    return roles;
}


} // namespace viewmodel