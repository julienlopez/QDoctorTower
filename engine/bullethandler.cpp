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
            //qDebug() << m_bullets.indexOf(b) << ": " << b;
            b->update(dt());
            ++i;
        }
        else
        {
            //(*i)->deleteLater();
            m_bullets.erase(i++);
        }
    }
}

void BulletHandler::removeBullet(Bullet* b)
{
    qDebug() << "BulletHandler::removeBullet(" << b << ") {";
    int i = m_bullets.indexOf(b);
    qDebug() << i << " => " << b;
    if(i<0) return;
    m_bullets[i] = 0;
    qDebug() << "}";
}

void BulletHandler::drawBullets(QPainter *p) const
{
    foreach(Bullet* b, m_bullets) if(b) b->draw(p);
}

void BulletHandler::cleanUpBullets(Creep* c)
{
    qDebug() << "BulletHandler::cleanUpBullets(" << c << ") {";
    for(QList<Bullet*>::iterator i = m_bullets.begin(); i != m_bullets.end(); ++i)
        if(*i && (*i)->cible() == c) *i = 0;
    qDebug() << "}";
}
