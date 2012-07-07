#ifndef IENGINE_HPP
#define IENGINE_HPP

#include <QList>

class Creep;

class QPointF;

class iEngine
{
public:
    virtual const QList<Creep*>& creeps() const =0;

    virtual double dt() const =0;

protected:
    virtual Creep* closestCreep(const QPointF& p) const =0;

    virtual QList<Creep*>& creeps() =0;
};

#endif // IENGINE_HPP
