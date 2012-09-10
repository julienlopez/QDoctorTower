#ifndef BULLETHANDLER_HPP
#define BULLETHANDLER_HPP

#include "iengine.hpp"
#include <utils/list.hpp>

class Bullet;

class QPainter;

class BulletHandler : public iEngine
{
public:
    typedef List<Bullet*> type_liste;

    BulletHandler();

    virtual void addBullet(Bullet* b);

protected:
    void maj();

    void removeBullet(Bullet *b);

    void drawBullets(QPainter* p) const;

    void cleanUpBullets(Creep* c);

private:
    type_liste m_bullets;
};

#endif // BULLETHANDLER_HPP
