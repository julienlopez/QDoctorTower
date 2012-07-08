#ifndef BULLETHANDLER_HPP
#define BULLETHANDLER_HPP

#include "iengine.hpp"

class Bullet;

class QPainter;

class BulletHandler : public iEngine
{
public:
    BulletHandler();

    virtual void addBullet(Bullet* b);

protected:
    void maj();

    void removeBullet(Bullet *b);

    void drawBullets(QPainter* p) const;

private:
    QList<Bullet*> m_bullets;
};

#endif // BULLETHANDLER_HPP
