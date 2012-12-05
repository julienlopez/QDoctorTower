#include "arrowtower.hpp"
#include <towers/towerfactory.hpp>
#include "engine/engine.hpp"
#include "bullets/fleche.hpp"

const quint8 ArrowTower::s_idType = 1;

const QString ArrowTower::s_icone = TowerFactory::prefixeIcones()+"arrow_tower.png";

ArrowTower::ArrowTower(const QPoint& p, double range, double rechargeTime, quint32 cost): Attacker(p, cost)
{
    setPortee(range);
    abilityTirer().setRechargeTime(rechargeTime);
}

void ArrowTower::affecteValues(const ArrowTower* at)
{
    setCost(at->cost());
    setPortee(at->portee());
    abilityTirer().setRechargeTime(at->abilityTirer().rechargeTime());
}

bool ArrowTower::canGoOnWater() const
{
    return false;
}

void ArrowTower::tirer()
{
    Engine::instance()->addBullet(Engine::sp_bullet(new Fleche(coords(), cible())));
}

const QString& ArrowTower::icone() const
{
    return s_icone;
}

bool ArrowTower::canLevelUp() const
{
    return s_levels.find(level()+1) != s_levels.end();
}

#include <QDebug>

void ArrowTower::levelUp()
{
    qDebug() << "ArrowTower::levelUp() (" << level() << ")";
    type_containr_levels::const_iterator i = s_levels.find(level()+1);
    if(i == s_levels.end()) return;
    qDebug() << "trouvé";
    affecteValues(i->second.get());
    setLevel(i->first);
}

std::string ArrowTower::label() const
{
    return "Arrow Tower";
}

namespace
{
Tower* createArrowTower(const QPoint& p) {
    return new ArrowTower(p);
}

ArrowTower::type_containr_levels initTowerLevels()
{
    ArrowTower::type_containr_levels res;
    res.insert(std::make_pair(1, new ArrowTower(QPoint())));
    res.insert(std::make_pair(2, new ArrowTower(QPoint(), 5.1, 0.45, 100)));
    return res;
}
}

const bool ArrowTower::s_registered = TowerFactory::registerTower(ArrowTower::s_idType, &createArrowTower, s_icone);

const ArrowTower::type_containr_levels ArrowTower::s_levels = initTowerLevels();
