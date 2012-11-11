#include "generator.hpp"

Generator::Generator(const QPoint& p, quint32 cost, double energyMax): Tower(p, cost)
{
    setEnergyMax(energyMax);
}

bool Generator::canTarget() const
{
    return false;
}

void Generator::update(double dt)
{
    if(rechargeCounter() < rechargeTime()) addToRechargeCounter(dt);
    if(rechargeCounter() >= rechargeTime())
    {
        addEnergy(dt*produceEnergy());
        useRechargeTime();
    }
}
