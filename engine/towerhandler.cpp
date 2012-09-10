#include "towerhandler.hpp"
#include "towers/attackers/attacker.hpp"
#include "creeps/creep.h"

TowerHandler::TowerHandler()
{
}

void TowerHandler::addTower(Tower* t)
{
    Q_ASSERT(t);
    m_towers << t;
}

void TowerHandler::maj()
{
    foreach(Tower* t, m_towers)
    {
        if(!creeps().empty() && t->canTarget())
        {
            Attacker* a = qobject_cast<Attacker*>(t);
            Q_ASSERT(a);
            Creep* c = a->cible();
            if(c && a->isCreepInRange(c)) //gestion de la cible sortant de la zone de portée
                a->setCible(0);
            else //si pas de cible, on en cherche une nouvelle
            {
                c = closestCreep(a->coords());
                if(c)
                {
                    a->setCible(c);
                }
            }
        }
        t->update(dt());
    }
}
