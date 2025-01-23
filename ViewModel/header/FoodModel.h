#pragma once

#include <QString>

namespace viewmodel {

class FoodModel {
public:
    FoodModel(QString name, double points)
        : m_name(std::move(name))
        , m_points(points)
    {
    }

    const QString& getName() const { return m_name; }
    double getPoints() const { return m_points; }

private:
    QString m_name;
    double m_points;
};

} //  namespace viewmodel