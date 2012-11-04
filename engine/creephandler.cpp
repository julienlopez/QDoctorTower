#include "creephandler.hpp"
#include <creeps/creep.h>
#include <creeps/creepfactory.h>

#include <QPainter>

CreepHandler::CreepHandler()
{}

namespace {
struct DistCreep {
    CreepHandler::sp_creep creep;
    double distance;
};
}

CreepHandler::sp_creep CreepHandler::closestCreep(const QPointF& p) const
{
    type_liste_creep::const_iterator i = m_creeps.begin();
    while(i != m_creeps.end() && !(*i)) ++i;
    if(i == m_creeps.end()) return sp_creep();
    DistCreep dc;
    dc.creep = *i;
    dc.distance = ((*i)->coords()-p).manhattanLength();
    ++i;
    double dist;
    for(; i != m_creeps.end(); ++i)
    {
        if(!(*i)) continue;
        dist = ((*i)->coords()-p).manhattanLength();
        if(dist < dc.distance)
        {
            dc.creep = *i;
            dc.distance = dist;
        }
    }
    return dc.creep;
}

Creep* CreepHandler::createCreep(const QPoint &spawn, const QPoint &goal, quint32 level)
{
    Creep* c = CreepFactory::createCreep(level, spawn);
    c->setGoal(goal);
    m_creeps.push_back(sp_creep(c));
    return c;
}

CreepHandler::type_liste_creep& CreepHandler::creeps()
{
    return m_creeps;
}

const CreepHandler::type_liste_creep& CreepHandler::creeps() const
{
    return m_creeps;
}

void CreepHandler::maj()
{
    for(type_liste_creep::iterator i = m_creeps.begin(); i != m_creeps.end();)
        if(*i)
        {
            (*i)->update(dt());
            ++i;
        }
        else m_creeps.erase(i++);
}

void CreepHandler::removeCreep(wp_creep c)
{
    sp_creep creep = c.lock();
    Q_ASSERT(creep.get());
    type_liste_creep::iterator it = std::find(m_creeps.begin(), m_creeps.end(), creep);
    Q_ASSERT(it != m_creeps.end());
    m_creeps.erase(it);
}

void CreepHandler::drawCreeps(QPainter* p) const
{
    p->setPen(Qt::black);
    Q_FOREACH(sp_creep c, m_creeps) if(c) c->draw(p);
}
