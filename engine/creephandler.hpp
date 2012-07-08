#ifndef CREEPHANDLER_HPP
#define CREEPHANDLER_HPP

#include "iengine.hpp"

class QPoint;
class QPainter;

class CreepHandler : public iEngine
{
public:
    CreepHandler();

protected:
    virtual const QList<Creep*>& creeps() const;

    virtual Creep* closestCreep(const QPointF& p) const;

    Creep* createCreep(const QPoint& spawn, const QPoint &goal, quint32 level);

    virtual QList<Creep*>& creeps();

    void maj();

    void removeCreep(Creep* c);

    void drawCreeps(QPainter* p) const;

private:
    QList<Creep*> m_creeps;    
};

#endif // CREEPHANDLER_HPP
