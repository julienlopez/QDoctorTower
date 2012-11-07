#include "attacker.hpp"
#include <creeps/creep.h>

#include <cmath>

#include <QVector2D>

Attacker::Attacker(const QPoint& p, quint32 cost): Tower(p, cost)
{
    m_tempsRecharge = 0;
    m_portee = 0;
    m_compteurRecharge = 0;
}

void Attacker::update(double dt)
{
    if(m_compteurRecharge < m_tempsRecharge) m_compteurRecharge += dt;
    if(!m_cible.expired() && m_compteurRecharge >= m_tempsRecharge)
    {
        tirer();
        m_compteurRecharge -= m_tempsRecharge;
    }
}

double Attacker::tempsRecharge() const
{
    return m_tempsRecharge;
}

double Attacker::portee() const
{
    return m_portee;
}

double Attacker::compteurRecharge() const
{
    return m_compteurRecharge;
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

void Attacker::setTempsRecharge(double t)
{
    m_tempsRecharge = t;
}

void Attacker::setPortee(double t)
{
    m_portee = t;
}

void Attacker::setCompteurRecharge(double d)
{
    m_compteurRecharge = d;
}
