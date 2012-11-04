#include "bullethandler.hpp"
#include "bullets/bullet.hpp"

#include <utils/predicates.hpp>

BulletHandler::BulletHandler()
{}

void BulletHandler::addBullet(sp_bullet b)
{
    Q_ASSERT(b.get());
    m_bullets.push_back(b);
    b->toDel().connect(boost::bind(&BulletHandler::removeBullet, this, _1));
}

void BulletHandler::maj()
{
    for(type_liste::iterator i = m_bullets.begin(); i != m_bullets.end();)
    {
        sp_bullet b = *i;
        if(b)
        {
            b->update(dt());
            ++i;
        }
        else m_bullets.erase(i++);
    }
}

void BulletHandler::removeBullet(Bullet& b)
{
    type_liste::iterator it = std::find_if(m_bullets.begin(), m_bullets.end(), ComparePtr<Bullet>(&b));
    if(it != m_bullets.end()) it->reset();
}

void BulletHandler::drawBullets(QPainter *p) const
{
    Q_FOREACH(sp_bullet b, m_bullets) if(b) b->draw(p);
}

void BulletHandler::cleanUpBullets(wp_creep c)
{
    for(type_liste::iterator i = m_bullets.begin(); i != m_bullets.end(); ++i) {
        if(!i->get()) continue;
        if((*i)->cible().expired()) continue;
        sp_creep cible = (*i)->cible().lock();
        sp_creep creep = c.lock();
        if(cible == creep) {
            (*i)->clearCible();
            i->reset();
        }
    }
}
