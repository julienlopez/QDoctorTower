#ifndef BULLETHANDLER_HPP
#define BULLETHANDLER_HPP

#include "iengine.hpp"

class Bullet;

class QPainter;

class BulletHandler : public iEngine
{
public:
    typedef boost::shared_ptr<Bullet> sp_bullet;
    typedef std::list<sp_bullet> type_liste;

    BulletHandler();

    virtual void addBullet(sp_bullet b);

protected:
    void maj();

    void removeBullet(Bullet& b);

    void drawBullets(QPainter* p) const;

    void cleanUpBullets(wp_creep c);

private:
    type_liste m_bullets;
};

#endif // BULLETHANDLER_HPP
