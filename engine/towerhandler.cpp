#include "towerhandler.hpp"
#include "towers/attackers/attacker.hpp"
#include "creeps/creep.h"

TowerHandler::TowerHandler()
{}

void TowerHandler::addTower(Tower* t)
{
    Q_ASSERT(t);
    m_towers.push_back(sp_tower(t));
}

void TowerHandler::maj()
{
    Q_FOREACH(sp_tower t, m_towers)
    {
        if(!creeps().empty() && t->canTarget())
        {
            Attacker* a = dynamic_cast<Attacker*>(t.get());
            Q_ASSERT(a);
            wp_creep creep = a->cible();
            sp_creep c = creep.lock();
            if(c.get() && a->isCreepInRange(c)) //gestion de la cible sortant de la zone de portée
                a->setCible(sp_creep());
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
