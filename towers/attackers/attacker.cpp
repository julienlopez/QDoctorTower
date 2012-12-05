#include "attacker.hpp"
#include <creeps/creep.h>

#include <cmath>

#include <boost/bind.hpp>

#include <QVector2D>

Attacker::Attacker(const QPoint& p, quint32 cost): Tower(p, cost), m_portee(0), m_tirer(boost::bind(&Attacker::tirer, this), boost::bind(&Attacker::canFire, this))
{}

void Attacker::update(double dt)
{
    m_tirer.update(dt);
}

double Attacker::portee() const
{
    return m_portee;
}

Attacker::wp_creep Attacker::cible() const
{
    return m_cible;
}

void Attacker::setCible(wp_creep creep)
{
    Q_ASSERT(!creep.expired());
    boost::shared_ptr<Creep> c = creep.lock();
    Q_ASSERT(c.get());
    boost::shared_ptr<Creep> cible = m_cible.lock();
    if(c.get() == cible.get()) return;
    if(!isCreepInRange(c)) return;
    m_cible = creep;
}

bool Attacker::canTarget() const
{
    return true;
}

bool Attacker::isCreepInRange(wp_creep creep) const
{
    Q_ASSERT(!creep.expired());
    boost::shared_ptr<Creep> c = creep.lock();
    Q_ASSERT(c.get());
    return QVector2D(c->coords()-coords()).lengthSquared() <= pow(portee(),2);
}

void Attacker::setPortee(double t)
{
    m_portee = t;
}

Ability& Attacker::abilityTirer()
{
    return m_tirer;
}

const Ability& Attacker::abilityTirer() const
{
    return m_tirer;
}

bool Attacker::canFire() const
{
    return !m_cible.expired();
}
