#include "fleche.hpp"
#include "creeps/creep.h"

#include <QVector2D>

Fleche::Fleche(const QPointF& coords, Creep* cible): Bullet(coords, cible, 5)
{
    setVitesse(5);
}

void Fleche::update(double dt)
{
    if(!cible()) return;
    QVector2D reste(cible()->coords() - coords());
    if(reste.lengthSquared() < vitesse()*dt)
    {
        //dernier deplacement
        setCoords(cible()->coords());
        onHit();
        return;
    }
    (*this) += (reste.normalized()*vitesse()*dt).toPointF();
}
