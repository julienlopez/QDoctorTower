#include "bullet.hpp"
#include "creeps/creep.h"

Bullet::Bullet(const QPointF& coords, wp_creep cible, quint32 degats) :
    Moving<QPointF>(coords), m_degats(degats)
{
    Q_ASSERT(!cible.expired());
    m_cible = cible;
}

Bullet::~Bullet()
{}

Bullet::wp_creep Bullet::cible()
{
    return m_cible;
}

Bullet::wp_creep Bullet::cible() const
{
    return m_cible;
}

void Bullet::clearCible()
{
    m_cible.reset();
}

void Bullet::onHit()
{
    if(m_cible.expired()) return;
    sp_creep c = cible().lock();
    Q_ASSERT(c.get());
    c->hit(m_degats);
    emitToDel();
}
