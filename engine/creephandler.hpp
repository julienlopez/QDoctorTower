#ifndef CREEPHANDLER_HPP
#define CREEPHANDLER_HPP

#include "iengine.hpp"

class QPoint;

class CreepHandler : public iEngine
{
public:
    CreepHandler();

    virtual const QList<Creep*>& creeps() const;

protected:
    virtual Creep* closestCreep(const QPointF& p) const;

    Creep* createCreep(const QPoint& spawn, const QPoint &goal, quint32 level);

    virtual QList<Creep*>& creeps();

    void maj();

    void removeCreep(Creep* c);

private:
    QList<Creep*> m_creeps;    
};

#endif // CREEPHANDLER_HPP
