#include "bullet.hpp"
#include "creeps/creep.h"

Bullet::Bullet(const QPointF& coords, Creep* cible, quint32 degats, QObject *parent) :
    QObject(parent), Moving<QPointF>(coords), m_degats(degats)
{
    Q_ASSERT(cible);
    m_cible = cible;
    connect(m_cible, SIGNAL(dead()), this, SLOT(deleteLater()));
    connect(m_cible, SIGNAL(escaped()), this, SLOT(deleteLater()));
}

Creep* Bullet::cible()
{
    return m_cible;
}

const Creep* Bullet::cible() const
{
    return m_cible;
}

#include <QDebug>

void Bullet::onHit()
{
    qDebug() << "Bullet::onHit()";
    Q_ASSERT(m_cible);
    cible()->hit(m_degats);
    emit hasHit();
}
