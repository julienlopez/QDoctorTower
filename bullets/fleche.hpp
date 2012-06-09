#ifndef FLECHE_HPP
#define FLECHE_HPP

#include "bullet.hpp"

class Creep;

class Fleche : public Bullet
{
public:
    Fleche(const QPointF& coords, Creep* cible);

    virtual void update(double dt);

private:
    Creep* m_cible;
};

#endif // FLECHE_HPP
