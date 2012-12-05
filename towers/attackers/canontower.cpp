#include "canontower.hpp"
#include "towers/towerfactory.hpp"

const quint8 CanonTower::s_idType = 2;

const QString CanonTower::s_icone = TowerFactory::prefixeIcones()+"canon_tower.png";


CanonTower::CanonTower(const QPoint& p): Attacker(p, 100)
{
    setPortee(8);
    abilityTirer().setRechargeTime(1.5);
}

bool CanonTower::canGoOnWater() const
{
    return false;
}

void CanonTower::tirer()
{

}

const QString& CanonTower::icone() const
{
    return s_icone;
}

bool CanonTower::canLevelUp() const
{
    return false;
}

void CanonTower::levelUp()
{

}

std::string CanonTower::label() const
{
    return "Cannon Tower";
}

namespace
{
Tower* createCanonTower(const QPoint& p) {
    return new CanonTower(p);
}
}

const bool CanonTower::s_registered = TowerFactory::registerTower(CanonTower::s_idType, &createCanonTower, s_icone);
