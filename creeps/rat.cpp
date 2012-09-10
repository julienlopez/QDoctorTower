#include "rat.hpp"
#include "creepfactory.h"

const quint8 Rat::s_idType = 1;

Rat::Rat(const QPointF& p): Creep(p)
{
    setVitesse(0.5);
    setVieMax(50); //20);
}

namespace {
Creep* createRat(const QPointF& p)
{
    return new Rat(p);
}
}

const bool Rat::s_registered = CreepFactory::type_factory::instance().registerProduct(Rat::s_idType, &createRat);
