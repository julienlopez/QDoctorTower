#include "fleche.hpp"
#include "creeps/creep.h"

#include <QVector2D>
#include <QPainter>

Fleche::Fleche(const QPointF& coords, wp_creep cible): Bullet(coords, cible, 5)
{
    setVitesse(5);
}

void Fleche::update(double dt)
{
    if(cible().expired()) return;
    sp_creep c = cible().lock();
    QVector2D reste(c->coords() - coords());
    if(reste.lengthSquared() < vitesse()*dt)
    {
        //dernier deplacement
        setCoords(c->coords());
        onHit();
        return;
    }
    (*this) += (reste.normalized()*vitesse()*dt).toPointF();
}

void Fleche::draw(QPainter* painter) const {
    if(cible().expired()) return;
    sp_creep c = cible().lock();
    QPointF pointTo = QVector2D(c->coords()-coords()).normalized().toPointF();
    pointTo /= 10;
    painter->drawLine(coords(), coords()+pointTo);
}
