#include "blastertower.hpp"

#include <towers/towerfactory.hpp>
#include <engine/engine.hpp>
#include <bullets/blaster.hpp>

const quint8 BlasterTower::s_idType = 4;

const QString BlasterTower::s_icone = TowerFactory::prefixeIcones()+"blaster_tower.png";

BlasterTower::BlasterTower(const QPoint& p): Attacker(p, 100)
{
    setPortee(7);
    abilityTirer().setRechargeTime(2);

    setEnergyMax(100);
    setEnergyInputMax(10);
}

bool BlasterTower::canGoOnWater() const
{
    return false;
}

void BlasterTower::tirer()
{
    subtractEnergy(20);
    Engine::instance()->addBullet(Engine::sp_bullet(new Blaster(coords(), cible())));
}

const QString& BlasterTower::icone() const
{
    return s_icone;
}

bool BlasterTower::canLevelUp() const
{
    return false;
}

void BlasterTower::levelUp()
{

}

bool BlasterTower::canFire() const
{
    return Attacker::canFire() && energy() > 20;
}

std::string BlasterTower::label() const
{
    return "Blaster Tower";
}

namespace
{
Tower* createBlasterTower(const QPoint& p) {
    return new BlasterTower(p);
}
}

const bool BlasterTower::s_registered = TowerFactory::registerTower(BlasterTower::s_idType, &createBlasterTower, s_icone);
