#include "bullethandler.hpp"
#include "bullets/bullet.hpp"

BulletHandler::BulletHandler()
{}

void BulletHandler::addBullet(Bullet* b)
{
    Q_ASSERT(b);
    m_bullets << b;
}

void BulletHandler::maj()
{
    for(type_liste::iterator i = m_bullets.begin(); i != m_bullets.end();)
    {
        if(*i)
        {
            (*i)->update(dt());
            ++i;
        }
        else m_bullets.erase(i++);
    }
}

void BulletHandler::removeBullet(Bullet* b)
{
    //TODO faire ça avec iterators
    int i = m_bullets.indexOf(b);
    if(i<0) return;
    m_bullets[i] = 0;
}

void BulletHandler::drawBullets(QPainter *p) const
{
    foreach(Bullet* b, m_bullets) if(b) b->draw(p);
}

void BulletHandler::cleanUpBullets(Creep* c)
{
    for(type_liste::iterator i = m_bullets.begin(); i != m_bullets.end(); ++i)
        if(*i && (*i)->cible() == c) *i = 0;
}
