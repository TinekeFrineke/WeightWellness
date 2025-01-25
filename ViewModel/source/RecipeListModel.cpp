
#include "RecipeListModel.h"


#include "RecipeModel.h"

namespace viewmodel {

namespace {

enum RecipeRoles {
    NameRole = Qt::UserRole + 1,
    PointsRole
};

}

RecipeListModel::RecipeListModel(QObject* parent)
    : IRecipeListModel(parent)
{
}

void RecipeListModel::addRecipe(const RecipeModel& model)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_recipies << std::move(model);  // Move the object into the list
    endInsertRows();
}

Q_INVOKABLE QVariantList RecipeListModel::getRecipesForQML() const
{
    QVariantList recipeList;
    for (const RecipeModel& recipe : m_recipies) {
        QVariantMap recipeMap;
        recipeMap["name"] = recipe.getName();
        recipeMap["points"] = recipe.getPoints();
        recipeList.append(recipeMap);
    }
    return recipeList;
}

Q_INVOKABLE void RecipeListModel::remove(int index, int count)
{
    beginRemoveRows(QModelIndex(), index, index + count - 1);
    for (int row = 0; row < count; ++row) {
        m_recipies.removeAt(index);
    }
    endRemoveRows();
}

Q_INVOKABLE void RecipeListModel::push(const QString& name, double points)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_recipies << RecipeModel(name, points);
    endInsertRows();
}

int RecipeListModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return m_recipies.count();
}

QVariant RecipeListModel::data(const QModelIndex& index, int role) const
{
    if (index.row() < 0 || index.row() >= m_recipies.count())
        return {};

    const RecipeModel& foodModel = m_recipies[index.row()];
    switch (role) {
        case NameRole:
            return foodModel.getName();
        case PointsRole:
            return foodModel.getPoints();
        default:
            return {};
    }
}

QVariant RecipeListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    qDebug() << section << orientation << role;
    if (role != Qt::DisplayRole || orientation != Qt::Orientation::Horizontal)
        return QVariant();

    if (section == 0)
        return "Name";
    return "Points";
}

QHash<int, QByteArray> RecipeListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name"; // string
    roles[PointsRole] = "points"; // double
    return roles;
}


} // namespace viewmodel