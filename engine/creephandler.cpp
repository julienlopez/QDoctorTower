#include "creephandler.hpp"
#include <creeps/creep.h>
#include <creeps/creepfactory.h>

#include <QPainter>

CreepHandler::CreepHandler()
{}

namespace {
struct DistCreep {
    Creep* creep;
    double distance;
};
}

Creep* CreepHandler::closestCreep(const QPointF& p) const
{
    QList<Creep*>::const_iterator i = m_creeps.begin();
    while(i != m_creeps.end() && !(*i)) ++i;
    if(i == m_creeps.end()) return 0;
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
    m_creeps << c;
    return c;
}

QList<Creep*>& CreepHandler::creeps()
{
    return m_creeps;
}

const QList<Creep*>& CreepHandler::creeps() const
{
    return m_creeps;
}

void CreepHandler::maj()
{
    for(QList<Creep*>::iterator i = m_creeps.begin(); i != m_creeps.end();)
        if(*i)
        {
            (*i)->update(dt());
            ++i;
        }
        else m_creeps.erase(i++);
}

void CreepHandler::removeCreep(Creep* c)
{
    m_creeps[m_creeps.indexOf(c)] = 0;
    c->deleteLater();
}

void CreepHandler::drawCreeps(QPainter* p) const
{
    p->setPen(Qt::black);
    foreach(Creep* c, m_creeps) if(c) c->draw(p);
}
