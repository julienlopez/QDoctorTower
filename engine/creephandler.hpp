#ifndef CREEPHANDLER_HPP
#define CREEPHANDLER_HPP

#include "iengine.hpp"

#include <QtGlobal>

class QPoint;
class QPainter;

class CreepHandler : public iEngine
{
public:

    CreepHandler();

    void removeCreep(wp_creep c);

protected:

    virtual sp_creep closestCreep(const QPointF& p) const;

    Creep* createCreep(const QPoint& spawn, const QPoint &goal);

    virtual const type_liste_creep& creeps() const;

    virtual type_liste_creep& creeps();

    void maj();

    void drawCreeps(QPainter* p) const;

    void setCurrentCreepToCreate(quint8 cctc);

private:
    quint8 m_currentCreepToCreate;
    type_liste_creep m_creeps;
};

#endif // CREEPHANDLER_HPP
