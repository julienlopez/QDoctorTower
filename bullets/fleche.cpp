#include "fleche.hpp"
#include "creeps/creep.h"

#include <QVector2D>

Fleche::Fleche(const QPointF& coords, Creep* cible): Bullet(coords)
{
    m_cible = cible;
    Q_ASSERT(m_cible);
}


void Fleche::update(double dt)
{
    Q_ASSERT(m_cible);
    QVector2D reste(m_cible->coords() - coords());
    if(reste.lengthSquared() < vitesse()*dt)
    {
        //dernier deplacement
        setCoords(m_cible->coords());
        emit hit();
        return;
    }
    (*this) += (reste.normalized()*vitesse()*dt).toPointF();
}
