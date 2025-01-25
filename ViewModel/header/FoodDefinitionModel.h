#pragma once

#include <QString>

namespace viewmodel {

class FoodDefinitionModel {
public:
    FoodDefinitionModel(QString name, QString category, QString unit, double pointsPer100)
        : m_name(std::move(name))
        , m_category(std::move(category))
        , m_unit(std::move(unit))
        , m_pointsPer100Units(pointsPer100)
    {
    }

    const QString& getName() const { return m_name; }
    const QString& getCategory() const { return m_category; }
    const QString& getUnit() const { return m_unit; }
    double getPoints() const { return m_pointsPer100Units; }

private:
    QString m_name;
    QString m_category;
    QString m_unit;
    double m_pointsPer100Units;
};

} // namespace viewmodel