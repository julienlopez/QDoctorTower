#ifndef CREEPHANDLER_HPP
#define CREEPHANDLER_HPP

#include "iengine.hpp"
#include "utils/list.hpp"

#include <QtGlobal>

class QPoint;
class QPainter;

class CreepHandler : public iEngine
{
public:

    CreepHandler();

protected:

    virtual Creep* closestCreep(const QPointF& p) const;

    Creep* createCreep(const QPoint& spawn, const QPoint &goal, quint32 level);

    virtual const type_liste_creep& creeps() const;

    virtual type_liste_creep& creeps();

    void maj();

    void removeCreep(Creep* c);

    void drawCreeps(QPainter* p) const;

private:
    type_liste_creep m_creeps;
};

#endif // CREEPHANDLER_HPP
