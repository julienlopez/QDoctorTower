#include "bullet.hpp"

Bullet::Bullet(const QPointF& coords, QObject *parent) :
    QObject(parent), Moving<QPointF>(coords)
{
}
