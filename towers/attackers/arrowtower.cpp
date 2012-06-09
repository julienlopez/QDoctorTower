#include "arrowtower.hpp"
#include <towers/towerfactory.hpp>

const quint8 ArrowTower::s_idType = 1;

const QString ArrowTower::s_icone = "arrow_tower.png";

ArrowTower::ArrowTower(const QPoint& p): Attacker(p)
{}

bool ArrowTower::canGoOnWater() const
{
    return false;
}

void ArrowTower::tirer()
{

}

namespace
{
Tower* createArrowTower(const QPoint& p) {
    return new ArrowTower(p);
}
}

const bool ArrowTower::s_registered = TowerFactory::registerTower(ArrowTower::s_idType, &createArrowTower, s_icone);
