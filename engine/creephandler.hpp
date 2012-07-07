#ifndef CREEPHANDLER_HPP
#define CREEPHANDLER_HPP

#include <QList>

class Creep;

class QPointF;
class QPoint;

class CreepHandler
{
public:
    CreepHandler();

    virtual double dt() const =0;

protected:
    Creep* closestCreep(const QPointF& p) const;

    Creep* createCreep(const QPoint& spawn, const QPoint &goal, quint32 level);

    QList<Creep*>& creeps();

    const QList<Creep*>& creeps() const;

    void maj();

    void removeCreep(Creep* c);

private:
    QList<Creep*> m_creeps;    
};

#endif // CREEPHANDLER_HPP
