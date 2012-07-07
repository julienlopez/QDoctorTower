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
        if(!creeps().isEmpty() && t->canTarget())
        {
            Attacker* a = qobject_cast<Attacker*>(t);
            Q_ASSERT(a);
            Creep* c = a->cible();
            if(c) //gestion de la cible sortant de la zone de portée
            {
                QPointF p(c->coords() - t->coords());
                if(p.manhattanLength() > a->portee()*a->portee())
                {
                    a->setCible(0);
                }
            }
            if(!c) //si pas de cible, on en cherche une nouvelle
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
