#ifndef FLECHE_HPP
#define FLECHE_HPP

#include "bullet.hpp"

class Fleche : public Bullet
{
public:
    Fleche(const QPointF& coords, Creep* cible);

    virtual void update(double dt);
};

#endif // FLECHE_HPP
