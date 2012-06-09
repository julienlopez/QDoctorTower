#ifndef CREEPFACTORY_H
#define CREEPFACTORY_H

#include <utils/factory.hpp>

#include <QtGlobal>

class Creep;
class QPointF;

class CreepFactory
{
public:
    typedef Factory<Creep, quint8, Creep*(*)(const QPointF&)> type_factory;

    static Creep* createCreep(quint32 level, const QPointF& p);
};

#endif // CREEPFACTORY_H
