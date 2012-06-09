#include "attacker.hpp"
#include <creeps/creep.h>

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
    m_cible = creep;
    connect(creep, SIGNAL(dead()), this, SLOT(onCreepDead()));
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
    Q_ASSERT(m_cible == creep);
    m_cible = 0;
}
