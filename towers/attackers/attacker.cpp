#include "attacker.hpp"
#include <creeps/creep.h>

#include <cmath>

#include <QVector2D>

Attacker::Attacker(const QPoint& p): Tower(p)
{
    m_tempsRecharge = 0;
    m_portee = 0;
    m_compteurRecharge = 0;
    m_cible = 0;
}

void Attacker::update(double dt)
{
    if(m_compteurRecharge < m_tempsRecharge) m_compteurRecharge += dt;
    if(m_cible && m_compteurRecharge >= m_tempsRecharge)
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

Creep* Attacker::cible() const
{
    return m_cible;
}

void Attacker::setCible(Creep* creep)
{
    if(m_cible) disconnect(m_cible, SIGNAL(dead()), this, SLOT(onCreepDead()));
    if(creep && !isCreepInRange(creep)) return;
    m_cible = creep;
    if(creep) connect(creep, SIGNAL(dead()), this, SLOT(onCreepDead()));
}

bool Attacker::canTarget() const
{
    return true;
}

bool Attacker::isCreepInRange(Creep* creep) const
{
    return QVector2D(creep->coords()-coords()).lengthSquared() <= pow(portee(),2);
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

void Attacker::onCreepDead()
{
    Creep* creep = qobject_cast<Creep*>(sender());
    Q_ASSERT(creep);
    Q_UNUSED(creep);
    m_cible = 0;
}
