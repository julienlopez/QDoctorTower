#ifndef BLASTER_HPP
#define BLASTER_HPP

#include "bullet.hpp"

class Blaster : public Bullet
{
public:
    Blaster(const QPointF& coords, wp_creep cible);

    virtual void update(double dt);

    virtual void draw(QPainter* painter) const;
};

#endif // BLASTER_HPP
