#include "creepfactory.h"

#include "rat.hpp"

Creep* CreepFactory::createCreep(quint32 level, const QPointF& p)
{
    return type_factory::instance().create(Rat::s_idType, p);
}
