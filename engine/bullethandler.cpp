#include "bullethandler.hpp"
#include "bullets/bullet.hpp"

BulletHandler::BulletHandler()
{}

void BulletHandler::addBullet(Bullet* b)
{
    Q_ASSERT(b);
    m_bullets << b;
}

#include <QDebug>

void BulletHandler::maj()
{
    qDebug() << "mise Ã  jour des balles {";
    qDebug() << m_bullets;
    qDebug() << "}";
    Bullet* b;
    for(QList<Bullet*>::iterator i = m_bullets.begin(); i != m_bullets.end();)
    {
        b = *i;
        if(b)
        {
            qDebug() << m_bullets.indexOf(b) << ": " << b;
            b->update(dt());
            ++i;
        }
        else ++i;//else m_bullets.erase(i++);
    }
}

void BulletHandler::removeBullet(Bullet* b)
{
    int i = m_bullets.indexOf(b);
    qDebug() << i << ": " << b;
    m_bullets[i] = 0;
    b->deleteLater();
    qDebug() << m_bullets[i];
    qDebug() << m_bullets;
}
