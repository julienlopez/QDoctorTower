#ifndef IENGINE_HPP
#define IENGINE_HPP

#include <utils/list.hpp>

class Creep;

class QPointF;

class iEngine
{
public:
    typedef List<Creep*> type_liste_creep;

    virtual const type_liste_creep& creeps() const =0;

    virtual double dt() const =0;

protected:
    virtual Creep* closestCreep(const QPointF& p) const =0;

    virtual type_liste_creep& creeps() =0;
};

#endif // IENGINE_HPP
