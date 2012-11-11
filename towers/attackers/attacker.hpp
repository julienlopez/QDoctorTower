#ifndef ATTACKER_HPP
#define ATTACKER_HPP

#include <creeps/creep.h>
#include <towers/tower.hpp>
#include <towers/ability.hpp>

class Attacker : public Tower
{
public:
    typedef boost::weak_ptr<Creep> wp_creep;

    Attacker(const QPoint& p, quint32 cost);

    virtual void update(double dt);

    double portee() const;

    wp_creep cible() const;

    void setCible(wp_creep creep);

    virtual void tirer() =0;

    virtual bool canTarget() const;

    bool isCreepInRange(wp_creep creep) const;

protected:
    void setPortee(double t);

    Ability& abilityTirer();

    virtual bool canFire() const;

private:
    double m_portee;
    wp_creep m_cible;
    Ability m_tirer;
};

#endif // ATTACKER_HPP
