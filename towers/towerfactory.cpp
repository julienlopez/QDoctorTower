#include "towerfactory.hpp"
#include "attackers/arrowtower.hpp"
#include "attackers/canontower.hpp"

Tower* TowerFactory::createArrowTower(const QPoint& p)
{
    return type_factory::instance().create(ArrowTower::s_idType, p);
}

Tower* TowerFactory::createCanonTower(const QPoint& p)
{
    return type_factory::instance().create(CanonTower::s_idType, p);
}

Tower* TowerFactory::createTower(quint8 type, const QPoint& p)
{
    return type_factory::instance().create(type, p);
}

bool TowerFactory::registerTower(quint8 type, Tower*(*foncteur)(const QPoint&), const QString& icone)
{
    get().icones.insert(type, icone);
    return type_factory::instance().registerProduct(type, foncteur);
}

const TowerFactory::type_map_icones& TowerFactory::icones()
{
    return get().icones;
}

QString TowerFactory::prefixeIcones()
{
    return get().s_prefix;
}

TowerFactory::Nested& TowerFactory::get()
{
    static Nested n;
    return n;
}

TowerFactory::Nested::Nested()
{
    s_prefix = "images/icones/";
}
