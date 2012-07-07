#include "arrowtower.hpp"
#include <towers/towerfactory.hpp>
#include "engine/engine.hpp"
#include "bullets/fleche.hpp"

const quint8 ArrowTower::s_idType = 1;

const QString ArrowTower::s_icone = TowerFactory::prefixeIcones()+"arrow_tower.png";

ArrowTower::ArrowTower(const QPoint& p): Attacker(p)
{
    setPortee(2);
    setTempsRecharge(0.5);
}

bool ArrowTower::canGoOnWater() const
{
    return false;
}

void ArrowTower::tirer()
{
    Engine::instance()->addBullet(new Fleche(coords(), cible()));
}

QString ArrowTower::icone() const
{
    return s_icone;
}

namespace
{
Tower* createArrowTower(const QPoint& p) {
    return new ArrowTower(p);
}
}

const bool ArrowTower::s_registered = TowerFactory::registerTower(ArrowTower::s_idType, &createArrowTower, s_icone);
