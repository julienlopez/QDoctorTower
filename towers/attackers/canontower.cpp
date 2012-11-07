#include "canontower.hpp"
#include "towers/towerfactory.hpp"

const quint8 CanonTower::s_idType = 2;

const QString CanonTower::s_icone = TowerFactory::prefixeIcones()+"canon_tower.png";


CanonTower::CanonTower(const QPoint& p): Attacker(p, 100)
{}

bool CanonTower::canGoOnWater() const
{
    return false;
}

void CanonTower::tirer()
{

}

QString CanonTower::icone() const
{
    return s_icone;
}

namespace
{
Tower* createCanonTower(const QPoint& p) {
    return new CanonTower(p);
}
}

const bool CanonTower::s_registered = TowerFactory::registerTower(CanonTower::s_idType, &createCanonTower, s_icone);
