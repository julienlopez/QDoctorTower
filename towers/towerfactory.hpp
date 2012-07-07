#ifndef TOWERFACTORY_HPP
#define TOWERFACTORY_HPP

#include <utils/factory.hpp>

#include <QMap>
#include <QString>

class Tower;
class QPoint;

class TowerFactory
{
public:
    typedef QMap<quint8, QString> type_map_icones;

    static Tower* createArrowTower(const QPoint& p);

    static Tower* createCanonTower(const QPoint& p);

    static Tower* createTower(quint8 type, const QPoint& p);

    static bool registerTower(quint8, Tower*(*)(const QPoint&), const QString& icone);

    static const type_map_icones& icones();

    static QString prefixeIcones();

private:
    typedef Factory<Tower, quint8, Tower*(*)(const QPoint&)> type_factory;

    class Nested {
    public:
        Nested();
        type_map_icones icones;
        QString s_prefix;
    };

    static Nested& get();
};

#endif // TOWERFACTORY_HPP
